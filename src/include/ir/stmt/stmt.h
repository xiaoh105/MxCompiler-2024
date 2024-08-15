/*
 * Mx Compiler
 * File Name: stmt.h
 * Identification: ./src/include/ir/stmt/stmt.h
 * Function: IR node for statements
 */
#pragma once

/**
 * Virtual class for LLVM IR statements.
 */
class Stmt {
 public:
  Stmt() = default;
  virtual ~Stmt() = default;
  virtual void Print() const = 0;
};