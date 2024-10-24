/**
 * Mx Compiler
 * File Name: coalesce_graph.h
 * Identification: ./src/include/opt/reg_alloc/coalesce_graph.h
 * Function: Classes needed to maintain the coalesce graph
 */
#pragma once

#include <stack>
#include <unordered_map>
#include <unordered_set>

#include "asm/register/register.h"
#include "opt/cfg.h"
#include "opt/reg_alloc/spill_graph.h"

struct RegisterNode {
  RegisterNode() = delete;
  explicit RegisterNode(std::shared_ptr<Register> reg);

  std::shared_ptr<Register> register_;
  std::unordered_set<std::shared_ptr<RegisterNode>> edge_;
  std::unordered_map<std::shared_ptr<RegisterNode>, std::size_t> affinity_;
  bool precolored_{false};
};

class CoalesceGraph {
public:
  CoalesceGraph() = delete;
  explicit CoalesceGraph(ControlFlowGraph &cfg, SpillGraph &spill_graph);
  const std::unordered_map<std::shared_ptr<Register>, AsmRegister> &GetRegisterAllocation() const;

private:
  void BuildGraph(ControlFlowGraph &cfg, SpillGraph &spill_graph);
  void SimplifyAndCoalesce();
  void Select(std::stack<std::shared_ptr<RegisterNode>> worklist);
  void Coalesce(std::shared_ptr<RegisterNode> node1, std::shared_ptr<RegisterNode> node2);
  bool TrySimplify(const std::shared_ptr<RegisterNode> &node1, const std::shared_ptr<RegisterNode> &node2) const;
  std::list<std::shared_ptr<RegisterNode>> nodes_;
  std::unordered_map<std::shared_ptr<Register>, AsmRegister> allocation_;
  std::unordered_map<std::shared_ptr<RegisterNode>, std::shared_ptr<RegisterNode>> merge_info_;
};
