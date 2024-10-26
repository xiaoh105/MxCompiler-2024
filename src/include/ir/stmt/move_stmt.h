/*
 * Mx Compiler
 * File Name: move_stmt.h
 * Identification: ./src/include/ir/stmt/move_stmt.h
 * Function: IR node for move statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * IR node for move statements (which is a psudo-instruction)
 */
class MoveStmt : public Stmt {
 public:
  MoveStmt() = delete;
  MoveStmt(std::shared_ptr<Register> dest, std::shared_ptr<Var> src) : dest_(std::move(dest)), src_(std::move(src)) {
    assert(dest_ != nullptr);
    assert(src_ != nullptr);
    assert(dest_->GetType() == src_->GetType() || dest_->GetType().GetDim() >= 1 && src_->GetType() == kIRNullType);
  }
  [[nodiscard]] const std::shared_ptr<Register> &GetDest() const { return dest_; }
  [[nodiscard]] const std::shared_ptr<Var> &GetSrc() const { return src_; }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return dest_; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    if (auto src = std::dynamic_pointer_cast<Register>(src_); src != nullptr) {
      return {src};
    }
    return {};
  }
  void Print() const override {
    std::cout << dest_->GetName() << " = bitcast " << dest_->GetType().GetIRTypename() << " " << src_->GetName()
              << " to " << src_->GetType().GetIRTypename() << std::endl;
  }

 private:
  std::shared_ptr<Register> dest_;
  std::shared_ptr<Var> src_;
};