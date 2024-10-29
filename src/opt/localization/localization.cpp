/**
 * Mx Compiler
 * File Name: localization.cpp
 * Identification: ./src/opt/localization/localization.cpp
 * Function: Moves copy of global function to local for pure functions
 */
#include <queue>

#include "ir/ir.h"
#include "opt/localization/localization.h"

struct CallMapNode {
  std::shared_ptr<IRFunction> func_{nullptr};
  std::list<std::shared_ptr<CallMapNode>> callee_;
  std::list<std::shared_ptr<CallMapNode>> caller_;

  std::unordered_set<std::shared_ptr<Register>> use_;
  std::unordered_set<std::shared_ptr<Register>> def_;
};

class CallMap {
 public:
  CallMap() = delete;
  CallMap(FunctionManager &manager) {
    for (const auto &func : manager.GetFunctions()) {
      if (func.second->IsBuiltin()) {
        continue;
      }
      auto node = std::make_shared<CallMapNode>(func.second);
      nodes_.emplace_back(node);
      node_map_.emplace(func.second, node);
    }
    for (const auto &node : nodes_) {
      ParseDefUse(node);
    }
    DefUsePropagation();
  }
  [[nodiscard]] const std::list<std::shared_ptr<CallMapNode>> &GetNodes() const { return nodes_; }

 private:
  void ParseDefUse(const std::shared_ptr<CallMapNode> &node) {
    for (const auto &blocks : node->func_->GetBlocks()) {
      for (const auto &stmts : blocks->GetStmts()) {
        if (auto load_stmt = dynamic_cast<LoadStmt *>(stmts.get()); load_stmt != nullptr) {
          if (load_stmt->GetPtr()->IsGlobal()) {
            node->use_.insert(load_stmt->GetPtr());
          }
        } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmts.get()); store_stmt != nullptr) {
          if (store_stmt->GetPtr()->IsGlobal()) {
            node->def_.insert(store_stmt->GetPtr());
          }
        } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmts.get()); call_stmt != nullptr) {
          if (call_stmt->GetFunction().lock()->IsBuiltin()) {
            continue;
          }
          auto callee_node = node_map_.at(call_stmt->GetFunction().lock());
          node->callee_.push_back(callee_node);
          callee_node->caller_.push_back(node);
        }
      }
    }
  }
  void DefUsePropagation() {
    std::unordered_set<std::shared_ptr<CallMapNode>> flag;
    std::queue<std::shared_ptr<CallMapNode>> queue;
    for (const auto &node : nodes_) {
      queue.push(node);
      flag.insert(node);
    }
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();
      auto use_all = node->use_;
      auto def_all = node->def_;
      for (const auto &callee : node->callee_) {
        auto tmp = callee->use_;
        use_all.merge(tmp);
        tmp = callee->def_;
        def_all.merge(tmp);
      }
      if (def_all != node->def_ || use_all != node->use_) {
        node->def_ = std::move(def_all);
        node->use_ = std::move(use_all);
        for (const auto &caller : node->caller_) {
          if (!flag.contains(caller)) {
            flag.insert(caller);
            queue.push(caller);
          }
        }
      }
    }
  }
  std::unordered_map<std::shared_ptr<IRFunction>, std::shared_ptr<CallMapNode>> node_map_;
  std::list<std::shared_ptr<CallMapNode>> nodes_;
};

