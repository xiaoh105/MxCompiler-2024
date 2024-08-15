/*
 * Mx Compiler
 * File Name: block.h
 * Identification: ./src/include/ir/block.h
 * Function: IR node for blocks
 */
#pragma once

#include "ir/stmt/branch_stmt/branch_stmt.h"

/**
 * Node for blocks in LLVM IR
 */
class Block {
 public:
  Block() = delete;
  Block(std::string label, std::vector<std::unique_ptr<Stmt>> stmts, std::unique_ptr<BranchStmt> branch_stmt)
      : label_(std::move(label)), stmts_(std::move(stmts)), branch_stmt_(std::move(branch_stmt)) {}
  [[nodiscard]] const std::string &GetLabel() const { return label_; }
  void Print() const {
    std::cout << label_ << ": " << std::endl;
    for (const auto &stmt : stmts_) {
      stmt->Print();
    }
    branch_stmt_->Print();
  }

 private:
  const std::string label_;
  const std::vector<std::unique_ptr<Stmt>> stmts_;
  const std::unique_ptr<BranchStmt> branch_stmt_;
};