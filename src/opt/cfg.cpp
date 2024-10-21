/**
 * Mx Compiler
 * File Name: cfg.cpp
 * Identification: ./src/opt/cfg.h
 * Function: Classes required to build a control flow graph
 */
#include <queue>
#include <unordered_set>

#include "ir/ir.h"
#include "opt/cfg.h"

CFGNode::CFGNode(std::shared_ptr<Block> block) : block_(std::move(block)) {}

std::shared_ptr<Block> &CFGNode::GetBlock() { return block_; }

const Set<CFGNode> &CFGNode::GetDom() const { return dom_; }

Set<CFGNode> CFGNode::GetDom() { return dom_; }

const std::vector<std::weak_ptr<CFGNode>> &CFGNode::GetPred() const { return pred_; }

const std::vector<std::weak_ptr<CFGNode>> &CFGNode::GetSuc() const { return suc_; }

const std::vector<std::shared_ptr<CFGNode>> &CFGNode::GetDomBorder() const { return dom_border_; }

const std::vector<std::shared_ptr<CFGNode>> &CFGNode::GetDomChild() const { return dom_tree_child_; }

const std::weak_ptr<CFGNode> &CFGNode::GetDirectDom() const { return direct_dom_; }

void CFGNode::SetDom(Set<CFGNode> dom) { dom_ = std::move(dom); }

std::shared_ptr<CFGNode> CFGNode::SetDirectDom() {
  assert(direct_dom_.expired());
  auto dom_size = dom_.Size();
  for (const auto &node : dom_) {
    if (node->GetDom().Size() == dom_size - 1) {
      direct_dom_ = node;
      break;
    }
  }
  assert(!direct_dom_.expired());
  return direct_dom_.lock();
}

void CFGNode::PushPred(const std::shared_ptr<CFGNode> &node) { pred_.push_back(node); }

void CFGNode::PushSuc(const std::shared_ptr<CFGNode> &node) { suc_.push_back(node); }

void CFGNode::PushDomChild(const std::shared_ptr<CFGNode> &node) { dom_tree_child_.push_back(node); }

void CFGNode::PushDomBorder(const std::shared_ptr<CFGNode> &node) { dom_border_.push_back(node); }

ControlFlowGraph::ControlFlowGraph(const IRFunction &func) {
  auto &blocks = func.GetBlocks();
  std::unordered_map<std::shared_ptr<Block>, std::shared_ptr<CFGNode>> block_map;
  for (const auto &item : blocks) {
    auto node = std::make_shared<CFGNode>(item);
    block_map.emplace(item, node);
    set_manager_.AddElement(node);
    cfg_nodes_.push_back(node);
  }
  source_ = cfg_nodes_[0];
  for (const auto &node : std::ranges::views::values(block_map)) {
    node->SetDom(set_manager_.WholeSet());
    auto block = node->GetBlock();
    auto branch_stmt = block->GetBranchStmt().get();
    if (auto uncond_br = dynamic_cast<UnconditionalBrStmt *>(branch_stmt); uncond_br != nullptr) {
      auto dest = block_map.at(uncond_br->GetBlock().lock());
      node->PushSuc(dest);
      dest->PushPred(node);
    } else if (auto cond_br = dynamic_cast<ConditionalBrStmt *>(branch_stmt); cond_br != nullptr) {
      auto true_br = block_map.at(cond_br->GetTrueBlock().lock());
      auto false_br = block_map.at(cond_br->GetFalseBlock().lock());
      node->PushSuc(true_br);
      node->PushSuc(false_br);
      true_br->PushPred(node);
      false_br->PushPred(node);
    }
  }
}

std::shared_ptr<CFGNode> &ControlFlowGraph::GetSourceNode() { return source_; }

void ControlFlowGraph::GetDomSet() {
  std::unordered_set<std::shared_ptr<CFGNode>> flag;
  std::queue<std::shared_ptr<CFGNode>> queue;
  queue.push(source_);
  flag.insert(source_);
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();
    flag.erase(node);
    auto cur_set = set_manager_.WholeSet();
    for (const auto &pred : node->GetPred()) {
      cur_set.Intersect(pred.lock()->GetDom());
    }
    cur_set.Union(set_manager_.EmptySet().AddElement(node));
    if (cur_set != node->GetDom()) {
      for (const auto &suc : node->GetSuc()) {
        if (!flag.contains(suc.lock())) {
          flag.insert(suc.lock());
          queue.push(suc.lock());
        }
      }
    }
  }
  for (const auto &item : cfg_nodes_) {
    if (item == source_) {
      continue;
    }
    auto direct_dom = item->SetDirectDom();
    direct_dom->PushDomChild(item);
  }
  for (const auto &node : cfg_nodes_) {
    auto target_nodes = set_manager_.EmptySet();
    for (const auto &pred : node->GetPred()) {
      target_nodes |= pred.lock()->GetDom() - node->GetDom().RemoveElement(node);
    }
    for (const auto &item : target_nodes) {
      item->PushDomBorder(node);
    }
  }
}
