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
  ThisPrimaryNode(const Position &pos) : PrimaryNode(pos) {
    lvalue_ = true;
    null_ = false;
  }
};