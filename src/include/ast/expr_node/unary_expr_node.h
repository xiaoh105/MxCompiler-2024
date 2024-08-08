/*
 * Mx Compiler
 * File Name: unary_expr_node.h
 * Identification: ./src/include/ast/expr_node/unary_expr_node.h
 * Function: AST node for unary expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for unary expressions
 */
class UnaryExprNode : public ExprNode {
 public:
  enum class OpType : int {
    kUnknown = 0,
    kSufIncrement,
    kSufDecrement,
    kPreIncrement,
    kPreDecrement,
    kPlus,
    kMinus,
    kNot,
    kNotLogic
  };
  UnaryExprNode() = delete;
  UnaryExprNode(Position pos, OpType op_type, std::shared_ptr<ExprNode> expr_node)
      : ExprNode(std::move(pos)), op_type_(op_type), expr_node_(std::move(expr_node)) {}
  std::shared_ptr<ExprNode> &GetExprNode() { return expr_node_; }
  [[nodiscard]] OpType GetOpType() const { return op_type_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const OpType op_type_{kUnknown};
  std::shared_ptr<ExprNode> expr_node_{nullptr};
};