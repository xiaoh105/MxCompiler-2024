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

std::vector<std::weak_ptr<CFGNode>> &CFGNode::GetPred() { return pred_; }

std::vector<std::weak_ptr<CFGNode>> &CFGNode::GetSuc() { return suc_; }

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
  return direct_dom_.lock();
}

void CFGNode::PushPred(const std::shared_ptr<CFGNode> &node) { pred_.push_back(node); }

void CFGNode::PushSuc(const std::shared_ptr<CFGNode> &node) { suc_.push_back(node); }

void CFGNode::PushDomChild(const std::shared_ptr<CFGNode> &node) { dom_tree_child_.push_back(node); }

void CFGNode::PushDomBorder(const std::shared_ptr<CFGNode> &node) { dom_border_.push_back(node); }

const Set<Register> &CFGNode::GetLiveIn() const { return live_in_; }

void CFGNode::SetLiveIn(Set<Register> live_in) { live_in_ = std::move(live_in); }

const Set<Register> &CFGNode::GetLiveOut() const { return live_out_; }

void CFGNode::SetLiveOut(Set<Register> live_out) { live_out_ = std::move(live_out); }

const Set<Register> &CFGNode::GetDef() const { return def_; }

const Set<Register> &CFGNode::GetUse() const { return use_; }

void CFGNode::SetDefUse(Set<Register> def, Set<Register> use) {
  def_ = std::move(def);
  use_ = std::move(use);
}

extern bool generate_dominator_tree;
extern bool generate_data_flow;

