/*
 * Mx Compiler
 * File Name: literal_primary_node.h
 * Identification: ./src/include/ast/primary_node/literal_primary_node.h
 * Function: AST node for all kinds of literals.
 */
#pragma once

#include <variant>

#include "ast/primary_node/primary_node.h"

/**
 * AST node for all kinds of literals
 */
class LiteralPrimaryNode : public PrimaryNode {
 public:
  enum LiteralType : int { kUnknown = 0, kInt, kBool, kString, kNull, kArray };
  LiteralPrimaryNode() = delete;
  // Constructor when the literal is null
  LiteralPrimaryNode(Position pos) : PrimaryNode(std::move(pos)), literal_type_(kNull) {}
  // Constructor when the literal is a decimal number
  LiteralPrimaryNode(Position pos, int val) : PrimaryNode(std::move(pos)), literal_type_(kInt), value_(val) {}
  // Constructor when the literal is a bool
  LiteralPrimaryNode(Position pos, bool val) : PrimaryNode(std::move(pos)), literal_type_(kBool), value_(val) {}
  // Constructor when the literal is a string
  LiteralPrimaryNode(Position pos, std::string str)
      : PrimaryNode(std::move(pos)), literal_type_(kString), value_(std::move(str)) {}
  // Constructor when the literal is an array literal
  LiteralPrimaryNode(Position pos, std::shared_ptr<ArrayNode> array)
      : PrimaryNode(std::move(pos)), literal_type_(kArray), value_(std::move(array)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  void Initialize() {
    lvalue_ = false;
    null_ = literal_type_ == kNull;
  }
  const LiteralType literal_type_{kUnknown};
  std::variant<int, bool, std::string, std::shared_ptr<ArrayNode>> value_{};
};