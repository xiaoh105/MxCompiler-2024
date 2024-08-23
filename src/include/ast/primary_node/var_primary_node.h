/*
 * Mx Compiler
 * File Name: var_primary_node.h
 * Identification: ./src/include/ast/primary_node/var_primary_node.h
 * Function: AST node for variables.
 */
#pragma once

#include "ast/primary_node/primary_node.h"

/**
 * AST node for variables
 */
class VarPrimaryNode : public PrimaryNode {
 public:
  VarPrimaryNode() = delete;
  VarPrimaryNode(Position pos, std::string name) : PrimaryNode(std::move(pos)), name_(std::move(name)) {
    lvalue_ = true;
    null_ = false;
  }
  [[nodiscard]] const std::string &GetName() const { return name_; }
  void Rename(std::string name) { name_ = std::move(name); }
  void SetMember() { is_member_ = true; }
  [[nodiscard]] bool IsMember() const { return is_member_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::string name_;
  bool is_member_{false};
};