/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/utils/scope/function.h
 * Function: Manage function information for AST.
 */

#include <iostream>
#include <stdexcept>

#include "utils/scope/function.h"

Function::Function() : return_type_(kVoidType) {}

Function::Function(Type return_type, std::vector<std::string> arg_name, std::vector<Type> args)
    : return_type_(std::move(return_type)),
      arg_name_(std::make_shared<std::vector<std::string>>(std::move(arg_name))),
      arguments_(std::move(args)) {}

std::size_t Function::GetArgNum() const { return arguments_.size(); }

Type Function::GetArgument(std::size_t index) const {
  if (index >= arguments_.size()) {
    std::cerr << "Vector index out of bound when visiting arguments_ in Function class" << std::endl;
    throw std::runtime_error("Vector index out of bound");
  }
  return arguments_[index];
}

std::vector<std::string> &Function::GetArgName() { return *arg_name_; }

const std::vector<Type> &Function::GetArguments() const { return arguments_; }

const Type &Function::GetReturnType() const { return return_type_; }
