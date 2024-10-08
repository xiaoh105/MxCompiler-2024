/*
 * Mx Compiler
 * File Name: atom_expr_node.h
 * Identification: ./src/include/ast/expr_node/atom_expr_node.h
 * Function: AST node for atomic expressions.
 */
#pragma once

#include "ast/expr_node/expr_node.h"
#include "ast/primary_node/primary_node.h"

/**
 * AST node for atomic expressions
 */
class AtomExprNode : public ExprNode {
 public:
  AtomExprNode() = delete;
  AtomExprNode(Position position, std::shared_ptr<PrimaryNode> primary_node)
      : ExprNode(std::move(position)), primary_node_(std::move(primary_node)) {}
  std::shared_ptr<PrimaryNode> &GetPrimaryNode() { return primary_node_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<PrimaryNode> primary_node_{nullptr};
};