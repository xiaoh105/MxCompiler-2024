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
  ConditionalBrStmt(std::shared_ptr<Var> condition, int cond_raw, const std::shared_ptr<Block> &true_block,
                    const std::shared_ptr<Block> &false_block)
      : condition_(std::move(condition)), cond_raw_(cond_raw), true_block_(true_block), false_block_(false_block) {}
  void Print() const override {
    std::cout << "%truncTmp." << cond_raw_ << " = trunc i8 " << condition_->GetName() << " to i1" << std::endl;
    std::cout << "br i1 %truncTmp." << cond_raw_ << ", label %" << true_block_.lock()->GetLabel() << ", label %"
              << false_block_.lock()->GetLabel() << std::endl;
  }

 private:
  std::shared_ptr<Var> condition_;
  int cond_raw_;
  std::weak_ptr<Block> true_block_;
  std::weak_ptr<Block> false_block_;
};