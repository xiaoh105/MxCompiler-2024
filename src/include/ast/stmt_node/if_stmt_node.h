/*
 * Mx Compiler
 * File Name: if_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/if_stmt_node.h
 * Function: AST node for if statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for if statements
 */
class IfStmtNode : public StmtNode {
 public:
  IfStmtNode() = delete;
  IfStmtNode(Position pos, std::unique_ptr<ExprNode> condition, std::unique_ptr<StmtNode> then_stmt)
      : StmtNode(std::move(pos)), condition_expr_(std::move(condition)), then_stmt_(std::move(then_stmt)) {}
  IfStmtNode(Position pos, std::unique_ptr<ExprNode> condition, std::unique_ptr<StmtNode> then_stmt,
             std::unique_ptr<StmtNode> else_stmt)
      : StmtNode(std::move(pos)),
        condition_expr_(std::move(condition)),
        then_stmt_(std::move(then_stmt)),
        else_stmt_(std::move(else_stmt)) {}
  std::unique_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::unique_ptr<StmtNode> &GetThenStmt() { return then_stmt_; }
  std::unique_ptr<StmtNode> &GetElseStmt() { return else_stmt_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::unique_ptr<ExprNode> condition_expr_{nullptr};
  std::unique_ptr<StmtNode> then_stmt_{nullptr};
  std::unique_ptr<StmtNode> else_stmt_{nullptr};
};