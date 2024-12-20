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
  ICmpStmt(std::shared_ptr<Register> res, int res_raw, OpType op_type, std::shared_ptr<Var> lhs, std::shared_ptr<Var> rhs)
      : result_(std::move(res)), result_raw_(res_raw), op_type_(op_type), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {
    assert(result_->GetType() == kIRBoolType);
    assert(lhs_->GetType() == rhs_->GetType() || lhs_->GetType() == kIRNullType || rhs_->GetType() == kIRNullType);
  }
  [[nodiscard]] const std::shared_ptr<Register> &GetResult() const { return result_; }
  [[nodiscard]] OpType GetOpType() const { return op_type_; }
  [[nodiscard]] const std::shared_ptr<Var>& GetLhs() const { return lhs_; }
  [[nodiscard]] const std::shared_ptr<Var>& GetRhs() const { return rhs_; }
  void SetLhs(std::shared_ptr<Var> lhs) { lhs_ = std::move(lhs); }
  void SetRhs(std::shared_ptr<Var> rhs) { rhs_ = std::move(rhs); }
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return result_; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override {
    std::vector<std::shared_ptr<Register>> ret;
    if (auto lhs = std::dynamic_pointer_cast<Register>(lhs_); lhs != nullptr && !lhs->IsGlobal()) {
      ret.push_back(lhs);
    }
    if (auto rhs = std::dynamic_pointer_cast<Register>(rhs_); rhs != nullptr && !rhs->IsGlobal()) {
      ret.push_back(rhs);
    }
    return ret;
  }
  void Print() const override {
    std::cout << "%zextTmp." << result_raw_ << " = icmp " << GetOpName(op_type_) << " " << lhs_->GetType().GetIRTypename() << " "
              << lhs_->GetName() << ", " << rhs_->GetName() << std::endl;
    std::cout << result_->GetName() << " = zext i1 %zextTmp." << result_raw_ << " to i8" << std::endl;
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
  int result_raw_;
  OpType op_type_{kUnknown};
  std::shared_ptr<Var> lhs_{nullptr};
  std::shared_ptr<Var> rhs_{nullptr};
};