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
 */
class PrimaryNode : public ASTNode {
 public:
  PrimaryNode() = delete;
  PrimaryNode(const Position &pos) : ASTNode(pos) {}
  [[nodiscard]] bool IsAssignable() const { return lvalue_; }
  // Return the type of the node, nullptr for 'null'.
  [[nodiscard]] const std::unique_ptr<Type> &GetType() const {
    if (!null_ && type_ == nullptr) {
      throw std::runtime_error("Fetch type from Primary Node whose type is undetermined");
    }
    return type_;
  }

 protected:
  // The type of the node, nullptr for 'null'.
  std::unique_ptr<Type> type_{nullptr};
  bool lvalue_{false};
  bool null_{false};
};