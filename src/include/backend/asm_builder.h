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
  void ScanFunction(std::shared_ptr<IRFunction> function);
  std::unique_ptr<BasicBlock> BuildBlock(const std::shared_ptr<Block> &block);
  void ScanBlock(const std::shared_ptr<Block>& block);
  std::shared_ptr<AsmFunction> cur_func_{nullptr};
  FunctionManager functions_;
  VarManager vars_;
  ClassManager classes_;
  std::vector<std::shared_ptr<AsmFunction>> asm_functions_;
};