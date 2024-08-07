/*
 * Mx Compiler
 * File Name: simple_array_node.h
 * Identification: ./src/include/ast/array_node/simple_array_node.h
 * Function: AST node for one dimensional array literal
 */
#pragma once

#include "ast/array_node/array_node.h"

/**
 * AST node for one dimensional array literal.
 */
class SimpleArrayNode : public ArrayNode {
 public:
  SimpleArrayNode() = delete;
  SimpleArrayNode(Position pos, std::vector<Type> elements)
      : ArrayNode(std::move(pos)), elements_(std::move(elements)) {}
  [[nodiscard]] const std::vector<Type> &GetElements() const { return elements_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::vector<Type> elements_;
};
