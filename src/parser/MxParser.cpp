
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
          "",        "'int main()'", "'[]'",     "'f\"'",     "",       "'true'", "'false'",  "",      "",
          "",        "'null'",       "'new'",    "'class'",   "'this'", "'if'",   "'else'",   "'for'", "'while'",
          "'break'", "'continue'",   "'return'", "'bool'",    "'int'",  "'void'", "'string'", "",      "'+'",
          "'-'",     "'*'",          "'/'",      "'%'",       "'<'",    "'<='",   "'>'",      "'>='",  "'=='",
          "'!='",    "'&&'",         "'||'",     "'!'",       "'>>'",   "'<<'",   "'&'",      "'|'",   "'^'",
          "'~'",     "'='",          "'++'",     "'--'",      "'.'",    "'('",    "')'",      "'['",   "']'",
          "'{'",     "'}'",          "'$'",      "'\\u003F'", "':'",    "';'",    "','"},
      std::vector<std::string>{"",
                               "",
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
      4,   1,   63,  390, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,   4,   7,
      4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,   2,   10,
      7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  1,   0,   1,   0,   1,   0,   5,   0,   32,
      8,   0,   10,  0,   12,  0,   35,  9,   0,   1,   0,   1,   0,   1,   0,   1,   0,   5,   0,   41,  8,   0,   10,
      0,   12,  0,   44,  9,   0,   1,   1,   1,   1,   1,   1,   1,   2,   1,   2,   1,   2,   1,   2,   5,   2,   53,
      8,   2,   10,  2,   12,  2,   56,  9,   2,   1,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,
      5,   3,   65,  8,   3,   10,  3,   12,  3,   68,  9,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   5,   3,   82,  8,   3,   10,  3,   12,  3,   85,
      9,   3,   1,   3,   1,   3,   1,   3,   3,   3,   90,  8,   3,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,
      1,   4,   1,   4,   1,   4,   1,   4,   5,   4,   101, 8,   4,   10,  4,   12,  4,   104, 9,   4,   3,   4,   106,
      8,   4,   1,   4,   1,   4,   1,   4,   1,   5,   1,   5,   1,   5,   1,   5,   3,   5,   115, 8,   5,   1,   5,
      1,   5,   1,   5,   1,   5,   3,   5,   121, 8,   5,   5,   5,   123, 8,   5,   10,  5,   12,  5,   126, 9,   5,
      1,   5,   1,   5,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,   134, 8,   6,   1,   6,   1,   6,   1,   6,
      1,   6,   3,   6,   140, 8,   6,   5,   6,   142, 8,   6,   10,  6,   12,  6,   145, 9,   6,   1,   6,   1,   6,
      1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,
      6,   160, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,
      6,   3,   6,   172, 8,   6,   1,   6,   1,   6,   3,   6,   176, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,
      1,   6,   3,   6,   183, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,   190, 8,   6,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   5,   7,   200, 8,   7,   10,  7,   12,
      7,   203, 9,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   209, 8,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   218, 8,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   266, 8,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   4,   7,   274, 8,   7,   11,  7,   12,  7,   275, 1,   7,   1,   7,   1,   7,
      5,   7,   281, 8,   7,   10,  7,   12,  7,   284, 9,   7,   1,   8,   1,   8,   5,   8,   288, 8,   8,   10,  8,
      12,  8,   291, 9,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,   5,   9,   298, 8,   9,   10,  9,   12,
      9,   301, 9,   9,   1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,
      10,  1,   10,  3,   10,  314, 8,   10,  1,   10,  1,   10,  1,   10,  4,   10,  319, 8,   10,  11,  10,  12,  10,
      320, 1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  4,   10,  331, 8,   10,  11,
      10,  12,  10,  332, 1,   10,  5,   10,  336, 8,   10,  10,  10,  12,  10,  339, 9,   10,  3,   10,  341, 8,   10,
      1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  5,   11,  349, 8,   11,  10,  11,  12,  11,  352, 9,
      11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  5,   11,  360, 8,   11,  10,  11,  12,  11,  363,
      9,   11,  1,   11,  1,   11,  3,   11,  367, 8,   11,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,
      3,   12,  375, 8,   12,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  1,   13,  4,   13,  384, 8,
      13,  11,  13,  12,  13,  385, 3,   13,  388, 8,   13,  1,   13,  0,   1,   14,  14,  0,   2,   4,   6,   8,   10,
      12,  14,  16,  18,  20,  22,  24,  26,  0,   8,   1,   0,   47,  48,  1,   0,   26,  27,  2,   0,   39,  39,  45,
      45,  1,   0,   28,  30,  1,   0,   40,  41,  1,   0,   31,  34,  1,   0,   35,  36,  2,   0,   21,  22,  24,  25,
      459, 0,   33,  1,   0,   0,   0,   2,   45,  1,   0,   0,   0,   4,   48,  1,   0,   0,   0,   6,   89,  1,   0,
      0,   0,   8,   91,  1,   0,   0,   0,   10,  110, 1,   0,   0,   0,   12,  189, 1,   0,   0,   0,   14,  217, 1,
      0,   0,   0,   16,  285, 1,   0,   0,   0,   18,  294, 1,   0,   0,   0,   20,  340, 1,   0,   0,   0,   22,  366,
      1,   0,   0,   0,   24,  374, 1,   0,   0,   0,   26,  387, 1,   0,   0,   0,   28,  32,  3,   4,   2,   0,   29,
      32,  3,   8,   4,   0,   30,  32,  3,   10,  5,   0,   31,  28,  1,   0,   0,   0,   31,  29,  1,   0,   0,   0,
      31,  30,  1,   0,   0,   0,   32,  35,  1,   0,   0,   0,   33,  31,  1,   0,   0,   0,   33,  34,  1,   0,   0,
      0,   34,  36,  1,   0,   0,   0,   35,  33,  1,   0,   0,   0,   36,  42,  3,   2,   1,   0,   37,  41,  3,   4,
      2,   0,   38,  41,  3,   8,   4,   0,   39,  41,  3,   10,  5,   0,   40,  37,  1,   0,   0,   0,   40,  38,  1,
      0,   0,   0,   40,  39,  1,   0,   0,   0,   41,  44,  1,   0,   0,   0,   42,  40,  1,   0,   0,   0,   42,  43,
      1,   0,   0,   0,   43,  1,   1,   0,   0,   0,   44,  42,  1,   0,   0,   0,   45,  46,  5,   1,   0,   0,   46,
      47,  3,   16,  8,   0,   47,  3,   1,   0,   0,   0,   48,  49,  5,   12,  0,   0,   49,  50,  5,   25,  0,   0,
      50,  54,  5,   54,  0,   0,   51,  53,  3,   6,   3,   0,   52,  51,  1,   0,   0,   0,   53,  56,  1,   0,   0,
      0,   54,  52,  1,   0,   0,   0,   54,  55,  1,   0,   0,   0,   55,  57,  1,   0,   0,   0,   56,  54,  1,   0,
      0,   0,   57,  58,  5,   55,  0,   0,   58,  59,  5,   59,  0,   0,   59,  5,   1,   0,   0,   0,   60,  61,  3,
      26,  13,  0,   61,  66,  5,   25,  0,   0,   62,  63,  5,   60,  0,   0,   63,  65,  5,   25,  0,   0,   64,  62,
      1,   0,   0,   0,   65,  68,  1,   0,   0,   0,   66,  64,  1,   0,   0,   0,   66,  67,  1,   0,   0,   0,   67,
      69,  1,   0,   0,   0,   68,  66,  1,   0,   0,   0,   69,  70,  5,   59,  0,   0,   70,  90,  1,   0,   0,   0,
      71,  72,  5,   25,  0,   0,   72,  73,  5,   50,  0,   0,   73,  74,  5,   51,  0,   0,   74,  90,  3,   16,  8,
      0,   75,  76,  3,   26,  13,  0,   76,  77,  5,   25,  0,   0,   77,  83,  5,   50,  0,   0,   78,  79,  3,   26,
      13,  0,   79,  80,  5,   25,  0,   0,   80,  82,  1,   0,   0,   0,   81,  78,  1,   0,   0,   0,   82,  85,  1,
      0,   0,   0,   83,  81,  1,   0,   0,   0,   83,  84,  1,   0,   0,   0,   84,  86,  1,   0,   0,   0,   85,  83,
      1,   0,   0,   0,   86,  87,  5,   51,  0,   0,   87,  88,  3,   16,  8,   0,   88,  90,  1,   0,   0,   0,   89,
      60,  1,   0,   0,   0,   89,  71,  1,   0,   0,   0,   89,  75,  1,   0,   0,   0,   90,  7,   1,   0,   0,   0,
      91,  92,  3,   26,  13,  0,   92,  93,  5,   25,  0,   0,   93,  105, 5,   50,  0,   0,   94,  95,  3,   26,  13,
      0,   95,  102, 5,   25,  0,   0,   96,  97,  5,   60,  0,   0,   97,  98,  3,   26,  13,  0,   98,  99,  5,   25,
      0,   0,   99,  101, 1,   0,   0,   0,   100, 96,  1,   0,   0,   0,   101, 104, 1,   0,   0,   0,   102, 100, 1,
      0,   0,   0,   102, 103, 1,   0,   0,   0,   103, 106, 1,   0,   0,   0,   104, 102, 1,   0,   0,   0,   105, 94,
      1,   0,   0,   0,   105, 106, 1,   0,   0,   0,   106, 107, 1,   0,   0,   0,   107, 108, 5,   51,  0,   0,   108,
      109, 3,   16,  8,   0,   109, 9,   1,   0,   0,   0,   110, 111, 3,   26,  13,  0,   111, 114, 5,   25,  0,   0,
      112, 113, 5,   46,  0,   0,   113, 115, 3,   14,  7,   0,   114, 112, 1,   0,   0,   0,   114, 115, 1,   0,   0,
      0,   115, 124, 1,   0,   0,   0,   116, 117, 5,   60,  0,   0,   117, 120, 5,   25,  0,   0,   118, 119, 5,   46,
      0,   0,   119, 121, 3,   14,  7,   0,   120, 118, 1,   0,   0,   0,   120, 121, 1,   0,   0,   0,   121, 123, 1,
      0,   0,   0,   122, 116, 1,   0,   0,   0,   123, 126, 1,   0,   0,   0,   124, 122, 1,   0,   0,   0,   124, 125,
      1,   0,   0,   0,   125, 127, 1,   0,   0,   0,   126, 124, 1,   0,   0,   0,   127, 128, 5,   59,  0,   0,   128,
      11,  1,   0,   0,   0,   129, 130, 3,   26,  13,  0,   130, 133, 5,   25,  0,   0,   131, 132, 5,   46,  0,   0,
      132, 134, 3,   14,  7,   0,   133, 131, 1,   0,   0,   0,   133, 134, 1,   0,   0,   0,   134, 143, 1,   0,   0,
      0,   135, 136, 5,   60,  0,   0,   136, 139, 5,   25,  0,   0,   137, 138, 5,   46,  0,   0,   138, 140, 3,   14,
      7,   0,   139, 137, 1,   0,   0,   0,   139, 140, 1,   0,   0,   0,   140, 142, 1,   0,   0,   0,   141, 135, 1,
      0,   0,   0,   142, 145, 1,   0,   0,   0,   143, 141, 1,   0,   0,   0,   143, 144, 1,   0,   0,   0,   144, 146,
      1,   0,   0,   0,   145, 143, 1,   0,   0,   0,   146, 147, 5,   59,  0,   0,   147, 190, 1,   0,   0,   0,   148,
      190, 3,   16,  8,   0,   149, 150, 3,   14,  7,   0,   150, 151, 5,   59,  0,   0,   151, 190, 1,   0,   0,   0,
      152, 153, 5,   14,  0,   0,   153, 154, 5,   50,  0,   0,   154, 155, 3,   14,  7,   0,   155, 156, 5,   51,  0,
      0,   156, 159, 3,   12,  6,   0,   157, 158, 5,   15,  0,   0,   158, 160, 3,   12,  6,   0,   159, 157, 1,   0,
      0,   0,   159, 160, 1,   0,   0,   0,   160, 190, 1,   0,   0,   0,   161, 162, 5,   17,  0,   0,   162, 163, 5,
      50,  0,   0,   163, 164, 3,   14,  7,   0,   164, 165, 5,   51,  0,   0,   165, 166, 3,   16,  8,   0,   166, 190,
      1,   0,   0,   0,   167, 168, 5,   16,  0,   0,   168, 169, 5,   50,  0,   0,   169, 171, 3,   12,  6,   0,   170,
      172, 3,   14,  7,   0,   171, 170, 1,   0,   0,   0,   171, 172, 1,   0,   0,   0,   172, 173, 1,   0,   0,   0,
      173, 175, 5,   59,  0,   0,   174, 176, 3,   14,  7,   0,   175, 174, 1,   0,   0,   0,   175, 176, 1,   0,   0,
      0,   176, 177, 1,   0,   0,   0,   177, 178, 5,   51,  0,   0,   178, 179, 3,   12,  6,   0,   179, 190, 1,   0,
      0,   0,   180, 182, 5,   20,  0,   0,   181, 183, 3,   14,  7,   0,   182, 181, 1,   0,   0,   0,   182, 183, 1,
      0,   0,   0,   183, 184, 1,   0,   0,   0,   184, 190, 5,   59,  0,   0,   185, 186, 5,   18,  0,   0,   186, 190,
      5,   59,  0,   0,   187, 188, 5,   19,  0,   0,   188, 190, 5,   59,  0,   0,   189, 129, 1,   0,   0,   0,   189,
      148, 1,   0,   0,   0,   189, 149, 1,   0,   0,   0,   189, 152, 1,   0,   0,   0,   189, 161, 1,   0,   0,   0,
      189, 167, 1,   0,   0,   0,   189, 180, 1,   0,   0,   0,   189, 185, 1,   0,   0,   0,   189, 187, 1,   0,   0,
      0,   190, 13,  1,   0,   0,   0,   191, 192, 6,   7,   -1,  0,   192, 218, 3,   20,  10,  0,   193, 201, 5,   3,
      0,   0,   194, 200, 5,   9,   0,   0,   195, 196, 5,   56,  0,   0,   196, 197, 3,   14,  7,   0,   197, 198, 5,
      56,  0,   0,   198, 200, 1,   0,   0,   0,   199, 194, 1,   0,   0,   0,   199, 195, 1,   0,   0,   0,   200, 203,
      1,   0,   0,   0,   201, 199, 1,   0,   0,   0,   201, 202, 1,   0,   0,   0,   202, 204, 1,   0,   0,   0,   203,
      201, 1,   0,   0,   0,   204, 218, 5,   4,   0,   0,   205, 206, 5,   25,  0,   0,   206, 208, 5,   50,  0,   0,
      207, 209, 3,   18,  9,   0,   208, 207, 1,   0,   0,   0,   208, 209, 1,   0,   0,   0,   209, 210, 1,   0,   0,
      0,   210, 218, 5,   51,  0,   0,   211, 212, 7,   0,   0,   0,   212, 218, 3,   14,  7,   15,  213, 214, 7,   1,
      0,   0,   214, 218, 3,   14,  7,   14,  215, 216, 7,   2,   0,   0,   216, 218, 3,   14,  7,   13,  217, 191, 1,
      0,   0,   0,   217, 193, 1,   0,   0,   0,   217, 205, 1,   0,   0,   0,   217, 211, 1,   0,   0,   0,   217, 213,
      1,   0,   0,   0,   217, 215, 1,   0,   0,   0,   218, 282, 1,   0,   0,   0,   219, 220, 10,  12,  0,   0,   220,
      221, 7,   3,   0,   0,   221, 281, 3,   14,  7,   13,  222, 223, 10,  11,  0,   0,   223, 224, 7,   1,   0,   0,
      224, 281, 3,   14,  7,   12,  225, 226, 10,  10,  0,   0,   226, 227, 7,   4,   0,   0,   227, 281, 3,   14,  7,
      11,  228, 229, 10,  9,   0,   0,   229, 230, 7,   5,   0,   0,   230, 281, 3,   14,  7,   10,  231, 232, 10,  8,
      0,   0,   232, 233, 7,   6,   0,   0,   233, 281, 3,   14,  7,   9,   234, 235, 10,  7,   0,   0,   235, 236, 5,
      42,  0,   0,   236, 281, 3,   14,  7,   8,   237, 238, 10,  6,   0,   0,   238, 239, 5,   44,  0,   0,   239, 281,
      3,   14,  7,   7,   240, 241, 10,  5,   0,   0,   241, 242, 5,   43,  0,   0,   242, 281, 3,   14,  7,   6,   243,
      244, 10,  4,   0,   0,   244, 245, 5,   37,  0,   0,   245, 281, 3,   14,  7,   5,   246, 247, 10,  3,   0,   0,
      247, 248, 5,   38,  0,   0,   248, 281, 3,   14,  7,   4,   249, 250, 10,  2,   0,   0,   250, 251, 5,   57,  0,
      0,   251, 252, 3,   14,  7,   0,   252, 253, 5,   58,  0,   0,   253, 254, 3,   14,  7,   2,   254, 281, 1,   0,
      0,   0,   255, 256, 10,  1,   0,   0,   256, 257, 5,   46,  0,   0,   257, 281, 3,   14,  7,   2,   258, 259, 10,
      20,  0,   0,   259, 281, 7,   0,   0,   0,   260, 261, 10,  18,  0,   0,   261, 262, 5,   49,  0,   0,   262, 263,
      5,   25,  0,   0,   263, 265, 5,   50,  0,   0,   264, 266, 3,   18,  9,   0,   265, 264, 1,   0,   0,   0,   265,
      266, 1,   0,   0,   0,   266, 267, 1,   0,   0,   0,   267, 281, 5,   51,  0,   0,   268, 273, 10,  17,  0,   0,
      269, 270, 5,   52,  0,   0,   270, 271, 3,   14,  7,   0,   271, 272, 5,   53,  0,   0,   272, 274, 1,   0,   0,
      0,   273, 269, 1,   0,   0,   0,   274, 275, 1,   0,   0,   0,   275, 273, 1,   0,   0,   0,   275, 276, 1,   0,
      0,   0,   276, 281, 1,   0,   0,   0,   277, 278, 10,  16,  0,   0,   278, 279, 5,   49,  0,   0,   279, 281, 5,
      25,  0,   0,   280, 219, 1,   0,   0,   0,   280, 222, 1,   0,   0,   0,   280, 225, 1,   0,   0,   0,   280, 228,
      1,   0,   0,   0,   280, 231, 1,   0,   0,   0,   280, 234, 1,   0,   0,   0,   280, 237, 1,   0,   0,   0,   280,
      240, 1,   0,   0,   0,   280, 243, 1,   0,   0,   0,   280, 246, 1,   0,   0,   0,   280, 249, 1,   0,   0,   0,
      280, 255, 1,   0,   0,   0,   280, 258, 1,   0,   0,   0,   280, 260, 1,   0,   0,   0,   280, 268, 1,   0,   0,
      0,   280, 277, 1,   0,   0,   0,   281, 284, 1,   0,   0,   0,   282, 280, 1,   0,   0,   0,   282, 283, 1,   0,
      0,   0,   283, 15,  1,   0,   0,   0,   284, 282, 1,   0,   0,   0,   285, 289, 5,   54,  0,   0,   286, 288, 3,
      12,  6,   0,   287, 286, 1,   0,   0,   0,   288, 291, 1,   0,   0,   0,   289, 287, 1,   0,   0,   0,   289, 290,
      1,   0,   0,   0,   290, 292, 1,   0,   0,   0,   291, 289, 1,   0,   0,   0,   292, 293, 5,   55,  0,   0,   293,
      17,  1,   0,   0,   0,   294, 299, 3,   14,  7,   0,   295, 296, 5,   60,  0,   0,   296, 298, 3,   14,  7,   0,
      297, 295, 1,   0,   0,   0,   298, 301, 1,   0,   0,   0,   299, 297, 1,   0,   0,   0,   299, 300, 1,   0,   0,
      0,   300, 19,  1,   0,   0,   0,   301, 299, 1,   0,   0,   0,   302, 303, 5,   50,  0,   0,   303, 304, 3,   14,
      7,   0,   304, 305, 5,   51,  0,   0,   305, 341, 1,   0,   0,   0,   306, 341, 3,   24,  12,  0,   307, 341, 5,
      25,  0,   0,   308, 341, 5,   13,  0,   0,   309, 310, 5,   11,  0,   0,   310, 313, 3,   26,  13,  0,   311, 312,
      5,   50,  0,   0,   312, 314, 5,   51,  0,   0,   313, 311, 1,   0,   0,   0,   313, 314, 1,   0,   0,   0,   314,
      341, 1,   0,   0,   0,   315, 316, 5,   11,  0,   0,   316, 318, 3,   26,  13,  0,   317, 319, 5,   2,   0,   0,
      318, 317, 1,   0,   0,   0,   319, 320, 1,   0,   0,   0,   320, 318, 1,   0,   0,   0,   320, 321, 1,   0,   0,
      0,   321, 322, 1,   0,   0,   0,   322, 323, 3,   22,  11,  0,   323, 341, 1,   0,   0,   0,   324, 325, 5,   11,
      0,   0,   325, 330, 3,   26,  13,  0,   326, 327, 5,   52,  0,   0,   327, 328, 3,   14,  7,   0,   328, 329, 5,
      53,  0,   0,   329, 331, 1,   0,   0,   0,   330, 326, 1,   0,   0,   0,   331, 332, 1,   0,   0,   0,   332, 330,
      1,   0,   0,   0,   332, 333, 1,   0,   0,   0,   333, 337, 1,   0,   0,   0,   334, 336, 5,   2,   0,   0,   335,
      334, 1,   0,   0,   0,   336, 339, 1,   0,   0,   0,   337, 335, 1,   0,   0,   0,   337, 338, 1,   0,   0,   0,
      338, 341, 1,   0,   0,   0,   339, 337, 1,   0,   0,   0,   340, 302, 1,   0,   0,   0,   340, 306, 1,   0,   0,
      0,   340, 307, 1,   0,   0,   0,   340, 308, 1,   0,   0,   0,   340, 309, 1,   0,   0,   0,   340, 315, 1,   0,
      0,   0,   340, 324, 1,   0,   0,   0,   341, 21,  1,   0,   0,   0,   342, 343, 5,   54,  0,   0,   343, 367, 5,
      55,  0,   0,   344, 345, 5,   54,  0,   0,   345, 350, 3,   24,  12,  0,   346, 347, 5,   60,  0,   0,   347, 349,
      3,   24,  12,  0,   348, 346, 1,   0,   0,   0,   349, 352, 1,   0,   0,   0,   350, 348, 1,   0,   0,   0,   350,
      351, 1,   0,   0,   0,   351, 353, 1,   0,   0,   0,   352, 350, 1,   0,   0,   0,   353, 354, 5,   55,  0,   0,
      354, 367, 1,   0,   0,   0,   355, 356, 5,   54,  0,   0,   356, 361, 3,   22,  11,  0,   357, 358, 5,   60,  0,
      0,   358, 360, 3,   22,  11,  0,   359, 357, 1,   0,   0,   0,   360, 363, 1,   0,   0,   0,   361, 359, 1,   0,
      0,   0,   361, 362, 1,   0,   0,   0,   362, 364, 1,   0,   0,   0,   363, 361, 1,   0,   0,   0,   364, 365, 5,
      55,  0,   0,   365, 367, 1,   0,   0,   0,   366, 342, 1,   0,   0,   0,   366, 344, 1,   0,   0,   0,   366, 355,
      1,   0,   0,   0,   367, 23,  1,   0,   0,   0,   368, 375, 5,   7,   0,   0,   369, 375, 5,   5,   0,   0,   370,
      375, 5,   6,   0,   0,   371, 375, 5,   8,   0,   0,   372, 375, 5,   10,  0,   0,   373, 375, 3,   22,  11,  0,
      374, 368, 1,   0,   0,   0,   374, 369, 1,   0,   0,   0,   374, 370, 1,   0,   0,   0,   374, 371, 1,   0,   0,
      0,   374, 372, 1,   0,   0,   0,   374, 373, 1,   0,   0,   0,   375, 25,  1,   0,   0,   0,   376, 388, 5,   22,
      0,   0,   377, 388, 5,   21,  0,   0,   378, 388, 5,   24,  0,   0,   379, 388, 5,   25,  0,   0,   380, 388, 5,
      23,  0,   0,   381, 383, 7,   7,   0,   0,   382, 384, 5,   2,   0,   0,   383, 382, 1,   0,   0,   0,   384, 385,
      1,   0,   0,   0,   385, 383, 1,   0,   0,   0,   385, 386, 1,   0,   0,   0,   386, 388, 1,   0,   0,   0,   387,
      376, 1,   0,   0,   0,   387, 377, 1,   0,   0,   0,   387, 378, 1,   0,   0,   0,   387, 379, 1,   0,   0,   0,
      387, 380, 1,   0,   0,   0,   387, 381, 1,   0,   0,   0,   388, 27,  1,   0,   0,   0,   42,  31,  33,  40,  42,
      54,  66,  83,  89,  102, 105, 114, 120, 124, 133, 139, 143, 159, 171, 175, 182, 189, 199, 201, 208, 217, 265, 275,
      280, 282, 289, 299, 313, 320, 332, 337, 340, 350, 361, 366, 374, 385, 387};
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
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 65015808) != 0)) {
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
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    mainFunc();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 65015808) != 0)) {
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
    setState(45);
    match(MxParser::T__0);
    setState(46);
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
    setState(48);
    match(MxParser::Class);
    setState(49);
    antlrcpp::downCast<ClassDefContext *>(_localctx)->classIdentifier = match(MxParser::Identifier);
    setState(50);
    match(MxParser::LeftBrace);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 65011712) != 0)) {
      setState(51);
      classStmt();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
    match(MxParser::RightBrace);
    setState(58);
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
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::MemberDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(60);
        antlrcpp::downCast<MemberDefStmtContext *>(_localctx)->memberType = type();
        setState(61);
        match(MxParser::Identifier);
        setState(66);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(62);
          match(MxParser::Comma);
          setState(63);
          match(MxParser::Identifier);
          setState(68);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(69);
        match(MxParser::Semicolon);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::ConstructorDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(71);
        antlrcpp::downCast<ConstructorDefStmtContext *>(_localctx)->classIdentifier = match(MxParser::Identifier);
        setState(72);
        match(MxParser::LeftParen);
        setState(73);
        match(MxParser::RightParen);
        setState(74);
        suite();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::FuncDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(75);
        antlrcpp::downCast<FuncDefStmtContext *>(_localctx)->returnType = type();
        setState(76);
        antlrcpp::downCast<FuncDefStmtContext *>(_localctx)->funcName = match(MxParser::Identifier);
        setState(77);
        match(MxParser::LeftParen);
        setState(83);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 65011712) != 0)) {
          setState(78);
          type();
          setState(79);
          match(MxParser::Identifier);
          setState(85);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(86);
        match(MxParser::RightParen);
        setState(87);
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
    setState(91);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->returnType = type();
    setState(92);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->funcName = match(MxParser::Identifier);
    setState(93);
    match(MxParser::LeftParen);
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 65011712) != 0)) {
      setState(94);
      type();
      setState(95);
      match(MxParser::Identifier);
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(96);
        match(MxParser::Comma);
        setState(97);
        type();
        setState(98);
        match(MxParser::Identifier);
        setState(104);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(107);
    match(MxParser::RightParen);
    setState(108);
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
    setState(110);
    type();
    setState(111);
    match(MxParser::Identifier);
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(112);
      match(MxParser::Assign);
      setState(113);
      expression(0);
    }
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(116);
      match(MxParser::Comma);
      setState(117);
      match(MxParser::Identifier);
      setState(120);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(118);
        match(MxParser::Assign);
        setState(119);
        expression(0);
      }
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
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

