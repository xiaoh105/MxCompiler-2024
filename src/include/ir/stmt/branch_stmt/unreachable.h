/*
 * Mx Compiler
 * File Name: unreachable.h
 * Identification: ./src/include/ir/stmt/branch_stmt/unreachable.h
 * Function: IR node for unconditional "br" statements
 */
#pragma once

class Unreachable final : public BranchStmt {
 public:
  Unreachable() = default;
  [[nodiscard]] std::shared_ptr<Register> GetDef() const override { return nullptr; }
  [[nodiscard]] std::vector<std::shared_ptr<Register>> GetUse() const override { return {}; }
  void Print() const override {
    std::cout << "unreachable" << std::endl;
  }
};