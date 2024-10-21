/*
 * Mx Compiler
 * File Name: block.h
 * Identification: ./src/include/ir/block.h
 * Function: IR node for blocks
 */
#pragma once

#include <iostream>
#include <vector>

#include "ir/stmt/branch_stmt/branch_stmt.h"

class PhiStmt;

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
  void ReservePhi(const std::shared_ptr<Register> &reg) {
    if (reserved_phi_.contains(reg)) {
      return;
    }
    reserved_phi_[reg] = {};
  }
  void AppendPhi(std::unique_ptr<Stmt> stmt) { phi_stmts_.push_back(std::move(stmt)); }
  [[nodiscard]] const std::string &GetLabel() const { return label_; }
  std::vector<std::unique_ptr<Stmt>> &GetStmts() { return stmts_; }
  std::unique_ptr<BranchStmt> &GetBranchStmt() { return branch_stmt_; }
  void PushPhi(const std::shared_ptr<Register> &alloca_var, const std::shared_ptr<Block> &pred_block,
               std::shared_ptr<Register> value) {
    assert(reserved_phi_.contains(alloca_var));
    reserved_phi_[alloca_var].emplace_back(std::move(value), std::weak_ptr(pred_block));
  }
  [[nodiscard]] const auto &GetReservedPhi() const { return reserved_phi_; }
  void Print() const {
    std::cout << label_ << ": " << std::endl;
    for (const auto &stmt : phi_stmts_) {
      stmt->Print();
    }
    for (const auto &stmt : stmts_) {
      stmt->Print();
    }
    branch_stmt_->Print();
  }

 private:
  const std::string label_;
  std::unordered_map<std::shared_ptr<Register>,
                     std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>>>
      reserved_phi_;
  std::vector<std::unique_ptr<Stmt>> phi_stmts_;
  std::vector<std::unique_ptr<Stmt>> stmts_;
  std::unique_ptr<BranchStmt> branch_stmt_;
};