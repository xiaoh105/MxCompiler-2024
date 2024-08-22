/*
 * Mx Compiler
 * File Name: binary_stmt.h
 * Identification: ./src/include/ir/stmt/binary_stmt.h
 * Function: IR node for binary statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * IR node for binary statements
 */
class BinaryStmt final : public Stmt {
 public:
  enum class OpType : int { kUnknown = 0, kAdd, kSub, kMul, kSDiv, kSRem, kShiftL, kShiftR, kAnd, kOr, kXor };
  BinaryStmt() = delete;
  BinaryStmt(std::shared_ptr<Register> res, OpType op, std::shared_ptr<Var> lhs, std::shared_ptr<Var> rhs)
      : result_(std::move(res)), op_type_(op), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {
    assert(lhs_->GetType() == rhs_->GetType());
  }
  void Print() const override {
    std::cout << result_->GetName() << " = " << GetOpName(op_type_) << " " << lhs_->GetType().GetIRTypename() << " " << lhs_->GetName()
              << ", " << rhs_->GetName() << std::endl;
  }

 private:
  static std::string GetOpName(OpType op) {
    switch (op) {
      case OpType::kAdd:
        return "add";
      case OpType::kSub:
        return "sub";
      case OpType::kMul:
        return "mul";
      case OpType::kSDiv:
        return "sdiv";
      case OpType::kSRem:
        return "srem";
      case OpType::kShiftL:
        return "shl";
      case OpType::kShiftR:
        return "ashr";
      case OpType::kAnd:
        return "and";
      case OpType::kOr:
        return "or";
      case OpType::kXor:
        return "xor";
      case OpType::kUnknown:
        throw std::runtime_error("Unknown operation type");
    }
    throw std::runtime_error("Unknown operation type");
  }
  std::shared_ptr<Register> result_{nullptr};
  const OpType op_type_;
  std::shared_ptr<Var> lhs_{nullptr};
  std::shared_ptr<Var> rhs_{nullptr};
};