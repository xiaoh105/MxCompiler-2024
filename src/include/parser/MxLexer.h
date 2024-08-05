
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
