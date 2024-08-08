/*
 * Mx Compiler
 * File Name: function_def_class_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/class_stmt_node/function_def_class_stmt_node.h
 * Function: AST node for method definition in classes
 */
#pragma once

#include "ast/stmt_node/class_stmt_node/class_stmt_node.h"

/**
 * AST node for method definition in classes
 */
class FunctionDefClassStmtNode : public ClassStmtNode {
 public:
  FunctionDefClassStmtNode() = delete;
  FunctionDefClassStmtNode(Position pos, std::string name, std::string return_type,
                           std::vector<std::pair<std::string, std::string>> arguments, std::shared_ptr<StmtNode> suite)
      : ClassStmtNode(std::move(pos)),
        name_(std::move(name)),
        return_type_(std::move(return_type)),
        arguments_(std::move(arguments)),
        function_body_(std::move(suite)) {}
  [[nodiscard]] const std::string &GetFuncName() const { return name_; }
  [[nodiscard]] const std::string &GetReturnType() const { return return_type_; }
  [[nodiscard]] const std::vector<std::pair<std::string, std::string>> &GetArguments() const { return arguments_; }
  std::shared_ptr<StmtNode> &GetFunctionBody() { return function_body_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string name_;
  const std::string return_type_;
  const std::vector<std::pair<std::string, std::string>> arguments_;
  std::shared_ptr<StmtNode> function_body_{nullptr};
};