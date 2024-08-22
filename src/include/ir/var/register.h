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
class Register final : public Var {
 public:
  Register() = delete;
  Register(IRType type, std::string name, bool global)
      : Var(false), type_(std::move(type)), name_((global ? "@" : "%") + std::move(name)), global_(global) {
    assert(type_.GetBaseType() != kIRVoidBase && type_.GetBaseType() != kIRNullBase);
    if (type_ == kIRIntType || type_ == kIRBoolType) {
      init_val_ = std::make_shared<Constant>(0);
    } else {
      init_val_ = std::make_shared<Constant>(nullptr);
    }
  }
  Register(IRType type, std::string name, bool global, std::shared_ptr<Constant> init_val)
      : Var(false), type_(std::move(type)), name_(std::move(name)), global_(global), init_val_(std::move(init_val)) {}
  [[nodiscard]] const std::shared_ptr<Constant> &GetInitVal() const { return init_val_; }
  [[nodiscard]] std::string GetName() const override { return name_; }
  [[nodiscard]] IRType GetType() const override { return type_; }

 private:
  const IRType type_;
  const std::string name_;
  const bool global_{false};
  std::shared_ptr<Constant> init_val_{nullptr};
};