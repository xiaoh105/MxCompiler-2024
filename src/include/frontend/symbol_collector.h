/*
 * Mx Compiler
 * File Name: symbol_collector.h
 * Identification: ./src/include/frontend/symbol_collector.h
 * Function: Scan the parser tree and collect all global symbols
 */
#pragma once

#include "ast/ast_visitor.h"
#include "utils/scope/scope.h"

std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node);

class SymbolCollector : public ASTVisitor {
  friend std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node);

 public:
  SymbolCollector();
  void CollectClass(RootNode *node);
  void visit(RootNode *node) override;

 private:
  void visit(JaggedArrayNode *node) final {}
  void visit(SimpleArrayNode *node) final {}
  void visit(ClassDefNode *node) final;
  void visit(FunctionDefNode *node) final;
  void visit(VarDefNode *node) final {}
  void visit(AssignExprNode *node) final {}
  void visit(AtomExprNode *node) final {}
  void visit(BinaryExprNode *node) final {}
  void visit(FormatExprNode *node) final {}
  void visit(FunctionCallExprNode *node) final {}
  void visit(MemberExprNode *node) final {}
  void visit(SubscriptExprNode *node) final {}
  void visit(TenaryExprNode *node) final {}
  void visit(UnaryExprNode *node) final {}
  void visit(LiteralPrimaryNode *node) final {}
  void visit(NewPrimaryNode *node) final {}
  void visit(ThisPrimaryNode *node) final {}
  void visit(VarPrimaryNode *node) final {}
  void visit(ControlStmtNode *node) final {}
  void visit(EmptyStmtNode *node) final {}
  void visit(ExprStmtNode *node) final {}
  void visit(ForStmtNode *node) final {}
  void visit(IfStmtNode *node) final {}
  void visit(SuiteStmtNode *node) final {}
  void visit(VarDefStmtNode *node) final {}
  void visit(WhileStmtNode *node) final {}
  void visit(ConstructorClassStmtNode *node) final;
  void visit(FunctionDefClassStmtNode *node) final;
  void visit(VarDefClassStmtNode *node) final;
  Scope scope_;
  GlobalScope global_scope_;
  std::shared_ptr<Typename> current_class_;
};
