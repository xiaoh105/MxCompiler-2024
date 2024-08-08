/*
 * Mx Compiler
 * File Name: while_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/while_stmt_node.h
 * Function: AST node for while statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for while statements
 */
class WhileStmtNode : public StmtNode {
 public:
  WhileStmtNode() = delete;
  WhileStmtNode(Position pos, std::shared_ptr<ExprNode> condition, std::shared_ptr<StmtNode> loop)
      : StmtNode(std::move(pos)), condition_expr_(std::move(condition)), loop_stmt_(std::move(loop)) {}
  std::shared_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::shared_ptr<StmtNode> &GetLoopStmt() { return loop_stmt_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<ExprNode> condition_expr_{nullptr};
  std::shared_ptr<StmtNode> loop_stmt_{nullptr};
};