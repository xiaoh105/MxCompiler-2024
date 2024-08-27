/*
 * Mx Compiler
 * File Name: mem.h
 * Identification: ./src/include/asm/instruction/mem.h
 * Function: Assembly instruction for memory instructions
 */
#pragma once

#include "asm/instruction/instruction.h"

enum class MemType : int { kUnknown = 0, kWord, kHalfWord, kByte };

class LoadInstruction : public AsmInstruction {
 public:
  LoadInstruction(AsmRegister rd, AsmRegister rs1, int imm, MemType mem_type)
      : rd_(rd), rs1_(rs1), imm_(imm), mem_type_(mem_type) {
    assert(mem_type_ != MemType::kUnknown);
  }
  void Print() const override {
    std::string type = mem_type_ == MemType::kWord ? "w" : mem_type_ == MemType::kHalfWord ? "h" : "b";
    std::cout << "l" << type << " " << rd_.GetName() << " " << imm_ << "(" << rs1_.GetName() << ")" << std::endl;
  }

 private:
  AsmRegister rd_;
  AsmRegister rs1_;
  int imm_;
  MemType mem_type_;
};

class StoreInstruction : public AsmInstruction {
public:
  StoreInstruction(AsmRegister rs1, AsmRegister rs2, int imm, MemType mem_type)
      : rs1_(rs1), rs2_(rs2), imm_(imm), mem_type_(mem_type) {
    assert(mem_type_ != MemType::kUnknown);
  }
  void Print() const override {
    std::string type = mem_type_ == MemType::kWord ? "w" : mem_type_ == MemType::kHalfWord ? "h" : "b";
    std::cout << "s" << type << " " << rs2_.GetName() << " " << imm_ << "(" << rs1_.GetName() << ")" << std::endl;
  }

private:
  AsmRegister rs1_;
  AsmRegister rs2_;
  int imm_;
  MemType mem_type_;
};