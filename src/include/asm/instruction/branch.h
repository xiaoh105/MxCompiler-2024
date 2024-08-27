/*
 * Mx Compiler
 * File Name: mem.h
 * Identification: ./src/include/asm/instruction/branch.h
 * Function: Assembly instruction for branch instructions
 */
#pragma once

#include "asm/instruction/instruction.h"

class BranchInstruction : public AsmInstruction {
 public:
  enum BranchType { kUnknown, kEq, kNe, kLt, kGe };
  BranchInstruction(std::string label, AsmRegister rs1, AsmRegister rs2, BranchType branch_type)
      : label_(std::move(label)), rs1_(rs1), rs2_(rs2), branch_type_(branch_type) {
    assert(branch_type_ != BranchType::kUnknown);
  }
  void Print() const override {
    std::string name;
    switch (branch_type_) {
      case BranchType::kEq:
        name = "eq";
        break;
      case BranchType::kNe:
        name = "ne";
        break;
      case BranchType::kLt:
        name = "lt";
        break;
      case BranchType::kGe:
        name = "ge";
        break;
      case BranchType::kUnknown:
        assert(false);
    }
    std::cout << "b" << name << " " << rs1_.GetName() << " " << rs2_.GetName() << " " << label_ << std::endl;
  }

 private:
  const std::string label_;
  AsmRegister rs1_;
  AsmRegister rs2_;
  BranchType branch_type_;
};

class CallInstruction : public AsmInstruction {
public:
  explicit CallInstruction(std::string label) : label_(std::move(label)) {}
  void Print() const override {
    std::cout << "call " << label_ << std::endl;
  }
private:
  const std::string label_;
};

class JInstruction : public AsmInstruction {
public:
  explicit JInstruction(std::string label) : label_(std::move(label)) {}
  void Print() const override {
    std::cout << "j " << label_ << std::endl;
  }
private:
  const std::string label_;
};

class RetInstruction : public AsmInstruction {
public:
  RetInstruction() = default;
  void Print() const override {
    std::cout << "ret" << std::endl;
  }
};