/**
 * Mx Compiler
 * File Name: interference_graph.cpp
 * Identification: ./src/opt/reg_alloc/interference_graph.cpp
 * Function: Classes needed to maintain the interference graph
 */
#include "asm/register/register.h"
#include "opt/reg_alloc/spill_graph.h"

SpillNode::SpillNode(std::shared_ptr<Register> reg) : register_(std::move(reg)) {}

SpillGraph::SpillGraph(ControlFlowGraph &cfg) : cfg_(cfg), reg_manager_(cfg_.GetRegManager()) {
  BuildGraph();
  Spill();
}

void SpillGraph::BuildGraph() {
  for (const auto &reg : cfg_.GetRegisters()) {
    auto reg_node = std::make_shared<SpillNode>(reg);
    nodes_.push_back(reg_node);
    node_map_[reg] = reg_node;
  }
  for (const auto &node : cfg_.GetCFGNodes()) {
    auto live_out = node->GetLiveOut();
    auto &br_stmt = node->GetBlock()->GetBranchStmt();
    live_out |= reg_manager_.GetSet(br_stmt->GetUse());
    for (const auto &stmt : std::ranges::reverse_view(node->GetBlock()->GetStmts())) {
      auto def = stmt->GetDef();
      if (def != nullptr) {
        auto cur_node = node_map_.at(def);
        cur_node->pressure_ = 0;
        for (const auto &regs : live_out) {
          if (def == regs) {
            continue;
          }
          auto live_node = node_map_.at(regs);
          live_node->edge_.insert(cur_node);
          cur_node->rev_edge_.insert(live_node);
        }
        cur_node->pressure_ = cur_node->rev_edge_.size() + 1;
      }
      live_out = reg_manager_.GetSet(stmt->GetUse()) | live_out - reg_manager_.GetSet({def});
    }
    for (const auto &stmt : std::ranges::reverse_view(node->GetBlock()->GetPhiStmts())) {
      auto def = stmt->GetDef();
      if (def != nullptr) {
        auto cur_node = node_map_.at(def);
        cur_node->pressure_ = 0;
        for (const auto &regs : live_out) {
          if (def == regs) {
            continue;
          }
          auto live_node = node_map_.at(regs);
          live_node->edge_.insert(cur_node);
          cur_node->rev_edge_.insert(live_node);
        }
        cur_node->pressure_ = cur_node->rev_edge_.size() + 1;
      }
      live_out = reg_manager_.GetSet(stmt->GetUse()) | live_out - reg_manager_.GetSet({def});
    }
  }
  for (const auto &node : nodes_) {
    for (const auto &suc : node->edge_) {
      if (suc->pressure_ > kAvailableRegisters) {
        ++node->useful_;
      }
    }
  }
}

void SpillGraph::Spill() {
  std::size_t total_overpressure = 0;
  for (const auto &node : nodes_) {
    if (node->pressure_ > kAvailableRegisters) {
      ++total_overpressure;
    }
  }
  while (total_overpressure > 0) {
    std::shared_ptr<SpillNode> useful_node = nullptr;
    std::size_t max_useful = 0;
    for (const auto &node : nodes_) {
      if (node->useful_ > max_useful) {
        max_useful = node->useful_;
        useful_node = node;
      }
    }
    assert(max_useful > 0);
    spilled_registers_.insert(useful_node->register_);
    if (useful_node->pressure_ > kAvailableRegisters) {
      --total_overpressure;
      for (const auto &prev : useful_node->rev_edge_) {
        --prev->useful_;
      }
    }
    for (const auto &suc : useful_node->edge_) {
      if (suc->pressure_ > kAvailableRegisters) {
        --suc->pressure_;
        if (suc->pressure_ <= kAvailableRegisters) {
          --total_overpressure;
          for (const auto &prev : suc->rev_edge_) {
            --prev->useful_;
          }
        }
      }
    }
    for (const auto &suc : useful_node->edge_) {
      suc->rev_edge_.erase(useful_node);
    }
    for (const auto &prev : useful_node->rev_edge_) {
      prev->edge_.erase(useful_node);
    }
    for (auto it = nodes_.begin(); it != nodes_.end(); ++it) {
      if (*it == useful_node) {
        nodes_.erase(it);
        break;
      }
    }
  }
}

const std::unordered_set<std::shared_ptr<Register>> &SpillGraph::GetSpilledRegs() const { return spilled_registers_; }
