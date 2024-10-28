/**
 * Mx Compiler
 * File Name: mem_to_reg.cpp
 * Identification: ./src/opt/mem_to_reg.h
 * Function: Functions used for Mem2Reg optimization
 */
#include <queue>
#include <stack>
#include <unordered_set>

#include "ir/ir.h"
#include "opt/mem_to_reg/mem_to_reg.h"

std::unordered_set<std::shared_ptr<Register>> alloca_reg;
std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<Var>> reg_version;
std::unordered_map<std::shared_ptr<Var>, std::shared_ptr<Var>> replace_reg;

void ReservePhi(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes, VarManager &var_manager) {
  for (const auto &block : cfg_nodes) {
    for (const auto &stmt : block->GetBlock()->GetStmts()) {
      if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
        alloca_reg.emplace(alloca_stmt->GetResult());
        auto type = alloca_stmt->GetResult()->GetType().RemovePtr();
        if (type == kIRIntType) {
          reg_version[alloca_stmt->GetResult()] = var_manager.GetInt(0);
        } else if (type == kIRBoolType) {
          reg_version[alloca_stmt->GetResult()] = var_manager.GetBool(false);
        } else {
          reg_version[alloca_stmt->GetResult()] = var_manager.GetNull();
        }
      }
    }
  }
  for (const auto &node : cfg_nodes) {
    auto &block = node->GetBlock();
    for (const auto &stmt : block->GetStmts()) {
      if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
        auto &ptr = store_stmt->GetPtr();
        if (alloca_reg.contains(ptr)) {
          std::queue<std::shared_ptr<CFGNode>> border_queue;
          for (const auto &border : node->GetDomBorder()) {
            border_queue.push(border);
          }
          while (!border_queue.empty()) {
            auto border = border_queue.front();
            border_queue.pop();
            if (!border->GetBlock()->HasReserved(ptr)) {
              border->GetBlock()->ReservePhi(ptr);
              for (const auto &item : border->GetDomBorder()) {
                border_queue.push(item);
              }
            }
          }
        }
      }
    }
  }
}

void PlacePhi(const std::shared_ptr<CFGNode> &cur_node, VarManager &var_manager) {  // NOLINT
  auto &block = cur_node->GetBlock();
  std::stack<std::pair<std::shared_ptr<Register>, std::shared_ptr<Var>>> old_ver;
  for (const auto &[alloca_var, vec] : cur_node->GetBlock()->GetReservedPhi()) {
    auto block_var =
        var_manager.CreateTmpVar(alloca_var->GetType().RemovePtr(), alloca_var->GetName().substr(1) + ".ver");
    old_ver.emplace(alloca_var, reg_version[alloca_var]);
    block->NamePhi(alloca_var, block_var);
    reg_version[alloca_var] = block_var;
  }
  auto &stmts = block->GetStmts();
  for (auto it = stmts.begin(); it != stmts.end();) {
    auto &stmt = *it;
    if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      auto &ptr = load_stmt->GetPtr();
      if (alloca_reg.contains(ptr)) {
        replace_reg[load_stmt->GetResult()] = reg_version[ptr];
        it = stmts.erase(it);
        continue;
      }
    } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
      auto &ptr = store_stmt->GetPtr();
      if (alloca_reg.contains(ptr)) {
        old_ver.emplace(ptr, reg_version[ptr]);
        reg_version[ptr] = store_stmt->GetValue();
        it = stmts.erase(it);
        continue;
      }
    }
    ++it;
  }
  for (const auto &suc : cur_node->GetSuc()) {
    auto &reserved_phi = suc.lock()->GetBlock()->GetReservedPhi();
    for (auto &phi : reserved_phi) {
      suc.lock()->GetBlock()->PushPhi(phi.first, block, reg_version[phi.first]);
    }
  }
  for (const auto &border : cur_node->GetDomChild()) {
    PlacePhi(border, var_manager);
  }
  while (!old_ver.empty()) {
    const auto &[alloca_var, old] = old_ver.top();
    reg_version[alloca_var] = old;
    old_ver.pop();
  }
}

