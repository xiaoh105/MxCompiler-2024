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
  for (auto &info : function_call_info_ | std::views::values) {
    for (auto it = info.live_in_.begin(); it != info.live_in_.end();) {
      if (spilled_registers_.contains(*it)) {
        it = info.live_in_.erase(it);
      } else {
        ++it;
      }
    }
    for (auto it = info.live_out_.begin(); it != info.live_out_.end();) {
      if (spilled_registers_.contains(*it)) {
        it = info.live_out_.erase(it);
      } else {
        ++it;
      }
    }
  }
}

void SpillGraph::BuildGraph() {
  for (const auto &reg : cfg_.GetRegisters()) {
    auto reg_node = std::make_shared<SpillNode>(reg);
    nodes_.push_back(reg_node);
    node_map_[reg] = reg_node;
    register_info_.emplace(reg, RegisterInfo{});
  }
  for (const auto &node : cfg_.GetCFGNodes()) {
    auto live_out = node->GetLiveOut();
    auto &br_stmt = node->GetBlock()->GetBranchStmt();
    if (auto ret_stmt = dynamic_cast<RetStmt *>(br_stmt.get()); ret_stmt != nullptr) {
      auto ret_arg = ret_stmt->GetRet();
      if (ret_arg != nullptr && std::dynamic_pointer_cast<Register>(ret_arg) != nullptr) {
        auto ret_reg = std::dynamic_pointer_cast<Register>(ret_arg);
        assert(register_info_.contains(ret_reg));
        ++register_info_[ret_reg].arg_offset_[0];
      }
    }
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
      auto live_in = reg_manager_.GetSet(stmt->GetUse()) | live_out - reg_manager_.GetSet({def});
      if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
        for (const auto &reg : live_in) {
          if (live_out.Contains(reg)) {
            ++register_info_[reg].pass_function_;
          }
        }
        auto &arg_var = call_stmt->GetArguments();
        for (int i = 0; i < std::min(arg_var.size(), 8ul); ++i) {
          auto reg = std::dynamic_pointer_cast<Register>(arg_var[i]);
          if (reg == nullptr || reg->IsGlobal()) {
            continue;
          }
          assert(register_info_.contains(reg));
          ++register_info_[reg].arg_offset_[i];
        }
        auto ret_var = call_stmt->GetResult();
        if (ret_var != nullptr && std::dynamic_pointer_cast<Register>(ret_var) != nullptr) {
          auto ret_reg = std::dynamic_pointer_cast<Register>(ret_var);
          assert(register_info_.contains(ret_reg));
          ++register_info_[ret_reg].arg_offset_[0];
        }
        std::unordered_set<std::shared_ptr<Register>> live_in_set{};
        std::unordered_set<std::shared_ptr<Register>> live_out_set{};
        for (const auto &reg : live_in) {
          live_in_set.insert(reg);
        }
        for (const auto &reg : live_out) {
          live_out_set.insert(reg);
        }
        function_call_info_[call_stmt] = {std::move(live_in_set), std::move(live_out_set)};
      }
      live_out = std::move(live_in);
    }
    for (const auto &stmt : node->GetBlock()->GetPhiStmts()) {
      live_out |= reg_manager_.GetSet(stmt->GetUse());
      live_out.AddElement(stmt->GetDef());
    }
    for (const auto &stmt : std::ranges::reverse_view(node->GetBlock()->GetPhiStmts())) {
      auto def = stmt->GetDef();
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
  }
  auto &arg_var = cfg_.GetIRFunction()->GetArgumentVars();
  for (int i = 0; i < arg_var.size(); ++i) {
    auto cur_node = node_map_.at(arg_var[i]);
    for (int j = 0; j < i; ++j) {
      auto pred_var = node_map_.at(arg_var[j]);
      cur_node->edge_.insert(pred_var);
      pred_var->rev_edge_.insert(cur_node);
    }
    if (i < 8) {
      assert(register_info_.contains(arg_var[i]));
      ++register_info_[arg_var[i]].arg_offset_[i];
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
  for (const auto &node : nodes_) {
    assert(node->pressure_ <= kAvailableRegisters);
    assert(node->rev_edge_.size() <= kAvailableRegisters || node->pressure_ == node->rev_edge_.size());
  }
}

const std::unordered_set<std::shared_ptr<Register>> &SpillGraph::GetSpilledRegs() const { return spilled_registers_; }
