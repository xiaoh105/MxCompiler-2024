/*
 * Mx Compiler
 * File Name: for_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/for_stmt_node.h
 * Function: AST node for 'for' loop statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for 'for' loop statements
 */
class ForStmtNode : public StmtNode {
 public:
  ForStmtNode() = delete;
  ForStmtNode(const Position &pos, std::unique_ptr<StmtNode> initialize_stmt, std::unique_ptr<ExprNode> condition,
              std::unique_ptr<ExprNode> step, std::unique_ptr<StmtNode> loop)
      : StmtNode(pos),
        initialize_stmt_(std::move(initialize_stmt)),
        condition_expr_(std::move(condition)),
        step_expr(std::move(step)),
        loop_stmt(std::move(loop)) {}
  std::unique_ptr<StmtNode> &GetInitializeStmt() { return initialize_stmt_; }
  std::unique_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::unique_ptr<ExprNode> &GetStep() { return step_expr; }
  std::unique_ptr<StmtNode> &GetLoop() { return loop_stmt; }

 private:
  std::unique_ptr<StmtNode> initialize_stmt_{nullptr};
  std::unique_ptr<ExprNode> condition_expr_{nullptr};
  std::unique_ptr<ExprNode> step_expr{nullptr};
  std::unique_ptr<StmtNode> loop_stmt{nullptr};
};