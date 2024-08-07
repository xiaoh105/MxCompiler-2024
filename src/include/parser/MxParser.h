
// Generated from Mx.g4 by ANTLR 4.13.1

#pragma once

#include "antlr4-runtime.h"

class MxParser : public antlr4::Parser {
 public:
  enum {
    T__0 = 1,
    T__1 = 2,
    FormatQuatation = 3,
    Quotation = 4,
    True = 5,
    False = 6,
    DecimalNumber = 7,
    StringLiteral = 8,
    FormatStringLiteral = 9,
    Null = 10,
    New = 11,
    Class = 12,
    This = 13,
    If = 14,
    Else = 15,
    For = 16,
    While = 17,
    Break = 18,
    Continue = 19,
    Return = 20,
    Bool = 21,
    Int = 22,
    Void = 23,
    String = 24,
    Identifier = 25,
    Add = 26,
    Sub = 27,
    Mul = 28,
    Div = 29,
    Mod = 30,
    Less = 31,
    LessEqual = 32,
    Greater = 33,
    GreaterEqual = 34,
    Equal = 35,
    UnEqual = 36,
    AndLogic = 37,
    OrLogic = 38,
    NotLogic = 39,
    ShiftRight = 40,
    ShiftLeft = 41,
    And = 42,
    Or = 43,
    Xor = 44,
    Not = 45,
    Assign = 46,
    Increment = 47,
    Decrement = 48,
    Dot = 49,
    LeftParen = 50,
    RightParen = 51,
    LeftBracket = 52,
    RightBracket = 53,
    LeftBrace = 54,
    RightBrace = 55,
    Dollar = 56,
    Question = 57,
    Colon = 58,
    Semicolon = 59,
    Comma = 60,
    Whitespace = 61,
    LineComment = 62,
    BlockComment = 63
  };

  enum {
    RuleProgram = 0,
    RuleMainFunc = 1,
    RuleClassDef = 2,
    RuleClassStmt = 3,
    RuleFuncDef = 4,
    RuleVarDef = 5,
    RuleStatement = 6,
    RuleExpression = 7,
    RuleSuite = 8,
    RuleArguments = 9,
    RulePrimary = 10,
    RuleArray = 11,
    RuleLiteral = 12,
    RuleType = 13
  };

  explicit MxParser(antlr4::TokenStream *input);

  MxParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MxParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN &getATN() const override;

  const std::vector<std::string> &getRuleNames() const override;

  const antlr4::dfa::Vocabulary &getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  class ProgramContext;
  class MainFuncContext;
  class ClassDefContext;
  class ClassStmtContext;
  class FuncDefContext;
  class VarDefContext;
  class StatementContext;
  class ExpressionContext;
  class SuiteContext;
  class ArgumentsContext;
  class PrimaryContext;
  class ArrayContext;
  class LiteralContext;
  class TypeContext;

