/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/include/ir/function.h
 * Function: IR node for functions
 */
#pragma once

class IRFunction {
public:

  [[nodiscard]] const std::string &GetName() const;
  [[nodiscard]] std::string GetReturnType() const;

private:
};