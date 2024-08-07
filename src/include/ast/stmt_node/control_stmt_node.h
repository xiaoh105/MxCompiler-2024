/*
 * Mx Compiler
 * File Name: control_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/control_stmt_node.h
 * Function: AST node for control statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for control statements (i.e. break, continue and return)
 */
class ControlStmtNode : public StmtNode {
 public:
  enum class StmtType : int { kUnknown = 0, kBreak, kContinue, kReturn };
  ControlStmtNode() = delete;
  ControlStmtNode(const Position &pos, StmtType stmt_type) : StmtNode(pos), stmt_type_(stmt_type) {}
  ControlStmtNode(const Position &pos, StmtType stmt_type, std::unique_ptr<ExprNode> return_expr)
      : StmtNode(pos), stmt_type_(stmt_type), return_expr_(std::move(return_expr)) {}
  [[nodiscard]] StmtType GetStmtType() const { return stmt_type_; }
  std::unique_ptr<ExprNode> &GetReturnExpr() {
    if (stmt_type_ != StmtType::kReturn) {
      throw std::runtime_error("Trying to fetch return expression from non-return control statements");
    }
    return return_expr_;
  }

 private:
  const StmtType stmt_type_{kUnknown};
  std::unique_ptr<ExprNode> return_expr_{nullptr};
};