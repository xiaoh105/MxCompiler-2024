/**
 * Mx Compiler
 * File Name: coalesce_graph.cpp
 * Identification: ./src/opt/reg_alloc/coalesce_graph.cpp
 * Function: Classes needed to maintain the coalesce graph
 */
#include "opt/reg_alloc/coalesce_graph.h"

#include "opt/reg_alloc/reg_alloc.h"

RegisterNode::RegisterNode(std::shared_ptr<Register> reg) : register_(std::move(reg)) {
  precolored_ = std::dynamic_pointer_cast<MachineRegister>(register_) != nullptr;
}

CoalesceGraph::CoalesceGraph(ControlFlowGraph &cfg, SpillGraph &spill_graph) {
  BuildGraph(cfg, spill_graph);
  SimplifyAndCoalesce();
}

const std::unordered_map<std::shared_ptr<Register>, AsmRegister> &CoalesceGraph::GetRegisterAllocation() const {
  return allocation_;
}

void CoalesceGraph::BuildGraph(ControlFlowGraph &cfg, SpillGraph &spill_graph) {
  auto &spilled_reg = spill_graph.GetSpilledRegs();
  std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<RegisterNode>> node_map;
  for (const auto &reg : cfg.GetRegisters()) {
    if (spilled_reg.contains(reg)) {
      continue;
    }
    auto node = std::make_shared<RegisterNode>(reg);
    node_map.insert({reg, node});
    nodes_.push_back(node);
  }
  for (const auto &node : spill_graph.GetSpilledNodes()) {
    auto &cur_node = node_map.at(node->register_);
    for (const auto &prev : node->rev_edge_) {
      auto &prev_node = node_map.at(prev->register_);
      cur_node->edge_.insert(prev_node);
    }
    for (const auto &suc : node->edge_) {
      auto &suc_node = node_map.at(suc->register_);
      cur_node->edge_.insert(suc_node);
    }
  }
  for (const auto &node : cfg.GetCFGNodes()) {
    for (const auto &stmt : node->GetBlock()->GetStmts()) {
      if (auto move_stmt = dynamic_cast<MoveStmt *>(stmt.get()); move_stmt != nullptr) {
        auto dest = move_stmt->GetDest();
        auto src = std::dynamic_pointer_cast<Register>(move_stmt->GetSrc());
        if (src == nullptr) {
          continue;
        }
        if (node_map.contains(dest) && node_map.contains(src)) {
          auto &src_node = node_map.at(src);
          auto &dest_node = node_map.at(dest);
          ++src_node->affinity_[dest_node];
          ++dest_node->affinity_[src_node];
        }
      }
    }
    for (const auto &stmt : node->GetBlock()->GetMoveStmts()) {
      if (auto move_stmt = dynamic_cast<MoveStmt *>(stmt.get()); move_stmt != nullptr) {
        auto dest = move_stmt->GetDest();
        auto src = std::dynamic_pointer_cast<Register>(move_stmt->GetSrc());
        if (src == nullptr) {
          continue;
        }
        if (node_map.contains(dest) && node_map.contains(src)) {
          auto &src_node = node_map.at(src);
          auto &dest_node = node_map.at(dest);
          ++src_node->affinity_[dest_node];
          ++dest_node->affinity_[src_node];
        }
      }
    }
  }
}

void CoalesceGraph::SimplifyAndCoalesce() {
  std::size_t precolored_cnt = 0;
  std::stack<std::shared_ptr<RegisterNode>> work_stack;
  for (auto &node : nodes_) {
    if (node->precolored_) {
      ++precolored_cnt;
    }
  }
  while (nodes_.size() > precolored_cnt) {
    bool simplify_succeed = false;
    std::shared_ptr<RegisterNode> u{nullptr};
    std::shared_ptr<RegisterNode> v{nullptr};
    std::size_t max_affinity = 0;
    for (auto it = nodes_.begin(); it != nodes_.end();) {
      auto &node = *it;
      if (node->edge_.size() < kAvailableRegisters && node->affinity_.empty()) {
        simplify_succeed = true;
        work_stack.push(node);
        for (const auto &suc : node->edge_) {
          suc->edge_.erase(node);
        }
        it = nodes_.erase(it);
        continue;
      }
      for (const auto &item : node->affinity_) {
        if (item.second > max_affinity) {
          max_affinity = item.second;
          u = node;
          v = item.first;
        }
      }
      ++it;
    }
    if (simplify_succeed) {
      continue;
    }
    bool rule_succeed = false;
    for (const auto &node1 : nodes_) {
      std::unordered_set<std::shared_ptr<RegisterNode>> high_deg1{};
      for (const auto &neighbor : node1->edge_) {
        if (neighbor->edge_.size() >= kAvailableRegisters) {
          high_deg1.insert(neighbor);
        }
      }
      for (const auto &node2 : node1->affinity_ | std::views::keys) {
        std::unordered_set<std::shared_ptr<RegisterNode>> high_deg2{};
        for (const auto &neighbor : node2->edge_) {
          if (neighbor->edge_.size() >= kAvailableRegisters) {
            high_deg2.insert(neighbor);
          }
        }
        if (high_deg1 == high_deg2) {
          rule_succeed = true;
          Coalesce(node1, node2);
          continue;
        }
        if (high_deg1.size() < high_deg2.size()) {
          std::swap(high_deg1, high_deg2);
        }
        high_deg1.merge(high_deg2);
        if (high_deg1.size() < kAvailableRegisters) {
          rule_succeed = true;
          Coalesce(node1, node2);
        }
      }
    }
    if (rule_succeed) {
      continue;
    }
    if (TrySimplify(u, v)) {
      Coalesce(u, v);
    } else {
      u->affinity_.erase(v);
      v->affinity_.erase(u);
    }
  }
  Select(work_stack);
}

