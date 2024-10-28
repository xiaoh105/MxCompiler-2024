
// Generated from Mx.g4 by ANTLR 4.13.1

#include "parser/MxVisitor.h"

#include "parser/MxParser.h"

using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MxParserStaticData final {
  MxParserStaticData(std::vector<std::string> ruleNames, std::vector<std::string> literalNames,
                     std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)),
        literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxParserStaticData(const MxParserStaticData &) = delete;
  MxParserStaticData(MxParserStaticData &&) = delete;
  MxParserStaticData &operator=(const MxParserStaticData &) = delete;
  MxParserStaticData &operator=(MxParserStaticData &&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
    MxParserStaticData *mxParserStaticData = nullptr;

void mxParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxParserStaticData != nullptr) {
    return;
  }
#else
  assert(mxParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxParserStaticData>(
      std::vector<std::string>{"program", "mainFunc", "classDef", "classStmt", "funcDef", "varDef", "statement",
                               "expression", "suite", "arguments", "primary", "array", "literal", "type"},
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
      4,   1,   62,  404, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,   4,   7,
      4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,   2,   10,
      7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  1,   0,   1,   0,   1,   0,   5,   0,   32,
      8,   0,   10,  0,   12,  0,   35,  9,   0,   1,   0,   1,   0,   1,   0,   1,   0,   5,   0,   41,  8,   0,   10,
      0,   12,  0,   44,  9,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      2,   1,   2,   1,   2,   1,   2,   5,   2,   58,  8,   2,   10,  2,   12,  2,   61,  9,   2,   1,   2,   1,   2,
      1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   5,   3,   70,  8,   3,   10,  3,   12,  3,   73,  9,   3,   1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,
      1,   3,   1,   3,   1,   3,   5,   3,   90,  8,   3,   10,  3,   12,  3,   93,  9,   3,   3,   3,   95,  8,   3,
      1,   3,   1,   3,   1,   3,   3,   3,   100, 8,   3,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,
      1,   4,   1,   4,   1,   4,   5,   4,   111, 8,   4,   10,  4,   12,  4,   114, 9,   4,   3,   4,   116, 8,   4,
      1,   4,   1,   4,   1,   4,   1,   5,   1,   5,   1,   5,   1,   5,   3,   5,   125, 8,   5,   1,   5,   1,   5,
      1,   5,   1,   5,   3,   5,   131, 8,   5,   5,   5,   133, 8,   5,   10,  5,   12,  5,   136, 9,   5,   1,   5,
      1,   5,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,   144, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,
      3,   6,   150, 8,   6,   5,   6,   152, 8,   6,   10,  6,   12,  6,   155, 9,   6,   1,   6,   1,   6,   1,   6,
      1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,   170,
      8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,
      6,   182, 8,   6,   1,   6,   1,   6,   3,   6,   186, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,
      3,   6,   193, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,   201, 8,   6,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      5,   7,   215, 8,   7,   10,  7,   12,  7,   218, 9,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   224,
      8,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   233, 8,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,
      281, 8,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   4,   7,   289, 8,   7,   11,  7,   12,
      7,   290, 1,   7,   1,   7,   1,   7,   5,   7,   296, 8,   7,   10,  7,   12,  7,   299, 9,   7,   1,   8,   1,
      8,   5,   8,   303, 8,   8,   10,  8,   12,  8,   306, 9,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,
      5,   9,   313, 8,   9,   10,  9,   12,  9,   316, 9,   9,   1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,
      10,  1,   10,  1,   10,  1,   10,  4,   10,  327, 8,   10,  11,  10,  12,  10,  328, 1,   10,  1,   10,  5,   10,
      333, 8,   10,  10,  10,  12,  10,  336, 9,   10,  1,   10,  1,   10,  1,   10,  1,   10,  4,   10,  342, 8,   10,
      11,  10,  12,  10,  343, 1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  3,   10,  352, 8,   10,  3,
      10,  354, 8,   10,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  5,   11,  362, 8,   11,  10,  11,
      12,  11,  365, 9,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  5,   11,  373, 8,   11,  10,
      11,  12,  11,  376, 9,   11,  1,   11,  1,   11,  3,   11,  380, 8,   11,  1,   12,  1,   12,  1,   12,  1,   12,
      1,   12,  1,   12,  3,   12,  388, 8,   12,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,
      1,   13,  4,   13,  398, 8,   13,  11,  13,  12,  13,  399, 3,   13,  402, 8,   13,  1,   13,  0,   1,   14,  14,
      0,   2,   4,   6,   8,   10,  12,  14,  16,  18,  20,  22,  24,  26,  0,   8,   1,   0,   46,  47,  1,   0,   25,
      26,  2,   0,   38,  38,  44,  44,  1,   0,   27,  29,  1,   0,   39,  40,  1,   0,   30,  33,  1,   0,   34,  35,
      2,   0,   20,  21,  23,  24,  475, 0,   33,  1,   0,   0,   0,   2,   47,  1,   0,   0,   0,   4,   53,  1,   0,
      0,   0,   6,   99,  1,   0,   0,   0,   8,   101, 1,   0,   0,   0,   10,  120, 1,   0,   0,   0,   12,  200, 1,
      0,   0,   0,   14,  232, 1,   0,   0,   0,   16,  300, 1,   0,   0,   0,   18,  309, 1,   0,   0,   0,   20,  353,
      1,   0,   0,   0,   22,  379, 1,   0,   0,   0,   24,  387, 1,   0,   0,   0,   26,  401, 1,   0,   0,   0,   28,
      32,  3,   4,   2,   0,   29,  32,  3,   8,   4,   0,   30,  32,  3,   10,  5,   0,   31,  28,  1,   0,   0,   0,
      31,  29,  1,   0,   0,   0,   31,  30,  1,   0,   0,   0,   32,  35,  1,   0,   0,   0,   33,  31,  1,   0,   0,
      0,   33,  34,  1,   0,   0,   0,   34,  36,  1,   0,   0,   0,   35,  33,  1,   0,   0,   0,   36,  42,  3,   2,
      1,   0,   37,  41,  3,   4,   2,   0,   38,  41,  3,   8,   4,   0,   39,  41,  3,   10,  5,   0,   40,  37,  1,
      0,   0,   0,   40,  38,  1,   0,   0,   0,   40,  39,  1,   0,   0,   0,   41,  44,  1,   0,   0,   0,   42,  40,
      1,   0,   0,   0,   42,  43,  1,   0,   0,   0,   43,  45,  1,   0,   0,   0,   44,  42,  1,   0,   0,   0,   45,
      46,  5,   0,   0,   1,   46,  1,   1,   0,   0,   0,   47,  48,  5,   21,  0,   0,   48,  49,  5,   19,  0,   0,
      49,  50,  5,   49,  0,   0,   50,  51,  5,   50,  0,   0,   51,  52,  3,   16,  8,   0,   52,  3,   1,   0,   0,
      0,   53,  54,  5,   10,  0,   0,   54,  55,  5,   24,  0,   0,   55,  59,  5,   53,  0,   0,   56,  58,  3,   6,
      3,   0,   57,  56,  1,   0,   0,   0,   58,  61,  1,   0,   0,   0,   59,  57,  1,   0,   0,   0,   59,  60,  1,
      0,   0,   0,   60,  62,  1,   0,   0,   0,   61,  59,  1,   0,   0,   0,   62,  63,  5,   54,  0,   0,   63,  64,
      5,   58,  0,   0,   64,  5,   1,   0,   0,   0,   65,  66,  3,   26,  13,  0,   66,  71,  5,   24,  0,   0,   67,
      68,  5,   59,  0,   0,   68,  70,  5,   24,  0,   0,   69,  67,  1,   0,   0,   0,   70,  73,  1,   0,   0,   0,
      71,  69,  1,   0,   0,   0,   71,  72,  1,   0,   0,   0,   72,  74,  1,   0,   0,   0,   73,  71,  1,   0,   0,
      0,   74,  75,  5,   58,  0,   0,   75,  100, 1,   0,   0,   0,   76,  77,  5,   24,  0,   0,   77,  78,  5,   49,
      0,   0,   78,  79,  5,   50,  0,   0,   79,  100, 3,   16,  8,   0,   80,  81,  3,   26,  13,  0,   81,  82,  5,
      24,  0,   0,   82,  94,  5,   49,  0,   0,   83,  84,  3,   26,  13,  0,   84,  91,  5,   24,  0,   0,   85,  86,
      5,   59,  0,   0,   86,  87,  3,   26,  13,  0,   87,  88,  5,   24,  0,   0,   88,  90,  1,   0,   0,   0,   89,
      85,  1,   0,   0,   0,   90,  93,  1,   0,   0,   0,   91,  89,  1,   0,   0,   0,   91,  92,  1,   0,   0,   0,
      92,  95,  1,   0,   0,   0,   93,  91,  1,   0,   0,   0,   94,  83,  1,   0,   0,   0,   94,  95,  1,   0,   0,
      0,   95,  96,  1,   0,   0,   0,   96,  97,  5,   50,  0,   0,   97,  98,  3,   16,  8,   0,   98,  100, 1,   0,
      0,   0,   99,  65,  1,   0,   0,   0,   99,  76,  1,   0,   0,   0,   99,  80,  1,   0,   0,   0,   100, 7,   1,
      0,   0,   0,   101, 102, 3,   26,  13,  0,   102, 103, 5,   24,  0,   0,   103, 115, 5,   49,  0,   0,   104, 105,
      3,   26,  13,  0,   105, 112, 5,   24,  0,   0,   106, 107, 5,   59,  0,   0,   107, 108, 3,   26,  13,  0,   108,
      109, 5,   24,  0,   0,   109, 111, 1,   0,   0,   0,   110, 106, 1,   0,   0,   0,   111, 114, 1,   0,   0,   0,
      112, 110, 1,   0,   0,   0,   112, 113, 1,   0,   0,   0,   113, 116, 1,   0,   0,   0,   114, 112, 1,   0,   0,
      0,   115, 104, 1,   0,   0,   0,   115, 116, 1,   0,   0,   0,   116, 117, 1,   0,   0,   0,   117, 118, 5,   50,
      0,   0,   118, 119, 3,   16,  8,   0,   119, 9,   1,   0,   0,   0,   120, 121, 3,   26,  13,  0,   121, 124, 5,
      24,  0,   0,   122, 123, 5,   45,  0,   0,   123, 125, 3,   14,  7,   0,   124, 122, 1,   0,   0,   0,   124, 125,
      1,   0,   0,   0,   125, 134, 1,   0,   0,   0,   126, 127, 5,   59,  0,   0,   127, 130, 5,   24,  0,   0,   128,
      129, 5,   45,  0,   0,   129, 131, 3,   14,  7,   0,   130, 128, 1,   0,   0,   0,   130, 131, 1,   0,   0,   0,
      131, 133, 1,   0,   0,   0,   132, 126, 1,   0,   0,   0,   133, 136, 1,   0,   0,   0,   134, 132, 1,   0,   0,
      0,   134, 135, 1,   0,   0,   0,   135, 137, 1,   0,   0,   0,   136, 134, 1,   0,   0,   0,   137, 138, 5,   58,
      0,   0,   138, 11,  1,   0,   0,   0,   139, 140, 3,   26,  13,  0,   140, 143, 5,   24,  0,   0,   141, 142, 5,
      45,  0,   0,   142, 144, 3,   14,  7,   0,   143, 141, 1,   0,   0,   0,   143, 144, 1,   0,   0,   0,   144, 153,
      1,   0,   0,   0,   145, 146, 5,   59,  0,   0,   146, 149, 5,   24,  0,   0,   147, 148, 5,   45,  0,   0,   148,
      150, 3,   14,  7,   0,   149, 147, 1,   0,   0,   0,   149, 150, 1,   0,   0,   0,   150, 152, 1,   0,   0,   0,
      151, 145, 1,   0,   0,   0,   152, 155, 1,   0,   0,   0,   153, 151, 1,   0,   0,   0,   153, 154, 1,   0,   0,
      0,   154, 156, 1,   0,   0,   0,   155, 153, 1,   0,   0,   0,   156, 157, 5,   58,  0,   0,   157, 201, 1,   0,
      0,   0,   158, 201, 3,   16,  8,   0,   159, 160, 3,   14,  7,   0,   160, 161, 5,   58,  0,   0,   161, 201, 1,
      0,   0,   0,   162, 163, 5,   12,  0,   0,   163, 164, 5,   49,  0,   0,   164, 165, 3,   14,  7,   0,   165, 166,
      5,   50,  0,   0,   166, 169, 3,   12,  6,   0,   167, 168, 5,   13,  0,   0,   168, 170, 3,   12,  6,   0,   169,
      167, 1,   0,   0,   0,   169, 170, 1,   0,   0,   0,   170, 201, 1,   0,   0,   0,   171, 172, 5,   15,  0,   0,
      172, 173, 5,   49,  0,   0,   173, 174, 3,   14,  7,   0,   174, 175, 5,   50,  0,   0,   175, 176, 3,   12,  6,
      0,   176, 201, 1,   0,   0,   0,   177, 178, 5,   14,  0,   0,   178, 179, 5,   49,  0,   0,   179, 181, 3,   12,
      6,   0,   180, 182, 3,   14,  7,   0,   181, 180, 1,   0,   0,   0,   181, 182, 1,   0,   0,   0,   182, 183, 1,
      0,   0,   0,   183, 185, 5,   58,  0,   0,   184, 186, 3,   14,  7,   0,   185, 184, 1,   0,   0,   0,   185, 186,
      1,   0,   0,   0,   186, 187, 1,   0,   0,   0,   187, 188, 5,   50,  0,   0,   188, 189, 3,   12,  6,   0,   189,
      201, 1,   0,   0,   0,   190, 192, 5,   18,  0,   0,   191, 193, 3,   14,  7,   0,   192, 191, 1,   0,   0,   0,
      192, 193, 1,   0,   0,   0,   193, 194, 1,   0,   0,   0,   194, 201, 5,   58,  0,   0,   195, 196, 5,   16,  0,
      0,   196, 201, 5,   58,  0,   0,   197, 198, 5,   17,  0,   0,   198, 201, 5,   58,  0,   0,   199, 201, 5,   58,
      0,   0,   200, 139, 1,   0,   0,   0,   200, 158, 1,   0,   0,   0,   200, 159, 1,   0,   0,   0,   200, 162, 1,
      0,   0,   0,   200, 171, 1,   0,   0,   0,   200, 177, 1,   0,   0,   0,   200, 190, 1,   0,   0,   0,   200, 195,
      1,   0,   0,   0,   200, 197, 1,   0,   0,   0,   200, 199, 1,   0,   0,   0,   201, 13,  1,   0,   0,   0,   202,
      203, 6,   7,   -1,  0,   203, 204, 5,   49,  0,   0,   204, 205, 3,   14,  7,   0,   205, 206, 5,   50,  0,   0,
      206, 233, 1,   0,   0,   0,   207, 233, 3,   20,  10,  0,   208, 216, 5,   1,   0,   0,   209, 215, 5,   7,   0,
      0,   210, 211, 5,   55,  0,   0,   211, 212, 3,   14,  7,   0,   212, 213, 5,   55,  0,   0,   213, 215, 1,   0,
      0,   0,   214, 209, 1,   0,   0,   0,   214, 210, 1,   0,   0,   0,   215, 218, 1,   0,   0,   0,   216, 214, 1,
      0,   0,   0,   216, 217, 1,   0,   0,   0,   217, 219, 1,   0,   0,   0,   218, 216, 1,   0,   0,   0,   219, 233,
      5,   2,   0,   0,   220, 221, 5,   24,  0,   0,   221, 223, 5,   49,  0,   0,   222, 224, 3,   18,  9,   0,   223,
      222, 1,   0,   0,   0,   223, 224, 1,   0,   0,   0,   224, 225, 1,   0,   0,   0,   225, 233, 5,   50,  0,   0,
      226, 227, 7,   0,   0,   0,   227, 233, 3,   14,  7,   15,  228, 229, 7,   1,   0,   0,   229, 233, 3,   14,  7,
      14,  230, 231, 7,   2,   0,   0,   231, 233, 3,   14,  7,   13,  232, 202, 1,   0,   0,   0,   232, 207, 1,   0,
      0,   0,   232, 208, 1,   0,   0,   0,   232, 220, 1,   0,   0,   0,   232, 226, 1,   0,   0,   0,   232, 228, 1,
      0,   0,   0,   232, 230, 1,   0,   0,   0,   233, 297, 1,   0,   0,   0,   234, 235, 10,  12,  0,   0,   235, 236,
      7,   3,   0,   0,   236, 296, 3,   14,  7,   13,  237, 238, 10,  11,  0,   0,   238, 239, 7,   1,   0,   0,   239,
      296, 3,   14,  7,   12,  240, 241, 10,  10,  0,   0,   241, 242, 7,   4,   0,   0,   242, 296, 3,   14,  7,   11,
      243, 244, 10,  9,   0,   0,   244, 245, 7,   5,   0,   0,   245, 296, 3,   14,  7,   10,  246, 247, 10,  8,   0,
      0,   247, 248, 7,   6,   0,   0,   248, 296, 3,   14,  7,   9,   249, 250, 10,  7,   0,   0,   250, 251, 5,   41,
      0,   0,   251, 296, 3,   14,  7,   8,   252, 253, 10,  6,   0,   0,   253, 254, 5,   43,  0,   0,   254, 296, 3,
      14,  7,   7,   255, 256, 10,  5,   0,   0,   256, 257, 5,   42,  0,   0,   257, 296, 3,   14,  7,   6,   258, 259,
      10,  4,   0,   0,   259, 260, 5,   36,  0,   0,   260, 296, 3,   14,  7,   5,   261, 262, 10,  3,   0,   0,   262,
      263, 5,   37,  0,   0,   263, 296, 3,   14,  7,   4,   264, 265, 10,  2,   0,   0,   265, 266, 5,   56,  0,   0,
      266, 267, 3,   14,  7,   0,   267, 268, 5,   57,  0,   0,   268, 269, 3,   14,  7,   2,   269, 296, 1,   0,   0,
      0,   270, 271, 10,  1,   0,   0,   271, 272, 5,   45,  0,   0,   272, 296, 3,   14,  7,   2,   273, 274, 10,  20,
      0,   0,   274, 296, 7,   0,   0,   0,   275, 276, 10,  18,  0,   0,   276, 277, 5,   48,  0,   0,   277, 278, 5,
      24,  0,   0,   278, 280, 5,   49,  0,   0,   279, 281, 3,   18,  9,   0,   280, 279, 1,   0,   0,   0,   280, 281,
      1,   0,   0,   0,   281, 282, 1,   0,   0,   0,   282, 296, 5,   50,  0,   0,   283, 288, 10,  17,  0,   0,   284,
      285, 5,   51,  0,   0,   285, 286, 3,   14,  7,   0,   286, 287, 5,   52,  0,   0,   287, 289, 1,   0,   0,   0,
      288, 284, 1,   0,   0,   0,   289, 290, 1,   0,   0,   0,   290, 288, 1,   0,   0,   0,   290, 291, 1,   0,   0,
      0,   291, 296, 1,   0,   0,   0,   292, 293, 10,  16,  0,   0,   293, 294, 5,   48,  0,   0,   294, 296, 5,   24,
      0,   0,   295, 234, 1,   0,   0,   0,   295, 237, 1,   0,   0,   0,   295, 240, 1,   0,   0,   0,   295, 243, 1,
      0,   0,   0,   295, 246, 1,   0,   0,   0,   295, 249, 1,   0,   0,   0,   295, 252, 1,   0,   0,   0,   295, 255,
      1,   0,   0,   0,   295, 258, 1,   0,   0,   0,   295, 261, 1,   0,   0,   0,   295, 264, 1,   0,   0,   0,   295,
      270, 1,   0,   0,   0,   295, 273, 1,   0,   0,   0,   295, 275, 1,   0,   0,   0,   295, 283, 1,   0,   0,   0,
      295, 292, 1,   0,   0,   0,   296, 299, 1,   0,   0,   0,   297, 295, 1,   0,   0,   0,   297, 298, 1,   0,   0,
      0,   298, 15,  1,   0,   0,   0,   299, 297, 1,   0,   0,   0,   300, 304, 5,   53,  0,   0,   301, 303, 3,   12,
      6,   0,   302, 301, 1,   0,   0,   0,   303, 306, 1,   0,   0,   0,   304, 302, 1,   0,   0,   0,   304, 305, 1,
      0,   0,   0,   305, 307, 1,   0,   0,   0,   306, 304, 1,   0,   0,   0,   307, 308, 5,   54,  0,   0,   308, 17,
      1,   0,   0,   0,   309, 314, 3,   14,  7,   0,   310, 311, 5,   59,  0,   0,   311, 313, 3,   14,  7,   0,   312,
      310, 1,   0,   0,   0,   313, 316, 1,   0,   0,   0,   314, 312, 1,   0,   0,   0,   314, 315, 1,   0,   0,   0,
      315, 19,  1,   0,   0,   0,   316, 314, 1,   0,   0,   0,   317, 354, 3,   24,  12,  0,   318, 354, 5,   24,  0,
      0,   319, 354, 5,   11,  0,   0,   320, 321, 5,   9,   0,   0,   321, 326, 3,   26,  13,  0,   322, 323, 5,   51,
      0,   0,   323, 324, 3,   14,  7,   0,   324, 325, 5,   52,  0,   0,   325, 327, 1,   0,   0,   0,   326, 322, 1,
      0,   0,   0,   327, 328, 1,   0,   0,   0,   328, 326, 1,   0,   0,   0,   328, 329, 1,   0,   0,   0,   329, 334,
      1,   0,   0,   0,   330, 331, 5,   51,  0,   0,   331, 333, 5,   52,  0,   0,   332, 330, 1,   0,   0,   0,   333,
      336, 1,   0,   0,   0,   334, 332, 1,   0,   0,   0,   334, 335, 1,   0,   0,   0,   335, 354, 1,   0,   0,   0,
      336, 334, 1,   0,   0,   0,   337, 338, 5,   9,   0,   0,   338, 341, 3,   26,  13,  0,   339, 340, 5,   51,  0,
      0,   340, 342, 5,   52,  0,   0,   341, 339, 1,   0,   0,   0,   342, 343, 1,   0,   0,   0,   343, 341, 1,   0,
      0,   0,   343, 344, 1,   0,   0,   0,   344, 345, 1,   0,   0,   0,   345, 346, 3,   22,  11,  0,   346, 354, 1,
      0,   0,   0,   347, 348, 5,   9,   0,   0,   348, 351, 3,   26,  13,  0,   349, 350, 5,   49,  0,   0,   350, 352,
      5,   50,  0,   0,   351, 349, 1,   0,   0,   0,   351, 352, 1,   0,   0,   0,   352, 354, 1,   0,   0,   0,   353,
      317, 1,   0,   0,   0,   353, 318, 1,   0,   0,   0,   353, 319, 1,   0,   0,   0,   353, 320, 1,   0,   0,   0,
      353, 337, 1,   0,   0,   0,   353, 347, 1,   0,   0,   0,   354, 21,  1,   0,   0,   0,   355, 356, 5,   53,  0,
      0,   356, 380, 5,   54,  0,   0,   357, 358, 5,   53,  0,   0,   358, 363, 3,   22,  11,  0,   359, 360, 5,   59,
      0,   0,   360, 362, 3,   22,  11,  0,   361, 359, 1,   0,   0,   0,   362, 365, 1,   0,   0,   0,   363, 361, 1,
      0,   0,   0,   363, 364, 1,   0,   0,   0,   364, 366, 1,   0,   0,   0,   365, 363, 1,   0,   0,   0,   366, 367,
      5,   54,  0,   0,   367, 380, 1,   0,   0,   0,   368, 369, 5,   53,  0,   0,   369, 374, 3,   24,  12,  0,   370,
      371, 5,   59,  0,   0,   371, 373, 3,   24,  12,  0,   372, 370, 1,   0,   0,   0,   373, 376, 1,   0,   0,   0,
      374, 372, 1,   0,   0,   0,   374, 375, 1,   0,   0,   0,   375, 377, 1,   0,   0,   0,   376, 374, 1,   0,   0,
      0,   377, 378, 5,   54,  0,   0,   378, 380, 1,   0,   0,   0,   379, 355, 1,   0,   0,   0,   379, 357, 1,   0,
      0,   0,   379, 368, 1,   0,   0,   0,   380, 23,  1,   0,   0,   0,   381, 388, 5,   5,   0,   0,   382, 388, 5,
      3,   0,   0,   383, 388, 5,   4,   0,   0,   384, 388, 5,   6,   0,   0,   385, 388, 5,   8,   0,   0,   386, 388,
      3,   22,  11,  0,   387, 381, 1,   0,   0,   0,   387, 382, 1,   0,   0,   0,   387, 383, 1,   0,   0,   0,   387,
      384, 1,   0,   0,   0,   387, 385, 1,   0,   0,   0,   387, 386, 1,   0,   0,   0,   388, 25,  1,   0,   0,   0,
      389, 402, 5,   21,  0,   0,   390, 402, 5,   20,  0,   0,   391, 402, 5,   23,  0,   0,   392, 402, 5,   24,  0,
      0,   393, 402, 5,   22,  0,   0,   394, 397, 7,   7,   0,   0,   395, 396, 5,   51,  0,   0,   396, 398, 5,   52,
      0,   0,   397, 395, 1,   0,   0,   0,   398, 399, 1,   0,   0,   0,   399, 397, 1,   0,   0,   0,   399, 400, 1,
      0,   0,   0,   400, 402, 1,   0,   0,   0,   401, 389, 1,   0,   0,   0,   401, 390, 1,   0,   0,   0,   401, 391,
      1,   0,   0,   0,   401, 392, 1,   0,   0,   0,   401, 393, 1,   0,   0,   0,   401, 394, 1,   0,   0,   0,   402,
      27,  1,   0,   0,   0,   43,  31,  33,  40,  42,  59,  71,  91,  94,  99,  112, 115, 124, 130, 134, 143, 149, 153,
      169, 181, 185, 192, 200, 214, 216, 223, 232, 280, 290, 295, 297, 304, 314, 328, 334, 343, 351, 353, 363, 374, 379,
      387, 399, 401};
  staticData->serializedATN = antlr4::atn::SerializedATNView(
      serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxParserStaticData = staticData.release();
}

}  // namespace

