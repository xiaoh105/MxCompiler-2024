/*
 * Mx Compiler
 * File Name: register.h
 * Identification: ./src/include/ir/var/register.h
 * Function: IR node for global and local variables
 */
#pragma once

#include <cassert>
#include <iostream>

#include "ir/var/var.h"
#include "utils/scope/type.h"

/**
 * IR node for global and local variables
 */
class Register final : public Var {
 public:
  Register() = delete;
  Register(Type type, std::string name, bool global)
      : type_(std::move(type)), name_(std::move(name)), global_(global) {}
  [[nodiscard]] std::string GetName() const override { return (global_ ? "@" : "%") + name_; }
  [[nodiscard]] std::string GetType() const override { return GetIRTypename(type_); }
  void DefineGlobal() const {
    assert(global_ == true);
    std::cout << GetName() << " = global " << GetType() << " ";
    if (type_ == kIntType) {
      std::cout << 0 << std::endl;
    } else if (type_ == kBoolType) {
      std::cout << "false" << std::endl;
    } else {
      std::cout << "null" << std::endl;
    }
  }

 private:
  const Type type_;
  const std::string name_;
  bool global_{false};
};