/*
 * Mx Compiler
 * File Name: register.h
 * Identification: ./src/include/ir/var/register.h
 * Function: IR node for global and local variables
 */
#pragma once

#include "ir/var/var.h"
#include "utils/scope/type.h"

/**
 * IR node for global and local variables
 */
class Register final : public Var {
public:
  Register() = delete;
  Register(Type type, std::string name, bool global) : type_(std::move(type)), name_(std::move(name)), global_(global) {}
  [[nodiscard]] std::string GetName() const override {
    return (global_ ? "@" : "%") + name_;
  }
  [[nodiscard]] std::string GetType() const override {
    return GetIRTypename(type_);
  }

private:
   const Type type_;
   const std::string name_;
   bool global_{false};
};