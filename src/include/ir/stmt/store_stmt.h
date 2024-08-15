/*
* Mx Compiler
 * File Name: store_stmt.h
 * Identification: ./src/include/ir/stmt/store_stmt.h
 * Function: IR node for memory store statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * IR node for memory load statements
 */
class StoreStmt : public Stmt {
public:
  StoreStmt() = delete;
  StoreStmt(std::shared_ptr<Var> val, std::shared_ptr<Register> ptr)
      : value_(std::move(val)), ptr_(std::move(ptr)) {}
  void Print() const override {
    std::cout << "store " << value_->GetType() << " " << value_->GetName() << ", ptr " << ptr_->GetName() << std::endl;
  }

private:
  std::shared_ptr<Var> value_;
  std::shared_ptr<Register> ptr_;
};