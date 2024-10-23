/*
 * Mx Compiler
 * File Name: def_stmt.h
 * Identification: ./src/include/ir/stmt/def_stmt.h
 * Function: IR node for defining a variable
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * A psudo-instruction that defines a variable (for live analysis)
 */
class DefStmt : public Stmt {
 public:
  DefStmt() = delete;
  explicit DefStmt(std::shared_ptr<Register> result) : result_(std::move(result)) {}
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return result_; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override { return {}; }
  void Print() const override {}

 private:
  std::shared_ptr<Register> result_;
};
