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
    for (const auto &reg : use) {
      auto local_reg = std::make_shared<Register>(reg->GetType(), reg->GetName().substr(1) + ".local", false, true);
      local_map.emplace(reg, local_reg);
    }
    int temp_cnt = 0;
    ret.emplace(func, GlobalUsageInfo{node->def_, node->use_});
    for (const auto &block : func->GetBlocks()) {
      auto &stmts = block->GetStmts();
      for (auto it = stmts.begin(); it != stmts.end();) {
        auto &stmt = *it;
        if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
          if (load_stmt->GetPtr()->IsGlobal() && local_map.contains(load_stmt->GetPtr())) {
            load_stmt->SetPtr(local_map.at(load_stmt->GetPtr()));
          }
        } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
          if (store_stmt->GetPtr()->IsGlobal() && local_map.contains(store_stmt->GetPtr())) {
            store_stmt->SetPtr(local_map.at(store_stmt->GetPtr()));
          }
        } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
          auto &call_func = call_stmt->GetFunction();
          auto next_it = ++it;
          --it;
          if (!call_func.lock()->IsBuiltin()) {
            for (const auto &call_node : list) {
              if (call_node->func_ == call_func.lock()) {
                for (const auto &use_reg : use) {
                  if (def.contains(use_reg) && call_node->use_.contains(use_reg)) {
                    auto &local_reg = local_map.at(use_reg);
                    auto tmp_reg = std::make_shared<Register>(local_reg->GetType().RemovePtr(),
                                                              "loadLocal." + std::to_string(temp_cnt++), false, false);
                    stmts.insert(it, std::make_unique<LoadStmt>(tmp_reg, local_reg));
                    stmts.insert(it, std::make_unique<StoreStmt>(tmp_reg, use_reg));
                  }
                  if (call_node->def_.contains(use_reg)) {
                    auto &local_reg = local_map.at(use_reg);
                    auto tmp_reg = std::make_shared<Register>(local_reg->GetType().RemovePtr(),
                                                              "storeLocal." + std::to_string(temp_cnt++), false, false);
                    stmts.insert(next_it, std::make_unique<LoadStmt>(tmp_reg, use_reg));
                    stmts.insert(next_it, std::make_unique<StoreStmt>(tmp_reg, local_reg));
                  }
                }
              }
            }
            it = next_it;
            continue;
          }
        }
        ++it;
      }
      auto &br_stmt = block->GetBranchStmt();
      if (auto ret_stmt = dynamic_cast<RetStmt *>(br_stmt.get()); ret_stmt != nullptr) {
        for (const auto &reg : def) {
          if (use.contains(reg)) {
            auto &local_reg = local_map.at(reg);
            auto tmp_reg = std::make_shared<Register>(local_reg->GetType().RemovePtr(),
                                                      "loadLocal." + std::to_string(temp_cnt++), false, false);
            stmts.push_back(std::make_unique<LoadStmt>(tmp_reg, local_reg));
            stmts.push_back(std::make_unique<StoreStmt>(tmp_reg, reg));
          }
        }
      }
    }
    for (const auto &reg : use) {
      auto &local_reg = local_map.at(reg);
      func->GetBlocks()[0]->GetStmts().push_back(std::make_unique<AllocaStmt>(local_reg));
      auto tmp_reg = std::make_shared<Register>(local_reg->GetType().RemovePtr(),
                                                "storeLocal." + std::to_string(temp_cnt++), false, false);
      func->GetBlocks()[0]->GetStmts().push_back(std::make_unique<LoadStmt>(tmp_reg, reg));
      func->GetBlocks()[0]->GetStmts().push_back(std::make_unique<StoreStmt>(tmp_reg, local_reg));
    }
  }
  return ret;
}
