/**
 * Mx Compiler
 * File Name: mem_to_reg.cpp
 * Identification: ./src/opt/mem_to_reg.h
 * Function: Functions used for Mem2Reg optimization
 */
#include <stack>
#include <unordered_set>

#include "ir/ir.h"
#include "opt/mem_to_reg/mem_to_reg.h"

std::unordered_set<std::shared_ptr<Register>> alloca_reg;
std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<Register>> reg_version;

void MemToReg(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes, VarManager &var_manager) {
  alloca_reg.clear();
  reg_version.clear();
  ReservePhi(cfg_nodes);
  PlacePhi(cfg_nodes[0], var_manager);
}

void ReservePhi(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes) {
  for (const auto &block : cfg_nodes) {
    for (const auto &stmt : block->GetBlock()->GetStmts()) {
      if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
        alloca_reg.emplace(alloca_stmt->GetResult());
      }
    }
  }
  for (const auto &node : cfg_nodes) {
    auto &block = node->GetBlock();
    for (const auto &stmt : block->GetStmts()) {
      if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
        auto &ptr = store_stmt->GetPtr();
        if (alloca_reg.contains(ptr)) {
          block->ReservePhi(ptr);
          for (const auto &border : node->GetDomBorder()) {
            border->GetBlock()->ReservePhi(ptr);
          }
        }
      }
    }
  }
}

void PlacePhi(const std::shared_ptr<CFGNode>& cur_node, VarManager &var_manager) {
  auto &block = cur_node->GetBlock();
  std::stack<std::pair<std::shared_ptr<Register>, std::shared_ptr<Register>>> old_ver;
  for (const auto &[alloca_var, vec] : cur_node->GetBlock()->GetReservedPhi()) {
    auto block_var = var_manager.CreateTmpVar(alloca_var->GetType().RemovePtr(), alloca_var->GetName() + ".ver");
    old_ver.emplace(alloca_var, reg_version[alloca_var]);
    block->AppendPhi(std::make_unique<PhiStmt>(block_var, vec));
    reg_version[alloca_var] = block_var;
  }
  for (auto &stmt : block->GetStmts()) {
    if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      auto &ptr = load_stmt->GetPtr();
      if (alloca_reg.contains(ptr)) {
        stmt = std::make_unique<BinaryStmt>(load_stmt->GetResult(), BinaryStmt::OpType::kAdd, reg_version[ptr],
                                            var_manager.GetInt(0));
      }
    } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
      auto &ptr = store_stmt->GetPtr();
      if (alloca_reg.contains(ptr)) {
        auto var = var_manager.CreateTmpVar(ptr->GetType().RemovePtr(), ptr->GetName() + ".ver");
        reg_version[ptr] = var;
        stmt =
            std::make_unique<BinaryStmt>(var, BinaryStmt::OpType::kAdd, store_stmt->GetValue(), var_manager.GetInt(0));
      }
    }
  }
  for (const auto &suc : cur_node->GetSuc()) {
    auto &reserved_phi = suc.lock()->GetBlock()->GetReservedPhi();
    for (auto &phi : reserved_phi) {
      suc.lock()->GetBlock()->PushPhi(phi.first, block, reg_version[phi.first]);
    }
  }
  for (const auto &border : cur_node->GetDomBorder()) {
    PlacePhi(border, var_manager);
  }
  while (!old_ver.empty()) {
    const auto &[alloca_var, old] = old_ver.top();
    reg_version[alloca_var] = old;
    old_ver.pop();
  }
}
