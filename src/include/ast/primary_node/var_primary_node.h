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
  VarPrimaryNode(const Position &pos, const std::string &name) : PrimaryNode(pos), name_(name) {
    lvalue_ = true;
    null_ = false;
  }
  [[nodiscard]] const std::string &GetName() const { return name_; }

 private:
  const std::string &name_;
};