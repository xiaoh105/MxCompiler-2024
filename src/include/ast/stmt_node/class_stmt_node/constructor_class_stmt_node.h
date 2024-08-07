/*
 * Mx Compiler
 * File Name: constructor_class_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/class_stmt_node/constructor_class_stmt_node.h
 * Function: AST node for default constructor in classes
 */
#pragma once

#include "ast/stmt_node/class_stmt_node/class_stmt_node.h"

class ConstructorClassStmtNode : public ClassStmtNode {
 public:
  ConstructorClassStmtNode() = delete;
  ConstructorClassStmtNode(Position pos, std::string type, std::unique_ptr<StmtNode> function_body)
      : ClassStmtNode(std::move(pos)), type_(std::move(type)), function_body_(std::move(function_body)) {}
  [[nodiscard]] const std::string &GetType() const { return type_; }
  std::unique_ptr<StmtNode> &GetFunctionBody() { return function_body_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string type_;
  std::unique_ptr<StmtNode> function_body_;
};