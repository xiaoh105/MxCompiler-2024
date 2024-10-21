/**
 * Mx Compiler
 * File Name: cfg.h
 * Identification: ./src/include/opt/cfg.h
 * Function: Classes required to build a control flow graph
 */
#pragma once

#include <memory>
#include <vector>

#include "ir/block.h"
#include "utils/set.h"

class CFGNode {
public:
  CFGNode() = delete;
  CFGNode(std::shared_ptr<Block> block);
  [[nodiscard]] const std::vector<std::weak_ptr<CFGNode>> &GetPred() const;
  [[nodiscard]] const std::vector<std::weak_ptr<CFGNode>> &GetSuc() const;
  Set<CFGNode> GetDom();
  [[nodiscard]] const Set<CFGNode> &GetDom() const;
  [[nodiscard]] const std::vector<std::shared_ptr<CFGNode>> &GetDomBorder() const;
  [[nodiscard]] const std::weak_ptr<CFGNode> &GetDirectDom() const;
  [[nodiscard]] const std::vector<std::shared_ptr<CFGNode>> &GetDomChild() const;
  [[nodiscard]] std::shared_ptr<Block> &GetBlock();
  void PushPred(const std::shared_ptr<CFGNode> &node);
  void PushSuc(const std::shared_ptr<CFGNode> &node);
  void PushDomBorder(const std::shared_ptr<CFGNode> &node);
  void SetDom(Set<CFGNode> dom);
  std::shared_ptr<CFGNode> SetDirectDom();
  void PushDomChild(const std::shared_ptr<CFGNode> &node);

private:
  std::shared_ptr<Block> block_{nullptr};
  std::vector<std::weak_ptr<CFGNode>> suc_;
  std::vector<std::weak_ptr<CFGNode>> pred_;
  Set<CFGNode> dom_;
  std::vector<std::shared_ptr<CFGNode>> dom_border_;
  std::weak_ptr<CFGNode> direct_dom_{};
  std::vector<std::shared_ptr<CFGNode>> dom_tree_child_{};
};

class ControlFlowGraph {
public:
  ControlFlowGraph() = delete;
  explicit ControlFlowGraph(const IRFunction &func);
  ControlFlowGraph(const ControlFlowGraph &) = delete;
  ControlFlowGraph(ControlFlowGraph &&) = delete;
  ControlFlowGraph &operator=(const ControlFlowGraph &) = delete;
  ControlFlowGraph &operator=(ControlFlowGraph &&) = delete;
  std::shared_ptr<CFGNode> &GetSourceNode();
  std::vector<std::shared_ptr<CFGNode>> &GetCFGNodes();

private:
  void GetDomSet();
  std::vector<std::shared_ptr<CFGNode>> cfg_nodes_;
  SetManager<CFGNode> set_manager_;
  std::shared_ptr<CFGNode> source_;
};