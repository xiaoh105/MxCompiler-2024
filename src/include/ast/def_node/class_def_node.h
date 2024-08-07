/*
 * Mx Compiler
 * File Name: class_def_node.h
 * Identification: ./src/include/ast/def_node/class_def_node.h
 * Function: AST node for class definitions
 */
#pragma once

#include "ast/def_node/def_node.h"

class ClassDefNode : public DefNode {
 public:
  ClassDefNode() = delete;
  ClassDefNode(const Position &pos, const std::string &class_name,
               std::vector<std::unique_ptr<ClassStmtNode>> class_stmt)
      : DefNode(pos), class_name_(class_name), class_stmt_(std::move(class_stmt)) {}
  [[nodiscard]] const std::string &GetClassName() const { return class_name_; }
  std::vector<std::unique_ptr<ClassStmtNode>> &GetClassStmt() { return class_stmt_; }

 private:
  const std::string class_name_;
  std::vector<std::unique_ptr<ClassStmtNode>> class_stmt_{};
};