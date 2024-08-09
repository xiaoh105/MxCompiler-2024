/*
 * Mx Compiler
 * File Name: array_node.h
 * Identification: ./src/include/ast/array_node/array_node.h
 * Function: Regulating AST node for array literals.
 */
#pragma once

#include <memory>

#include "ast/ast_node.h"
#include "utils/scope/type.h"

class ASTNode;

/**
 * Virtual class for regulating AST node for array literals.
 */
class ArrayNode : public ASTNode {
 public:
  ArrayNode() = delete;
  ArrayNode(Position pos) : ASTNode(std::move(pos)) {}
  [[nodiscard]] const std::shared_ptr<Type> &GetType() const {
    if (type_ == nullptr) {
      throw std::runtime_error("Fetching type from Array Node with undetermined type");
    }
    return type_;
  }
  void SetType(std::shared_ptr<Type> type) { type_ = std::move(type); }

 private:
  // type_ MUST NOT be nullptr since 'null' can't appear in string literals
  std::shared_ptr<Type> type_{nullptr};
};