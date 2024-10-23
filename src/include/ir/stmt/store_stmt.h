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
  StoreStmt(std::shared_ptr<Var> val, std::shared_ptr<Register> ptr) : value_(std::move(val)), ptr_(std::move(ptr)) {
    assert(ptr_->GetType().IsPtrOf(value_->GetType()) || value_->GetType() == kIRNullType);
  }
  [[nodiscard]] const std::shared_ptr<Var> &GetValue() const { return value_; }
  [[nodiscard]] const std::shared_ptr<Register> &GetPtr() const { return ptr_; }
  void SetValue(std::shared_ptr<Var> value) { value_ = std::move(value); }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return nullptr; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    std::vector<std::shared_ptr<Register>> ret;
    if (!ptr_->IsGlobal()) {
      ret.push_back(ptr_);
    }
    if (auto reg = std::dynamic_pointer_cast<Register>(value_); reg != nullptr && !reg->IsGlobal()) {
      ret.push_back(reg);
    }
    return ret;
  }
  void Print() const override {
    std::cout << "store " << value_->GetType().GetIRTypename() << " " << value_->GetName() << ", ptr "
              << ptr_->GetName() << std::endl;
  }

 private:
  std::shared_ptr<Var> value_;
  std::shared_ptr<Register> ptr_;
};