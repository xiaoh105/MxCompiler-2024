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
  WhileStmtNode(const Position &pos, std::unique_ptr<ExprNode> condition, std::unique_ptr<StmtNode> loop)
      : StmtNode(pos), condition_expr_(std::move(condition)), loop_stmt_(std::move(loop)) {}
  std::unique_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::unique_ptr<StmtNode> &GetLoopStmt() { return loop_stmt_; }

 private:
  std::unique_ptr<ExprNode> condition_expr_{nullptr};
  std::unique_ptr<StmtNode> loop_stmt_{nullptr};
};