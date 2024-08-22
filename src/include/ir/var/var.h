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
  explicit Var(bool is_const) : is_const_(is_const) {};
  virtual ~Var() = default;
  [[nodiscard]] virtual IRType GetType() const = 0;
  [[nodiscard]] virtual std::string GetName() const = 0;

 protected:
  bool is_const_;
};