void CoalesceGraph::Select(std::stack<std::shared_ptr<RegisterNode>> worklist) {
  for (const auto &node : nodes_) {
    assert(node->precolored_);
    auto machine_reg = std::dynamic_pointer_cast<MachineRegister>(node->register_);
    assert(machine_reg != nullptr);
    allocation_.emplace(node->register_, machine_reg->GetAsmRegister());
  }
  while (!worklist.empty()) {
    auto node = worklist.top();
    worklist.pop();
    std::unordered_set<std::size_t> used_regs = GetAvailableRegisters();
    for (const auto &suc : node->edge_) {
      auto suc_node = suc;
      while (merge_info_.contains(suc)) {
        suc_node = merge_info_.at(suc_node);
      }
      if (merge_info_.contains(suc)) {
        merge_info_[suc] = suc_node;
      }
      assert(allocation_.contains(suc_node->register_));
      assert(used_regs.contains(allocation_.at(suc_node->register_).GetId()));
      used_regs.erase(allocation_.at(suc_node->register_).GetId());
    }
    allocation_.emplace(node->register_, AsmRegister{static_cast<int>(*used_regs.begin())});
  }
  for (auto [node, belong] : merge_info_) {
    while (merge_info_.contains(belong)) {
      belong = merge_info_.at(belong);
    }
    allocation_.emplace(node->register_, allocation_.at(belong->register_));
    merge_info_[node] = belong;
  }
}

void CoalesceGraph::Coalesce(std::shared_ptr<RegisterNode> node1, std::shared_ptr<RegisterNode> node2) {
  assert(!node1->precolored_ || !node2->precolored_ ||
         std::dynamic_pointer_cast<MachineRegister>(node1->register_)->GetAsmRegister() ==
             std::dynamic_pointer_cast<MachineRegister>(node2->register_)->GetAsmRegister());
  if (node2->precolored_) {
    std::swap(node1, node2);
  }
  merge_info_[node2] = node1;
  if (node1->edge_.size() < node2->edge_.size()) {
    std::swap(node1->edge_, node2->edge_);
  }
  for (const auto &neighbor : node2->edge_) {
    assert(neighbor->edge_.contains(node2));
    neighbor->edge_.erase(node2);
    neighbor->edge_.insert(node1);
  }
  node1->edge_.merge(node2->edge_);
  if (node1->affinity_.size() < node2->affinity_.size()) {
    std::swap(node1->affinity_, node2->affinity_);
  }
  for (const auto &item : node2->affinity_) {
    item.first->affinity_[node1] += item.second;
    item.first->affinity_.erase(node2);
    node1->affinity_[item.first] += item.second;
  }
  for (auto it = nodes_.begin(); it != nodes_.end(); ++it) {
    if (*it == node2) {
      nodes_.erase(it);
      return;
    }
  }
  assert(false);
}

bool CoalesceGraph::TrySimplify(const std::shared_ptr<RegisterNode> &node1,
                                const std::shared_ptr<RegisterNode> &node2) const {
  std::list<std::shared_ptr<RegisterNode>> nodes;
  std::size_t precolored_cnt = 0;
  std::shared_ptr<RegisterNode> u{nullptr}, v{nullptr};
  for (const auto &node : nodes_) {
    auto temp_node = std::make_shared<RegisterNode>(*node);
    if (node == node1) {
      u = temp_node;
    }
    if (node == node2) {
      v = temp_node;
    }
    if (temp_node->precolored_) {
      ++precolored_cnt;
    }
    nodes.emplace_back(std::move(temp_node));
  }
  u->edge_.merge(v->edge_);
  for (auto it = nodes.begin(); it != nodes.end(); ++it) {
    if (*it == v) {
      nodes.erase(it);
      break;
    }
  }
  while (nodes.size() > precolored_cnt) {
    bool succeed = false;
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
      auto &node = *it;
      if (node->edge_.size() < kAvailableRegisters) {
        for (const auto &suc : node->edge_) {
          suc->edge_.erase(node);
        }
        nodes.erase(it);
        succeed = true;
        break;
      }
    }
    if (succeed) {
      continue;
    }
    return false;
  }
  return true;
}
