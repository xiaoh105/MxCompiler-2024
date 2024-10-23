/*
 * Mx Compiler
 * File Name: register.h
 * Identification: ./src/include/ir/var/register.h
 * Function: IR node for global and local variables
 */
#pragma once

#include <cassert>

#include "ir/var/constant.h"
#include "ir/var/var.h"

/**
 * IR node for global and local variables
 */
class Register : public Var {
 public:
  Register() = delete;
  Register(IRType type, std::string name, bool global, bool lvalue)
      : Var(lvalue, false), type_(std::move(type)), name_((global ? "@" : "%") + std::move(name)), global_(global) {
    assert(type_.GetBaseType() != kIRVoidBase && type_.GetBaseType() != kIRNullBase);
  }
  [[nodiscard]] std::string GetName() const override { return name_; }
  [[nodiscard]] IRType GetType() const override { return type_; }
  [[nodiscard]] bool IsGlobal() const { return global_; }

 private:
  const IRType type_;
  const std::string name_;
  const bool global_{false};
};