/*
 * Mx Compiler
 * File Name: var_def_class_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/class_stmt_node/var_def_class_stmt_node.h
 * Function: AST node for member definition in classes
 */
#pragma once

#include "ast/stmt_node/class_stmt_node/class_stmt_node.h"

/**
 * AST node for member definition in classes
 */
class VarDefClassStmtNode : public ClassStmtNode {
 public:
  VarDefClassStmtNode() = delete;
  VarDefClassStmtNode(Position pos, TypeType type_name, std::vector<std::string> member_name)
      : ClassStmtNode(std::move(pos)), type_name_(std::move(type_name)), member_name_(std::move(member_name)) {}
  [[nodiscard]] const TypeType &GetTypeName() const { return type_name_; }
  [[nodiscard]] const std::vector<std::string> &GetMemberName() const { return member_name_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const TypeType type_name_;
  std::vector<std::string> member_name_;
};