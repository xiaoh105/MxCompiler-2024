/*
 * Mx Compiler
 * File Name: assign_expr_node.h
 * Identification: ./src/include/ast/expr_node/assign_expr_node.h
 * Function: AST node for assign expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for assign expressions.
 */
class AssignExprNode : public ExprNode {
 public:
  AssignExprNode() = delete;
  AssignExprNode(Position pos, std::shared_ptr<ExprNode> lhs, std::shared_ptr<ExprNode> rhs)
      : ExprNode(std::move(pos)), left_expr_node_(std::move(lhs)), right_expr_node_(std::move(rhs)) {}
  std::shared_ptr<ExprNode> &GetLeftExprNode() { return left_expr_node_; }
  std::shared_ptr<ExprNode> &GetRightExprNode() { return right_expr_node_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<ExprNode> left_expr_node_{nullptr};
  std::shared_ptr<ExprNode> right_expr_node_{nullptr};
};