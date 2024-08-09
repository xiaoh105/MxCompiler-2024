/*
 * Mx Compiler
 * File Name: simple_array_node.h
 * Identification: ./src/include/ast/array_node/simple_array_node.h
 * Function: AST node for one dimensional array literal
 */
#pragma once

#include "ast/array_node/array_node.h"
#include "ast/primary_node/literal_primary_node.h"

/**
 * AST node for one dimensional array literal.
 */
class SimpleArrayNode : public ArrayNode {
 public:
  SimpleArrayNode() = delete;
  SimpleArrayNode(Position pos, std::vector<std::shared_ptr<PrimaryNode>> elements)
      : ArrayNode(std::move(pos)), elements_(std::move(elements)) {}
  std::vector<std::shared_ptr<PrimaryNode>> &GetElements() { return elements_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::vector<std::shared_ptr<PrimaryNode>> elements_;
};
