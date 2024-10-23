/*
 * Mx Compiler
 * File Name: stmt.h
 * Identification: ./src/include/ir/stmt/stmt.h
 * Function: IR node for statements
 */
#pragma once

#include <memory>

class Register;

/**
 * Virtual class for LLVM IR statements.
 */
class Stmt {
 public:
  Stmt() = default;
  virtual ~Stmt() = default;
  virtual void Print() const = 0;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Register>> GetUse() const = 0;
  [[nodiscard]] virtual std::shared_ptr<Register> GetDef() const = 0;
};