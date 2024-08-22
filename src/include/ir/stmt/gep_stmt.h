/*
 * Mx Compiler
 * File Name: gep_stmt.h
 * Identification: ./src/include/ir/stmt/gep_stmt.h
 * Function: IR node for pointer arithmetic statements
 */
#pragma once

#include "ir/stmt/stmt.h"
#include "ir/var/var.h"

/**
 * IR node for "getelementptr" statements
 */
class GetElementPtrStmt final : public Stmt {
 public:
  GetElementPtrStmt() = delete;
  GetElementPtrStmt(std::shared_ptr<Register> res, std::shared_ptr<Register> ptr,
                    std::vector<std::shared_ptr<Var>> index)
      : result_(std::move(res)), ptr_(std::move(ptr)), index_(std::move(index)) {}
  void Print() const override {
    std::cout << result_->GetName() << " = getelementptr " << ptr_->GetType().GetElementIRTypename() << ", ptr " << ptr_->GetName();
    for (const auto &item : index_) {
      assert(item->GetType() == kIRIntType);
      std::cout << ", " << item->GetType().GetIRTypename() << " " << item->GetName();
    }
    std::cout << std::endl;
  }

 private:
  const std::shared_ptr<Register> result_;
  const std::shared_ptr<Register> ptr_;
  const std::vector<std::shared_ptr<Var>> index_;
};