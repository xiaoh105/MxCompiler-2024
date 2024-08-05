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

/**
 * A class used to manage function parameters.
 */
class Function {
 public:
  Function() = default;
  explicit Function(const std::string &name, const Type &return_type);
  void AppendArgument(const Type &type);
  [[nodiscard]] std::size_t GetArgNum() const;
  [[nodiscard]] Type GetArgument(std::size_t index) const;
  [[nodiscard]] const std::vector<Type> &GetArguments() const;

 private:
  std::string name_{};
  std::vector<Type> arguments_{};
  Type return_type_{};
};
