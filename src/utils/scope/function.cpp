/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/utils/scope/function.h
 * Function: Manage function information for AST.
 */

#include <iostream>
#include <stdexcept>

#include "utils/scope/function.h"

Function::Function() : return_type_({}) {}

Function::Function(const std::string &name, const Type &return_type) : name_(name), return_type_(return_type) {}

void Function::AppendArgument(const Type &type) { arguments_.push_back(type); }

std::size_t Function::GetArgNum() const { return arguments_.size(); }

Type Function::GetArgument(std::size_t index) const {
  if (index >= arguments_.size()) {
    std::cerr << "Vector index out of bound when visiting arguments_ in Function class" << std::endl;
    throw std::runtime_error("Vector index out of bound");
  }
  return arguments_[index];
}

const std::vector<Type> &Function::GetArguments() const { return arguments_; }