MxParser::SuiteContext *MxParser::WhileStmtContext::suite() { return getRuleContext<MxParser::SuiteContext>(0); }

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
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::VarDefStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(129);
        type();
        setState(130);
        match(MxParser::Identifier);
        setState(133);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(131);
          match(MxParser::Assign);
          setState(132);
          expression(0);
        }
        setState(143);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(135);
          match(MxParser::Comma);
          setState(136);
          match(MxParser::Identifier);
          setState(139);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MxParser::Assign) {
            setState(137);
            match(MxParser::Assign);
            setState(138);
            expression(0);
          }
          setState(145);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(146);
        match(MxParser::Semicolon);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::SuiteStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(148);
        suite();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::ExprStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(149);
        expression(0);
        setState(150);
        match(MxParser::Semicolon);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<MxParser::IfStmtContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(152);
        match(MxParser::If);
        setState(153);
        match(MxParser::LeftParen);
        setState(154);
        expression(0);
        setState(155);
        match(MxParser::RightParen);
        setState(156);
        antlrcpp::downCast<IfStmtContext *>(_localctx)->trueStmt = statement();
        setState(159);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
          case 1: {
            setState(157);
            match(MxParser::Else);
            setState(158);
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
        setState(161);
        match(MxParser::While);
        setState(162);
        match(MxParser::LeftParen);
        setState(163);
        expression(0);
        setState(164);
        match(MxParser::RightParen);
        setState(165);
        suite();
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<MxParser::ForStmtContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(167);
        match(MxParser::For);
        setState(168);
        match(MxParser::LeftParen);
        setState(169);
        antlrcpp::downCast<ForStmtContext *>(_localctx)->initializeStmt = statement();
        setState(171);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
          setState(170);
          antlrcpp::downCast<ForStmtContext *>(_localctx)->conditionExpr = expression(0);
        }
        setState(173);
        match(MxParser::Semicolon);
        setState(175);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
          setState(174);
          antlrcpp::downCast<ForStmtContext *>(_localctx)->stepExpr = expression(0);
        }
        setState(177);
        match(MxParser::RightParen);
        setState(178);
        statement();
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(180);
        match(MxParser::Return);
        setState(182);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
          setState(181);
          antlrcpp::downCast<ReturnStmtContext *>(_localctx)->returnExpr = expression(0);
        }
        setState(184);
        match(MxParser::Semicolon);
        break;
      }

      case 8: {
        _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(185);
        match(MxParser::Break);
        setState(186);
        match(MxParser::Semicolon);
        break;
      }

      case 9: {
        _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(187);
        match(MxParser::Continue);
        setState(188);
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
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<AtomicExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(192);
        primary();
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(193);
        match(MxParser::FormatQuatation);
        setState(201);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatStringLiteral

               || _la == MxParser::Dollar) {
          setState(199);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case MxParser::FormatStringLiteral: {
              setState(194);
              match(MxParser::FormatStringLiteral);
              break;
            }

            case MxParser::Dollar: {
              setState(195);
              match(MxParser::Dollar);
              setState(196);
              expression(0);
              setState(197);
              match(MxParser::Dollar);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(204);
        match(MxParser::Quotation);
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<FuncCallExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(205);
        antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
        setState(206);
        match(MxParser::LeftParen);
        setState(208);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
          setState(207);
          arguments();
        }
        setState(210);
        match(MxParser::RightParen);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(211);
        _la = _input->LA(1);
        if (!(_la == MxParser::Increment

              || _la == MxParser::Decrement)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(212);
        expression(15);
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(213);
        _la = _input->LA(1);
        if (!(_la == MxParser::Add

              || _la == MxParser::Sub)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(214);
        expression(14);
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(215);
        _la = _input->LA(1);
        if (!(_la == MxParser::NotLogic

              || _la == MxParser::Not)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(216);
        expression(13);
        break;
      }

      default:
        break;
    }
    _ctx->stop = _input->LT(-1);
    setState(282);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty()) triggerExitRuleEvent();
        previousContext = _localctx;
        setState(280);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
          case 1: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(219);

            if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
            setState(220);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 1879048192) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(221);
            expression(13);
            break;
          }

          case 2: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(222);

            if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
            setState(223);
            _la = _input->LA(1);
            if (!(_la == MxParser::Add

                  || _la == MxParser::Sub)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(224);
            expression(12);
            break;
          }

          case 3: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(225);

            if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
            setState(226);
            _la = _input->LA(1);
            if (!(_la == MxParser::ShiftRight

                  || _la == MxParser::ShiftLeft)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(227);
            expression(11);
            break;
          }

          case 4: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(228);

            if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
            setState(229);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32212254720) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(230);
            expression(10);
            break;
          }

          case 5: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(231);

            if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
            setState(232);
            _la = _input->LA(1);
            if (!(_la == MxParser::Equal

                  || _la == MxParser::UnEqual)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(233);
            expression(9);
            break;
          }

          case 6: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(234);

            if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
            setState(235);
            match(MxParser::And);
            setState(236);
            expression(8);
            break;
          }

          case 7: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(237);

            if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
            setState(238);
            match(MxParser::Xor);
            setState(239);
            expression(7);
            break;
          }

          case 8: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(240);

            if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
            setState(241);
            match(MxParser::Or);
            setState(242);
            expression(6);
            break;
          }

          case 9: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(243);

            if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
            setState(244);
            match(MxParser::AndLogic);
            setState(245);
            expression(5);
            break;
          }

          case 10: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(246);

            if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
            setState(247);
            match(MxParser::OrLogic);
            setState(248);
            expression(4);
            break;
          }

          case 11: {
            auto newContext = _tracker.createInstance<TenaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(249);

            if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
            setState(250);
            match(MxParser::Question);
            setState(251);
            expression(0);
            setState(252);
            match(MxParser::Colon);
            setState(253);
            expression(2);
            break;
          }

          case 12: {
            auto newContext = _tracker.createInstance<AssignExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(255);

            if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
            setState(256);
            match(MxParser::Assign);
            setState(257);
            expression(2);
            break;
          }

          case 13: {
            auto newContext = _tracker.createInstance<UnaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(258);

            if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
            setState(259);
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
            setState(260);

            if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
            setState(261);
            match(MxParser::Dot);
            setState(262);
            antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
            setState(263);
            match(MxParser::LeftParen);
            setState(265);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
              setState(264);
              arguments();
            }
            setState(267);
            match(MxParser::RightParen);
            break;
          }

          case 15: {
            auto newContext = _tracker.createInstance<SubscriptExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(268);

            if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
            setState(273);
            _errHandler->sync(this);
            alt = 1;
            do {
              switch (alt) {
                case 1: {
                  setState(269);
                  match(MxParser::LeftBracket);
                  setState(270);
                  antlrcpp::downCast<SubscriptExprContext *>(_localctx)->index = expression(0);
                  setState(271);
                  match(MxParser::RightBracket);
                  break;
                }

                default:
                  throw NoViableAltException(this);
              }
              setState(275);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
            } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
            break;
          }

          case 16: {
            auto newContext = _tracker.createInstance<MemberExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(277);

            if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
            setState(278);
            match(MxParser::Dot);
            setState(279);
            match(MxParser::Identifier);
            break;
          }

          default:
            break;
        }
      }
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
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
    setState(285);
    match(MxParser::LeftBrace);
    setState(289);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245277691368) != 0)) {
      setState(286);
      statement();
      setState(291);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(292);
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
    setState(294);
    expression(0);
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(295);
      match(MxParser::Comma);
      setState(296);
      expression(0);
      setState(301);
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
//----------------- ParenPrimaryContext ------------------------------------------------------------------

tree::TerminalNode *MxParser::ParenPrimaryContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

MxParser::ExpressionContext *MxParser::ParenPrimaryContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode *MxParser::ParenPrimaryContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::ParenPrimaryContext::ParenPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

std::any MxParser::ParenPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor *>(visitor))
    return parserVisitor->visitParenPrimary(this);
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

