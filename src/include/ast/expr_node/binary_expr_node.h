/*
 * Mx Compiler
 * File Name: binary_expr_node.h
 * Identification: ./src/include/ast/expr_node/binary_expr_node.h
 * Function: AST node for binary expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for binary expressions
 */
class BinaryExprNode : public ExprNode {
 public:
  enum class OpType : int {
    kUnknown = 0,
    kAdd,
    kSub,
    kMul,
    kDiv,
    kMod,
    kShiftL,
    kShiftR,
    kLess,
    kLessEqual,
    kGreater,
    kGreaterEqual,
    kEqual,
    kNotEqual,
    kAnd,
    kAndLogic,
    kOr,
    kOrLogic,
    kXor
  };
  BinaryExprNode() = delete;
  BinaryExprNode(Position pos, OpType op_type, std::unique_ptr<ExprNode> lhs, std::unique_ptr<ExprNode> rhs)
      : ExprNode(std::move(pos)),
        op_type_(op_type),
        left_expr_node_(std::move(lhs)),
        right_expr_node_(std::move(rhs)) {}
  std::unique_ptr<ExprNode> &GetLeftNode() { return left_expr_node_; }
  std::unique_ptr<ExprNode> &GetRightNode() { return right_expr_node_; }
  [[nodiscard]] OpType GetOpType() const { return op_type_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const OpType op_type_{kUnknown};
  std::unique_ptr<ExprNode> left_expr_node_{nullptr};
  std::unique_ptr<ExprNode> right_expr_node_{nullptr};
};