std::unordered_map<std::shared_ptr<IRFunction>, GlobalUsageInfo> Localization(FunctionManager &func_manager) {
  CallMap call_map(func_manager);
  auto &list = call_map.GetNodes();
  std::unordered_map<std::shared_ptr<IRFunction>, GlobalUsageInfo> ret;
  for (const auto &node : list) {
    auto &def = node->def_;
    auto &use = node->use_;
    auto &func = node->func_;
    std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<Register>> local_map;
    std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<Register>> replace_map;
    for (const auto &reg : use) {
      if (!def.contains(reg)) {
        auto local_reg =
            std::make_shared<Register>(reg->GetType().RemovePtr(), reg->GetName().substr(1) + ".local", false, false);
        local_map.emplace(reg, local_reg);
      }
    }
    ret.emplace(func, GlobalUsageInfo{node->def_, node->use_});
    for (const auto &block : func->GetBlocks()) {
      auto &stmts = block->GetStmts();
      for (auto it = stmts.begin(); it != stmts.end();) {
        auto &stmt = *it;
        if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
          if (replace_map.contains(load_stmt->GetPtr())) {
            load_stmt->SetPtr(replace_map.at(load_stmt->GetPtr()));
          }
          if (load_stmt->GetPtr()->IsGlobal() && local_map.contains(load_stmt->GetPtr())) {
            replace_map[load_stmt->GetResult()] = local_map.at(load_stmt->GetPtr());
            it = stmts.erase(it);
            continue;
          }
        } else if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
          auto lhs = std::dynamic_pointer_cast<Register>(binary_stmt->GetLeft());
          auto rhs = std::dynamic_pointer_cast<Register>(binary_stmt->GetRight());
          if (lhs != nullptr && replace_map.contains(lhs)) {
            binary_stmt->SetLeft(replace_map.at(lhs));
          }
          if (rhs != nullptr && replace_map.contains(rhs)) {
            binary_stmt->SetRight(replace_map.at(rhs));
          }
        } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
          auto &args = call_stmt->GetArguments();
          for (auto &arg : args) {
            auto reg = std::dynamic_pointer_cast<Register>(arg);
            if (reg != nullptr && replace_map.contains(reg)) {
              arg = replace_map.at(reg);
            }
          }
        } else if (auto gep_stmt = dynamic_cast<GetElementPtrStmt *>(stmt.get()); gep_stmt != nullptr) {
          if (replace_map.contains(gep_stmt->GetPtr())) {
            gep_stmt->SetPtr(replace_map.at(gep_stmt->GetPtr()));
          }
          auto &index = gep_stmt->GetIndex();
          for (auto &arg : index) {
            auto reg = std::dynamic_pointer_cast<Register>(arg);
            if (reg != nullptr && replace_map.contains(reg)) {
              arg = replace_map.at(reg);
            }
          }
        } else if (auto icmp_stmt = dynamic_cast<ICmpStmt *>(stmt.get()); icmp_stmt != nullptr) {
          auto lhs = std::dynamic_pointer_cast<Register>(icmp_stmt->GetLhs());
          auto rhs = std::dynamic_pointer_cast<Register>(icmp_stmt->GetRhs());
          if (lhs != nullptr && replace_map.contains(lhs)) {
            icmp_stmt->SetLhs(replace_map.at(lhs));
          }
          if (rhs != nullptr && replace_map.contains(rhs)) {
            icmp_stmt->SetRhs(replace_map.at(rhs));
          }
        } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
          if (replace_map.contains(store_stmt->GetPtr())) {
            store_stmt->SetPtr(replace_map.at(store_stmt->GetPtr()));
          }
          auto val = std::dynamic_pointer_cast<Register>(store_stmt->GetValue());
          if (val != nullptr && replace_map.contains(val)) {
            store_stmt->SetValue(replace_map.at(val));
          }
        }
        ++it;
      }
      auto &br_stmt = block->GetBranchStmt();
      if (auto cond_br_stmt = dynamic_cast<ConditionalBrStmt *>(br_stmt.get()); cond_br_stmt != nullptr) {
        auto reg = std::dynamic_pointer_cast<Register>(cond_br_stmt->GetCondition());
        if (reg != nullptr && replace_map.contains(reg)) {
          cond_br_stmt->SetCondition(replace_map.at(reg));
        }
      } else if (auto ret_stmt = dynamic_cast<RetStmt *>(br_stmt.get()); ret_stmt != nullptr) {
        auto reg = std::dynamic_pointer_cast<Register>(ret_stmt->GetRet());
        if (reg != nullptr && replace_map.contains(reg)) {
          ret_stmt->SetRet(replace_map.at(reg));
        }
      }
    }
    for (const auto &reg : use) {
      if (!def.contains(reg)) {
        func->GetBlocks()[0]->GetStmts().push_back(std::make_unique<LoadStmt>(local_map.at(reg), reg));
      }
    }
  }
  return ret;
}
