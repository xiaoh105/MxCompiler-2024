/*
 * Mx Compiler
 * File Name: br_uncond_stmt.h
 * Identification: ./src/include/ir/stmt/branch_stmt/br_uncond_stmt.h
 * Function: IR node for unconditional "br" statements
 */
#pragma once

#include "ir/var/var.h"

class RetStmt final : public BranchStmt {
public:
  RetStmt() = default;
  RetStmt(std::shared_ptr<Var> ret_val) : ret_val_(std::move(ret_val)) {}
  [[nodiscard]] const std::shared_ptr<Var> &GetRet() const { return ret_val_; }
  void SetRet(const std::shared_ptr<Var> &ret_val) { ret_val_ = ret_val; }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return nullptr; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    if (auto reg = std::dynamic_pointer_cast<Register>(ret_val_); reg != nullptr && !reg->IsGlobal()) {
      return {reg};
    }
    return {};
  }
  void Print() const override {
    if (ret_val_ != nullptr) {
      std::cout << "ret " << ret_val_->GetType().GetIRTypename() << " " << ret_val_->GetName() << std::endl;
    } else {
      std::cout << "ret void" << std::endl;
    }
  }

private:
  std::shared_ptr<Var> ret_val_{nullptr};
};