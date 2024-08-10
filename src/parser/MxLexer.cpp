
// Generated from Mx.g4 by ANTLR 4.13.1

#include "parser/MxLexer.h"

using namespace antlr4;

using namespace antlr4;

namespace {

struct MxLexerStaticData final {
  MxLexerStaticData(std::vector<std::string> ruleNames, std::vector<std::string> channelNames,
                    std::vector<std::string> modeNames, std::vector<std::string> literalNames,
                    std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)),
        channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)),
        literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxLexerStaticData(const MxLexerStaticData &) = delete;
  MxLexerStaticData(MxLexerStaticData &&) = delete;
  MxLexerStaticData &operator=(const MxLexerStaticData &) = delete;
  MxLexerStaticData &operator=(MxLexerStaticData &&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
    MxLexerStaticData *mxlexerLexerStaticData = nullptr;

void mxlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(mxlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxLexerStaticData>(
      std::vector<std::string>{"T__0",
                               "FormatQuatation",
                               "Quotation",
                               "True",
                               "False",
                               "DecimalNumber",
                               "StringLiteral",
                               "FormatStringLiteral",
                               "Null",
                               "New",
                               "Class",
                               "This",
                               "If",
                               "Else",
                               "For",
                               "While",
                               "Break",
                               "Continue",
                               "Return",
                               "Bool",
                               "Int",
                               "Void",
                               "String",
                               "Identifier",
                               "Add",
                               "Sub",
                               "Mul",
                               "Div",
                               "Mod",
                               "Less",
                               "LessEqual",
                               "Greater",
                               "GreaterEqual",
                               "Equal",
                               "UnEqual",
                               "AndLogic",
                               "OrLogic",
                               "NotLogic",
                               "ShiftRight",
                               "ShiftLeft",
                               "And",
                               "Or",
                               "Xor",
                               "Not",
                               "Assign",
                               "Increment",
                               "Decrement",
                               "Dot",
                               "LeftParen",
                               "RightParen",
                               "LeftBracket",
                               "RightBracket",
                               "LeftBrace",
                               "RightBrace",
                               "Dollar",
                               "Question",
                               "Colon",
                               "Semicolon",
                               "Comma",
                               "Whitespace",
                               "LineComment",
                               "BlockComment"},
      std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"}, std::vector<std::string>{"DEFAULT_MODE"},
      std::vector<std::string>{
          "",           "'main'",   "'f\"'",     "",       "'true'", "'false'",  "",      "",        "",
          "'null'",     "'new'",    "'class'",   "'this'", "'if'",   "'else'",   "'for'", "'while'", "'break'",
          "'continue'", "'return'", "'bool'",    "'int'",  "'void'", "'string'", "",      "'+'",     "'-'",
          "'*'",        "'/'",      "'%'",       "'<'",    "'<='",   "'>'",      "'>='",  "'=='",    "'!='",
          "'&&'",       "'||'",     "'!'",       "'>>'",   "'<<'",   "'&'",      "'|'",   "'^'",     "'~'",
          "'='",        "'++'",     "'--'",      "'.'",    "'('",    "')'",      "'['",   "']'",     "'{'",
          "'}'",        "'$'",      "'\\u003F'", "':'",    "';'",    "','"},
      std::vector<std::string>{"",
                               "",
                               "FormatQuatation",
                               "Quotation",
                               "True",
                               "False",
                               "DecimalNumber",
                               "StringLiteral",
                               "FormatStringLiteral",
                               "Null",
                               "New",
                               "Class",
                               "This",
                               "If",
                               "Else",
                               "For",
                               "While",
                               "Break",
                               "Continue",
                               "Return",
                               "Bool",
                               "Int",
                               "Void",
                               "String",
                               "Identifier",
                               "Add",
                               "Sub",
                               "Mul",
                               "Div",
                               "Mod",
                               "Less",
                               "LessEqual",
                               "Greater",
                               "GreaterEqual",
                               "Equal",
                               "UnEqual",
                               "AndLogic",
                               "OrLogic",
                               "NotLogic",
                               "ShiftRight",
                               "ShiftLeft",
                               "And",
                               "Or",
                               "Xor",
                               "Not",
                               "Assign",
                               "Increment",
                               "Decrement",
                               "Dot",
                               "LeftParen",
                               "RightParen",
                               "LeftBracket",
                               "RightBracket",
                               "LeftBrace",
                               "RightBrace",
                               "Dollar",
                               "Question",
                               "Colon",
                               "Semicolon",
                               "Comma",
                               "Whitespace",
                               "LineComment",
                               "BlockComment"});
  static const int32_t serializedATNSegment[] = {
      4,   0,   62,  388, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,
      4,   7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,
      2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  2,   14,  7,   14,  2,   15,  7,
      15,  2,   16,  7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,  2,   21,
      7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25,  7,   25,  2,   26,  7,   26,  2,
      27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,  7,   31,  2,   32,  7,   32,
      2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,  2,   37,  7,   37,  2,   38,  7,
      38,  2,   39,  7,   39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,  7,   42,  2,   43,  7,   43,  2,   44,
      7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  2,   47,  7,   47,  2,   48,  7,   48,  2,   49,  7,   49,  2,
      50,  7,   50,  2,   51,  7,   51,  2,   52,  7,   52,  2,   53,  7,   53,  2,   54,  7,   54,  2,   55,  7,   55,
      2,   56,  7,   56,  2,   57,  7,   57,  2,   58,  7,   58,  2,   59,  7,   59,  2,   60,  7,   60,  2,   61,  7,
      61,  1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,
      1,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   4,   1,   4,   1,   4,   1,
      4,   1,   4,   1,   4,   1,   5,   1,   5,   5,   5,   153, 8,   5,   10,  5,   12,  5,   156, 9,   5,   1,   5,
      3,   5,   159, 8,   5,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,
      5,   6,   170, 8,   6,   10,  6,   12,  6,   173, 9,   6,   1,   6,   1,   6,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   4,   7,   187, 8,   7,   11,  7,   12,  7,   188,
      1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,   1,   9,   1,   10,  1,   10,  1,
      10,  1,   10,  1,   10,  1,   10,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   12,  1,   12,  1,   12,
      1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  1,   14,  1,   14,  1,   14,  1,   14,  1,   15,  1,   15,  1,
      15,  1,   15,  1,   15,  1,   15,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   17,  1,   17,
      1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   18,  1,   18,  1,   18,  1,   18,  1,
      18,  1,   18,  1,   18,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   20,  1,   20,  1,   20,  1,   20,
      1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,
      22,  1,   23,  1,   23,  5,   23,  274, 8,   23,  10,  23,  12,  23,  277, 9,   23,  1,   24,  1,   24,  1,   25,
      1,   25,  1,   26,  1,   26,  1,   27,  1,   27,  1,   28,  1,   28,  1,   29,  1,   29,  1,   30,  1,   30,  1,
      30,  1,   31,  1,   31,  1,   32,  1,   32,  1,   32,  1,   33,  1,   33,  1,   33,  1,   34,  1,   34,  1,   34,
      1,   35,  1,   35,  1,   35,  1,   36,  1,   36,  1,   36,  1,   37,  1,   37,  1,   38,  1,   38,  1,   38,  1,
      39,  1,   39,  1,   39,  1,   40,  1,   40,  1,   41,  1,   41,  1,   42,  1,   42,  1,   43,  1,   43,  1,   44,
      1,   44,  1,   45,  1,   45,  1,   45,  1,   46,  1,   46,  1,   46,  1,   47,  1,   47,  1,   48,  1,   48,  1,
      49,  1,   49,  1,   50,  1,   50,  1,   51,  1,   51,  1,   52,  1,   52,  1,   53,  1,   53,  1,   54,  1,   54,
      1,   54,  1,   55,  1,   55,  1,   56,  1,   56,  1,   57,  1,   57,  1,   58,  1,   58,  1,   59,  1,   59,  1,
      59,  1,   59,  1,   60,  1,   60,  1,   60,  1,   60,  5,   60,  368, 8,   60,  10,  60,  12,  60,  371, 9,   60,
      1,   60,  1,   60,  1,   61,  1,   61,  1,   61,  1,   61,  5,   61,  379, 8,   61,  10,  61,  12,  61,  382, 9,
      61,  1,   61,  1,   61,  1,   61,  1,   61,  1,   61,  1,   380, 0,   62,  1,   1,   3,   2,   5,   3,   7,   4,
      9,   5,   11,  6,   13,  7,   15,  8,   17,  9,   19,  10,  21,  11,  23,  12,  25,  13,  27,  14,  29,  15,  31,
      16,  33,  17,  35,  18,  37,  19,  39,  20,  41,  21,  43,  22,  45,  23,  47,  24,  49,  25,  51,  26,  53,  27,
      55,  28,  57,  29,  59,  30,  61,  31,  63,  32,  65,  33,  67,  34,  69,  35,  71,  36,  73,  37,  75,  38,  77,
      39,  79,  40,  81,  41,  83,  42,  85,  43,  87,  44,  89,  45,  91,  46,  93,  47,  95,  48,  97,  49,  99,  50,
      101, 51,  103, 52,  105, 53,  107, 54,  109, 55,  111, 56,  113, 57,  115, 58,  117, 59,  119, 60,  121, 61,  123,
      62,  1,   0,   8,   1,   0,   49,  57,  1,   0,   48,  57,  3,   0,   32,  33,  35,  91,  93,  126, 4,   0,   32,
      33,  35,  35,  37,  91,  93,  126, 2,   0,   65,  90,  97,  122, 4,   0,   48,  57,  65,  90,  95,  95,  97,  122,
      3,   0,   9,   10,  13,  13,  32,  32,  2,   0,   10,  10,  13,  13,  401, 0,   1,   1,   0,   0,   0,   0,   3,
      1,   0,   0,   0,   0,   5,   1,   0,   0,   0,   0,   7,   1,   0,   0,   0,   0,   9,   1,   0,   0,   0,   0,
      11,  1,   0,   0,   0,   0,   13,  1,   0,   0,   0,   0,   15,  1,   0,   0,   0,   0,   17,  1,   0,   0,   0,
      0,   19,  1,   0,   0,   0,   0,   21,  1,   0,   0,   0,   0,   23,  1,   0,   0,   0,   0,   25,  1,   0,   0,
      0,   0,   27,  1,   0,   0,   0,   0,   29,  1,   0,   0,   0,   0,   31,  1,   0,   0,   0,   0,   33,  1,   0,
      0,   0,   0,   35,  1,   0,   0,   0,   0,   37,  1,   0,   0,   0,   0,   39,  1,   0,   0,   0,   0,   41,  1,
      0,   0,   0,   0,   43,  1,   0,   0,   0,   0,   45,  1,   0,   0,   0,   0,   47,  1,   0,   0,   0,   0,   49,
      1,   0,   0,   0,   0,   51,  1,   0,   0,   0,   0,   53,  1,   0,   0,   0,   0,   55,  1,   0,   0,   0,   0,
      57,  1,   0,   0,   0,   0,   59,  1,   0,   0,   0,   0,   61,  1,   0,   0,   0,   0,   63,  1,   0,   0,   0,
      0,   65,  1,   0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,  1,   0,   0,   0,   0,   71,  1,   0,   0,
      0,   0,   73,  1,   0,   0,   0,   0,   75,  1,   0,   0,   0,   0,   77,  1,   0,   0,   0,   0,   79,  1,   0,
      0,   0,   0,   81,  1,   0,   0,   0,   0,   83,  1,   0,   0,   0,   0,   85,  1,   0,   0,   0,   0,   87,  1,
      0,   0,   0,   0,   89,  1,   0,   0,   0,   0,   91,  1,   0,   0,   0,   0,   93,  1,   0,   0,   0,   0,   95,
      1,   0,   0,   0,   0,   97,  1,   0,   0,   0,   0,   99,  1,   0,   0,   0,   0,   101, 1,   0,   0,   0,   0,
      103, 1,   0,   0,   0,   0,   105, 1,   0,   0,   0,   0,   107, 1,   0,   0,   0,   0,   109, 1,   0,   0,   0,
      0,   111, 1,   0,   0,   0,   0,   113, 1,   0,   0,   0,   0,   115, 1,   0,   0,   0,   0,   117, 1,   0,   0,
      0,   0,   119, 1,   0,   0,   0,   0,   121, 1,   0,   0,   0,   0,   123, 1,   0,   0,   0,   1,   125, 1,   0,
      0,   0,   3,   130, 1,   0,   0,   0,   5,   135, 1,   0,   0,   0,   7,   139, 1,   0,   0,   0,   9,   144, 1,
      0,   0,   0,   11,  158, 1,   0,   0,   0,   13,  160, 1,   0,   0,   0,   15,  176, 1,   0,   0,   0,   17,  190,
      1,   0,   0,   0,   19,  195, 1,   0,   0,   0,   21,  199, 1,   0,   0,   0,   23,  205, 1,   0,   0,   0,   25,
      210, 1,   0,   0,   0,   27,  213, 1,   0,   0,   0,   29,  218, 1,   0,   0,   0,   31,  222, 1,   0,   0,   0,
      33,  228, 1,   0,   0,   0,   35,  234, 1,   0,   0,   0,   37,  243, 1,   0,   0,   0,   39,  250, 1,   0,   0,
      0,   41,  255, 1,   0,   0,   0,   43,  259, 1,   0,   0,   0,   45,  264, 1,   0,   0,   0,   47,  271, 1,   0,
      0,   0,   49,  278, 1,   0,   0,   0,   51,  280, 1,   0,   0,   0,   53,  282, 1,   0,   0,   0,   55,  284, 1,
      0,   0,   0,   57,  286, 1,   0,   0,   0,   59,  288, 1,   0,   0,   0,   61,  290, 1,   0,   0,   0,   63,  293,
      1,   0,   0,   0,   65,  295, 1,   0,   0,   0,   67,  298, 1,   0,   0,   0,   69,  301, 1,   0,   0,   0,   71,
      304, 1,   0,   0,   0,   73,  307, 1,   0,   0,   0,   75,  310, 1,   0,   0,   0,   77,  312, 1,   0,   0,   0,
      79,  315, 1,   0,   0,   0,   81,  318, 1,   0,   0,   0,   83,  320, 1,   0,   0,   0,   85,  322, 1,   0,   0,
      0,   87,  324, 1,   0,   0,   0,   89,  326, 1,   0,   0,   0,   91,  328, 1,   0,   0,   0,   93,  331, 1,   0,
      0,   0,   95,  334, 1,   0,   0,   0,   97,  336, 1,   0,   0,   0,   99,  338, 1,   0,   0,   0,   101, 340, 1,
      0,   0,   0,   103, 342, 1,   0,   0,   0,   105, 344, 1,   0,   0,   0,   107, 346, 1,   0,   0,   0,   109, 348,
      1,   0,   0,   0,   111, 351, 1,   0,   0,   0,   113, 353, 1,   0,   0,   0,   115, 355, 1,   0,   0,   0,   117,
      357, 1,   0,   0,   0,   119, 359, 1,   0,   0,   0,   121, 363, 1,   0,   0,   0,   123, 374, 1,   0,   0,   0,
      125, 126, 5,   109, 0,   0,   126, 127, 5,   97,  0,   0,   127, 128, 5,   105, 0,   0,   128, 129, 5,   110, 0,
      0,   129, 2,   1,   0,   0,   0,   130, 131, 5,   102, 0,   0,   131, 132, 5,   34,  0,   0,   132, 133, 1,   0,
      0,   0,   133, 134, 6,   1,   0,   0,   134, 4,   1,   0,   0,   0,   135, 136, 4,   2,   0,   0,   136, 137, 5,
      34,  0,   0,   137, 138, 6,   2,   1,   0,   138, 6,   1,   0,   0,   0,   139, 140, 5,   116, 0,   0,   140, 141,
      5,   114, 0,   0,   141, 142, 5,   117, 0,   0,   142, 143, 5,   101, 0,   0,   143, 8,   1,   0,   0,   0,   144,
      145, 5,   102, 0,   0,   145, 146, 5,   97,  0,   0,   146, 147, 5,   108, 0,   0,   147, 148, 5,   115, 0,   0,
      148, 149, 5,   101, 0,   0,   149, 10,  1,   0,   0,   0,   150, 154, 7,   0,   0,   0,   151, 153, 7,   1,   0,
      0,   152, 151, 1,   0,   0,   0,   153, 156, 1,   0,   0,   0,   154, 152, 1,   0,   0,   0,   154, 155, 1,   0,
      0,   0,   155, 159, 1,   0,   0,   0,   156, 154, 1,   0,   0,   0,   157, 159, 5,   48,  0,   0,   158, 150, 1,
      0,   0,   0,   158, 157, 1,   0,   0,   0,   159, 12,  1,   0,   0,   0,   160, 161, 4,   6,   1,   0,   161, 171,
      5,   34,  0,   0,   162, 163, 5,   92,  0,   0,   163, 170, 5,   110, 0,   0,   164, 165, 5,   92,  0,   0,   165,
      170, 5,   92,  0,   0,   166, 167, 5,   92,  0,   0,   167, 170, 5,   34,  0,   0,   168, 170, 7,   2,   0,   0,
      169, 162, 1,   0,   0,   0,   169, 164, 1,   0,   0,   0,   169, 166, 1,   0,   0,   0,   169, 168, 1,   0,   0,
      0,   170, 173, 1,   0,   0,   0,   171, 169, 1,   0,   0,   0,   171, 172, 1,   0,   0,   0,   172, 174, 1,   0,
      0,   0,   173, 171, 1,   0,   0,   0,   174, 175, 5,   34,  0,   0,   175, 14,  1,   0,   0,   0,   176, 186, 4,
      7,   2,   0,   177, 178, 5,   92,  0,   0,   178, 187, 5,   110, 0,   0,   179, 180, 5,   92,  0,   0,   180, 187,
      5,   92,  0,   0,   181, 182, 5,   92,  0,   0,   182, 187, 5,   34,  0,   0,   183, 184, 5,   36,  0,   0,   184,
      187, 5,   36,  0,   0,   185, 187, 7,   3,   0,   0,   186, 177, 1,   0,   0,   0,   186, 179, 1,   0,   0,   0,
      186, 181, 1,   0,   0,   0,   186, 183, 1,   0,   0,   0,   186, 185, 1,   0,   0,   0,   187, 188, 1,   0,   0,
      0,   188, 186, 1,   0,   0,   0,   188, 189, 1,   0,   0,   0,   189, 16,  1,   0,   0,   0,   190, 191, 5,   110,
      0,   0,   191, 192, 5,   117, 0,   0,   192, 193, 5,   108, 0,   0,   193, 194, 5,   108, 0,   0,   194, 18,  1,
      0,   0,   0,   195, 196, 5,   110, 0,   0,   196, 197, 5,   101, 0,   0,   197, 198, 5,   119, 0,   0,   198, 20,
      1,   0,   0,   0,   199, 200, 5,   99,  0,   0,   200, 201, 5,   108, 0,   0,   201, 202, 5,   97,  0,   0,   202,
      203, 5,   115, 0,   0,   203, 204, 5,   115, 0,   0,   204, 22,  1,   0,   0,   0,   205, 206, 5,   116, 0,   0,
      206, 207, 5,   104, 0,   0,   207, 208, 5,   105, 0,   0,   208, 209, 5,   115, 0,   0,   209, 24,  1,   0,   0,
      0,   210, 211, 5,   105, 0,   0,   211, 212, 5,   102, 0,   0,   212, 26,  1,   0,   0,   0,   213, 214, 5,   101,
      0,   0,   214, 215, 5,   108, 0,   0,   215, 216, 5,   115, 0,   0,   216, 217, 5,   101, 0,   0,   217, 28,  1,
      0,   0,   0,   218, 219, 5,   102, 0,   0,   219, 220, 5,   111, 0,   0,   220, 221, 5,   114, 0,   0,   221, 30,
      1,   0,   0,   0,   222, 223, 5,   119, 0,   0,   223, 224, 5,   104, 0,   0,   224, 225, 5,   105, 0,   0,   225,
      226, 5,   108, 0,   0,   226, 227, 5,   101, 0,   0,   227, 32,  1,   0,   0,   0,   228, 229, 5,   98,  0,   0,
      229, 230, 5,   114, 0,   0,   230, 231, 5,   101, 0,   0,   231, 232, 5,   97,  0,   0,   232, 233, 5,   107, 0,
      0,   233, 34,  1,   0,   0,   0,   234, 235, 5,   99,  0,   0,   235, 236, 5,   111, 0,   0,   236, 237, 5,   110,
      0,   0,   237, 238, 5,   116, 0,   0,   238, 239, 5,   105, 0,   0,   239, 240, 5,   110, 0,   0,   240, 241, 5,
      117, 0,   0,   241, 242, 5,   101, 0,   0,   242, 36,  1,   0,   0,   0,   243, 244, 5,   114, 0,   0,   244, 245,
      5,   101, 0,   0,   245, 246, 5,   116, 0,   0,   246, 247, 5,   117, 0,   0,   247, 248, 5,   114, 0,   0,   248,
      249, 5,   110, 0,   0,   249, 38,  1,   0,   0,   0,   250, 251, 5,   98,  0,   0,   251, 252, 5,   111, 0,   0,
      252, 253, 5,   111, 0,   0,   253, 254, 5,   108, 0,   0,   254, 40,  1,   0,   0,   0,   255, 256, 5,   105, 0,
      0,   256, 257, 5,   110, 0,   0,   257, 258, 5,   116, 0,   0,   258, 42,  1,   0,   0,   0,   259, 260, 5,   118,
      0,   0,   260, 261, 5,   111, 0,   0,   261, 262, 5,   105, 0,   0,   262, 263, 5,   100, 0,   0,   263, 44,  1,
      0,   0,   0,   264, 265, 5,   115, 0,   0,   265, 266, 5,   116, 0,   0,   266, 267, 5,   114, 0,   0,   267, 268,
      5,   105, 0,   0,   268, 269, 5,   110, 0,   0,   269, 270, 5,   103, 0,   0,   270, 46,  1,   0,   0,   0,   271,
      275, 7,   4,   0,   0,   272, 274, 7,   5,   0,   0,   273, 272, 1,   0,   0,   0,   274, 277, 1,   0,   0,   0,
      275, 273, 1,   0,   0,   0,   275, 276, 1,   0,   0,   0,   276, 48,  1,   0,   0,   0,   277, 275, 1,   0,   0,
      0,   278, 279, 5,   43,  0,   0,   279, 50,  1,   0,   0,   0,   280, 281, 5,   45,  0,   0,   281, 52,  1,   0,
      0,   0,   282, 283, 5,   42,  0,   0,   283, 54,  1,   0,   0,   0,   284, 285, 5,   47,  0,   0,   285, 56,  1,
      0,   0,   0,   286, 287, 5,   37,  0,   0,   287, 58,  1,   0,   0,   0,   288, 289, 5,   60,  0,   0,   289, 60,
      1,   0,   0,   0,   290, 291, 5,   60,  0,   0,   291, 292, 5,   61,  0,   0,   292, 62,  1,   0,   0,   0,   293,
      294, 5,   62,  0,   0,   294, 64,  1,   0,   0,   0,   295, 296, 5,   62,  0,   0,   296, 297, 5,   61,  0,   0,
      297, 66,  1,   0,   0,   0,   298, 299, 5,   61,  0,   0,   299, 300, 5,   61,  0,   0,   300, 68,  1,   0,   0,
      0,   301, 302, 5,   33,  0,   0,   302, 303, 5,   61,  0,   0,   303, 70,  1,   0,   0,   0,   304, 305, 5,   38,
      0,   0,   305, 306, 5,   38,  0,   0,   306, 72,  1,   0,   0,   0,   307, 308, 5,   124, 0,   0,   308, 309, 5,
      124, 0,   0,   309, 74,  1,   0,   0,   0,   310, 311, 5,   33,  0,   0,   311, 76,  1,   0,   0,   0,   312, 313,
      5,   62,  0,   0,   313, 314, 5,   62,  0,   0,   314, 78,  1,   0,   0,   0,   315, 316, 5,   60,  0,   0,   316,
      317, 5,   60,  0,   0,   317, 80,  1,   0,   0,   0,   318, 319, 5,   38,  0,   0,   319, 82,  1,   0,   0,   0,
      320, 321, 5,   124, 0,   0,   321, 84,  1,   0,   0,   0,   322, 323, 5,   94,  0,   0,   323, 86,  1,   0,   0,
      0,   324, 325, 5,   126, 0,   0,   325, 88,  1,   0,   0,   0,   326, 327, 5,   61,  0,   0,   327, 90,  1,   0,
      0,   0,   328, 329, 5,   43,  0,   0,   329, 330, 5,   43,  0,   0,   330, 92,  1,   0,   0,   0,   331, 332, 5,
      45,  0,   0,   332, 333, 5,   45,  0,   0,   333, 94,  1,   0,   0,   0,   334, 335, 5,   46,  0,   0,   335, 96,
      1,   0,   0,   0,   336, 337, 5,   40,  0,   0,   337, 98,  1,   0,   0,   0,   338, 339, 5,   41,  0,   0,   339,
      100, 1,   0,   0,   0,   340, 341, 5,   91,  0,   0,   341, 102, 1,   0,   0,   0,   342, 343, 5,   93,  0,   0,
      343, 104, 1,   0,   0,   0,   344, 345, 5,   123, 0,   0,   345, 106, 1,   0,   0,   0,   346, 347, 5,   125, 0,
      0,   347, 108, 1,   0,   0,   0,   348, 349, 5,   36,  0,   0,   349, 350, 6,   54,  2,   0,   350, 110, 1,   0,
      0,   0,   351, 352, 5,   63,  0,   0,   352, 112, 1,   0,   0,   0,   353, 354, 5,   58,  0,   0,   354, 114, 1,
      0,   0,   0,   355, 356, 5,   59,  0,   0,   356, 116, 1,   0,   0,   0,   357, 358, 5,   44,  0,   0,   358, 118,
      1,   0,   0,   0,   359, 360, 7,   6,   0,   0,   360, 361, 1,   0,   0,   0,   361, 362, 6,   59,  3,   0,   362,
      120, 1,   0,   0,   0,   363, 364, 5,   47,  0,   0,   364, 365, 5,   47,  0,   0,   365, 369, 1,   0,   0,   0,
      366, 368, 8,   7,   0,   0,   367, 366, 1,   0,   0,   0,   368, 371, 1,   0,   0,   0,   369, 367, 1,   0,   0,
      0,   369, 370, 1,   0,   0,   0,   370, 372, 1,   0,   0,   0,   371, 369, 1,   0,   0,   0,   372, 373, 6,   60,
      3,   0,   373, 122, 1,   0,   0,   0,   374, 375, 5,   47,  0,   0,   375, 376, 5,   42,  0,   0,   376, 380, 1,
      0,   0,   0,   377, 379, 9,   0,   0,   0,   378, 377, 1,   0,   0,   0,   379, 382, 1,   0,   0,   0,   380, 381,
      1,   0,   0,   0,   380, 378, 1,   0,   0,   0,   381, 383, 1,   0,   0,   0,   382, 380, 1,   0,   0,   0,   383,
      384, 5,   42,  0,   0,   384, 385, 5,   47,  0,   0,   385, 386, 1,   0,   0,   0,   386, 387, 6,   61,  3,   0,
      387, 124, 1,   0,   0,   0,   10,  0,   154, 158, 169, 171, 186, 188, 275, 369, 380, 4,   1,   1,   0,   1,   2,
      1,   1,   54,  2,   6,   0,   0};
  staticData->serializedATN = antlr4::atn::SerializedATNView(
      serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxlexerLexerStaticData = staticData.release();
}

}  // namespace

MxLexer::MxLexer(CharStream *input) : Lexer(input) {
  MxLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mxlexerLexerStaticData->atn, mxlexerLexerStaticData->decisionToDFA,
                                            mxlexerLexerStaticData->sharedContextCache);
}

