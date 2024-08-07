/*
 * Mx Compiler
 * File Name: new_primary_node.h
 * Identification: ./src/include/ast/primary_node/new_primary_node.h
 * Function: AST node for all kinds of 'new' statements
 */
#pragma once

#include "ast/array_node/array_node.h"
#include "ast/expr_node/expr_node.h"
#include "ast/primary_node/primary_node.h"

/**
 * AST node for all kinds of 'new' statements
 */
class NewPrimaryNode : public PrimaryNode {
  enum class NewType : int { kUnknown = 0, kNewVar, kNewArray, kNewArrayLiteral };

 public:
  NewPrimaryNode() = delete;
  NewPrimaryNode(Position pos, std::string type_name)
      : PrimaryNode(std::move(pos)), new_type_(NewType::kNewVar), type_name_(std::move(type_name)) {
    null_ = false;
    lvalue_ = false;
  }
  NewPrimaryNode(Position pos, std::string type_name, std::unique_ptr<ArrayNode> array_literal)
      : PrimaryNode(std::move(pos)),
        new_type_(NewType::kNewArrayLiteral),
        type_name_(std::move(type_name)),
        dim_(1),
        array_literal_(std::move(array_literal)) {
    null_ = false;
    lvalue_ = false;
  }
  NewPrimaryNode(Position pos, std::string type_name, std::size_t dim, std::vector<std::unique_ptr<ExprNode>> expr)
      : PrimaryNode(std::move(pos)),
        new_type_(NewType::kNewArray),
        type_name_(std::move(type_name)),
        dim_(dim),
        expression_(std::move(expr)) {
    null_ = false;
    lvalue_ = false;
  }
  [[nodiscard]] NewType GetNewType() const { return new_type_; }
  [[nodiscard]] const std::string &GetTypename() const { return type_name_; }
  std::unique_ptr<ArrayNode> &GetArrayLiteral() { return array_literal_; }
  [[nodiscard]] std::size_t GetDim() const { return dim_; }
  std::vector<std::unique_ptr<ExprNode>> &GetExpressions() { return expression_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  NewType new_type_{kUnknown};
  const std::string type_name_{};
  std::unique_ptr<ArrayNode> array_literal_{nullptr};
  std::size_t dim_{};
  std::vector<std::unique_ptr<ExprNode>> expression_;
};