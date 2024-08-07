/*
 * Mx Compiler
 * File Name: format_expr_node.h
 * Identification: ./src/include/ast/expr_node/format_expr_node.h
 * Function: AST node for string format expressions
 */
#pragma once

#include <variant>

#include "ast/expr_node/expr_node.h"

/**
 * AST node for string format expressions
 */
class FormatExprNode : public ExprNode {
 public:
  FormatExprNode() = delete;
  FormatExprNode(const Position &pos, std::vector<std::variant<std::string, std::unique_ptr<ExprNode>>> elements)
      : ExprNode(pos), elements_(std::move(elements)) {}
  std::vector<std::variant<std::string, std::unique_ptr<ExprNode>>> &GetElements() { return elements_; }

 private:
  std::vector<std::variant<std::string, std::unique_ptr<ExprNode>>> elements_;
};