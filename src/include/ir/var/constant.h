/*
 * Mx Compiler
 * File Name: register.h
 * Identification: ./src/include/ir/var/register.h
 * Function: IR node for constants
 */
#pragma once

#include <variant>

#include "ir/var/var.h"

/**
 * IR node for constants
 */
class Constant final : public Var {
 public:
  Constant() = delete;
  explicit Constant(void *) : Var(true), type_(kIRNullType) {}
  explicit Constant(bool value) : Var(true), type_(kIRBoolType), value_(value) {}
  explicit Constant(int value) : Var(true), type_(kIRIntType), value_(value) {}
  explicit Constant(std::shared_ptr<Var> var, std::string val)
      : Var(true), type_(kIRStringType), var_(std::move(var)), value_(std::move(val)) {}
  [[nodiscard]] IRType GetType() const override { return type_; }
  [[nodiscard]] std::string GetName() const override {
    if (type_ == kIRIntType) {
      return std::to_string(std::get<int>(value_));
    }
    if (type_ == kIRBoolType) {
      return std::to_string(std::get<bool>(value_));
    }
    if (type_ == kIRStringType) {
      return var_->GetName();
    }
    if (type_ == kIRNullType) {
      return "null";
    }
    assert(false);
  }
  [[nodiscard]] const std::shared_ptr<Var> &GetVar() const { return var_; }

 private:
  const IRType type_;
  const std::shared_ptr<Var> var_;
  const std::variant<int, bool, std::string> value_;
};