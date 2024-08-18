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
  AllocaStmt(std::shared_ptr<Register> res, std::shared_ptr<Var> len) : result_(std::move(res)), len_(std::move(len)) {}
  void Print() const override {
    if (result_ == nullptr) {
      std::cout << result_->GetName() << " = alloca " << result_->GetType() << std::endl;
    } else {
      std::cout << result_->GetName() << " = alloca [ " << len_->GetName() << " x i8 ]" << std::endl;
    }
  }

 private:
  const std::shared_ptr<Register> result_{nullptr};
  const std::shared_ptr<Var> len_{nullptr};
};