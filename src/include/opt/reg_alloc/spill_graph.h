/**
 * Mx Compiler
 * File Name: spill_graph.h
 * Identification: ./src/include/opt/reg_alloc/spill_graph.h
 * Function: Classes needed to maintain the interference graph
 */
#pragma once

#include <memory>
#include <unordered_set>

#include "ir/ir.h"
#include "opt/cfg.h"

struct SpillNode {
  SpillNode() = delete;
  explicit SpillNode(std::shared_ptr<Register> reg);

  std::shared_ptr<Register> register_;
  std::unordered_set<std::shared_ptr<SpillNode>> edge_;
  std::unordered_set<std::shared_ptr<SpillNode>> rev_edge_;
  std::size_t pressure_{};
  std::size_t useful_{};
};

struct RegisterInfo {
  int pass_function_{0};
  int arg_offset_[8]{};
};

struct FunctionCallInfo {
  std::unordered_set<std::shared_ptr<Register>> live_in_{};
  std::unordered_set<std::shared_ptr<Register>> live_out_{};
};

class SpillGraph {
 public:
  SpillGraph() = delete;
  explicit SpillGraph(ControlFlowGraph &cfg);
  [[nodiscard]] const std::unordered_set<std::shared_ptr<Register>> &GetSpilledRegs() const;
  [[nodiscard]] const std::list<std::shared_ptr<SpillNode>> &GetSpilledNodes() const { return nodes_; }
  [[nodiscard]] const std::unordered_map<std::shared_ptr<Register>, RegisterInfo> &GetRegisterInfo() const {
    return register_info_;
  }
  [[nodiscard]] const std::unordered_map<CallStmt *, FunctionCallInfo> &GetFunctionCallInfo() const {
    return function_call_info_;
  }

 private:
  void BuildGraph();
  void Spill();
  ControlFlowGraph &cfg_;
  SetManager<Register> &reg_manager_;
  std::list<std::shared_ptr<SpillNode>> nodes_;
  std::unordered_map<std::shared_ptr<Register>, std::shared_ptr<SpillNode>> node_map_;
  std::unordered_set<std::shared_ptr<Register>> spilled_registers_;
  std::unordered_map<std::shared_ptr<Register>, RegisterInfo> register_info_;
  std::unordered_map<CallStmt *, FunctionCallInfo> function_call_info_;
};