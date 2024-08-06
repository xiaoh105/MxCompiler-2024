/*
 * Mx Compiler
 * File Name: literal_primary_node.h
 * Identification: ./src/include/ast/primary_node/literal_primary_node.h
 * Function: AST node for all kinds of literals.
 */
#pragma once

#include "ast/primary_node/primary_node.h"

/**
 * AST node for all kinds of literals
 */
class LiteralPrimaryNode : public PrimaryNode {
 public:
  LiteralPrimaryNode() = delete;
  LiteralPrimaryNode(const Position &pos, const Type &type, bool null) : PrimaryNode(pos) {
    lvalue_ = false;
    type_ = null ? nullptr : std::make_unique<Type>(type);
    null_ = null;
  }
};