/*
 * Mx Compiler
 * File Name: tenary_expr_node.h
 * Identification: ./src/include/ast/expr_node/tenary_expr_node.h
 * Function: AST node for tenary expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for tenary expresions (i.e. condition ? thenExpr : elseExpr)
 */
class TenaryExprNode : public ExprNode {
 public:
  TenaryExprNode() = delete;
  TenaryExprNode(const Position &pos, std::unique_ptr<ExprNode> condition, std::unique_ptr<ExprNode> then_expr,
                 std::unique_ptr<ExprNode> else_expr)
      : ExprNode(pos),
        condition_expr_(std::move(condition)),
        then_expr_(std::move(then_expr)),
        else_expr_(std::move(else_expr)) {}
  std::unique_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::unique_ptr<ExprNode> &GetThenExpr() { return then_expr_; }
  std::unique_ptr<ExprNode> &GetElseExpr() { return else_expr_; }

 private:
  std::unique_ptr<ExprNode> condition_expr_{nullptr};
  std::unique_ptr<ExprNode> then_expr_{nullptr};
  std::unique_ptr<ExprNode> else_expr_{nullptr};
};