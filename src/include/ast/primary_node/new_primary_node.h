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
  NewPrimaryNode(const Position &pos, const std::string &type_name)
      : PrimaryNode(pos), new_type_(NewType::kNewVar), type_name_(type_name) {
    null_ = false;
    lvalue_ = false;
  }
  NewPrimaryNode(const Position &pos, const std::string &type_name, std::size_t dim)
      : PrimaryNode(pos), new_type_(NewType::kNewArray), type_name_(type_name), dim_(dim) {
    null_ = false;
    lvalue_ = false;
  }
  NewPrimaryNode(const Position &pos, const std::string &type_name, std::size_t dim,
                 const std::vector<std::shared_ptr<ExprNode>> &expr)
      : PrimaryNode(pos), new_type_(NewType::kNewArrayLiteral), type_name_(type_name), dim_(dim), expression_(expr) {
    null_ = false;
    lvalue_ = false;
  }

 private:
  NewType new_type_{kUnknown};
  const std::string &type_name_{};
  std::shared_ptr<ArrayNode> array_literal_{nullptr};
  std::size_t dim_{};
  std::vector<std::shared_ptr<ExprNode>> expression_;
};