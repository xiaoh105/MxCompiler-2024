/*
 * Mx Compiler
 * File Name: suite_stmt_node.h
 * Identification: ./src/include/ast/stmt_node/suite_stmt_node.h
 * Function: AST node for suite statements
 */
#pragma once

#include "ast/stmt_node/stmt_node.h"

/**
 * AST node for suite statements (i.e. Block of statements inside a pair of '{' '}')
 */
class SuiteStmtNode : public StmtNode {
 public:
  SuiteStmtNode() = delete;
  SuiteStmtNode(const Position &pos, std::vector<std::unique_ptr<StmtNode>> statements)
      : StmtNode(pos), statements_(std::move(statements)) {}
  std::vector<std::unique_ptr<StmtNode>> &GetStatements() { return statements_; }

 private:
  std::vector<std::unique_ptr<StmtNode>> statements_;
};