MxParser::MxParser(TokenStream *input) : MxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MxParser::MxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mxParserStaticData->atn, mxParserStaticData->decisionToDFA,
                                             mxParserStaticData->sharedContextCache, options);
}

MxParser::~MxParser() { delete _interpreter; }

const atn::ATN &MxParser::getATN() const { return *mxParserStaticData->atn; }

std::string MxParser::getGrammarFileName() const { return "Mx.g4"; }

const std::vector<std::string> &MxParser::getRuleNames() const { return mxParserStaticData->ruleNames; }

const dfa::Vocabulary &MxParser::getVocabulary() const { return mxParserStaticData->vocabulary; }

antlr4::atn::SerializedATNView MxParser::getSerializedATN() const { return mxParserStaticData->serializedATN; }

//----------------- ProgramContext ------------------------------------------------------------------

MxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

MxParser::MainFuncContext *MxParser::ProgramContext::mainFunc() { return getRuleContext<MxParser::MainFuncContext>(0); }

tree::TerminalNode *MxParser::ProgramContext::EOF() { return getToken(MxParser::EOF, 0); }

std::vector<MxParser::ClassDefContext *> MxParser::ProgramContext::classDef() {
  return getRuleContexts<MxParser::ClassDefContext>();
}

MxParser::ClassDefContext *MxParser::ProgramContext::classDef(size_t i) {
  return getRuleContext<MxParser::ClassDefContext>(i);
}

