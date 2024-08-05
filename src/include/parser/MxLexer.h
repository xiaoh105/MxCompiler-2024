
// Generated from Mx.g4 by ANTLR 4.13.1

#pragma once

#include "antlr4-runtime.h"

class MxLexer : public antlr4::Lexer {
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
    ArrayLiteral = 11,
    New = 12,
    Class = 13,
    This = 14,
    If = 15,
    Else = 16,
    For = 17,
    While = 18,
    Break = 19,
    Continue = 20,
    Return = 21,
    Bool = 22,
    Int = 23,
    Void = 24,
    String = 25,
    Identifier = 26,
    Add = 27,
    Sub = 28,
    Mul = 29,
    Div = 30,
    Mod = 31,
    Less = 32,
    LessEqual = 33,
    Greater = 34,
    GreaterEqual = 35,
    Equal = 36,
    UnEqual = 37,
    AndLogic = 38,
    OrLogic = 39,
    NotLogic = 40,
    ShiftRight = 41,
    ShiftLeft = 42,
    And = 43,
    Or = 44,
    Xor = 45,
    Not = 46,
    Assign = 47,
    Increment = 48,
    Decrement = 49,
    Dot = 50,
    LeftParen = 51,
    RightParen = 52,
    LeftBracket = 53,
    RightBracket = 54,
    LeftBrace = 55,
    RightBrace = 56,
    Dollar = 57,
    Question = 58,
    Colon = 59,
    Semicolon = 60,
    Comma = 61,
    Whitespace = 62,
    LineComment = 63,
    BlockComment = 64
  };

  explicit MxLexer(antlr4::CharStream *input);

  ~MxLexer() override;

  int formatMode = 0;
  bool exprMode = false;

  std::string getGrammarFileName() const override;

  const std::vector<std::string> &getRuleNames() const override;

  const std::vector<std::string> &getChannelNames() const override;

  const std::vector<std::string> &getModeNames() const override;

  const antlr4::dfa::Vocabulary &getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN &getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

 private:
  // Individual action functions triggered by action() above.
  void FormatQuatationAction(antlr4::RuleContext *context, size_t actionIndex);
  void QuotationAction(antlr4::RuleContext *context, size_t actionIndex);
  void DollarAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool QuotationSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool StringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool FormatStringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
};
