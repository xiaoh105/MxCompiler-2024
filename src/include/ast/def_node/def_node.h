/*
 * Mx Compiler
 * File Name: def_node.h
 * Identification: ./src/include/ast/def_node/def_node.h
 * Function: Regulates the behaviour of AST global definition nodes.
 */
#pragma once

#include "ast/ast_node.h"

/**
 * Virtual class regulating the behaviour of AST global definition nodes
 * Note: In this class (and its deriving classes), there's no special attributes and you don't have to manage anything.
 */
class DefNode : public ASTNode {
 public:
  DefNode() = delete;
  DefNode(const Position &pos) : ASTNode(pos) {}
};