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
  FunctionCallExprNode(Position pos, std::string name, std::vector<std::shared_ptr<ExprNode>> arguments)
      : ExprNode(std::move(pos)), function_name_(std::move(name)), arguments_(std::move(arguments)) {}
  FunctionCallExprNode(Position pos, std::shared_ptr<ExprNode> base, std::string name,
                       std::vector<std::shared_ptr<ExprNode>> arguments)
      : ExprNode(std::move(pos)),
        base_expr_node_(std::move(base)),
        function_name_(std::move(name)),
        arguments_(std::move(arguments)) {}
  std::shared_ptr<ExprNode> &GetBaseExpr() { return base_expr_node_; }
  [[nodiscard]] const std::string &GetFuncName() const { return function_name_; }
  std::vector<std::shared_ptr<ExprNode>> &GetArguments() { return arguments_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  // Base expression for method calling expressions, nullptr for function calling
  std::shared_ptr<ExprNode> base_expr_node_{nullptr};
  const std::string function_name_;
  std::vector<std::shared_ptr<ExprNode>> arguments_;
};