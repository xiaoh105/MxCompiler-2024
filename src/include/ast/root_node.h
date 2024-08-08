/*
 * Mx Compiler
 * File Name: root_node.h
 * Identification: ./src/include/ast/root_node.h
 * Function: The root node of the whole AST
 */
#pragma once

#include "ast/ast_node.h"
#include "ast/def_node/def_node.h"
#include "ast/stmt_node/stmt_node.h"

class RootNode : public ASTNode {
 public:
  RootNode() = delete;
  RootNode(Position pos, std::shared_ptr<StmtNode> main_func, std::vector<std::shared_ptr<DefNode>> definitions)
      : ASTNode(std::move(pos)), main_func_body_(std::move(main_func)), def_nodes_(std::move(definitions)) {}
  std::shared_ptr<StmtNode> &GetMainFunction() { return main_func_body_; }
  std::vector<std::shared_ptr<DefNode>> &GetDefNodes() { return def_nodes_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<StmtNode> main_func_body_{nullptr};
  std::vector<std::shared_ptr<DefNode>> def_nodes_{};
};