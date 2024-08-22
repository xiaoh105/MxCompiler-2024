/*
 * Mx Compiler
 * File Name: branch_stmt.h
 * Identification: ./src/include/ir/stmt/branch_stmt/branch_stmt.h
 * Function: IR node for branch statements
 */
#pragma once

#include "ir/stmt/stmt.h"

/**
 * Virtual class for branch statements.
 */
class BranchStmt : public Stmt {
 public:
  BranchStmt() = default;
  void Print() const override = 0;
};