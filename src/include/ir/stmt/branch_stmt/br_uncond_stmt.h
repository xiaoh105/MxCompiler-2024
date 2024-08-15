/*
 * Mx Compiler
 * File Name: br_uncond_stmt.h
 * Identification: ./src/include/ir/stmt/branch_stmt/br_uncond_stmt.h
 * Function: IR node for unconditional "br" statements
 */
#pragma once

#include <memory>

#include "ir/block.h"
#include "ir/stmt/branch_stmt/branch_stmt.h"

class UnconditionalBrStmt final : public BranchStmt {
public:
  UnconditionalBrStmt() = delete;
  UnconditionalBrStmt(const std::shared_ptr<Block> &block) : block_(block) {}
  void Print() const override {
    std::cout << "br label " << block_.lock()->GetLabel() << std::endl;
  }

private:
  std::weak_ptr<Block> block_;
};