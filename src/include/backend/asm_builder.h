/*
 * Mx Compiler
 * File Name: asm_builder.h
 * Identification: ./src/include/backend/asm_builder.h
 * Function: Class for building assembly
 */
#pragma once

#include "asm/asm.h"
#include "backend/ir_builder.h"

class AsmBuilder {
public:
  AsmBuilder(FunctionManager functions, VarManager vars, ClassManager classes);
  void Print() const;

private:
  void Build();
  void BuildFunction(std::shared_ptr<IRFunction> function);
  void ScanFunction(const std::shared_ptr<IRFunction>& function);
  void BuildBlock(const std::shared_ptr<Block> &block);
  void ScanBlock(const std::shared_ptr<Block>& block);
  void LoadRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg);
  void LoadRegister(VirtualRegister virtual_reg, AsmRegister reg);
  void StoreRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg);
  void StoreRegister(VirtualRegister virtual_reg, AsmRegister reg);
  std::shared_ptr<AsmFunction> cur_func_{nullptr};
  FunctionManager functions_;
  VarManager vars_;
  ClassManager classes_;
  std::unordered_map<std::string, std::shared_ptr<AsmFunction>> asm_functions_;
  std::size_t tag_index_{0};
};