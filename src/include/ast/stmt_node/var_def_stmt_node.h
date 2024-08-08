/*
 * Mx Compiler
 * File Name: var_def_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/var_def_stmt_node.h
 * Function: AST node for variable define statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for variable define statements
 */
class VarDefStmtNode : public StmtNode {
 public:
  VarDefStmtNode() = delete;
  VarDefStmtNode(Position pos, std::string type_name, std::vector<std::string> var_name,
                 std::vector<std::shared_ptr<ExprNode>> initial_value)
      : StmtNode(std::move(pos)),
        type_name_(std::move(type_name)),
        var_name_(std::move(var_name)),
        initial_value_(std::move(initial_value)) {}
  [[nodiscard]] const std::vector<std::string> &GetVarName() const { return var_name_; }
  std::vector<std::shared_ptr<ExprNode>> &GetInitialValue() { return initial_value_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string type_name_;
  const std::vector<std::string> var_name_;
  std::vector<std::shared_ptr<ExprNode>> initial_value_;
};