/*
 * Mx Compiler
 * File Name: function_call_expr_node.h
 * Identification: ./src/include/ast/expr_node/function_call_expr_node.h
 * Function: AST node for function/method calling expressions
 */
#pragma once

#include "ast/expr_node/expr_node.h"

/**
 * AST node for function/method calling expressions
 */
class FunctionCallExprNode : public ExprNode {
 public:
  FunctionCallExprNode() = delete;
  FunctionCallExprNode(const Position &pos, const std::string &name, std::vector<std::unique_ptr<ExprNode>> arguments)
      : ExprNode(pos), function_name_(name), arguments_(std::move(arguments)) {}
  FunctionCallExprNode(const Position &pos, std::unique_ptr<ExprNode> base, const std::string &name,
                       std::vector<std::unique_ptr<ExprNode>> arguments)
      : ExprNode(pos), base_expr_node_(std::move(base)), function_name_(name), arguments_(std::move(arguments)) {}
  std::unique_ptr<ExprNode> &GetBaseExpr() { return base_expr_node_; }
  [[nodiscard]] const std::string &GetFuncName() const { return function_name_; }
  std::vector<std::unique_ptr<ExprNode>> &GetArguments() { return arguments_; }

 private:
  // Base expression for method calling expressions, nullptr for function calling
  std::unique_ptr<ExprNode> base_expr_node_{nullptr};
  const std::string function_name_;
  std::vector<std::unique_ptr<ExprNode>> arguments_;
};