  class ProgramContext : public antlr4::ParserRuleContext {
   public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainFuncContext *mainFunc();
    std::vector<ClassDefContext *> classDef();
    ClassDefContext *classDef(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext *funcDef(size_t i);
    std::vector<VarDefContext *> varDef();
    VarDefContext *varDef(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgramContext *program();

  class MainFuncContext : public antlr4::ParserRuleContext {
   public:
    MainFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SuiteContext *suite();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MainFuncContext *mainFunc();

  class ClassDefContext : public antlr4::ParserRuleContext {
   public:
    antlr4::Token *classIdentifier = nullptr;
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *Identifier();
    std::vector<ClassStmtContext *> classStmt();
    ClassStmtContext *classStmt(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ClassDefContext *classDef();

  class ClassStmtContext : public antlr4::ParserRuleContext {
   public:
    ClassStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ClassStmtContext() = default;
    void copyFrom(ClassStmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class MemberDefStmtContext : public ClassStmtContext {
   public:
    MemberDefStmtContext(ClassStmtContext *ctx);

    MxParser::TypeContext *memberType = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode *Identifier(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ConstructorDefStmtContext : public ClassStmtContext {
   public:
    ConstructorDefStmtContext(ClassStmtContext *ctx);

    antlr4::Token *classIdentifier = nullptr;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    antlr4::tree::TerminalNode *Identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class FuncDefStmtContext : public ClassStmtContext {
   public:
    FuncDefStmtContext(ClassStmtContext *ctx);

    MxParser::TypeContext *returnType = nullptr;
    antlr4::Token *funcName = nullptr;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    std::vector<TypeContext *> type();
    TypeContext *type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode *Identifier(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ClassStmtContext *classStmt();

  class FuncDefContext : public antlr4::ParserRuleContext {
   public:
    MxParser::TypeContext *returnType = nullptr;
    antlr4::Token *funcName = nullptr;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    std::vector<TypeContext *> type();
    TypeContext *type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode *Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncDefContext *funcDef();

  class VarDefContext : public antlr4::ParserRuleContext {
   public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode *Identifier(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode *Assign(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDefContext *varDef();

  class StatementContext : public antlr4::ParserRuleContext {
   public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class VarDefStmtContext : public StatementContext {
   public:
    VarDefStmtContext(StatementContext *ctx);

    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode *Identifier(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode *Assign(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ExprStmtContext : public StatementContext {
   public:
    ExprStmtContext(StatementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ForStmtContext : public StatementContext {
   public:
    ForStmtContext(StatementContext *ctx);

    MxParser::StatementContext *initializeStmt = nullptr;
    MxParser::ExpressionContext *conditionExpr = nullptr;
    MxParser::ExpressionContext *stepExpr = nullptr;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class WhileStmtContext : public StatementContext {
   public:
    WhileStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class IfStmtContext : public StatementContext {
   public:
    IfStmtContext(StatementContext *ctx);

    MxParser::StatementContext *trueStmt = nullptr;
    MxParser::StatementContext *falseStmt = nullptr;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class BreakStmtContext : public StatementContext {
   public:
    BreakStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ReturnStmtContext : public StatementContext {
   public:
    ReturnStmtContext(StatementContext *ctx);

    MxParser::ExpressionContext *returnExpr = nullptr;
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semicolon();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ContinueStmtContext : public StatementContext {
   public:
    ContinueStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class SuiteStmtContext : public StatementContext {
   public:
    SuiteStmtContext(StatementContext *ctx);

    SuiteContext *suite();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext *statement();

  class ExpressionContext : public antlr4::ParserRuleContext {
   public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class AtomicExprContext : public ExpressionContext {
   public:
    AtomicExprContext(ExpressionContext *ctx);

    PrimaryContext *primary();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class UnaryExprContext : public ExpressionContext {
   public:
    UnaryExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Increment();
    antlr4::tree::TerminalNode *Decrement();
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *NotLogic();
    antlr4::tree::TerminalNode *Not();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class SubscriptExprContext : public ExpressionContext {
   public:
    SubscriptExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *index = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode *LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode *RightBracket(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class TenaryExprContext : public ExpressionContext {
   public:
    TenaryExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    antlr4::tree::TerminalNode *Question();
    antlr4::tree::TerminalNode *Colon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class MemberExprContext : public ExpressionContext {
   public:
    MemberExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Dot();
    antlr4::tree::TerminalNode *Identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class BinaryExprContext : public ExpressionContext {
   public:
    BinaryExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    antlr4::tree::TerminalNode *Mul();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *ShiftLeft();
    antlr4::tree::TerminalNode *ShiftRight();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *GreaterEqual();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *UnEqual();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Xor();
    antlr4::tree::TerminalNode *Or();
    antlr4::tree::TerminalNode *AndLogic();
    antlr4::tree::TerminalNode *OrLogic();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class FormatExprContext : public ExpressionContext {
   public:
    FormatExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *FormatQuatation();
    antlr4::tree::TerminalNode *Quotation();
    std::vector<antlr4::tree::TerminalNode *> FormatStringLiteral();
    antlr4::tree::TerminalNode *FormatStringLiteral(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Dollar();
    antlr4::tree::TerminalNode *Dollar(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class FuncCallExprContext : public ExpressionContext {
   public:
    FuncCallExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *classVar = nullptr;
    antlr4::Token *funcName = nullptr;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *Identifier();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *Dot();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class AssignExprContext : public ExpressionContext {
   public:
    AssignExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    antlr4::tree::TerminalNode *Assign();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext *expression();
  ExpressionContext *expression(int precedence);
  class SuiteContext : public antlr4::ParserRuleContext {
   public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SuiteContext *suite();

  class ArgumentsContext : public antlr4::ParserRuleContext {
   public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgumentsContext *arguments();

  class PrimaryContext : public antlr4::ParserRuleContext {
   public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    PrimaryContext() = default;
    void copyFrom(PrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class ThisPrimaryContext : public PrimaryContext {
   public:
    ThisPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *This();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ParenPrimaryContext : public PrimaryContext {
   public:
    ParenPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class VarPrimaryContext : public PrimaryContext {
   public:
    VarPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *Identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class LiteralPrimaryContext : public PrimaryContext {
   public:
    LiteralPrimaryContext(PrimaryContext *ctx);

    LiteralContext *literal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class NewPrimaryContext : public PrimaryContext {
   public:
    NewPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *New();
    TypeContext *type();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    ArrayContext *array();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode *LeftBracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode *RightBracket(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryContext *primary();

  class ArrayContext : public antlr4::ParserRuleContext {
   public:
    ArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<LiteralContext *> literal();
    LiteralContext *literal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode *Comma(size_t i);
    std::vector<ArrayContext *> array();
    ArrayContext *array(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArrayContext *array();

  class LiteralContext : public antlr4::ParserRuleContext {
   public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class DecimalLiteralContext : public LiteralContext {
   public:
    DecimalLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *DecimalNumber();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class NullLiteralContext : public LiteralContext {
   public:
    NullLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *Null();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class StringLiteralContext : public LiteralContext {
   public:
    StringLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ArrayLiteralContext : public LiteralContext {
   public:
    ArrayLiteralContext(LiteralContext *ctx);

    ArrayContext *array();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class BoolLiteralContext : public LiteralContext {
   public:
    BoolLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext *literal();

  class TypeContext : public antlr4::ParserRuleContext {
   public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Void();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext *type();

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

 private:
};
