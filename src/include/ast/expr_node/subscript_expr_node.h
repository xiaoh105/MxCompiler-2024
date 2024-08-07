/*
 * Mx Compiler
 * File Name: subscript_expr_node.h
 * Identification: ./src/include/ast/expr_node/subscipt_expr_node.h
 * Function: AST node for subscipt expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for subscript expressions (i.e. baseExpr[indexExpr])
 */
class SubscriptExprNode : public ExprNode {
 public:
  SubscriptExprNode() = delete;
  SubscriptExprNode(const Position &pos, std::unique_ptr<ExprNode> base, std::unique_ptr<ExprNode> index)
      : ExprNode(pos), base_expr_node_(std::move(base)), index_expr_node_(std::move(index)) {}

 private:
  std::unique_ptr<ExprNode> base_expr_node_{nullptr};
  std::unique_ptr<ExprNode> index_expr_node_{nullptr};
};