MxLexer::~MxLexer() { delete _interpreter; }

std::string MxLexer::getGrammarFileName() const { return "Mx.g4"; }

const std::vector<std::string> &MxLexer::getRuleNames() const { return mxlexerLexerStaticData->ruleNames; }

const std::vector<std::string> &MxLexer::getChannelNames() const { return mxlexerLexerStaticData->channelNames; }

const std::vector<std::string> &MxLexer::getModeNames() const { return mxlexerLexerStaticData->modeNames; }

const dfa::Vocabulary &MxLexer::getVocabulary() const { return mxlexerLexerStaticData->vocabulary; }

antlr4::atn::SerializedATNView MxLexer::getSerializedATN() const { return mxlexerLexerStaticData->serializedATN; }

const atn::ATN &MxLexer::getATN() const { return *mxlexerLexerStaticData->atn; }

void MxLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 1:
      FormatQuatationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;
    case 2:
      QuotationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;
    case 54:
      DollarAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;

    default:
      break;
  }
}

bool MxLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2:
      return QuotationSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 6:
      return StringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 7:
      return FormatStringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

    default:
      break;
  }
  return true;
}

void MxLexer::FormatQuatationAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:
      formatMode++;
      exprMode = false;
      break;

    default:
      break;
  }
}

void MxLexer::QuotationAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:
      formatMode--;
      if (formatMode > 0) {
        exprMode = true;
      }
      break;

    default:
      break;
  }
}

void MxLexer::DollarAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:
      exprMode = !exprMode;
      break;

    default:
      break;
  }
}

bool MxLexer::QuotationSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0:
      return formatMode > 0 && !exprMode;

    default:
      break;
  }
  return true;
}

bool MxLexer::StringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1:
      return formatMode == 0 || exprMode;

    default:
      break;
  }
  return true;
}

bool MxLexer::FormatStringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2:
      return formatMode > 0 && !exprMode;

    default:
      break;
  }
  return true;
}

void MxLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(mxlexerLexerOnceFlag, mxlexerLexerInitialize);
#endif
}
