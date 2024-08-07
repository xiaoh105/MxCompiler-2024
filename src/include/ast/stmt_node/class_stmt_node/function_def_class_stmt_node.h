/*
 * Mx Compiler
 * File Name: function_def_class_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/class_stmt_node/function_def_class_stmt_node.h
 * Function: AST node for method definition in classes
 */
#pragma once

#include "ast/stmt_node/class_stmt_node/class_stmt_node.h"

/**
 * AST node for method definition in classes
 */
class FunctionDefClassStmtNode : public ClassStmtNode {
 public:
  FunctionDefClassStmtNode() = delete;
  FunctionDefClassStmtNode(const Position &pos, const std::string &name, const std::string &return_type,
                           std::vector<std::pair<std::string, std::string>> arguments, std::unique_ptr<StmtNode> suite)
      : ClassStmtNode(pos),
        name_(name),
        return_type_(return_type),
        arguments_(std::move(arguments)),
        function_body_(std::move(suite)) {}

 private:
  const std::string name_;
  const std::string return_type_;
  std::vector<std::pair<std::string, std::string>> arguments_;
  std::unique_ptr<StmtNode> function_body_{nullptr};
};