ControlFlowGraph::ControlFlowGraph(std::shared_ptr<IRFunction> func) : func_(std::move(func)) {
  auto &blocks = func_->GetBlocks();
  std::unordered_map<std::shared_ptr<Block>, std::shared_ptr<CFGNode>> block_map;
  for (const auto &item : blocks) {
    auto node = std::make_shared<CFGNode>(item);
    if (auto &branch_stmt = node->GetBlock()->GetBranchStmt();
        dynamic_cast<Unreachable *>(branch_stmt.get()) != nullptr) {
      continue;
    }
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
  if (generate_dominator_tree) {
    GetDomSet();
  }
  if (generate_data_flow) {
    GetDataFlow();
  }
}

std::shared_ptr<CFGNode> &ControlFlowGraph::GetSourceNode() { return source_; }

std::vector<std::shared_ptr<CFGNode>> &ControlFlowGraph::GetCFGNodes() { return cfg_nodes_; }

std::shared_ptr<IRFunction> &ControlFlowGraph::GetIRFunction() { return func_; }

std::vector<std::shared_ptr<Register>> ControlFlowGraph::GetRegisters() const { return registers_; }

SetManager<Register> &ControlFlowGraph::GetRegManager() { return reg_manager_; }

void ControlFlowGraph::GetDomSet() {
  std::unordered_set<std::shared_ptr<CFGNode>> flag;
  std::queue<std::shared_ptr<CFGNode>> queue;
  for (const auto &node : cfg_nodes_) {
    queue.push(node);
    flag.insert(node);
  }
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();
    flag.erase(node);
    auto cur_set = node->GetPred().empty() ? set_manager_.EmptySet() : set_manager_.WholeSet();
    for (const auto &pred : node->GetPred()) {
      cur_set.Intersect(pred.lock()->GetDom());
    }
    cur_set.AddElement(node);
    if (node->GetPred().empty()) {
      cur_set = set_manager_.EmptySet().AddElement(node);
    }
    if (cur_set != node->GetDom()) {
      for (const auto &suc : node->GetSuc()) {
        if (!flag.contains(suc.lock())) {
          flag.insert(suc.lock());
          queue.push(suc.lock());
        }
      }
      node->SetDom(std::move(cur_set));
    }
  }
  for (const auto &item : cfg_nodes_) {
    if (item->GetPred().empty()) {
      continue;
    }
    auto direct_dom = item->SetDirectDom();
    if (direct_dom == nullptr) {
      continue;
    }
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

void ControlFlowGraph::CollectRegister() {
  for (const auto &node : cfg_nodes_) {
    for (const auto &stmt : node->GetBlock()->GetPhiStmts()) {
      if (auto reg = stmt->GetDef(); reg != nullptr) {
        reg_manager_.AddElement(reg);
        registers_.push_back(reg);
      }
    }
    for (const auto &stmt : node->GetBlock()->GetStmts()) {
      if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
        reg_manager_.AddElement(alloca_stmt->GetResult());
        registers_.push_back(alloca_stmt->GetResult());
      }
      if (auto reg = stmt->GetDef(); reg != nullptr) {
        reg_manager_.AddElement(reg);
        registers_.push_back(reg);
      }
    }
    for (const auto &stmt : node->GetBlock()->GetMoveStmts()) {
      if (auto reg = stmt->GetDef(); reg != nullptr) {
        reg_manager_.AddElement(reg);
        registers_.push_back(reg);
      }
    }
    if (auto reg = node->GetBlock()->GetBranchStmt()->GetDef(); reg != nullptr) {
      reg_manager_.AddElement(reg);
      registers_.push_back(reg);
    }
  }
  for (const auto &arg : func_->GetArgumentVars()) {
    if (reg_manager_.HasElement(arg)) {
      continue;
    }
    reg_manager_.AddElement(arg);
    registers_.push_back(arg);
  }
}

void ControlFlowGraph::SetDefUse() {
  for (const auto &node : cfg_nodes_) {
    auto &block = node->GetBlock();
    auto def = reg_manager_.EmptySet();
    auto use = reg_manager_.EmptySet();
    for (const auto &stmt : block->GetPhiStmts()) {
      def |= reg_manager_.GetSet({stmt->GetDef()});
    }
    for (const auto &stmt : block->GetStmts()) {
      use |= reg_manager_.GetSet(stmt->GetUse()) - def;
      def |= reg_manager_.GetSet({stmt->GetDef()});
    }
    for (const auto &stmt : block->GetMoveStmts()) {
      use |= reg_manager_.GetSet(stmt->GetUse()) - def;
      def |= reg_manager_.GetSet({stmt->GetDef()});
    }
    use |= reg_manager_.GetSet(block->GetBranchStmt()->GetUse()) - def;
    def |= reg_manager_.GetSet({block->GetBranchStmt()->GetDef()});
    node->SetDefUse(std::move(def), std::move(use));
  }
}

void ControlFlowGraph::GetDataFlow() {
  CollectRegister();
  if (reg_manager_.Size() == 0) {
    return;
  }
  SetDefUse();
  std::unordered_set<std::shared_ptr<CFGNode>> flag;
  std::queue<std::shared_ptr<CFGNode>> queue;
  for (const auto &node : cfg_nodes_) {
    node->SetLiveIn(reg_manager_.EmptySet());
    node->SetLiveOut(reg_manager_.EmptySet());
    queue.push(node);
    flag.insert(node);
  }
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();
    flag.erase(node);
    auto live_in = reg_manager_.EmptySet();
    auto live_out = reg_manager_.EmptySet();
    for (const auto &suc : node->GetSuc()) {
      live_out |= suc.lock()->GetLiveIn();
      for (const auto &stmt : suc.lock()->GetBlock()->GetPhiStmts()) {
        auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get());
        assert(phi_stmt != nullptr);
        for (const auto &pred : phi_stmt->GetBlocks()) {
          if (pred.second.lock() == node->GetBlock()) {
            auto reg = std::dynamic_pointer_cast<Register>(pred.first);
            if (reg != nullptr && !reg->IsGlobal()) {
              live_out.AddElement(reg);
            }
            break;
          }
        }
      }
    }
    live_in = node->GetUse() | live_out - node->GetDef();
    if (live_out != node->GetLiveOut() || live_in != node->GetLiveIn()) {
      node->SetLiveOut(live_out);
      node->SetLiveIn(live_in);
      for (const auto &pred : node->GetPred()) {
        if (!flag.contains(pred.lock())) {
          queue.push(pred.lock());
          flag.insert(pred.lock());
        }
      }
    }
  }
}
