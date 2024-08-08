/*
 * Mx Compiler
 * File Name: class_def_node.h
 * Identification: ./src/include/ast/def_node/class_def_node.h
 * Function: AST node for class definitions
 */
#pragma once

#include "ast/def_node/def_node.h"
#include "ast/stmt_node/class_stmt_node/class_stmt_node.h"

class ClassDefNode : public DefNode {
 public:
  ClassDefNode() = delete;
  ClassDefNode(Position pos, std::string class_name, std::vector<std::shared_ptr<ClassStmtNode>> class_stmt)
      : DefNode(std::move(pos)), class_name_(std::move(class_name)), class_stmt_(std::move(class_stmt)) {}
  [[nodiscard]] const std::string &GetClassName() const { return class_name_; }
  std::vector<std::shared_ptr<ClassStmtNode>> &GetClassStmt() { return class_stmt_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string class_name_;
  std::vector<std::shared_ptr<ClassStmtNode>> class_stmt_{};
};