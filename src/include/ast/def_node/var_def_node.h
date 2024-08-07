/*
 * Mx Compiler
 * File Name: var_def_node.h
 * Identification: ./src/include/ast/def_node/var_def_node.h
 * Function: AST node for global variable definition
 */
#pragma once

#include "ast/def_node/def_node.h"

/**
 * AST node for global variable definitions.
 */
class VarDefNode : public DefNode {
 public:
  VarDefNode() = delete;
  VarDefNode(const Position &pos, const std::string &type_name, std::vector<std::string> var_name,
             std::vector<std::unique_ptr<ExprNode>> initial_val)
      : DefNode(pos), type_name_(type_name), var_name_(std::move(var_name)), initial_val_(std::move(initial_val)) {}
  [[nodiscard]] const std::string &GetTypename() const { return type_name_; }
  [[nodiscard]] const std::vector<std::string> &GetVarName() const { return var_name_; }
  std::vector<std::unique_ptr<ExprNode>> &GetInitialValue() { return initial_val_; }

 private:
  const std::string type_name_;
  std::vector<std::string> var_name_;
  std::vector<std::unique_ptr<ExprNode>> initial_val_;
};