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

class Register;

/**
 * Virtual class for regulating AST node for array literals.
 */
class ArrayNode : public ASTNode {
 public:
  ArrayNode() = delete;
  ArrayNode(Position pos) : ASTNode(std::move(pos)) {}
  [[nodiscard]] const std::shared_ptr<Type> &GetType() const { return type_; }
  void SetType(std::shared_ptr<Type> type) { type_ = std::move(type); }
  void SetVar(std::shared_ptr<Register> value) { value_ = std::move(value); }
  [[nodiscard]] const std::shared_ptr<Register> &GetVar() const { return value_; }

 private:
  // type_ MUST NOT be nullptr since 'null' can't appear in string literals
  std::shared_ptr<Type> type_{nullptr};
  std::shared_ptr<Register> value_{nullptr};
};