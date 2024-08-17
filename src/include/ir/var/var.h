/*
 * Mx Compiler
 * File Name: var.h
 * Identification: ./src/include/ir/var/var.h
 * Function: IR node for variables and constants
 */
#pragma once

#include <string>

/**
 * IR node for variables and constants
 */
class Var {
 public:
  Var() = default;
  virtual ~Var() = 0;
  [[nodiscard]] virtual std::string GetName() const = 0;
  [[nodiscard]] virtual std::string GetType() const = 0;
};