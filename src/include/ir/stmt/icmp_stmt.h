/*
 * Mx Compiler
 * File Name: icmp_stmt.h
 * Identification: ./src/include/ir/stmt/icmp_stmt.h
 * Function: IR node for compare statements
 */
#pragma once

#include "ir/stmt/stmt.h"
#include "ir/var/var.h"

/**
 * IR node for "icmp" statements
 */
class ICmpStmt final : public Stmt {
 public:
  enum class OpType : int { kUnknown = 0, kEq, kNe, kSgt, kSge, kSlt, kSle };
  ICmpStmt() = delete;
  ICmpStmt(std::shared_ptr<Register> res, OpType op_type, std::shared_ptr<Var> lhs, std::shared_ptr<Var> rhs)
      : result_(std::move(res)), op_type_(op_type), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}
  void Print() const override {
    std::cout << result_->GetName() << " = icmp " << GetOpName(op_type_) << " " << lhs_->GetType() << " "
              << lhs_->GetName() << ", " << rhs_->GetName() << std::endl;
  }

 private:
  static std::string GetOpName(OpType op) {
    switch (op) {
      case OpType::kEq:
        return "eq";
      case OpType::kNe:
        return "ne";
      case OpType::kSgt:
        return "sgt";
      case OpType::kSge:
        return "sge";
      case OpType::kSlt:
        return "slt";
      case OpType::kSle:
        return "sle";
      case OpType::kUnknown:
        throw std::runtime_error("Invalid OpType");
    }
    throw std::runtime_error("Invalid OpType");
  }
  std::shared_ptr<Register> result_{nullptr};
  OpType op_type_{kUnknown};
  std::shared_ptr<Var> lhs_{nullptr};
  std::shared_ptr<Var> rhs_{nullptr};
};