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
  void SetClassName(std::shared_ptr<Typename> class_name) { class_name_ = std::move(class_name); }
  std::shared_ptr<Typename> &GetClassName() { return class_name_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::string name_;
  std::shared_ptr<Typename> class_name_{nullptr};
};