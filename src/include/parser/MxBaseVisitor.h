
// Generated from Mx.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "MxVisitor.h"


/**
 * This class provides an empty implementation of MxVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MxBaseVisitor : public MxVisitor {
public:

  virtual std::any visitProgram(MxParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMainFunc(MxParser::MainFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDef(MxParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberDefStmt(MxParser::MemberDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructorDefStmt(MxParser::ConstructorDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDefStmt(MxParser::FuncDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(MxParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(MxParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefStmt(MxParser::VarDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuiteStmt(MxParser::SuiteStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(MxParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(MxParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(MxParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatStmt(MxParser::FormatStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomicStmt(MxParser::AtomicStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(MxParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncCallStmt(MxParser::FuncCallStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptStmt(MxParser::SubscriptStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryStmt(MxParser::UnaryStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryStmt(MxParser::BinaryStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberStmt(MxParser::MemberStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTenaryStmt(MxParser::TenaryStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(MxParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(MxParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenPrimary(MxParser::ParenPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralPrimary(MxParser::LiteralPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarPrimary(MxParser::VarPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThisPrimary(MxParser::ThisPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewPrimary(MxParser::NewPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalLiteral(MxParser::DecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolLiteral(MxParser::BoolLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(MxParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullLiteral(MxParser::NullLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLiteral(MxParser::ArrayLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(MxParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(MxParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }


};