tree::TerminalNode *MxParser::NewPrimaryContext::LeftParen() { return getToken(MxParser::LeftParen, 0); }

tree::TerminalNode *MxParser::NewPrimaryContext::RightParen() { return getToken(MxParser::RightParen, 0); }

MxParser::ArrayContext *MxParser::NewPrimaryContext::array() { return getRuleContext<MxParser::ArrayContext>(0); }

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
    setState(340);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(302);
        match(MxParser::LeftParen);
        setState(303);
        expression(0);
        setState(304);
        match(MxParser::RightParen);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::LiteralPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(306);
        literal();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::VarPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(307);
        match(MxParser::Identifier);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(308);
        match(MxParser::This);
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(309);
        match(MxParser::New);
        setState(310);
        type();
        setState(313);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
          case 1: {
            setState(311);
            match(MxParser::LeftParen);
            setState(312);
            match(MxParser::RightParen);
            break;
          }

          default:
            break;
        }
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(315);
        match(MxParser::New);
        setState(316);
        type();
        setState(318);
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(317);
          match(MxParser::T__1);
          setState(320);
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MxParser::T__1);
        setState(322);
        array();
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(324);
        match(MxParser::New);
        setState(325);
        type();
        setState(330);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(326);
              match(MxParser::LeftBracket);
              setState(327);
              expression(0);
              setState(328);
              match(MxParser::RightBracket);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(332);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(337);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(334);
            match(MxParser::T__1);
          }
          setState(339);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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

