/*
 * Mx Compiler
 * File Name: expr_node.h
 * Identification: ./src/include/ast/expr_node/expr_node.h
 * Function: Regulates the behaviour of AST expression nodes.
 */
#pragma once

#include "ast/ast_node.h"
#include "utils/scope/type.h"

/**
 * Virtual class regulating the behaviour of AST expression nodes
 */
class ExprNode : public ASTNode {
 public:
  ExprNode(const Position &position) : ASTNode(position) {}
  [[nodiscard]] bool IsAssignable() const { return lvalue_; }
  /// Returns the pointer to the type, nullptr for 'null'
  [[nodiscard]] const Type &GetType() const {
    if (!null_ && type_ == nullptr) {
      throw std::runtime_error("Trying to fetch Type from an ExprNode with undetermined type");
    }
    return *type_;
  }

 protected:
  // The type of the node, nullptr for 'null' literal
  std::shared_ptr<Type> type_{nullptr};
  bool lvalue_{false};
  bool null_{false};
};