std::vector<MxParser::FuncDefContext *> MxParser::ProgramContext::funcDef() {
  return getRuleContexts<MxParser::FuncDefContext>();
}

MxParser::FuncDefContext *MxParser::ProgramContext::funcDef(size_t i) {
  return getRuleContext<MxParser::FuncDefContext>(i);
}

std::vector<MxParser::VarDefContext *> MxParser::ProgramContext::varDef() {
  return getRuleContexts<MxParser::VarDefContext>();
}

MxParser::VarDefContext *MxParser::ProgramContext::varDef(size_t i) {
  return getRuleContext<MxParser::VarDefContext>(i);
}

size_t MxParser::ProgramContext::getRuleIndex() const { return MxParser::RuleProgram; }

std::any MxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ProgramContext *MxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(31);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
          case 1: {
            setState(28);
            classDef();
            break;
          }

          case 2: {
            setState(29);
            funcDef();
            break;
          }

          case 3: {
            setState(30);
            varDef();
            break;
          }

          default:
            break;
        }
      }
      setState(35);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(36);
    mainFunc();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32506880) != 0)) {
      setState(40);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(37);
          classDef();
          break;
        }

        case 2: {
          setState(38);
          funcDef();
          break;
        }

        case 3: {
          setState(39);
          varDef();
          break;
        }

        default:
          break;
      }
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
    match(MxParser::EOF);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainFuncContext ------------------------------------------------------------------

