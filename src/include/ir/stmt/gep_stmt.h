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
      : result_(std::move(res)), ptr_(std::move(ptr)), index_(std::move(index)) {
    for (const auto &item : index_) {
      assert(item->GetType() == kIRIntType);
    }
  }
  [[nodiscard]] const std::shared_ptr<Register> &GetResult() const { return result_; }
  [[nodiscard]] const std::shared_ptr<Register> &GetPtr() const { return ptr_; }
  std::vector<std::shared_ptr<Var>> &GetIndex() { return index_; }
  void SetPtr(std::shared_ptr<Register> ptr) { ptr_ = std::move(ptr); }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return result_; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    std::vector ret{ptr_};
    for (const auto &index : index_) {
      if (auto reg = std::dynamic_pointer_cast<Register>(index); reg != nullptr && !reg->IsGlobal()) {
        ret.emplace_back(std::move(reg));
      }
    }
    return ret;
  }
  void Print() const override {
    std::cout << result_->GetName() << " = getelementptr " << ptr_->GetType().GetElementIRTypename() << ", ptr "
              << ptr_->GetName();
    for (const auto &item : index_) {
      std::cout << ", " << item->GetType().GetIRTypename() << " " << item->GetName();
    }
    std::cout << std::endl;
  }

 private:
  const std::shared_ptr<Register> result_;
  std::shared_ptr<Register> ptr_;
  std::vector<std::shared_ptr<Var>> index_;
};