/*
 * Mx Compiler
 * File Name: alloca_stmt.h
 * Identification: ./src/include/ir/stmt/alloca_stmt.h
 * Function: IR node for memory allocation statements
 */
#pragma once

#include "ir/stmt/stmt.h"
#include "ir/var/register.h"

/**
 * IR node for "alloca" statements
 */
class AllocaStmt final : public Stmt {
 public:
  AllocaStmt() = delete;
  AllocaStmt(std::shared_ptr<Register> res) : result_(std::move(res)) {}
  void Print() const override {
    std::cout << result_->GetName() << " = alloca " << result_->GetType().GetElementIRTypename() << std::endl;
  }

 private:
  const std::shared_ptr<Register> result_{nullptr};
};