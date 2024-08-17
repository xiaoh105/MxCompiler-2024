/*
 * Mx Compiler
 * File Name: program.h
 * Identification: ./src/include/ir/program.h
 * Function: IR node for the program
 */
#pragma once

#include "ir/function.h"
#include "ir/struct.h"

/**
 * IR node for the program
 */
class Program {
 public:
  Program() = default;
  [[nodiscard]] const std::vector<std::unique_ptr<Register>> &GetGlobalVar() const { return global_var_; }
  [[nodiscard]] const std::vector<std::unique_ptr<IRFunction>> &GetFunctions() const { return functions_; }
  [[nodiscard]] const std::vector<std::unique_ptr<IRStruct>> &GetStructs() const { return structs_; }
  std::unique_ptr<IRFunction> &GetCurrentFunction() { return functions_.back(); }
  void AddVar(std::unique_ptr<Register> reg) { global_var_.push_back(std::move(reg)); }
  void AddFunction(std::unique_ptr<IRFunction> function) { functions_.push_back(std::move(function)); }
  void AddStruct(std::unique_ptr<IRStruct> ir_struct) { structs_.push_back(std::move(ir_struct)); }
  void Print() const {
    for (const auto &item : structs_) {
      item->PrintDeclare();
    }
    for (const auto &item : structs_) {
      item->PrintDefinition();
    }
    for (const auto &item : global_var_) {
      item->DefineGlobal();
    }
    for (const auto &item : functions_) {
      item->Print();
    }
  }

 private:
  std::vector<std::unique_ptr<Register>> global_var_;
  std::vector<std::unique_ptr<IRFunction>> functions_;
  std::vector<std::unique_ptr<IRStruct>> structs_;
};