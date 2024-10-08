/*
 * Mx Compiler
 * File Name: expr_node.h
 * Identification: ./src/include/ast/expr_node/expr_node.h
 * Function: Regulates the behaviour of AST expression nodes.
 */
#pragma once

#include "ast/ast_node.h"
#include "utils/scope/type.h"

class Var;

/**
 * Virtual class regulating the behaviour of AST expression nodes
 * Note: In this class (and its deriving classes), you need to manage type_, lvalue_ and null_ manually during semantic
 * check.
 */
class ExprNode : public ASTNode {
 public:
  ExprNode(Position position) : ASTNode(std::move(position)) {}
  [[nodiscard]] bool IsAssignable() const { return lvalue_; }
  [[nodiscard]] bool IsNull() const { return null_; }
  /// Returns the pointer to the type, nullptr for 'null'
  [[nodiscard]] const std::shared_ptr<Type> &GetType() const {
    if (!null_ && type_ == nullptr) {
      throw std::runtime_error("Trying to fetch Type from an ExprNode with undetermined type");
    }
    return type_;
  }
  void SetType(std::shared_ptr<Type> type) {
    if (type_ != nullptr) {
      throw std::runtime_error("Trying to set type to a node that already has a type");
    }
    type_ = std::move(type);
  }
  void SetAssignable(bool assignable) { lvalue_ = assignable; }
  void SetNull(bool is_null) { null_ = is_null; }
  void SetVar(std::shared_ptr<Var> value) { value_ = std::move(value); }
  [[nodiscard]] const std::shared_ptr<Var> &GetVar() const { return value_; }

 protected:
  // The type of the node, nullptr for 'null' literal
  std::shared_ptr<Type> type_{nullptr};
  bool lvalue_{false};
  bool null_{false};

  std::shared_ptr<Var> value_{nullptr};
};