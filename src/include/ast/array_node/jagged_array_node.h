/*
 * Mx Compiler
 * File Name: simple_array_node.h
 * Identification: ./src/include/ast/array_node/simple_array_node.h
 * Function: AST node for multi-dimensional array literal.
 */
#pragma once

#include "ast/array_node/array_node.h"
#include "ast/ast_visitor.h"

/**
 * AST node for multi-dimensional array literal.
 */
class JaggedArrayNode : public ArrayNode {
 public:
  JaggedArrayNode() = delete;
  JaggedArrayNode(Position pos, std::vector<std::shared_ptr<ArrayNode>> elements)
      : ArrayNode(std::move(pos)), elements_(std::move(elements)) {}
  std::vector<std::shared_ptr<ArrayNode>> &GetElements() { return elements_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::vector<std::shared_ptr<ArrayNode>> elements_;
};