MxParser::MainFuncContext::MainFuncContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::MainFuncContext::Int() { return getToken(MxParser::Int, 0); }

tree::TerminalNode *MxParser::MainFuncContext::Main() { return getToken(MxParser::Main, 0); }

tree::TerminalNode *MxParser::MainFuncContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::MainFuncContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::SuiteContext *MxParser::MainFuncContext::suite() { return getRuleContext<MxParser::SuiteContext>(0); }

size_t MxParser::MainFuncContext::getRuleIndex() const { return MxParser::RuleMainFunc; }

std::any MxParser::MainFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitMainFunc(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MainFuncContext *MxParser::mainFunc() {
  MainFuncContext *_localctx = _tracker.createInstance<MainFuncContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleMainFunc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(MxParser::Int);
    setState(48);
    match(MxParser::Main);
    setState(49);
    match(MxParser::LeftParen);
    setState(50);
    match(MxParser::RightParen);
    setState(51);
    suite();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

MxParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::ClassDefContext::Class() { return getToken(MxParser::Class, 0); }

tree::TerminalNode *MxParser::ClassDefContext::LeftBrace() { return getToken(MxParser::LeftBrace, 0); }

tree::TerminalNode *MxParser::ClassDefContext::RightBrace() { return getToken(MxParser::RightBrace, 0); }

tree::TerminalNode *MxParser::ClassDefContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

tree::TerminalNode *MxParser::ClassDefContext::Identifier() { return getToken(MxParser::Identifier, 0); }

std::vector<MxParser::ClassStmtContext *> MxParser::ClassDefContext::classStmt() {
  return getRuleContexts<MxParser::ClassStmtContext>();
}

MxParser::ClassStmtContext *MxParser::ClassDefContext::classStmt(size_t i) {
  return getRuleContext<MxParser::ClassStmtContext>(i);
}

size_t MxParser::ClassDefContext::getRuleIndex() const { return MxParser::RuleClassDef; }

std::any MxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDefContext *MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleClassDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(MxParser::Class);
    setState(54);
    antlrcpp::downCast<ClassDefContext *>(_localctx)->classIdentifier = match(MxParser::Identifier);
    setState(55);
    match(MxParser::LeftBrace);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32505856) != 0)) {
      setState(56);
      classStmt();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(MxParser::RightBrace);
    setState(63);
    match(MxParser::Semicolon);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassStmtContext ------------------------------------------------------------------

MxParser::ClassStmtContext::ClassStmtContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t MxParser::ClassStmtContext::getRuleIndex() const { return MxParser::RuleClassStmt; }

void MxParser::ClassStmtContext::copyFrom(ClassStmtContext *ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- MemberDefStmtContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> MxParser::MemberDefStmtContext::Identifier() {
  return getTokens(MxParser::Identifier);
}

tree::TerminalNode *MxParser::MemberDefStmtContext::Identifier(size_t i) { return getToken(MxParser::Identifier, i); }

tree::TerminalNode *MxParser::MemberDefStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::TypeContext *MxParser::MemberDefStmtContext::type() { return getRuleContext<MxParser::TypeContext>(0); }

std::vector<tree::TerminalNode *> MxParser::MemberDefStmtContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::MemberDefStmtContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

MxParser::MemberDefStmtContext::MemberDefStmtContext(ClassStmtContext *ctx) { copyFrom(ctx); }

std::any MxParser::MemberDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitMemberDefStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstructorDefStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ConstructorDefStmtContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::ConstructorDefStmtContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::SuiteContext *MxParser::ConstructorDefStmtContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}

tree::TerminalNode *MxParser::ConstructorDefStmtContext::Identifier() { return getToken(MxParser::Identifier, 0); }

MxParser::ConstructorDefStmtContext::ConstructorDefStmtContext(ClassStmtContext *ctx) { copyFrom(ctx); }

std::any MxParser::ConstructorDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitConstructorDefStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncDefStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::FuncDefStmtContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::FuncDefStmtContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::SuiteContext *MxParser::FuncDefStmtContext::suite() { return getRuleContext<MxParser::SuiteContext>(0); }

std::vector<MxParser::TypeContext *> MxParser::FuncDefStmtContext::type() {
  return getRuleContexts<MxParser::TypeContext>();
}

MxParser::TypeContext *MxParser::FuncDefStmtContext::type(size_t i) { return getRuleContext<MxParser::TypeContext>(i); }

std::vector<tree::TerminalNode *> MxParser::FuncDefStmtContext::Identifier() { return getTokens(MxParser::Identifier); }

tree::TerminalNode *MxParser::FuncDefStmtContext::Identifier(size_t i) { return getToken(MxParser::Identifier, i); }

std::vector<tree::TerminalNode *> MxParser::FuncDefStmtContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::FuncDefStmtContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

MxParser::FuncDefStmtContext::FuncDefStmtContext(ClassStmtContext *ctx) { copyFrom(ctx); }

std::any MxParser::FuncDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitFuncDefStmt(this);
  else
    return visitor->visitChildren(this);
}
MxParser::ClassStmtContext *MxParser::classStmt() {
  ClassStmtContext *_localctx = _tracker.createInstance<ClassStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleClassStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::MemberDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(65);
        antlrcpp::downCast<MemberDefStmtContext *>(_localctx)->memberType = type();
        setState(66);
        match(MxParser::Identifier);
        setState(71);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(67);
          match(MxParser::Comma);
          setState(68);
          match(MxParser::Identifier);
          setState(73);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(74);
        match(MxParser::Semicolon);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::ConstructorDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(76);
        antlrcpp::downCast<ConstructorDefStmtContext *>(_localctx)->classIdentifier = match(MxParser::Identifier);
        setState(77);
        match(MxParser::LeftParen);
        setState(78);
        match(MxParser::RightParen);
        setState(79);
        suite();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::FuncDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(80);
        antlrcpp::downCast<FuncDefStmtContext *>(_localctx)->returnType = type();
        setState(81);
        antlrcpp::downCast<FuncDefStmtContext *>(_localctx)->funcName = match(MxParser::Identifier);
        setState(82);
        match(MxParser::LeftParen);
        setState(94);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32505856) != 0)) {
          setState(83);
          type();
          setState(84);
          match(MxParser::Identifier);
          setState(91);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MxParser::Comma) {
            setState(85);
            match(MxParser::Comma);
            setState(86);
            type();
            setState(87);
            match(MxParser::Identifier);
            setState(93);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(96);
        match(MxParser::RightParen);
        setState(97);
        suite();
        break;
      }

      default:
        break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

MxParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::FuncDefContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::FuncDefContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::SuiteContext *MxParser::FuncDefContext::suite() { return getRuleContext<MxParser::SuiteContext>(0); }

std::vector<MxParser::TypeContext *> MxParser::FuncDefContext::type() {
  return getRuleContexts<MxParser::TypeContext>();
}

MxParser::TypeContext *MxParser::FuncDefContext::type(size_t i) { return getRuleContext<MxParser::TypeContext>(i); }

std::vector<tree::TerminalNode *> MxParser::FuncDefContext::Identifier() { return getTokens(MxParser::Identifier); }

tree::TerminalNode *MxParser::FuncDefContext::Identifier(size_t i) { return getToken(MxParser::Identifier, i); }

std::vector<tree::TerminalNode *> MxParser::FuncDefContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::FuncDefContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

size_t MxParser::FuncDefContext::getRuleIndex() const { return MxParser::RuleFuncDef; }

std::any MxParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FuncDefContext *MxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->returnType = type();
    setState(102);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->funcName = match(MxParser::Identifier);
    setState(103);
    match(MxParser::LeftParen);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32505856) != 0)) {
      setState(104);
      type();
      setState(105);
      match(MxParser::Identifier);
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(106);
        match(MxParser::Comma);
        setState(107);
        type();
        setState(108);
        match(MxParser::Identifier);
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(117);
    match(MxParser::RightParen);
    setState(118);
    suite();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

MxParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

MxParser::TypeContext *MxParser::VarDefContext::type() { return getRuleContext<MxParser::TypeContext>(0); }

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Identifier() { return getTokens(MxParser::Identifier); }

tree::TerminalNode *MxParser::VarDefContext::Identifier(size_t i) { return getToken(MxParser::Identifier, i); }

tree::TerminalNode *MxParser::VarDefContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Assign() { return getTokens(MxParser::Assign); }

tree::TerminalNode *MxParser::VarDefContext::Assign(size_t i) { return getToken(MxParser::Assign, i); }

std::vector<MxParser::ExpressionContext *> MxParser::VarDefContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::VarDefContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::VarDefContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

size_t MxParser::VarDefContext::getRuleIndex() const { return MxParser::RuleVarDef; }

std::any MxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefContext *MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    type();
    setState(121);
    match(MxParser::Identifier);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(122);
      match(MxParser::Assign);
      setState(123);
      expression(0);
    }
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(126);
      match(MxParser::Comma);
      setState(127);
      match(MxParser::Identifier);
      setState(130);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(128);
        match(MxParser::Assign);
        setState(129);
        expression(0);
      }
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(MxParser::Semicolon);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MxParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t MxParser::StatementContext::getRuleIndex() const { return MxParser::RuleStatement; }

void MxParser::StatementContext::copyFrom(StatementContext *ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- VarDefStmtContext ------------------------------------------------------------------

MxParser::TypeContext *MxParser::VarDefStmtContext::type() { return getRuleContext<MxParser::TypeContext>(0); }

std::vector<tree::TerminalNode *> MxParser::VarDefStmtContext::Identifier() { return getTokens(MxParser::Identifier); }

tree::TerminalNode *MxParser::VarDefStmtContext::Identifier(size_t i) { return getToken(MxParser::Identifier, i); }

tree::TerminalNode *MxParser::VarDefStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

std::vector<tree::TerminalNode *> MxParser::VarDefStmtContext::Assign() { return getTokens(MxParser::Assign); }

tree::TerminalNode *MxParser::VarDefStmtContext::Assign(size_t i) { return getToken(MxParser::Assign, i); }

std::vector<MxParser::ExpressionContext *> MxParser::VarDefStmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::VarDefStmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::VarDefStmtContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::VarDefStmtContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

MxParser::VarDefStmtContext::VarDefStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::VarDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitVarDefStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStmtContext ------------------------------------------------------------------

MxParser::ExpressionContext *MxParser::ExprStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::ExprStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::ExprStmtContext::ExprStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ForStmtContext::For() { return getToken(MxParser::For, 0); }

tree::TerminalNode *MxParser::ForStmtContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::ForStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

tree::TerminalNode *MxParser::ForStmtContext::RightParen() { return getToken(MxParser::RightParen, 0); }

std::vector<MxParser::StatementContext *> MxParser::ForStmtContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext *MxParser::ForStmtContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}

std::vector<MxParser::ExpressionContext *> MxParser::ForStmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::ForStmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

MxParser::ForStmtContext::ForStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::WhileStmtContext::While() { return getToken(MxParser::While, 0); }

tree::TerminalNode *MxParser::WhileStmtContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

MxParser::ExpressionContext *MxParser::WhileStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::WhileStmtContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::StatementContext *MxParser::WhileStmtContext::statement() {
  return getRuleContext<MxParser::StatementContext>(0);
}

MxParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::IfStmtContext::If() { return getToken(MxParser::If, 0); }

tree::TerminalNode *MxParser::IfStmtContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

MxParser::ExpressionContext *MxParser::IfStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::IfStmtContext::RightParen() { return getToken(MxParser::RightParen, 0); }

std::vector<MxParser::StatementContext *> MxParser::IfStmtContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext *MxParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}

tree::TerminalNode *MxParser::IfStmtContext::Else() { return getToken(MxParser::Else, 0); }

MxParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::BreakStmtContext::Break() { return getToken(MxParser::Break, 0); }

tree::TerminalNode *MxParser::BreakStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::BreakStmtContext::BreakStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::EmptyStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::EmptyStmtContext::EmptyStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::EmptyStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitEmptyStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ReturnStmtContext::Return() { return getToken(MxParser::Return, 0); }

tree::TerminalNode *MxParser::ReturnStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::ExpressionContext *MxParser::ReturnStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

MxParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ContinueStmtContext::Continue() { return getToken(MxParser::Continue, 0); }

tree::TerminalNode *MxParser::ContinueStmtContext::Semicolon() { return getToken(MxParser::Semicolon, 0); }

MxParser::ContinueStmtContext::ContinueStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SuiteStmtContext ------------------------------------------------------------------

