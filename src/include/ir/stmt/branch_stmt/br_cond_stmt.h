/*
 * Mx Compiler
 * File Name: br_cond_stmt.h
 * Identification: ./src/include/ir/stmt/branch_stmt/br_cond_stmt.h
 * Function: IR node for conditional "br" statements
 */
#pragma once

#include <memory>

#include "ir/block.h"
#include "ir/stmt/branch_stmt/branch_stmt.h"
#include "ir/var/var.h"

class Block;

class ConditionalBrStmt final : public BranchStmt {
 public:
  ConditionalBrStmt() = delete;
  ConditionalBrStmt(std::shared_ptr<Var> condition, const std::shared_ptr<Block> &true_block,
                    const std::shared_ptr<Block> &false_block)
      : condition_(std::move(condition)), true_block_(true_block), false_block_(false_block) {}
  void Print() const override {
    std::cout << "br i1 " << condition_->GetName() << ", label " << true_block_.lock()->GetLabel() << ", label "
              << false_block_.lock()->GetLabel() << std::endl;
  }

 private:
  std::shared_ptr<Var> condition_;
  std::weak_ptr<Block> true_block_;
  std::weak_ptr<Block> false_block_;
};