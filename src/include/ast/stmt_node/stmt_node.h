/*
 * Mx Compiler
 * File Name: stmt_node.h
 * Identification: ./src/include/ast/stmt_node/stmt_node.h
 * Function: Regulates the behaviour of AST statement nodes.
 */
#pragma once

#include "ast/ast_node.h"

/**
 * Virtual class regulating the behaviour of AST statement nodes
 * Note: In this class (and its deriving classes), there's no special attributes and you don't have to manage anything.
 */
class StmtNode : public ASTNode {
 public:
  StmtNode() = delete;
  StmtNode(Position pos) : ASTNode(std::move(pos)) {}
};