/*
 * Mx Compiler
 * File Name: this_primary_node.h
 * Identification: ./src/include/ast/primary_node/this_primary_node.h
 * Function: AST node for 'this' pointer in classes
 */
#pragma once

#include "ast/primary_node/primary_node.h"

/**
 * AST node for 'this' pointer in classes
 */
class ThisPrimaryNode : public PrimaryNode {
 public:
  ThisPrimaryNode() = delete;
  ThisPrimaryNode(Position pos) : PrimaryNode(std::move(pos)) {
    lvalue_ = false;
    null_ = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};