void ReplaceRegs(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes) {
  for (auto &item : replace_reg) {
    auto val = item.second;
    while (replace_reg.contains(val)) {
      val = replace_reg[val];
    }
    item.second = val;
  }
  for (auto &node : cfg_nodes) {
    auto &block = node->GetBlock();
    auto &phi_name = block->GetPhiResult();
    for (auto &item : block->GetReservedPhi()) {
      for (auto &reg : item.second) {
        if (replace_reg.contains(reg.first)) {
          reg.first = replace_reg[reg.first];
        }
      }
      block->AppendPhi(std::make_unique<PhiStmt>(phi_name.at(item.first), item.second));
    }
    auto &stmts = block->GetStmts();
    for (auto it = stmts.begin(); it != stmts.end();) {
      auto &stmt = *it;
      if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
        it = stmts.erase(it);
        continue;
      }
      if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
        auto &value = store_stmt->GetValue();
        if (replace_reg.contains(value)) {
          store_stmt->SetValue(replace_reg[value]);
        }
      } else if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
        auto &lhs = binary_stmt->GetLeft();
        auto &rhs = binary_stmt->GetRight();
        if (replace_reg.contains(lhs)) {
          binary_stmt->SetLeft(replace_reg[lhs]);
        }
        if (replace_reg.contains(rhs)) {
          binary_stmt->SetRight(replace_reg[rhs]);
        }
      } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
        auto &args = call_stmt->GetArguments();
        for (auto &arg : args) {
          if (replace_reg.contains(arg)) {
            arg = replace_reg[arg];
          }
        }
      } else if (auto gep_stmt = dynamic_cast<GetElementPtrStmt *>(stmt.get()); gep_stmt != nullptr) {
        auto &index = gep_stmt->GetIndex();
        for (auto &arg : index) {
          if (replace_reg.contains(arg)) {
            arg = replace_reg[arg];
          }
        }
        auto &ptr = gep_stmt->GetPtr();
        if (replace_reg.contains(ptr)) {
          gep_stmt->SetPtr(std::dynamic_pointer_cast<Register>(replace_reg.at(ptr)));
        }
      } else if (auto icmp_stmt = dynamic_cast<ICmpStmt *>(stmt.get()); icmp_stmt != nullptr) {
        auto &left = icmp_stmt->GetLhs();
        auto &right = icmp_stmt->GetRhs();
        if (replace_reg.contains(left)) {
          icmp_stmt->SetLhs(replace_reg[left]);
        }
        if (replace_reg.contains(right)) {
          icmp_stmt->SetRhs(replace_reg[right]);
        }
      } else if (auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get()); phi_stmt != nullptr) {
        assert(false);
      }
      ++it;
    }
    for (auto &stmt : node->GetBlock()->GetPhiStmts()) {
      auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get());
      assert(phi_stmt != nullptr);
      auto &args = phi_stmt->GetBlocks();
      for (auto &arg : args) {
        auto reg = std::dynamic_pointer_cast<Register>(arg.first);
        if (reg != nullptr && replace_reg.contains(reg)) {
          arg.first = replace_reg[arg.first];
        }
      }
    }
    if (auto ret_stmt = dynamic_cast<RetStmt *>(block->GetBranchStmt().get()); ret_stmt != nullptr) {
      auto &ret = ret_stmt->GetRet();
      if (replace_reg.contains(ret)) {
        ret_stmt->SetRet(replace_reg[ret]);
      }
    } else if (auto br_cond = dynamic_cast<ConditionalBrStmt *>(block->GetBranchStmt().get()); br_cond != nullptr) {
      auto &condition = br_cond->GetCondition();
      if (replace_reg.contains(condition)) {
        br_cond->SetCondition(replace_reg[condition]);
      }
    }
  }
}

void MemToReg(ControlFlowGraph &cfg, VarManager &var_manager) {
  const auto &cfg_nodes = cfg.GetCFGNodes();
  alloca_reg.clear();
  reg_version.clear();
  replace_reg.clear();
  ReservePhi(cfg_nodes, var_manager);
  PlacePhi(cfg_nodes[0], var_manager);
  ReplaceRegs(cfg_nodes);
}

void RemoveCriticalEdge(ControlFlowGraph &cfg) {
  auto &func = cfg.GetIRFunction();
  auto &cfg_nodes = cfg.GetCFGNodes();
  for (auto &node : cfg_nodes) {
    auto &suc_nodes = node->GetSuc();
    for (auto &suc : suc_nodes) {
      if (node->GetSuc().size() > 1 && suc.lock()->GetPred().size() > 1 &&
          !suc.lock()->GetBlock()->GetPhiStmts().empty()) {
        auto temp_block = std::make_shared<Block>(func->AssignTag("criticalRemoval"));
        auto &blocks = func->GetBlocks();
        for (auto it = blocks.begin(); it != blocks.end(); ++it) {
          if (*it == node->GetBlock()) {
            ++it;
            blocks.insert(it, temp_block);
            break;
          }
        }
        temp_block->Append(std::make_unique<UnconditionalBrStmt>(suc.lock()->GetBlock()));
        auto temp_node = std::make_shared<CFGNode>(temp_block);
        temp_node->PushSuc(suc.lock());
        temp_node->PushPred(node);
        for (auto &suc_pred : suc.lock()->GetPred()) {
          if (suc_pred.lock() == node) {
            suc_pred = std::weak_ptr(temp_node);
          }
        }
        auto br_cond_stmt = dynamic_cast<ConditionalBrStmt *>(node->GetBlock()->GetBranchStmt().get());
        assert(br_cond_stmt != nullptr);
        if (br_cond_stmt->GetTrueBlock().lock() == suc.lock()->GetBlock()) {
          br_cond_stmt->GetTrueBlock() = temp_block;
        } else if (br_cond_stmt->GetFalseBlock().lock() == suc.lock()->GetBlock()) {
          br_cond_stmt->GetFalseBlock() = temp_block;
        }
        for (auto &stmt : suc.lock()->GetBlock()->GetPhiStmts()) {
          auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get());
          assert(phi_stmt != nullptr);
          for (auto &block : phi_stmt->GetBlocks() | std::views::values) {
            if (block.lock() == node->GetBlock()) {
              block = temp_block;
            }
          }
        }
        suc = temp_node;
      }
    }
  }
}

void PlaceMove(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes) {
  for (auto &item : cfg_nodes) {
    auto &phi_stmts = item->GetBlock()->GetPhiStmts();
    for (const auto &stmt : phi_stmts) {
      auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get());
      for (auto &[var, block] : phi_stmt->GetBlocks()) {
        if (phi_stmt->GetResult() == var) {
          continue;
        }
        block.lock()->AppendMove(std::make_unique<MoveStmt>(phi_stmt->GetResult(), var));
      }
    }
    phi_stmts.clear();
  }
}

void DestructPhi(ControlFlowGraph &cfg) {
  RemoveCriticalEdge(cfg);
  PlaceMove(cfg.GetCFGNodes());
}
