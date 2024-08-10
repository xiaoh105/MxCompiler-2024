
// Generated from Mx.g4 by ANTLR 4.13.1

#pragma once

#include "antlr4-runtime.h"

class MxLexer : public antlr4::Lexer {
 public:
  enum {
    T__0 = 1,
    FormatQuatation = 2,
    Quotation = 3,
    True = 4,
    False = 5,
    DecimalNumber = 6,
    StringLiteral = 7,
    FormatStringLiteral = 8,
    Null = 9,
    New = 10,
    Class = 11,
    This = 12,
    If = 13,
    Else = 14,
    For = 15,
    While = 16,
    Break = 17,
    Continue = 18,
    Return = 19,
    Bool = 20,
    Int = 21,
    Void = 22,
    String = 23,
    Identifier = 24,
    Add = 25,
    Sub = 26,
    Mul = 27,
    Div = 28,
    Mod = 29,
    Less = 30,
    LessEqual = 31,
    Greater = 32,
    GreaterEqual = 33,
    Equal = 34,
    UnEqual = 35,
    AndLogic = 36,
    OrLogic = 37,
    NotLogic = 38,
    ShiftRight = 39,
    ShiftLeft = 40,
    And = 41,
    Or = 42,
    Xor = 43,
    Not = 44,
    Assign = 45,
    Increment = 46,
    Decrement = 47,
    Dot = 48,
    LeftParen = 49,
    RightParen = 50,
    LeftBracket = 51,
    RightBracket = 52,
    LeftBrace = 53,
    RightBrace = 54,
    Dollar = 55,
    Question = 56,
    Colon = 57,
    Semicolon = 58,
    Comma = 59,
    Whitespace = 60,
    LineComment = 61,
    BlockComment = 62
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
