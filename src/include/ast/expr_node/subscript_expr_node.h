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
  SubscriptExprNode(Position pos, std::shared_ptr<ExprNode> base, std::shared_ptr<ExprNode> index)
      : ExprNode(std::move(pos)), base_expr_node_(std::move(base)), index_expr_node_(std::move(index)) {}
  std::shared_ptr<ExprNode> &GetBaseExpr() { return base_expr_node_; }
  std::shared_ptr<ExprNode> &GetIndexExpr() { return index_expr_node_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<ExprNode> base_expr_node_{nullptr};
  std::shared_ptr<ExprNode> index_expr_node_{nullptr};
};