/*
 * Mx Compiler
 * File Name: ast_node.h
 * Identification: ./src/include/ast/ast_node.h
 * Function: Regulates the behaviour of all AST nodes.
 */
#pragma once

#include "ast/ast_visitor.h"
#include "utils/position.hpp"

using TypeType = std::pair<std::string, std::size_t>;

/**
 * A virtual class used to regulate the behaviour of AST nodes.
 * All AST node MUST be derived from this virtual class.
 */
class ASTNode {
public:
  ASTNode() = delete;
  virtual ~ASTNode() = default;
  ASTNode(Position pos) : position_(std::move(pos)) {}
  virtual void accept(ASTVisitor *visitor) = 0;
  [[nodiscard]] const Position &GetPos() const { return position_; }

protected:
  const Position position_;
};