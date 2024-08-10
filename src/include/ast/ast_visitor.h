/*
 * Mx Compiler
 * File Name: ast_visitor.h
 * Identification: ./src/include/ast/ast_visitor.h
 * Function: Regulates the behaviour of all AST visitors.
 */
#pragma once

class ASTNode;
class RootNode;
class JaggedArrayNode;
class SimpleArrayNode;
class ClassDefNode;
class FunctionDefNode;
class VarDefNode;
class AssignExprNode;
class AtomExprNode;
class BinaryExprNode;
class FormatExprNode;
class FunctionCallExprNode;
class MemberExprNode;
class SubscriptExprNode;
class TenaryExprNode;
class UnaryExprNode;
class LiteralPrimaryNode;
class NewPrimaryNode;
class ThisPrimaryNode;
class VarPrimaryNode;
class ControlStmtNode;
class EmptyStmtNode;
class ExprStmtNode;
class ForStmtNode;
class IfStmtNode;
class SuiteStmtNode;
class VarDefStmtNode;
class WhileStmtNode;
class ConstructorClassStmtNode;
class FunctionDefClassStmtNode;
class VarDefClassStmtNode;

/**
 * A virtual class regulating all AST visitors.
 */
class ASTVisitor {
 public:
  virtual ~ASTVisitor() = default;
  virtual void visit(RootNode *node) = 0;
  virtual void visit(JaggedArrayNode *node) = 0;
  virtual void visit(SimpleArrayNode *node) = 0;
  virtual void visit(ClassDefNode *node) = 0;
  virtual void visit(FunctionDefNode *node) = 0;
  virtual void visit(VarDefNode *node) = 0;
  virtual void visit(AssignExprNode *node) = 0;
  virtual void visit(AtomExprNode *node) = 0;
  virtual void visit(BinaryExprNode *node) = 0;
  virtual void visit(FormatExprNode *node) = 0;
  virtual void visit(FunctionCallExprNode *node) = 0;
  virtual void visit(MemberExprNode *node) = 0;
  virtual void visit(SubscriptExprNode *node) = 0;
  virtual void visit(TenaryExprNode *node) = 0;
  virtual void visit(UnaryExprNode *node) = 0;
  virtual void visit(LiteralPrimaryNode *node) = 0;
  virtual void visit(NewPrimaryNode *node) = 0;
  virtual void visit(ThisPrimaryNode *node) = 0;
  virtual void visit(VarPrimaryNode *node) = 0;
  virtual void visit(ControlStmtNode *node) = 0;
  virtual void visit(EmptyStmtNode *node) = 0;
  virtual void visit(ExprStmtNode *node) = 0;
  virtual void visit(ForStmtNode *node) = 0;
  virtual void visit(IfStmtNode *node) = 0;
  virtual void visit(SuiteStmtNode *node) = 0;
  virtual void visit(VarDefStmtNode *node) = 0;
  virtual void visit(WhileStmtNode *node) = 0;
  virtual void visit(ConstructorClassStmtNode *node) = 0;
  virtual void visit(FunctionDefClassStmtNode *node) = 0;
  virtual void visit(VarDefClassStmtNode *node) = 0;
};