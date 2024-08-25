/*
 * Mx Compiler
 * File Name: phi_stmt.h
 * Identification: ./src/include/ir/stmt/phi_stmt.h
 * Function: IR node for phi statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * IR node for phi statements
 */
class PhiStmt : public Stmt {
 public:
  PhiStmt() = delete;
  PhiStmt(std::shared_ptr<Register> res, std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>> blocks)
      : res_(std::move(res)), blocks_(std::move(blocks)) {}
  void Print() const override {
    std::cout << res_->GetName() << " = phi " << res_->GetType().GetIRTypename() << " ";
    for (int i = 0; i < blocks_.size(); ++i) {
      if (i != 0) {
        std::cout << ", ";
      }
      std::cout << "[ " << blocks_[i].first->GetName() << ", %" << blocks_[i].second.lock()->GetLabel() << " ]";
    }
    std::cout << std::endl;
  }

 private:
  const std::shared_ptr<Register> res_;
  std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>> blocks_;
};