MxParser::SuiteContext *MxParser::SuiteStmtContext::suite() { return getRuleContext<MxParser::SuiteContext>(0); }

MxParser::SuiteStmtContext::SuiteStmtContext(StatementContext *ctx) { copyFrom(ctx); }

std::any MxParser::SuiteStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitSuiteStmt(this);
  else
    return visitor->visitChildren(this);
}
MxParser::StatementContext *MxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::VarDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(139);
        type();
        setState(140);
        match(MxParser::Identifier);
        setState(143);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(141);
          match(MxParser::Assign);
          setState(142);
          expression(0);
        }
        setState(153);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(145);
          match(MxParser::Comma);
          setState(146);
          match(MxParser::Identifier);
          setState(149);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MxParser::Assign) {
            setState(147);
            match(MxParser::Assign);
            setState(148);
            expression(0);
          }
          setState(155);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(156);
        match(MxParser::Semicolon);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::SuiteStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(158);
        suite();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::ExprStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(159);
        expression(0);
        setState(160);
        match(MxParser::Semicolon);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<MxParser::IfStmtContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(162);
        match(MxParser::If);
        setState(163);
        match(MxParser::LeftParen);
        setState(164);
        expression(0);
        setState(165);
        match(MxParser::RightParen);
        setState(166);
        antlrcpp::downCast<IfStmtContext *>(_localctx)->trueStmt = statement();
        setState(169);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
          case 1: {
            setState(167);
            match(MxParser::Else);
            setState(168);
            antlrcpp::downCast<IfStmtContext *>(_localctx)->falseStmt = statement();
            break;
          }

          default:
            break;
        }
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<MxParser::WhileStmtContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(171);
        match(MxParser::While);
        setState(172);
        match(MxParser::LeftParen);
        setState(173);
        expression(0);
        setState(174);
        match(MxParser::RightParen);
        setState(175);
        statement();
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<MxParser::ForStmtContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(177);
        match(MxParser::For);
        setState(178);
        match(MxParser::LeftParen);
        setState(179);
        antlrcpp::downCast<ForStmtContext *>(_localctx)->initializeStmt = statement();
        setState(181);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 9799122622090106) != 0)) {
          setState(180);
          antlrcpp::downCast<ForStmtContext *>(_localctx)->conditionExpr = expression(0);
        }
        setState(183);
        match(MxParser::Semicolon);
        setState(185);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 9799122622090106) != 0)) {
          setState(184);
          antlrcpp::downCast<ForStmtContext *>(_localctx)->stepExpr = expression(0);
        }
        setState(187);
        match(MxParser::RightParen);
        setState(188);
        statement();
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(190);
        match(MxParser::Return);
        setState(192);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 9799122622090106) != 0)) {
          setState(191);
          antlrcpp::downCast<ReturnStmtContext *>(_localctx)->returnExpr = expression(0);
        }
        setState(194);
        match(MxParser::Semicolon);
        break;
      }

      case 8: {
        _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(195);
        match(MxParser::Break);
        setState(196);
        match(MxParser::Semicolon);
        break;
      }

      case 9: {
        _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(197);
        match(MxParser::Continue);
        setState(198);
        match(MxParser::Semicolon);
        break;
      }

      case 10: {
        _localctx = _tracker.createInstance<MxParser::EmptyStmtContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(199);
        match(MxParser::Semicolon);
        break;
      }

      default:
        break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t MxParser::ExpressionContext::getRuleIndex() const { return MxParser::RuleExpression; }

