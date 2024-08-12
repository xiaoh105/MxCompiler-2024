/*
 * Mx Compiler
 * File Name: compiler_error.hpp
 * Identification: ./src/utils/error/compiler_error.hpp
 * Function: Formalize errors in Mx Compiler.
 */

#pragma once

#include <exception>
#include <string>

#include "utils/position.hpp"

/**
 * A class used to regulate and report errors in Mx Compiler.
 */
class CompilerError : public std::exception {
 public:
  CompilerError() = delete;
  CompilerError(const std::string &error_type, const std::string &error_detail, const Position &pos)
      : error_type_(error_type), error_detail_(error_detail), position_(pos) {
#ifndef OJ
    error_msg_ = error_header_ + error_type_ + ": " + error_detail_ + ".\nLine " + position_.ToString();
#else
    error_msg_ = error_detail_ + "\n";
#endif
  }
  [[nodiscard]] const char *what() const noexcept override {
    return error_msg_.c_str();
  }

 private:
  const std::string error_header_{"Error occurred when compiler is running. \n"};
  const std::string error_type_;
  const std::string error_detail_;
  const Position position_;
  std::string error_msg_;
};