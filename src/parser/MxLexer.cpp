
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
      std::vector<std::string>{"FormatQuatation",
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
                               "Main",
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
          "",         "'f\"'",   "",          "'true'", "'false'", "",         "",        "",        "'null'",
          "'new'",    "'class'", "'this'",    "'if'",   "'else'",  "'for'",    "'while'", "'break'", "'continue'",
          "'return'", "",        "'bool'",    "'int'",  "'void'",  "'string'", "",        "'+'",     "'-'",
          "'*'",      "'/'",     "'%'",       "'<'",    "'<='",    "'>'",      "'>='",    "'=='",    "'!='",
          "'&&'",     "'||'",    "'!'",       "'>>'",   "'<<'",    "'&'",      "'|'",     "'^'",     "'~'",
          "'='",      "'++'",    "'--'",      "'.'",    "'('",     "')'",      "'['",     "']'",     "'{'",
          "'}'",      "'$'",     "'\\u003F'", "':'",    "';'",     "','"},
      std::vector<std::string>{"",
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
                               "Main",
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
      4,   0,   62,  391, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,
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
      61,  1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   2,
      1,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   4,   1,   4,   5,
      4,   148, 8,   4,   10,  4,   12,  4,   151, 9,   4,   1,   4,   3,   4,   154, 8,   4,   1,   5,   1,   5,   1,
      5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   5,   5,   165, 8,   5,   10,  5,   12,  5,   168,
      9,   5,   1,   5,   1,   5,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,
      6,   1,   6,   4,   6,   182, 8,   6,   11,  6,   12,  6,   183, 1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   8,   1,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   10,  1,
      10,  1,   10,  1,   10,  1,   10,  1,   11,  1,   11,  1,   11,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,
      1,   13,  1,   13,  1,   13,  1,   13,  1,   14,  1,   14,  1,   14,  1,   14,  1,   14,  1,   14,  1,   15,  1,
      15,  1,   15,  1,   15,  1,   15,  1,   15,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,
      1,   16,  1,   16,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   18,  1,   18,  1,
      18,  1,   18,  1,   18,  1,   18,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   20,  1,   20,  1,   20,
      1,   20,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,
      22,  1,   22,  1,   23,  1,   23,  5,   23,  275, 8,   23,  10,  23,  12,  23,  278, 9,   23,  1,   24,  1,   24,
      1,   25,  1,   25,  1,   26,  1,   26,  1,   27,  1,   27,  1,   28,  1,   28,  1,   29,  1,   29,  1,   30,  1,
      30,  1,   30,  1,   31,  1,   31,  1,   32,  1,   32,  1,   32,  1,   33,  1,   33,  1,   33,  1,   34,  1,   34,
      1,   34,  1,   35,  1,   35,  1,   35,  1,   36,  1,   36,  1,   36,  1,   37,  1,   37,  1,   38,  1,   38,  1,
      38,  1,   39,  1,   39,  1,   39,  1,   40,  1,   40,  1,   41,  1,   41,  1,   42,  1,   42,  1,   43,  1,   43,
      1,   44,  1,   44,  1,   45,  1,   45,  1,   45,  1,   46,  1,   46,  1,   46,  1,   47,  1,   47,  1,   48,  1,
      48,  1,   49,  1,   49,  1,   50,  1,   50,  1,   51,  1,   51,  1,   52,  1,   52,  1,   52,  1,   53,  1,   53,
      1,   53,  1,   54,  1,   54,  1,   54,  1,   55,  1,   55,  1,   56,  1,   56,  1,   57,  1,   57,  1,   58,  1,
      58,  1,   59,  1,   59,  1,   59,  1,   59,  1,   60,  1,   60,  1,   60,  1,   60,  5,   60,  371, 8,   60,  10,
      60,  12,  60,  374, 9,   60,  1,   60,  1,   60,  1,   61,  1,   61,  1,   61,  1,   61,  5,   61,  382, 8,   61,
      10,  61,  12,  61,  385, 9,   61,  1,   61,  1,   61,  1,   61,  1,   61,  1,   61,  1,   383, 0,   62,  1,   1,
      3,   2,   5,   3,   7,   4,   9,   5,   11,  6,   13,  7,   15,  8,   17,  9,   19,  10,  21,  11,  23,  12,  25,
      13,  27,  14,  29,  15,  31,  16,  33,  17,  35,  18,  37,  19,  39,  20,  41,  21,  43,  22,  45,  23,  47,  24,
      49,  25,  51,  26,  53,  27,  55,  28,  57,  29,  59,  30,  61,  31,  63,  32,  65,  33,  67,  34,  69,  35,  71,
      36,  73,  37,  75,  38,  77,  39,  79,  40,  81,  41,  83,  42,  85,  43,  87,  44,  89,  45,  91,  46,  93,  47,
      95,  48,  97,  49,  99,  50,  101, 51,  103, 52,  105, 53,  107, 54,  109, 55,  111, 56,  113, 57,  115, 58,  117,
      59,  119, 60,  121, 61,  123, 62,  1,   0,   8,   1,   0,   49,  57,  1,   0,   48,  57,  3,   0,   32,  33,  35,
      91,  93,  126, 4,   0,   32,  33,  35,  35,  37,  91,  93,  126, 2,   0,   65,  90,  97,  122, 4,   0,   48,  57,
      65,  90,  95,  95,  97,  122, 3,   0,   9,   10,  13,  13,  32,  32,  2,   0,   10,  10,  13,  13,  404, 0,   1,
      1,   0,   0,   0,   0,   3,   1,   0,   0,   0,   0,   5,   1,   0,   0,   0,   0,   7,   1,   0,   0,   0,   0,
      9,   1,   0,   0,   0,   0,   11,  1,   0,   0,   0,   0,   13,  1,   0,   0,   0,   0,   15,  1,   0,   0,   0,
      0,   17,  1,   0,   0,   0,   0,   19,  1,   0,   0,   0,   0,   21,  1,   0,   0,   0,   0,   23,  1,   0,   0,
      0,   0,   25,  1,   0,   0,   0,   0,   27,  1,   0,   0,   0,   0,   29,  1,   0,   0,   0,   0,   31,  1,   0,
      0,   0,   0,   33,  1,   0,   0,   0,   0,   35,  1,   0,   0,   0,   0,   37,  1,   0,   0,   0,   0,   39,  1,
      0,   0,   0,   0,   41,  1,   0,   0,   0,   0,   43,  1,   0,   0,   0,   0,   45,  1,   0,   0,   0,   0,   47,
      1,   0,   0,   0,   0,   49,  1,   0,   0,   0,   0,   51,  1,   0,   0,   0,   0,   53,  1,   0,   0,   0,   0,
      55,  1,   0,   0,   0,   0,   57,  1,   0,   0,   0,   0,   59,  1,   0,   0,   0,   0,   61,  1,   0,   0,   0,
      0,   63,  1,   0,   0,   0,   0,   65,  1,   0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,  1,   0,   0,
      0,   0,   71,  1,   0,   0,   0,   0,   73,  1,   0,   0,   0,   0,   75,  1,   0,   0,   0,   0,   77,  1,   0,
      0,   0,   0,   79,  1,   0,   0,   0,   0,   81,  1,   0,   0,   0,   0,   83,  1,   0,   0,   0,   0,   85,  1,
      0,   0,   0,   0,   87,  1,   0,   0,   0,   0,   89,  1,   0,   0,   0,   0,   91,  1,   0,   0,   0,   0,   93,
      1,   0,   0,   0,   0,   95,  1,   0,   0,   0,   0,   97,  1,   0,   0,   0,   0,   99,  1,   0,   0,   0,   0,
      101, 1,   0,   0,   0,   0,   103, 1,   0,   0,   0,   0,   105, 1,   0,   0,   0,   0,   107, 1,   0,   0,   0,
      0,   109, 1,   0,   0,   0,   0,   111, 1,   0,   0,   0,   0,   113, 1,   0,   0,   0,   0,   115, 1,   0,   0,
      0,   0,   117, 1,   0,   0,   0,   0,   119, 1,   0,   0,   0,   0,   121, 1,   0,   0,   0,   0,   123, 1,   0,
      0,   0,   1,   125, 1,   0,   0,   0,   3,   130, 1,   0,   0,   0,   5,   134, 1,   0,   0,   0,   7,   139, 1,
      0,   0,   0,   9,   153, 1,   0,   0,   0,   11,  155, 1,   0,   0,   0,   13,  171, 1,   0,   0,   0,   15,  185,
      1,   0,   0,   0,   17,  190, 1,   0,   0,   0,   19,  194, 1,   0,   0,   0,   21,  200, 1,   0,   0,   0,   23,
      205, 1,   0,   0,   0,   25,  208, 1,   0,   0,   0,   27,  213, 1,   0,   0,   0,   29,  217, 1,   0,   0,   0,
      31,  223, 1,   0,   0,   0,   33,  229, 1,   0,   0,   0,   35,  238, 1,   0,   0,   0,   37,  245, 1,   0,   0,
      0,   39,  251, 1,   0,   0,   0,   41,  256, 1,   0,   0,   0,   43,  260, 1,   0,   0,   0,   45,  265, 1,   0,
      0,   0,   47,  272, 1,   0,   0,   0,   49,  279, 1,   0,   0,   0,   51,  281, 1,   0,   0,   0,   53,  283, 1,
      0,   0,   0,   55,  285, 1,   0,   0,   0,   57,  287, 1,   0,   0,   0,   59,  289, 1,   0,   0,   0,   61,  291,
      1,   0,   0,   0,   63,  294, 1,   0,   0,   0,   65,  296, 1,   0,   0,   0,   67,  299, 1,   0,   0,   0,   69,
      302, 1,   0,   0,   0,   71,  305, 1,   0,   0,   0,   73,  308, 1,   0,   0,   0,   75,  311, 1,   0,   0,   0,
      77,  313, 1,   0,   0,   0,   79,  316, 1,   0,   0,   0,   81,  319, 1,   0,   0,   0,   83,  321, 1,   0,   0,
      0,   85,  323, 1,   0,   0,   0,   87,  325, 1,   0,   0,   0,   89,  327, 1,   0,   0,   0,   91,  329, 1,   0,
      0,   0,   93,  332, 1,   0,   0,   0,   95,  335, 1,   0,   0,   0,   97,  337, 1,   0,   0,   0,   99,  339, 1,
      0,   0,   0,   101, 341, 1,   0,   0,   0,   103, 343, 1,   0,   0,   0,   105, 345, 1,   0,   0,   0,   107, 348,
      1,   0,   0,   0,   109, 351, 1,   0,   0,   0,   111, 354, 1,   0,   0,   0,   113, 356, 1,   0,   0,   0,   115,
      358, 1,   0,   0,   0,   117, 360, 1,   0,   0,   0,   119, 362, 1,   0,   0,   0,   121, 366, 1,   0,   0,   0,
      123, 377, 1,   0,   0,   0,   125, 126, 5,   102, 0,   0,   126, 127, 5,   34,  0,   0,   127, 128, 1,   0,   0,
      0,   128, 129, 6,   0,   0,   0,   129, 2,   1,   0,   0,   0,   130, 131, 4,   1,   0,   0,   131, 132, 5,   34,
      0,   0,   132, 133, 6,   1,   1,   0,   133, 4,   1,   0,   0,   0,   134, 135, 5,   116, 0,   0,   135, 136, 5,
      114, 0,   0,   136, 137, 5,   117, 0,   0,   137, 138, 5,   101, 0,   0,   138, 6,   1,   0,   0,   0,   139, 140,
      5,   102, 0,   0,   140, 141, 5,   97,  0,   0,   141, 142, 5,   108, 0,   0,   142, 143, 5,   115, 0,   0,   143,
      144, 5,   101, 0,   0,   144, 8,   1,   0,   0,   0,   145, 149, 7,   0,   0,   0,   146, 148, 7,   1,   0,   0,
      147, 146, 1,   0,   0,   0,   148, 151, 1,   0,   0,   0,   149, 147, 1,   0,   0,   0,   149, 150, 1,   0,   0,
      0,   150, 154, 1,   0,   0,   0,   151, 149, 1,   0,   0,   0,   152, 154, 5,   48,  0,   0,   153, 145, 1,   0,
      0,   0,   153, 152, 1,   0,   0,   0,   154, 10,  1,   0,   0,   0,   155, 156, 4,   5,   1,   0,   156, 166, 5,
      34,  0,   0,   157, 158, 5,   92,  0,   0,   158, 165, 5,   110, 0,   0,   159, 160, 5,   92,  0,   0,   160, 165,
      5,   92,  0,   0,   161, 162, 5,   92,  0,   0,   162, 165, 5,   34,  0,   0,   163, 165, 7,   2,   0,   0,   164,
      157, 1,   0,   0,   0,   164, 159, 1,   0,   0,   0,   164, 161, 1,   0,   0,   0,   164, 163, 1,   0,   0,   0,
      165, 168, 1,   0,   0,   0,   166, 164, 1,   0,   0,   0,   166, 167, 1,   0,   0,   0,   167, 169, 1,   0,   0,
      0,   168, 166, 1,   0,   0,   0,   169, 170, 5,   34,  0,   0,   170, 12,  1,   0,   0,   0,   171, 181, 4,   6,
      2,   0,   172, 173, 5,   92,  0,   0,   173, 182, 5,   110, 0,   0,   174, 175, 5,   92,  0,   0,   175, 182, 5,
      92,  0,   0,   176, 177, 5,   92,  0,   0,   177, 182, 5,   34,  0,   0,   178, 179, 5,   36,  0,   0,   179, 182,
      5,   36,  0,   0,   180, 182, 7,   3,   0,   0,   181, 172, 1,   0,   0,   0,   181, 174, 1,   0,   0,   0,   181,
      176, 1,   0,   0,   0,   181, 178, 1,   0,   0,   0,   181, 180, 1,   0,   0,   0,   182, 183, 1,   0,   0,   0,
      183, 181, 1,   0,   0,   0,   183, 184, 1,   0,   0,   0,   184, 14,  1,   0,   0,   0,   185, 186, 5,   110, 0,
      0,   186, 187, 5,   117, 0,   0,   187, 188, 5,   108, 0,   0,   188, 189, 5,   108, 0,   0,   189, 16,  1,   0,
      0,   0,   190, 191, 5,   110, 0,   0,   191, 192, 5,   101, 0,   0,   192, 193, 5,   119, 0,   0,   193, 18,  1,
      0,   0,   0,   194, 195, 5,   99,  0,   0,   195, 196, 5,   108, 0,   0,   196, 197, 5,   97,  0,   0,   197, 198,
      5,   115, 0,   0,   198, 199, 5,   115, 0,   0,   199, 20,  1,   0,   0,   0,   200, 201, 5,   116, 0,   0,   201,
      202, 5,   104, 0,   0,   202, 203, 5,   105, 0,   0,   203, 204, 5,   115, 0,   0,   204, 22,  1,   0,   0,   0,
      205, 206, 5,   105, 0,   0,   206, 207, 5,   102, 0,   0,   207, 24,  1,   0,   0,   0,   208, 209, 5,   101, 0,
      0,   209, 210, 5,   108, 0,   0,   210, 211, 5,   115, 0,   0,   211, 212, 5,   101, 0,   0,   212, 26,  1,   0,
      0,   0,   213, 214, 5,   102, 0,   0,   214, 215, 5,   111, 0,   0,   215, 216, 5,   114, 0,   0,   216, 28,  1,
      0,   0,   0,   217, 218, 5,   119, 0,   0,   218, 219, 5,   104, 0,   0,   219, 220, 5,   105, 0,   0,   220, 221,
      5,   108, 0,   0,   221, 222, 5,   101, 0,   0,   222, 30,  1,   0,   0,   0,   223, 224, 5,   98,  0,   0,   224,
      225, 5,   114, 0,   0,   225, 226, 5,   101, 0,   0,   226, 227, 5,   97,  0,   0,   227, 228, 5,   107, 0,   0,
      228, 32,  1,   0,   0,   0,   229, 230, 5,   99,  0,   0,   230, 231, 5,   111, 0,   0,   231, 232, 5,   110, 0,
      0,   232, 233, 5,   116, 0,   0,   233, 234, 5,   105, 0,   0,   234, 235, 5,   110, 0,   0,   235, 236, 5,   117,
      0,   0,   236, 237, 5,   101, 0,   0,   237, 34,  1,   0,   0,   0,   238, 239, 5,   114, 0,   0,   239, 240, 5,
      101, 0,   0,   240, 241, 5,   116, 0,   0,   241, 242, 5,   117, 0,   0,   242, 243, 5,   114, 0,   0,   243, 244,
      5,   110, 0,   0,   244, 36,  1,   0,   0,   0,   245, 246, 4,   18,  3,   0,   246, 247, 5,   109, 0,   0,   247,
      248, 5,   97,  0,   0,   248, 249, 5,   105, 0,   0,   249, 250, 5,   110, 0,   0,   250, 38,  1,   0,   0,   0,
      251, 252, 5,   98,  0,   0,   252, 253, 5,   111, 0,   0,   253, 254, 5,   111, 0,   0,   254, 255, 5,   108, 0,
      0,   255, 40,  1,   0,   0,   0,   256, 257, 5,   105, 0,   0,   257, 258, 5,   110, 0,   0,   258, 259, 5,   116,
      0,   0,   259, 42,  1,   0,   0,   0,   260, 261, 5,   118, 0,   0,   261, 262, 5,   111, 0,   0,   262, 263, 5,
      105, 0,   0,   263, 264, 5,   100, 0,   0,   264, 44,  1,   0,   0,   0,   265, 266, 5,   115, 0,   0,   266, 267,
      5,   116, 0,   0,   267, 268, 5,   114, 0,   0,   268, 269, 5,   105, 0,   0,   269, 270, 5,   110, 0,   0,   270,
      271, 5,   103, 0,   0,   271, 46,  1,   0,   0,   0,   272, 276, 7,   4,   0,   0,   273, 275, 7,   5,   0,   0,
      274, 273, 1,   0,   0,   0,   275, 278, 1,   0,   0,   0,   276, 274, 1,   0,   0,   0,   276, 277, 1,   0,   0,
      0,   277, 48,  1,   0,   0,   0,   278, 276, 1,   0,   0,   0,   279, 280, 5,   43,  0,   0,   280, 50,  1,   0,
      0,   0,   281, 282, 5,   45,  0,   0,   282, 52,  1,   0,   0,   0,   283, 284, 5,   42,  0,   0,   284, 54,  1,
      0,   0,   0,   285, 286, 5,   47,  0,   0,   286, 56,  1,   0,   0,   0,   287, 288, 5,   37,  0,   0,   288, 58,
      1,   0,   0,   0,   289, 290, 5,   60,  0,   0,   290, 60,  1,   0,   0,   0,   291, 292, 5,   60,  0,   0,   292,
      293, 5,   61,  0,   0,   293, 62,  1,   0,   0,   0,   294, 295, 5,   62,  0,   0,   295, 64,  1,   0,   0,   0,
      296, 297, 5,   62,  0,   0,   297, 298, 5,   61,  0,   0,   298, 66,  1,   0,   0,   0,   299, 300, 5,   61,  0,
      0,   300, 301, 5,   61,  0,   0,   301, 68,  1,   0,   0,   0,   302, 303, 5,   33,  0,   0,   303, 304, 5,   61,
      0,   0,   304, 70,  1,   0,   0,   0,   305, 306, 5,   38,  0,   0,   306, 307, 5,   38,  0,   0,   307, 72,  1,
      0,   0,   0,   308, 309, 5,   124, 0,   0,   309, 310, 5,   124, 0,   0,   310, 74,  1,   0,   0,   0,   311, 312,
      5,   33,  0,   0,   312, 76,  1,   0,   0,   0,   313, 314, 5,   62,  0,   0,   314, 315, 5,   62,  0,   0,   315,
      78,  1,   0,   0,   0,   316, 317, 5,   60,  0,   0,   317, 318, 5,   60,  0,   0,   318, 80,  1,   0,   0,   0,
      319, 320, 5,   38,  0,   0,   320, 82,  1,   0,   0,   0,   321, 322, 5,   124, 0,   0,   322, 84,  1,   0,   0,
      0,   323, 324, 5,   94,  0,   0,   324, 86,  1,   0,   0,   0,   325, 326, 5,   126, 0,   0,   326, 88,  1,   0,
      0,   0,   327, 328, 5,   61,  0,   0,   328, 90,  1,   0,   0,   0,   329, 330, 5,   43,  0,   0,   330, 331, 5,
      43,  0,   0,   331, 92,  1,   0,   0,   0,   332, 333, 5,   45,  0,   0,   333, 334, 5,   45,  0,   0,   334, 94,
      1,   0,   0,   0,   335, 336, 5,   46,  0,   0,   336, 96,  1,   0,   0,   0,   337, 338, 5,   40,  0,   0,   338,
      98,  1,   0,   0,   0,   339, 340, 5,   41,  0,   0,   340, 100, 1,   0,   0,   0,   341, 342, 5,   91,  0,   0,
      342, 102, 1,   0,   0,   0,   343, 344, 5,   93,  0,   0,   344, 104, 1,   0,   0,   0,   345, 346, 5,   123, 0,
      0,   346, 347, 6,   52,  2,   0,   347, 106, 1,   0,   0,   0,   348, 349, 5,   125, 0,   0,   349, 350, 6,   53,
      3,   0,   350, 108, 1,   0,   0,   0,   351, 352, 5,   36,  0,   0,   352, 353, 6,   54,  4,   0,   353, 110, 1,
      0,   0,   0,   354, 355, 5,   63,  0,   0,   355, 112, 1,   0,   0,   0,   356, 357, 5,   58,  0,   0,   357, 114,
      1,   0,   0,   0,   358, 359, 5,   59,  0,   0,   359, 116, 1,   0,   0,   0,   360, 361, 5,   44,  0,   0,   361,
      118, 1,   0,   0,   0,   362, 363, 7,   6,   0,   0,   363, 364, 1,   0,   0,   0,   364, 365, 6,   59,  5,   0,
      365, 120, 1,   0,   0,   0,   366, 367, 5,   47,  0,   0,   367, 368, 5,   47,  0,   0,   368, 372, 1,   0,   0,
      0,   369, 371, 8,   7,   0,   0,   370, 369, 1,   0,   0,   0,   371, 374, 1,   0,   0,   0,   372, 370, 1,   0,
      0,   0,   372, 373, 1,   0,   0,   0,   373, 375, 1,   0,   0,   0,   374, 372, 1,   0,   0,   0,   375, 376, 6,
      60,  5,   0,   376, 122, 1,   0,   0,   0,   377, 378, 5,   47,  0,   0,   378, 379, 5,   42,  0,   0,   379, 383,
      1,   0,   0,   0,   380, 382, 9,   0,   0,   0,   381, 380, 1,   0,   0,   0,   382, 385, 1,   0,   0,   0,   383,
      384, 1,   0,   0,   0,   383, 381, 1,   0,   0,   0,   384, 386, 1,   0,   0,   0,   385, 383, 1,   0,   0,   0,
      386, 387, 5,   42,  0,   0,   387, 388, 5,   47,  0,   0,   388, 389, 1,   0,   0,   0,   389, 390, 6,   61,  5,
      0,   390, 124, 1,   0,   0,   0,   10,  0,   149, 153, 164, 166, 181, 183, 276, 372, 383, 6,   1,   0,   0,   1,
      1,   1,   1,   52,  2,   1,   53,  3,   1,   54,  4,   6,   0,   0};
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
    case 0:
      FormatQuatationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;
    case 1:
      QuotationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;
    case 52:
      LeftBraceAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
      break;
    case 53:
      RightBraceAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex);
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
    case 1:
      return QuotationSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 5:
      return StringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 6:
      return FormatStringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 18:
      return MainSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void MxLexer::LeftBraceAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:
      ++bracketDepth;
      break;

    default:
      break;
  }
}

void MxLexer::RightBraceAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:
      --bracketDepth;
      break;

    default:
      break;
  }
}

void MxLexer::DollarAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:
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

bool MxLexer::MainSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3:
      return bracketDepth == 0;

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
