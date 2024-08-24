/*
 * Mx Compiler
 * File Name: select_stmt.h
 * Identification: ./src/include/ir/stmt/select_stmt.h
 * Function: IR node for select statements
 */
#pragma once

#include "ir/stmt/stmt.h"

class SelectStmt : public Stmt {
 public:
  SelectStmt() = delete;
  SelectStmt(std::shared_ptr<Register> res, std::shared_ptr<Var> cond, std::shared_ptr<Var> true_var,
             std::shared_ptr<Var> false_var)
      : res_(std::move(res)), cond_(std::move(cond)), true_var_(std::move(true_var)), false_var_(std::move(false_var)) {
    assert(cond_->GetType() == kIRBoolType);
  }
  void Print() const override {
    const std::string res_typename = res_->GetType().GetIRTypename();
    std::cout << res_->GetName() << " = select i1 " << cond_->GetName() << ", " << res_typename << " "
              << true_var_->GetName() << ", " << res_typename << " " << false_var_->GetName() << std::endl;
  }

 private:
  std::shared_ptr<Register> res_;
  std::shared_ptr<Var> cond_;
  std::shared_ptr<Var> true_var_;
  std::shared_ptr<Var> false_var_;
};