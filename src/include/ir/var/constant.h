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
  explicit Constant(int val) : value_(val), is_int_(true) {}
  explicit Constant(bool val) : value_(val) {}
  [[nodiscard]] bool IsInt() const { return is_int_; }
  [[nodiscard]] bool GetBool() const { return std::get<bool>(value_); }
  [[nodiscard]] int GetInt() const { return std::get<int>(value_); }
  [[nodiscard]] std::string GetName() const override {
    if (is_int_) {
      return std::to_string(std::get<int>(value_));
    }
    return std::to_string(std::get<bool>(value_));
  }
  [[nodiscard]] std::string GetType() const override {
    return is_int_ ? "i32" : "i1";
  }

private:
  const bool is_int_{false};
  const std::variant<int, bool> value_;
};