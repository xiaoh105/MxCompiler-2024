/*
 * Mx Compiler
 * File Name: instruction.h
 * Identification: ./src/include/asm/instruction/instruction.h
 * Function: Virtual class for assembly instructions
 */
#pragma once

#include <list>

class AsmInstruction {
public:
  AsmInstruction() = default;
  virtual ~AsmInstruction() = default;
  virtual void Print() const = 0;
  [[nodiscard]] virtual int GetDestId() const = 0;
  [[nodiscard]] virtual std::list<int> GetSrcId() const = 0;
};