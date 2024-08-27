/*
 * Mx Compiler
 * File Name: instruction.h
 * Identification: ./src/include/asm/instruction/instruction.h
 * Function: Virtual class for assembly instructions
 */
#pragma once

class AsmInstruction {
public:
  AsmInstruction() = default;
  virtual ~AsmInstruction() = default;
  virtual void Print() const = 0;
};