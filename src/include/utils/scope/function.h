/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/include/utils/scope/function.h
 * Function: Manage function information for AST.
 */

#pragma once

#include <string>
#include <vector>

#include "utils/scope/type.h"

class Type;

/**
 * A class used to manage function parameters.
 */
class Function {
 public:
  Function();
  Function(Type return_type, std::vector<Type> args);
  [[nodiscard]] std::size_t GetArgNum() const;
  [[nodiscard]] Type GetArgument(std::size_t index) const;
  [[nodiscard]] const std::vector<Type> &GetArguments() const;

 private:
  const Type return_type_;
  std::vector<Type> arguments_;
};
