/*
 * Mx Compiler
 * File Name: member_expr_node.h
 * Identification: ./src/include/ast/expr_node/member_expr_node.h
 * Function: AST node for class member expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for class member expressions (e.g. Myclass.member1, Myclass.member2, ...)
 */
class MemberExprNode : public ExprNode {
 public:
  MemberExprNode() = delete;
  MemberExprNode(const Position &pos, std::unique_ptr<ExprNode> expr_node, const std::string &member_name)
      : ExprNode(pos), expr_node_(std::move(expr_node)), member_name_(member_name) {}
  std::unique_ptr<ExprNode> &GetExprNode() { return expr_node_; }
  [[nodiscard]] const std::string &GetMemberName() const { return member_name_; }

 private:
  std::unique_ptr<ExprNode> expr_node_{nullptr};
  const std::string member_name_;
};