/*
 * Mx Compiler
 * File Name: empty_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/empty_stmt_node.h
 * Function: AST node for empty statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for empty statements (i.e. statements with only a ";")
 */
class EmptyStmtNode : public StmtNode {
public:
  EmptyStmtNode() = delete;
  EmptyStmtNode(Position pos) : StmtNode(std::move(pos)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};