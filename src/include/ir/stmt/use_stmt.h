/*
 * Mx Compiler
 * File Name: use_stmt.h
 * Identification: ./src/include/ir/stmt/use_stmt.h
 * Function: IR node for using a variable
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * A psudo-instruction that uses a variable (for live analysis)
 */
class UseStmt : public Stmt {
 public:
  UseStmt() = delete;
  explicit UseStmt(std::shared_ptr<Register> result) : result_(std::move(result)) {}
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return nullptr; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override { return {result_}; }
  void Print() const override {}

 private:
  std::shared_ptr<Register> result_;
};
