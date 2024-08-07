/*
 * Mx Compiler
 * File Name: class_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/class_stmt_node/class_stmt_node.h
 * Function: Regulates the behaviour of AST statement nodes in classes.
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for regulating statements in classes
 * Note: In this class (and its deriving classes), there's no special attributes and you don't have to manage anything.
 */
class ClassStmtNode : public StmtNode {
 public:
  ClassStmtNode() = delete;
  ClassStmtNode(const Position &pos) : StmtNode(pos) {}
};