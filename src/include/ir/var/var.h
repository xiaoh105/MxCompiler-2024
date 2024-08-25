/*
 * Mx Compiler
 * File Name: var.h
 * Identification: ./src/include/ir/var/var.h
 * Function: IR node for variables and constants
 */
#pragma once

#include <string>

#include "ir/type/ir_type.h"

/**
 * IR node for variables and constants
 */
class Var {
 public:
  Var() = delete;
  explicit Var(bool lvalue, bool is_const) : lvalue_(lvalue), is_const_(is_const) {};
  virtual ~Var() = default;
  [[nodiscard]] virtual IRType GetType() const = 0;
  [[nodiscard]] virtual std::string GetName() const = 0;
  void SetConst(bool is_const) { is_const_ = is_const; }
  [[nodiscard]] bool IsConst() const { return is_const_; }
  [[nodiscard]] bool IsLValue() const { return lvalue_; }

 protected:
  bool is_const_;
  bool lvalue_;
};