std::vector<MxParser::LiteralContext *> MxParser::ArrayContext::literal() {
  return getRuleContexts<MxParser::LiteralContext>();
}

MxParser::LiteralContext *MxParser::ArrayContext::literal(size_t i) {
  return getRuleContext<MxParser::LiteralContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArrayContext::Comma() { return getTokens(MxParser::Comma); }

tree::TerminalNode *MxParser::ArrayContext::Comma(size_t i) { return getToken(MxParser::Comma, i); }

std::vector<MxParser::ArrayContext *> MxParser::ArrayContext::array() {
  return getRuleContexts<MxParser::ArrayContext>();
}

MxParser::ArrayContext *MxParser::ArrayContext::array(size_t i) { return getRuleContext<MxParser::ArrayContext>(i); }

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
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(342);
        match(MxParser::LeftBrace);
        setState(343);
        match(MxParser::RightBrace);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(344);
        match(MxParser::LeftBrace);
        setState(345);
        literal();
        setState(350);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(346);
          match(MxParser::Comma);
          setState(347);
          literal();
          setState(352);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(353);
        match(MxParser::RightBrace);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(355);
        match(MxParser::LeftBrace);
        setState(356);
        array();
        setState(361);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(357);
          match(MxParser::Comma);
          setState(358);
          array();
          setState(363);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(364);
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
    setState(374);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::DecimalNumber: {
        _localctx = _tracker.createInstance<MxParser::DecimalLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(368);
        match(MxParser::DecimalNumber);
        break;
      }

      case MxParser::True: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(369);
        match(MxParser::True);
        break;
      }

      case MxParser::False: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(370);
        match(MxParser::False);
        break;
      }

      case MxParser::StringLiteral: {
        _localctx = _tracker.createInstance<MxParser::StringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(371);
        match(MxParser::StringLiteral);
        break;
      }

      case MxParser::Null: {
        _localctx = _tracker.createInstance<MxParser::NullLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(372);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = _tracker.createInstance<MxParser::ArrayLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(373);
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
    setState(387);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(376);
        match(MxParser::Int);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(377);
        match(MxParser::Bool);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(378);
        match(MxParser::String);
        break;
      }

      case 4: {
        enterOuterAlt(_localctx, 4);
        setState(379);
        match(MxParser::Identifier);
        break;
      }

      case 5: {
        enterOuterAlt(_localctx, 5);
        setState(380);
        match(MxParser::Void);
        break;
      }

      case 6: {
        enterOuterAlt(_localctx, 6);
        setState(381);
        _la = _input->LA(1);
        if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 56623104) != 0))) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(383);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(382);
              match(MxParser::T__1);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(385);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
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
