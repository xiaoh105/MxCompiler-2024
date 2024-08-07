/*
 * Mx Compiler
 * File Name: function_def_node.h
 * Identification: ./src/include/ast/def_node/function_def_node.h
 * Function: AST node for function definitions
 */
#pragma once

#include "ast/def_node/def_node.h"

/**
 * AST node for function definitions
 */
class FunctionDefNode : public DefNode {
public:
 FunctionDefNode() = delete;
 FunctionDefNode(const Position &pos, const std::string &function_name, const std::string &return_type,
                 std::vector<std::pair<std::string, std::string>> arguments, std::unique_ptr<StmtNode> suite)
     : DefNode(pos),
       function_name_(function_name),
       return_type_{return_type},
       arguments_(std::move(arguments)),
       function_body_(std::move(suite)) {}
  [[nodiscard]] const std::string &GetFunctionName() const { return function_name_; }
  [[nodiscard]] const std::string &GetReturnType() const { return return_type_; }
  [[nodiscard]] const std::vector<std::pair<std::string, std::string>> &GetArguments() const { return arguments_; }
  std::unique_ptr<StmtNode> &GetFunctionBody() { return function_body_; }

 private:
  const std::string function_name_;
  const std::string return_type_;
  std::vector<std::pair<std::string, std::string>> arguments_;
  std::unique_ptr<StmtNode> function_body_{nullptr};
};