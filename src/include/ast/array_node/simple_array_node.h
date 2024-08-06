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
  SimpleArrayNode(const Position &pos, const std::vector<Type> &elements) : ArrayNode(pos), elements_(elements) {}
  [[nodiscard]] const std::vector<Type> &GetElements() const { return elements_; }

 private:
  const std::vector<Type> elements_;
};
