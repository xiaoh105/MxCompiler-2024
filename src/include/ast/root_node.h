/*
 * Mx Compiler
 * File Name: root_node.h
 * Identification: ./src/include/ast/root_node.h
 * Function: The root node of the whole AST
 */
#pragma once

#include "ast/ast_node.h"

class RootNode : public ASTNode {
 public:
  RootNode() = delete;
  RootNode(const Position &pos, std::unique_ptr<StmtNode> main_func, std::vector<std::unique_ptr<DefNode>> definitions)
      : ASTNode(pos), main_func_body_(std::move(main_func)), def_nodes_(std::move(definitions)) {}
  std::unique_ptr<StmtNode> &GetMainFunction() { return main_func_body_; }
  std::vector<std::unique_ptr<DefNode>> &GetDefNodes() { return def_nodes_; }

 private:
  std::unique_ptr<StmtNode> main_func_body_{nullptr};
  std::vector<std::unique_ptr<DefNode>> def_nodes_{};
};