void MxParser::ExpressionContext::copyFrom(ExpressionContext *ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- AtomicExprContext ------------------------------------------------------------------

MxParser::PrimaryContext *MxParser::AtomicExprContext::primary() { return getRuleContext<MxParser::PrimaryContext>(0); }

MxParser::AtomicExprContext::AtomicExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::AtomicExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitAtomicExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

MxParser::ExpressionContext *MxParser::UnaryExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::UnaryExprContext::Increment() { return getToken(MxParser::Increment, 0); }

tree::TerminalNode *MxParser::UnaryExprContext::Decrement() { return getToken(MxParser::Decrement, 0); }

tree::TerminalNode *MxParser::UnaryExprContext::Add() { return getToken(MxParser::Add, 0); }

tree::TerminalNode *MxParser::UnaryExprContext::Sub() { return getToken(MxParser::Sub, 0); }

tree::TerminalNode *MxParser::UnaryExprContext::NotLogic() { return getToken(MxParser::NotLogic, 0); }

tree::TerminalNode *MxParser::UnaryExprContext::Not() { return getToken(MxParser::Not, 0); }

MxParser::UnaryExprContext::UnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::SubscriptExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::SubscriptExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::SubscriptExprContext::LeftBracket() {
  return getTokens(MxParser::LeftBracket);
}

tree::TerminalNode *MxParser::SubscriptExprContext::LeftBracket(size_t i) { return getToken(MxParser::LeftBracket, i); }

std::vector<tree::TerminalNode *> MxParser::SubscriptExprContext::RightBracket() {
  return getTokens(MxParser::RightBracket);
}

tree::TerminalNode *MxParser::SubscriptExprContext::RightBracket(size_t i) {
  return getToken(MxParser::RightBracket, i);
}

MxParser::SubscriptExprContext::SubscriptExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::SubscriptExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitSubscriptExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TenaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::TenaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::TenaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode *MxParser::TenaryExprContext::Question() { return getToken(MxParser::Question, 0); }

tree::TerminalNode *MxParser::TenaryExprContext::Colon() { return getToken(MxParser::Colon, 0); }

MxParser::TenaryExprContext::TenaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::TenaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitTenaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberExprContext ------------------------------------------------------------------

MxParser::ExpressionContext *MxParser::MemberExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::MemberExprContext::Dot() { return getToken(MxParser::Dot, 0); }

tree::TerminalNode *MxParser::MemberExprContext::Identifier() { return getToken(MxParser::Identifier, 0); }

MxParser::MemberExprContext::MemberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::MemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::BinaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode *MxParser::BinaryExprContext::Mul() { return getToken(MxParser::Mul, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Div() { return getToken(MxParser::Div, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Mod() { return getToken(MxParser::Mod, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Add() { return getToken(MxParser::Add, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Sub() { return getToken(MxParser::Sub, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::ShiftLeft() { return getToken(MxParser::ShiftLeft, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::ShiftRight() { return getToken(MxParser::ShiftRight, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Less() { return getToken(MxParser::Less, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::LessEqual() { return getToken(MxParser::LessEqual, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Greater() { return getToken(MxParser::Greater, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::GreaterEqual() { return getToken(MxParser::GreaterEqual, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Equal() { return getToken(MxParser::Equal, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::UnEqual() { return getToken(MxParser::UnEqual, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::And() { return getToken(MxParser::And, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Xor() { return getToken(MxParser::Xor, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::Or() { return getToken(MxParser::Or, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::AndLogic() { return getToken(MxParser::AndLogic, 0); }

tree::TerminalNode *MxParser::BinaryExprContext::OrLogic() { return getToken(MxParser::OrLogic, 0); }

MxParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FormatExprContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::FormatExprContext::FormatQuatation() { return getToken(MxParser::FormatQuatation, 0); }

tree::TerminalNode *MxParser::FormatExprContext::Quotation() { return getToken(MxParser::Quotation, 0); }

std::vector<tree::TerminalNode *> MxParser::FormatExprContext::FormatStringLiteral() {
  return getTokens(MxParser::FormatStringLiteral);
}

tree::TerminalNode *MxParser::FormatExprContext::FormatStringLiteral(size_t i) {
  return getToken(MxParser::FormatStringLiteral, i);
}

std::vector<tree::TerminalNode *> MxParser::FormatExprContext::Dollar() { return getTokens(MxParser::Dollar); }

tree::TerminalNode *MxParser::FormatExprContext::Dollar(size_t i) { return getToken(MxParser::Dollar, i); }

std::vector<MxParser::ExpressionContext *> MxParser::FormatExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::FormatExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

MxParser::FormatExprContext::FormatExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::FormatExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitFormatExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallExprContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::FuncCallExprContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::FuncCallExprContext::RightParen() { return getToken(MxParser::RightParen, 0); }

tree::TerminalNode *MxParser::FuncCallExprContext::Identifier() { return getToken(MxParser::Identifier, 0); }

MxParser::ArgumentsContext *MxParser::FuncCallExprContext::arguments() {
  return getRuleContext<MxParser::ArgumentsContext>(0);
}

tree::TerminalNode *MxParser::FuncCallExprContext::Dot() { return getToken(MxParser::Dot, 0); }

MxParser::ExpressionContext *MxParser::FuncCallExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

MxParser::FuncCallExprContext::FuncCallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::FuncCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitFuncCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::AssignExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::AssignExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode *MxParser::AssignExprContext::Assign() { return getToken(MxParser::Assign, 0); }

MxParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ParenExprContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

MxParser::ExpressionContext *MxParser::ParenExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::ParenExprContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpressionContext *MxParser::expression() { return expression(0); }

MxParser::ExpressionContext *MxParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MxParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext;  // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, MxParser::RuleExpression, precedence);

  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(203);
        match(MxParser::LeftParen);
        setState(204);
        expression(0);
        setState(205);
        match(MxParser::RightParen);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<AtomicExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(207);
        primary();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(208);
        match(MxParser::FormatQuatation);
        setState(216);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatStringLiteral

               || _la == MxParser::Dollar) {
          setState(214);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case MxParser::FormatStringLiteral: {
              setState(209);
              match(MxParser::FormatStringLiteral);
              break;
            }

            case MxParser::Dollar: {
              setState(210);
              match(MxParser::Dollar);
              setState(211);
              expression(0);
              setState(212);
              match(MxParser::Dollar);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(218);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(219);
        match(MxParser::Quotation);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<FuncCallExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(220);
        antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
        setState(221);
        match(MxParser::LeftParen);
        setState(223);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 9799122622090106) != 0)) {
          setState(222);
          arguments();
        }
        setState(225);
        match(MxParser::RightParen);
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(226);
        _la = _input->LA(1);
        if (!(_la == MxParser::Increment

              || _la == MxParser::Decrement)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(227);
        expression(15);
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(228);
        _la = _input->LA(1);
        if (!(_la == MxParser::Add

              || _la == MxParser::Sub)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(229);
        expression(14);
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(230);
        _la = _input->LA(1);
        if (!(_la == MxParser::NotLogic

              || _la == MxParser::Not)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(231);
        expression(13);
        break;
      }

      default:
        break;
    }
    _ctx->stop = _input->LT(-1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty()) triggerExitRuleEvent();
        previousContext = _localctx;
        setState(295);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
          case 1: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(234);

            if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
            setState(235);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 939524096) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(236);
            expression(13);
            break;
          }

          case 2: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(237);

            if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
            setState(238);
            _la = _input->LA(1);
            if (!(_la == MxParser::Add

                  || _la == MxParser::Sub)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(239);
            expression(12);
            break;
          }

          case 3: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(240);

            if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
            setState(241);
            _la = _input->LA(1);
            if (!(_la == MxParser::ShiftRight

                  || _la == MxParser::ShiftLeft)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(242);
            expression(11);
            break;
          }

          case 4: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(243);

            if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
            setState(244);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 16106127360) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(245);
            expression(10);
            break;
          }

          case 5: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(246);

            if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
            setState(247);
            _la = _input->LA(1);
            if (!(_la == MxParser::Equal

                  || _la == MxParser::UnEqual)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(248);
            expression(9);
            break;
          }

          case 6: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(249);

            if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
            setState(250);
            match(MxParser::And);
            setState(251);
            expression(8);
            break;
          }

          case 7: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(252);

            if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
            setState(253);
            match(MxParser::Xor);
            setState(254);
            expression(7);
            break;
          }

          case 8: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(255);

            if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
            setState(256);
            match(MxParser::Or);
            setState(257);
            expression(6);
            break;
          }

          case 9: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(258);

            if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
            setState(259);
            match(MxParser::AndLogic);
            setState(260);
            expression(5);
            break;
          }

          case 10: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(261);

            if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
            setState(262);
            match(MxParser::OrLogic);
            setState(263);
            expression(4);
            break;
          }

          case 11: {
            auto newContext = _tracker.createInstance<TenaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(264);

            if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
            setState(265);
            match(MxParser::Question);
            setState(266);
            expression(0);
            setState(267);
            match(MxParser::Colon);
            setState(268);
            expression(2);
            break;
          }

          case 12: {
            auto newContext = _tracker.createInstance<AssignExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(270);

            if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
            setState(271);
            match(MxParser::Assign);
            setState(272);
            expression(2);
            break;
          }

          case 13: {
            auto newContext = _tracker.createInstance<UnaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(273);

            if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
            setState(274);
            _la = _input->LA(1);
            if (!(_la == MxParser::Increment

                  || _la == MxParser::Decrement)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            break;
          }

          case 14: {
            auto newContext = _tracker.createInstance<FuncCallExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            newContext->classVar = previousContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(275);

            if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
            setState(276);
            match(MxParser::Dot);
            setState(277);
            antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
            setState(278);
            match(MxParser::LeftParen);
            setState(280);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 9799122622090106) != 0)) {
              setState(279);
              arguments();
            }
            setState(282);
            match(MxParser::RightParen);
            break;
          }

          case 15: {
            auto newContext = _tracker.createInstance<SubscriptExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(283);

            if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
            setState(288);
            _errHandler->sync(this);
            alt = 1;
            do {
              switch (alt) {
                case 1: {
                  setState(284);
                  match(MxParser::LeftBracket);
                  setState(285);
                  antlrcpp::downCast<SubscriptExprContext *>(_localctx)->index = expression(0);
                  setState(286);
                  match(MxParser::RightBracket);
                  break;
                }

                default:
                  throw NoViableAltException(this);
              }
              setState(290);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
            } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
            break;
          }

          case 16: {
            auto newContext = _tracker.createInstance<MemberExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(292);

            if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
            setState(293);
            match(MxParser::Dot);
            setState(294);
            match(MxParser::Identifier);
            break;
          }

          default:
            break;
        }
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

MxParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::SuiteContext::LeftBrace() { return getToken(MxParser::LeftBrace, 0); }

tree::TerminalNode *MxParser::SuiteContext::RightBrace() { return getToken(MxParser::RightBrace, 0); }

std::vector<MxParser::StatementContext *> MxParser::SuiteContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext *MxParser::SuiteContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}

size_t MxParser::SuiteContext::getRuleIndex() const { return MxParser::RuleSuite; }

std::any MxParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteContext *MxParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(MxParser::LeftBrace);
    setState(304);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 298029498790042490) != 0)) {
      setState(301);
      statement();
      setState(306);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(307);
    match(MxParser::RightBrace);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

MxParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<MxParser::ExpressionContext *> MxParser::ArgumentsContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::ArgumentsContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArgumentsContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::ArgumentsContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

size_t MxParser::ArgumentsContext::getRuleIndex() const { return MxParser::RuleArguments; }

std::any MxParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArgumentsContext *MxParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    expression(0);
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(310);
      match(MxParser::Comma);
      setState(311);
      expression(0);
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

MxParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t MxParser::PrimaryContext::getRuleIndex() const { return MxParser::RulePrimary; }

void MxParser::PrimaryContext::copyFrom(PrimaryContext *ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- ThisPrimaryContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ThisPrimaryContext::This() { return getToken(MxParser::This, 0); }

MxParser::ThisPrimaryContext::ThisPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

std::any MxParser::ThisPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitThisPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarPrimaryContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::VarPrimaryContext::Identifier() { return getToken(MxParser::Identifier, 0); }

MxParser::VarPrimaryContext::VarPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

std::any MxParser::VarPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitVarPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralPrimaryContext ------------------------------------------------------------------

MxParser::LiteralContext *MxParser::LiteralPrimaryContext::literal() {
  return getRuleContext<MxParser::LiteralContext>(0);
}

MxParser::LiteralPrimaryContext::LiteralPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

std::any MxParser::LiteralPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitLiteralPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewPrimaryContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::NewPrimaryContext::New() { return getToken(MxParser::New, 0); }

MxParser::TypeContext *MxParser::NewPrimaryContext::type() { return getRuleContext<MxParser::TypeContext>(0); }

std::vector<tree::TerminalNode *> MxParser::NewPrimaryContext::LeftBracket() {
  return getTokens(MxParser::LeftBracket);
}

tree::TerminalNode *MxParser::NewPrimaryContext::LeftBracket(size_t i) { return getToken(MxParser::LeftBracket, i); }

std::vector<MxParser::ExpressionContext *> MxParser::NewPrimaryContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext *MxParser::NewPrimaryContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::NewPrimaryContext::RightBracket() {
  return getTokens(MxParser::RightBracket);
}

tree::TerminalNode *MxParser::NewPrimaryContext::RightBracket(size_t i) { return getToken(MxParser::RightBracket, i); }

MxParser::ArrayContext *MxParser::NewPrimaryContext::array() { return getRuleContext<MxParser::ArrayContext>(0); }

tree::TerminalNode *MxParser::NewPrimaryContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::NewPrimaryContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::NewPrimaryContext::NewPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

std::any MxParser::NewPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitNewPrimary(this);
  else
    return visitor->visitChildren(this);
}
MxParser::PrimaryContext *MxParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RulePrimary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(353);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::LiteralPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(317);
        literal();
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::VarPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(318);
        match(MxParser::Identifier);
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(319);
        match(MxParser::This);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(320);
        match(MxParser::New);
        setState(321);
        type();
        setState(326);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(322);
              match(MxParser::LeftBracket);
              setState(323);
              expression(0);
              setState(324);
              match(MxParser::RightBracket);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(328);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(334);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(330);
            match(MxParser::LeftBracket);
            setState(331);
            match(MxParser::RightBracket);
          }
          setState(336);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        }
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(337);
        match(MxParser::New);
        setState(338);
        type();
        setState(341);
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(339);
          match(MxParser::LeftBracket);
          setState(340);
          match(MxParser::RightBracket);
          setState(343);
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MxParser::LeftBracket);
        setState(345);
        array();
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(347);
        match(MxParser::New);
        setState(348);
        type();
        setState(351);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
          case 1: {
            setState(349);
            match(MxParser::LeftParen);
            setState(350);
            match(MxParser::RightParen);
            break;
          }

          default:
            break;
        }
        break;
      }

      default:
        break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

MxParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::ArrayContext::LeftBrace() { return getToken(MxParser::LeftBrace, 0); }

tree::TerminalNode *MxParser::ArrayContext::RightBrace() { return getToken(MxParser::RightBrace, 0); }

std::vector<MxParser::ArrayContext *> MxParser::ArrayContext::array() {
  return getRuleContexts<MxParser::ArrayContext>();
}

MxParser::ArrayContext *MxParser::ArrayContext::array(size_t i) { return getRuleContext<MxParser::ArrayContext>(i); }

std::vector<tree::TerminalNode *> MxParser::ArrayContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::ArrayContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

std::vector<MxParser::LiteralContext *> MxParser::ArrayContext::literal() {
  return getRuleContexts<MxParser::LiteralContext>();
}

MxParser::LiteralContext *MxParser::ArrayContext::literal(size_t i) {
  return getRuleContext<MxParser::LiteralContext>(i);
}

size_t MxParser::ArrayContext::getRuleIndex() const { return MxParser::RuleArray; }

std::any MxParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArrayContext *MxParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(379);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(355);
        match(MxParser::LeftBrace);
        setState(356);
        match(MxParser::RightBrace);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(357);
        match(MxParser::LeftBrace);
        setState(358);
        array();
        setState(363);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(359);
          match(MxParser::Comma);
          setState(360);
          array();
          setState(365);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(366);
        match(MxParser::RightBrace);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(368);
        match(MxParser::LeftBrace);
        setState(369);
        literal();
        setState(374);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(370);
          match(MxParser::Comma);
          setState(371);
          literal();
          setState(376);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(377);
        match(MxParser::RightBrace);
        break;
      }

      default:
        break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MxParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t MxParser::LiteralContext::getRuleIndex() const { return MxParser::RuleLiteral; }

void MxParser::LiteralContext::copyFrom(LiteralContext *ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- DecimalLiteralContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::DecimalLiteralContext::DecimalNumber() { return getToken(MxParser::DecimalNumber, 0); }

MxParser::DecimalLiteralContext::DecimalLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

std::any MxParser::DecimalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitDecimalLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::NullLiteralContext::Null() { return getToken(MxParser::Null, 0); }

MxParser::NullLiteralContext::NullLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

std::any MxParser::NullLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitNullLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::StringLiteralContext::StringLiteral() { return getToken(MxParser::StringLiteral, 0); }

MxParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

std::any MxParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayLiteralContext ------------------------------------------------------------------

MxParser::ArrayContext *MxParser::ArrayLiteralContext::array() { return getRuleContext<MxParser::ArrayContext>(0); }

MxParser::ArrayLiteralContext::ArrayLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

std::any MxParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::BoolLiteralContext::True() { return getToken(MxParser::True, 0); }

tree::TerminalNode *MxParser::BoolLiteralContext::False() { return getToken(MxParser::False, 0); }

MxParser::BoolLiteralContext::BoolLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

std::any MxParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}
MxParser::LiteralContext *MxParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(387);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::DecimalNumber: {
        _localctx = _tracker.createInstance<MxParser::DecimalLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(381);
        match(MxParser::DecimalNumber);
        break;
      }

      case MxParser::True: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(382);
        match(MxParser::True);
        break;
      }

      case MxParser::False: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(383);
        match(MxParser::False);
        break;
      }

      case MxParser::StringLiteral: {
        _localctx = _tracker.createInstance<MxParser::StringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(384);
        match(MxParser::StringLiteral);
        break;
      }

      case MxParser::Null: {
        _localctx = _tracker.createInstance<MxParser::NullLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(385);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = _tracker.createInstance<MxParser::ArrayLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(386);
        array();
        break;
      }

      default:
        throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MxParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *MxParser::TypeContext::Int() { return getToken(MxParser::Int, 0); }

tree::TerminalNode *MxParser::TypeContext::Bool() { return getToken(MxParser::Bool, 0); }

tree::TerminalNode *MxParser::TypeContext::String() { return getToken(MxParser::String, 0); }

tree::TerminalNode *MxParser::TypeContext::Identifier() { return getToken(MxParser::Identifier, 0); }

tree::TerminalNode *MxParser::TypeContext::Void() { return getToken(MxParser::Void, 0); }

std::vector<tree::TerminalNode *> MxParser::TypeContext::LeftBracket() { return getTokens(MxParser::LeftBracket); }

tree::TerminalNode *MxParser::TypeContext::LeftBracket(size_t i) { return getToken(MxParser::LeftBracket, i); }

std::vector<tree::TerminalNode *> MxParser::TypeContext::RightBracket() { return getTokens(MxParser::RightBracket); }

tree::TerminalNode *MxParser::TypeContext::RightBracket(size_t i) { return getToken(MxParser::RightBracket, i); }

size_t MxParser::TypeContext::getRuleIndex() const { return MxParser::RuleType; }

std::any MxParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypeContext *MxParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(401);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(389);
        match(MxParser::Int);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(390);
        match(MxParser::Bool);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(391);
        match(MxParser::String);
        break;
      }

      case 4: {
        enterOuterAlt(_localctx, 4);
        setState(392);
        match(MxParser::Identifier);
        break;
      }

      case 5: {
        enterOuterAlt(_localctx, 5);
        setState(393);
        match(MxParser::Void);
        break;
      }

      case 6: {
        enterOuterAlt(_localctx, 6);
        setState(394);
        _la = _input->LA(1);
        if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 28311552) != 0))) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(397);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(395);
              match(MxParser::LeftBracket);
              setState(396);
              match(MxParser::RightBracket);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(399);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      default:
        break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 7:
      return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

    default:
      break;
  }
  return true;
}

bool MxParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0:
      return precpred(_ctx, 12);
    case 1:
      return precpred(_ctx, 11);
    case 2:
      return precpred(_ctx, 10);
    case 3:
      return precpred(_ctx, 9);
    case 4:
      return precpred(_ctx, 8);
    case 5:
      return precpred(_ctx, 7);
    case 6:
      return precpred(_ctx, 6);
    case 7:
      return precpred(_ctx, 5);
    case 8:
      return precpred(_ctx, 4);
    case 9:
      return precpred(_ctx, 3);
    case 10:
      return precpred(_ctx, 2);
    case 11:
      return precpred(_ctx, 1);
    case 12:
      return precpred(_ctx, 20);
    case 13:
      return precpred(_ctx, 18);
    case 14:
      return precpred(_ctx, 17);
    case 15:
      return precpred(_ctx, 16);

    default:
      break;
  }
  return true;
}

void MxParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxParserInitialize();
#else
  ::antlr4::internal::call_once(mxParserOnceFlag, mxParserInitialize);
#endif
}
