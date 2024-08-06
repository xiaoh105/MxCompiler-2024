/*
 * Mx Compiler
 * File Name: simple_array_node.h
 * Identification: ./src/include/ast/array_node/simple_array_node.h
 * Function: AST node for multi-dimensional array literal.
 */
#pragma once

#include "ast/array_node/array_node.h"

/**
 * AST node for multi-dimensional array literal.
 */
class JaggedArrayNode : public ArrayNode {
 public:
  JaggedArrayNode() = delete;
  JaggedArrayNode(const Position &pos, const std::vector<std::unique_ptr<ArrayNode>> &elements)
      : ArrayNode(pos), elements_(elements) {}

 private:
  std::vector<std::unique_ptr<ArrayNode>> elements_;
};