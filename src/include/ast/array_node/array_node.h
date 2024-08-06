/*
 * Mx Compiler
 * File Name: array_node.h
 * Identification: ./src/include/ast/array_node/array_node.h
 * Function: Regulating AST node for array literals.
 */
#pragma once

#include "ast/ast_node.h"

/**
 * Virtual class for regulating AST node for array literals.
 */
class ArrayNode : public ASTNode {
 public:
  ArrayNode() = delete;
  ArrayNode(const Position &pos) : ASTNode(pos) {}
  [[nodiscard]] const std::shared_ptr<Type> &GetType() const {
    if (type_ == nullptr) {
      throw std::runtime_error("Fetching type from Array Node with undetermined type");
    }
    return type_;
  }

 private:
  // type_ MUST NOT be nullptr since 'null' can't appear in string literals
  std::shared_ptr<Type> type_{nullptr};
};