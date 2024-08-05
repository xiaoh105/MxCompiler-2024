
// Generated from Mx.g4 by ANTLR 4.13.1

#pragma once

#include "parser/MxParser.h"
#include "antlr4-runtime.h"

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MxParser.
 */
class MxVisitor : public antlr4::tree::AbstractParseTreeVisitor {
 public:
  /**
   * Visit parse trees produced by MxParser.
   */
  virtual std::any visitProgram(MxParser::ProgramContext *context) = 0;

  virtual std::any visitMainFunc(MxParser::MainFuncContext *context) = 0;

  virtual std::any visitClassDef(MxParser::ClassDefContext *context) = 0;

  virtual std::any visitMemberDefStmt(MxParser::MemberDefStmtContext *context) = 0;

  virtual std::any visitConstructorDefStmt(MxParser::ConstructorDefStmtContext *context) = 0;

  virtual std::any visitFuncDefStmt(MxParser::FuncDefStmtContext *context) = 0;

  virtual std::any visitFuncDef(MxParser::FuncDefContext *context) = 0;

  virtual std::any visitVarDef(MxParser::VarDefContext *context) = 0;

  virtual std::any visitVarDefStmt(MxParser::VarDefStmtContext *context) = 0;

  virtual std::any visitSuiteStmt(MxParser::SuiteStmtContext *context) = 0;

  virtual std::any visitExprStmt(MxParser::ExprStmtContext *context) = 0;

  virtual std::any visitIfStmt(MxParser::IfStmtContext *context) = 0;

  virtual std::any visitWhileStmt(MxParser::WhileStmtContext *context) = 0;

  virtual std::any visitForStmt(MxParser::ForStmtContext *context) = 0;

  virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *context) = 0;

  virtual std::any visitBreakStmt(MxParser::BreakStmtContext *context) = 0;

  virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *context) = 0;

  virtual std::any visitFormatStmt(MxParser::FormatStmtContext *context) = 0;

  virtual std::any visitAtomicStmt(MxParser::AtomicStmtContext *context) = 0;

  virtual std::any visitAssignStmt(MxParser::AssignStmtContext *context) = 0;

  virtual std::any visitFuncCallStmt(MxParser::FuncCallStmtContext *context) = 0;

  virtual std::any visitSubscriptStmt(MxParser::SubscriptStmtContext *context) = 0;

  virtual std::any visitUnaryStmt(MxParser::UnaryStmtContext *context) = 0;

  virtual std::any visitBinaryStmt(MxParser::BinaryStmtContext *context) = 0;

  virtual std::any visitMemberStmt(MxParser::MemberStmtContext *context) = 0;

  virtual std::any visitTenaryStmt(MxParser::TenaryStmtContext *context) = 0;

  virtual std::any visitSuite(MxParser::SuiteContext *context) = 0;

  virtual std::any visitArguments(MxParser::ArgumentsContext *context) = 0;

  virtual std::any visitParenPrimary(MxParser::ParenPrimaryContext *context) = 0;

  virtual std::any visitLiteralPrimary(MxParser::LiteralPrimaryContext *context) = 0;

  virtual std::any visitVarPrimary(MxParser::VarPrimaryContext *context) = 0;

  virtual std::any visitThisPrimary(MxParser::ThisPrimaryContext *context) = 0;

  virtual std::any visitNewPrimary(MxParser::NewPrimaryContext *context) = 0;

  virtual std::any visitArray(MxParser::ArrayContext *context) = 0;

  virtual std::any visitDecimalLiteral(MxParser::DecimalLiteralContext *context) = 0;

  virtual std::any visitBoolLiteral(MxParser::BoolLiteralContext *context) = 0;

  virtual std::any visitStringLiteral(MxParser::StringLiteralContext *context) = 0;

  virtual std::any visitNullLiteral(MxParser::NullLiteralContext *context) = 0;

  virtual std::any visitArrayLiteral(MxParser::ArrayLiteralContext *context) = 0;

  virtual std::any visitType(MxParser::TypeContext *context) = 0;
};
