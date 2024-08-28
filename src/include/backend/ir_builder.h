/*
 * Mx Compiler
 * File Name: ir_builder.h
 * Identification: ./src/include/backend/ir_builder.h
 * Function: Use the AST to build the IR tree
 */
#pragma once

#include "ast/ast.h"
#include "ast/ast_visitor.h"
#include "ir/ir.h"

class GlobalScope;

void GenerateIR(RootNode *root);

class IRBuilder final : public ASTVisitor {
  friend void GenerateIR(RootNode *root);
  friend void GenerateAsm(RootNode *root);
 public:
  IRBuilder(GlobalScope global_scope);
  void visit(RootNode *node) override;
  void visit(JaggedArrayNode *node) override;
  void visit(SimpleArrayNode *node) override;
  void visit(ClassDefNode *node) override;
  void visit(FunctionDefNode *node) override;
  void visit(VarDefNode *node) override;
  void visit(AssignExprNode *node) override;
  void visit(AtomExprNode *node) override;
  void visit(BinaryExprNode *node) override;
  void visit(FormatExprNode *node) override;
  void visit(FunctionCallExprNode *node) override;
  void visit(MemberExprNode *node) override;
  void visit(SubscriptExprNode *node) override;
  void visit(TenaryExprNode *node) override;
  void visit(UnaryExprNode *node) override;
  void visit(LiteralPrimaryNode *node) override;
  void visit(NewPrimaryNode *node) override;
  void visit(ThisPrimaryNode *node) override;
  void visit(VarPrimaryNode *node) override;
  void visit(ControlStmtNode *node) override;
  void visit(EmptyStmtNode *node) override;
  void visit(ExprStmtNode *node) override;
  void visit(ForStmtNode *node) override;
  void visit(IfStmtNode *node) override;
  void visit(SuiteStmtNode *node) override;
  void visit(VarDefStmtNode *node) override;
  void visit(WhileStmtNode *node) override;
  void visit(ConstructorClassStmtNode *node) override;
  void visit(FunctionDefClassStmtNode *node) override;
  void visit(VarDefClassStmtNode *node) override;

 private:
  std::shared_ptr<Register> CreateArray(std::size_t cur_dim, const std::shared_ptr<IRBaseType> &type,
                                        const std::vector<std::shared_ptr<ExprNode>> &expr, std::size_t dim);
  std::shared_ptr<Var> ToRightVal(const std::shared_ptr<Var> &var);
  std::shared_ptr<IRFunction> cur_func_{nullptr};
  std::shared_ptr<IRFunction> init_func_{nullptr};
  ClassManager classes_;
  FunctionManager functions_;
  VarManager vars_;

  std::stack<std::shared_ptr<Block>> loop_step_;
  std::stack<std::shared_ptr<Block>> loop_end_;
  std::shared_ptr<IRBaseType> cur_type_{nullptr};

  int zext_cnt_{0};
  int trunc_cnt_{0};
};