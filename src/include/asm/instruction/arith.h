/*
 * Mx Compiler
 * File Name: arith.h
 * Identification: ./src/include/asm/instruction/arith.h
 * Function: Assembly instruction for arithmetic instructions
 */
#pragma once

#include <iostream>

#include "asm/instruction/instruction.h"
#include "asm/register/register.h"

class ArithInstruction : public AsmInstruction {
 public:
  enum class ArithType : int { kUnknown = 0, kAdd, kSub, kAnd, kOr, kXor, kShiftL, kShiftR, kShiftRLogic, kSetLT, kMul, kMulH, kDiv, kRem };
  explicit ArithInstruction(ArithType type) : type_(type) {}
  [[nodiscard]] ArithType GetArithType() const { return type_; }
  void Print() const override = 0;

 protected:
  [[nodiscard]] std::string GetInstructionName() const {
    switch (type_) {
      case ArithType::kAdd:
        return "add";
      case ArithType::kSub:
        return "sub";
      case ArithType::kAnd:
        return "and";
      case ArithType::kOr:
        return "or";
      case ArithType::kXor:
        return "xor";
      case ArithType::kShiftL:
        return "sll";
      case ArithType::kShiftRLogic:
        return "srl";
      case ArithType::kShiftR:
        return "sra";
      case ArithType::kSetLT:
        return "slt";
      case ArithType::kMul:
        return "mul";
      case ArithType::kMulH:
        return "mulh";
      case ArithType::kDiv:
        return "div";
      case ArithType::kRem:
        return "rem";
      case ArithType::kUnknown:
        assert(false);
    }
    assert(false);
  }

 private:
  ArithType type_;
};

class RegArithInstruction : public ArithInstruction {
 public:
  RegArithInstruction(AsmRegister rd, AsmRegister rs1, AsmRegister rs2, ArithType type)
      : ArithInstruction(type), rd_(rd), rs1_(rs1), rs2_(rs2) {
    assert(type != ArithType::kUnknown);
  }
  void Print() const override {
    std::cout << GetInstructionName() << " " << rd_.GetName() << ", " << rs1_.GetName() << ", " << rs2_.GetName()
              << std::endl;
  }

 private:
  AsmRegister rd_;
  AsmRegister rs1_;
  AsmRegister rs2_;
};

class ImmArithInstruction : public ArithInstruction {
 public:
  ImmArithInstruction(AsmRegister rd, AsmRegister rs1, int imm, ArithType type)
      : ArithInstruction(type), rd_(rd), rs1_(rs1), imm_(imm) {
    assert(type != ArithType::kSub && type != ArithType::kUnknown);
    assert(imm_ >= -2048 && imm_ <= 2047);
  }
  void Print() const override {
    if (imm_ == 0 && GetArithType() == ArithType::kAdd && rd_ == rs1_) {
      return;
    }
    if (imm_ == 1 && GetArithType() == ArithType::kMul && rd_ == rs1_) {
      return;
    }
    std::cout << GetInstructionName() << "i " << rd_.GetName() << ", " << rs1_.GetName() << ", " << imm_ << std::endl;
  }

 private:
  AsmRegister rd_;
  AsmRegister rs1_;
  int imm_;
};

class MoveInstruction : public ArithInstruction {
 public:
  MoveInstruction(AsmRegister rd, AsmRegister rs) : ArithInstruction(ArithType::kAdd), rd_(rd), rs_(rs) {}
  void Print() const override {
    if (rd_ == rs_) {
      return;
    }
    std::cout << "mv " << rd_.GetName() << ", " << rs_.GetName() << std::endl;
  }

 private:
  AsmRegister rd_;
  AsmRegister rs_;
};

class LoadImmInstruction : public ArithInstruction {
 public:
  LoadImmInstruction(AsmRegister rd, int imm) : ArithInstruction(ArithType::kAdd), rd_(rd), imm_(imm) {}
  void Print() const override { std::cout << "li " << rd_.GetName() << ", " << imm_ << std::endl; }

 private:
  AsmRegister rd_;
  int imm_;
};

class LoadAddrInstruction : public ArithInstruction {
 public:
  LoadAddrInstruction(AsmRegister rd, std::string label)
      : ArithInstruction(ArithType::kAdd), rd_(rd), label_(std::move(label)) {}
  void Print() const override { std::cout << "la " << rd_.GetName() << ", " << label_ << std::endl; }

 private:
  AsmRegister rd_;
  const std::string label_;
};

class CmpZInstruction : public ArithInstruction {
 public:
  enum class CmpType : int { kUnknown = 0, kEqz, kNez, kLtz, kGtz };
  CmpZInstruction(AsmRegister rd, AsmRegister rs, CmpType type)
      : ArithInstruction(ArithType::kUnknown), rd_(rd), rs_(rs), type_(type) {}
  void Print() const override {
    std::string type;
    switch (type_) {
      case CmpType::kEqz:
        type = "eqz";
        break;
      case CmpType::kNez:
        type = "nez";
        break;
      case CmpType::kLtz:
        type = "ltz";
        break;
      case CmpType::kGtz:
        type = "gtz";
        break;
      case CmpType::kUnknown:
        assert(false);
    }
    std::cout << "s" << type << " " << rd_.GetName() << ", " << rs_.GetName() << std::endl;
  }

 private:
  AsmRegister rd_;
  AsmRegister rs_;
  CmpType type_;
};