/*
 * Mx Compiler
 * File Name: block.h
 * Identification: ./src/include/ir/block.h
 * Function: IR node for blocks
 */
#pragma once

#include <vector>

#include "ir/stmt/branch_stmt/branch_stmt.h"

/**
 * Node for blocks in LLVM IR
 */
class Block {
 public:
  Block() = delete;
  Block(std::string label) : label_(std::move(label)) {}
  void Append(std::unique_ptr<Stmt> stmt) {
    if (branch_stmt_ != nullptr) {
      return;
    }
    auto branch = dynamic_cast<BranchStmt *>(stmt.get());
    if (branch != nullptr) {
      branch_stmt_ = std::unique_ptr<BranchStmt>(dynamic_cast<BranchStmt *>(stmt.release()));
    } else {
      stmts_.push_back(std::move(stmt));
    }
  }
  [[nodiscard]] const std::string &GetLabel() const { return label_; }
  std::vector<std::unique_ptr<Stmt>> &GetStmts() { return stmts_; }
  std::unique_ptr<BranchStmt> &GetBranchStmt() { return branch_stmt_; }
  void Print() const {
    std::cout << label_ << ": " << std::endl;
    for (const auto &stmt : stmts_) {
      stmt->Print();
    }
    branch_stmt_->Print();
  }

 private:
  const std::string label_;
  std::vector<std::unique_ptr<Stmt>> stmts_;
  std::unique_ptr<BranchStmt> branch_stmt_;
};