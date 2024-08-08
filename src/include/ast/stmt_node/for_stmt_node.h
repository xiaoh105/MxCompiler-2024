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
  ForStmtNode(Position pos, std::shared_ptr<StmtNode> initialize_stmt, std::shared_ptr<ExprNode> condition,
              std::shared_ptr<ExprNode> step, std::shared_ptr<StmtNode> loop)
      : StmtNode(std::move(pos)),
        initialize_stmt_(std::move(initialize_stmt)),
        condition_expr_(std::move(condition)),
        step_expr(std::move(step)),
        loop_stmt(std::move(loop)) {}
  std::shared_ptr<StmtNode> &GetInitializeStmt() { return initialize_stmt_; }
  std::shared_ptr<ExprNode> &GetCondition() { return condition_expr_; }
  std::shared_ptr<ExprNode> &GetStep() { return step_expr; }
  std::shared_ptr<StmtNode> &GetLoop() { return loop_stmt; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<StmtNode> initialize_stmt_{nullptr};
  std::shared_ptr<ExprNode> condition_expr_{nullptr};
  std::shared_ptr<ExprNode> step_expr{nullptr};
  std::shared_ptr<StmtNode> loop_stmt{nullptr};
};