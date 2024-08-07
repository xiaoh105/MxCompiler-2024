/*
 * Mx Compiler
 * File Name: primary_node.h
 * Identification: ./src/include/ast/primary_node/primary_node.h
 * Function: Regulating AST node for atomic expressions. Corresponding to the 'primary' rule in Mx.g4.
 */
#pragma once

#include "ast/ast_node.h"
#include "utils/scope/type.h"

/**
 * AST node for atomic expressions.
 * Note: In this class (and its deriving classes), you need to manage member type_ manually during semantic check,
 * lvalue_ and null_ is automatically set.
 */
class PrimaryNode : public ASTNode {
 public:
  PrimaryNode() = delete;
  PrimaryNode(Position pos) : ASTNode(std::move(pos)) {}
  [[nodiscard]] bool IsAssignable() const { return lvalue_; }
  // Return the type of the node, nullptr for 'null'.
  [[nodiscard]] const std::unique_ptr<Type> &GetType() const {
    if (!null_ && type_ == nullptr) {
      throw std::runtime_error("Fetch type from Primary Node whose type is undetermined");
    }
    return type_;
  }
  void SetType(std::unique_ptr<Type> type) {
    if (type_ != nullptr) {
      throw std::runtime_error("Trying to set type to Primary Node that already has a type");
    }
    type_ = std::move(type);
  }

 protected:
  // The type of the node, nullptr for 'null'.
  std::unique_ptr<Type> type_{nullptr};
  bool lvalue_{false};
  bool null_{false};
};