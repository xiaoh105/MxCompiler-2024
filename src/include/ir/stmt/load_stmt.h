/*
 * Mx Compiler
 * File Name: load_stmt.h
 * Identification: ./src/include/ir/stmt/load_stmt.h
 * Function: IR node for memory load statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * IR node for memory load statements
 */
class LoadStmt : public Stmt {
 public:
  LoadStmt() = delete;
  LoadStmt(std::shared_ptr<Register> res, std::shared_ptr<Register> ptr)
      : result_(std::move(res)), ptr_(std::move(ptr)) {
    assert(ptr_->GetType().IsPtrOf(result_->GetType()));
  }
  [[nodiscard]] const std::shared_ptr<Register> &GetResult() const { return result_; }
  [[nodiscard]] const std::shared_ptr<Register> &GetPtr() const { return ptr_; }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return result_; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    if (ptr_->IsGlobal()) {
      return {};
    }
    return {ptr_};
  }
  void Print() const override {
    std::cout << result_->GetName() << " = load " << result_->GetType().GetIRTypename() << ", ptr " << ptr_->GetName()
              << std::endl;
  }

 private:
  std::shared_ptr<Register> result_;
  std::shared_ptr<Register> ptr_;
};