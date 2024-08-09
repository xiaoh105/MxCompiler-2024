/*
 * Mx Compiler
 * File Name: ast_builder.h
 * Identification: ./src/include/frontend/ast_builder.h
 * Function: Use parser tree to build Abstract Semantic Tree
 */
#pragma once

#include "parser/MxBaseVisitor.h"

class ASTBuilder : MxBaseVisitor {
 public:
  // Returns std::shared_ptr<RootNode> as the root for the entire AST
  std::any visitProgram(MxParser::ProgramContext *ctx) override;
  // Returns std::shared_ptr<StmtNode> as the function body
  std::any visitMainFunc(MxParser::MainFuncContext *ctx) override;
  // Returns std::shared_ptr<DefNode>
  std::any visitClassDef(MxParser::ClassDefContext *ctx) override;
  // Returns std::shared_ptr<ClassStmtNode>
  std::any visitMemberDefStmt(MxParser::MemberDefStmtContext *ctx) override;
  // Returns std::shared_ptr<ClassStmtNode>
  std::any visitConstructorDefStmt(MxParser::ConstructorDefStmtContext *ctx) override;
  // Returns std::shared_ptr<ClassStmtNode>
  std::any visitFuncDefStmt(MxParser::FuncDefStmtContext *ctx) override;
  // Returns std::shared_ptr<DefNode>
  std::any visitFuncDef(MxParser::FuncDefContext *ctx) override;
  // Returns std::shared_ptr<DefNode>
  std::any visitVarDef(MxParser::VarDefContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitVarDefStmt(MxParser::VarDefStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitSuiteStmt(MxParser::SuiteStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitExprStmt(MxParser::ExprStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitIfStmt(MxParser::IfStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitForStmt(MxParser::ForStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override;
  // Returns std::shared_ptr<StmtNode>
  std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitAtomicExpr(MxParser::AtomicExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitUnaryExpr(MxParser::UnaryExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitSubscriptExpr(MxParser::SubscriptExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitTenaryExpr(MxParser::TenaryExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitMemberExpr(MxParser::MemberExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitFormatExpr(MxParser::FormatExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitFuncCallExpr(MxParser::FuncCallExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitSuite(MxParser::SuiteContext *ctx) override;
  // Returns std::vector<std::shared_ptr<ExprNode>>
  std::any visitArguments(MxParser::ArgumentsContext *ctx) override;
  // Returns std::shared_ptr<ExprNode>
  std::any visitParenExpr(MxParser::ParenExprContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitLiteralPrimary(MxParser::LiteralPrimaryContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitVarPrimary(MxParser::VarPrimaryContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitThisPrimary(MxParser::ThisPrimaryContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitNewPrimary(MxParser::NewPrimaryContext *ctx) override;
  // Returns std::shared_ptr<ArrayNode>
  std::any visitArray(MxParser::ArrayContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitDecimalLiteral(MxParser::DecimalLiteralContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitBoolLiteral(MxParser::BoolLiteralContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitStringLiteral(MxParser::StringLiteralContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitNullLiteral(MxParser::NullLiteralContext *ctx) override;
  // Returns std::shared_ptr<PrimaryNode>
  std::any visitArrayLiteral(MxParser::ArrayLiteralContext *ctx) override;
  // Returns std::string representing the typename
  std::any visitType(MxParser::TypeContext *ctx) override;
};