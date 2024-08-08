/*
 * Mx Compiler
 * File Name: expr_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/expr_stmt_node.h
 * Function: AST node for expression statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for expression statements (i.e. statements composed of an expression and a ';')
 */
class ExprStmtNode : public StmtNode {
 public:
  ExprStmtNode() = delete;
  ExprStmtNode(Position pos, std::shared_ptr<ExprNode> expr_node)
      : StmtNode(std::move(pos)), expr_node_(std::move(expr_node)) {}
  std::shared_ptr<ExprNode> &GetExprNode() { return expr_node_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<ExprNode> expr_node_{nullptr};
};