/**
 * Mx Compiler
 * File Name: coalesce_graph.h
 * Identification: ./src/include/opt/reg_alloc/coalesce_graph.h
 * Function: Classes needed to maintain the coalesce graph
 */
#pragma once

#include <unordered_map>
#include <unordered_set>

#include "opt/cfg.h"
#include "opt/reg_alloc/reg_alloc.h"

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
  explicit CoalesceGraph(ControlFlowGraph &cfg);

private:
  void BuildGraph();
  void SimplifyAndCoalesce();
  CoalesceGraph &cfg_;
  std::vector<std::shared_ptr<RegisterNode>> nodes_;
  std::unordered_map<std::shared_ptr<Register>, AsmRegister> allocation_;
};