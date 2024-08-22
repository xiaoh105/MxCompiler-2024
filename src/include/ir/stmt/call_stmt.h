/*
 * Mx Compiler
 * File Name: call_stmt.h
 * Identification: ./src/include/ir/stmt/call_stmt.h
 * Function: IR node for function calling statements
 */
#pragma once

#include <memory>

#include "ir/stmt/stmt.h"

#include <ir/function.h>

class IRFunction;

/**
 * IR node for "call" statements
 */
class CallStmt final : public Stmt {
 public:
  CallStmt() = delete;
  CallStmt(const std::shared_ptr<IRFunction> &function, std::vector<std::shared_ptr<Var>> args)
      : function_(function), arguments_(std::move(args)) {}
  CallStmt(std::shared_ptr<Register> res, const std::shared_ptr<IRFunction> &function,
           std::vector<std::shared_ptr<Var>> args)
      : result_(std::move(res)), function_(function), arguments_(std::move(args)) {}
  void Print() const override {
    if (result_ == nullptr) {
      std::cout << "call void " << function_.lock()->GetName() << "(";
      for (int i = 0; i < arguments_.size(); i++) {
        if (i != 0) {
          std::cout << ", ";
        }
        std::cout << arguments_[i]->GetType().GetIRTypename() << " " << arguments_[i]->GetName();
      }
      std::cout << ")" << std::endl;
    } else {
      std::cout << result_->GetName() << " = call " << function_.lock()->GetReturnType().GetIRTypename() << " "
                << function_.lock()->GetName() << "(";
      for (int i = 0; i < arguments_.size(); i++) {
        if (i != 0) {
          std::cout << ", ";
        }
        std::cout << arguments_[i]->GetType().GetIRTypename() << " " << arguments_[i]->GetName();
      }
      std::cout << ")" << std::endl;
    }
  }

 private:
  std::shared_ptr<Register> result_{nullptr};
  std::weak_ptr<IRFunction> function_;
  std::vector<std::shared_ptr<Var>> arguments_;
};
