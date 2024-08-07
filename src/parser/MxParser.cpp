
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
      4,   1,   63,  385, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,   4,   7,
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
      6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,
      1,   6,   1,   6,   3,   6,   185, 8,   6,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   5,   7,   195, 8,   7,   10,  7,   12,  7,   198, 9,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,
      7,   204, 8,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   213, 8,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,
      7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,
      3,   7,   261, 8,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   4,   7,   269, 8,   7,   11,
      7,   12,  7,   270, 1,   7,   1,   7,   1,   7,   5,   7,   276, 8,   7,   10,  7,   12,  7,   279, 9,   7,   1,
      8,   1,   8,   5,   8,   283, 8,   8,   10,  8,   12,  8,   286, 9,   8,   1,   8,   1,   8,   1,   9,   1,   9,
      1,   9,   5,   9,   293, 8,   9,   10,  9,   12,  9,   296, 9,   9,   1,   10,  1,   10,  1,   10,  1,   10,  1,
      10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  3,   10,  309, 8,   10,  1,   10,  1,   10,  1,
      10,  4,   10,  314, 8,   10,  11,  10,  12,  10,  315, 1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,
      1,   10,  1,   10,  4,   10,  326, 8,   10,  11,  10,  12,  10,  327, 1,   10,  5,   10,  331, 8,   10,  10,  10,
      12,  10,  334, 9,   10,  3,   10,  336, 8,   10,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  5,
      11,  344, 8,   11,  10,  11,  12,  11,  347, 9,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,
      5,   11,  355, 8,   11,  10,  11,  12,  11,  358, 9,   11,  1,   11,  1,   11,  3,   11,  362, 8,   11,  1,   12,
      1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  3,   12,  370, 8,   12,  1,   13,  1,   13,  1,   13,  1,   13,
      1,   13,  1,   13,  1,   13,  4,   13,  379, 8,   13,  11,  13,  12,  13,  380, 3,   13,  383, 8,   13,  1,   13,
      0,   1,   14,  14,  0,   2,   4,   6,   8,   10,  12,  14,  16,  18,  20,  22,  24,  26,  0,   8,   1,   0,   47,
      48,  1,   0,   26,  27,  2,   0,   39,  39,  45,  45,  1,   0,   28,  30,  1,   0,   40,  41,  1,   0,   31,  34,
      1,   0,   35,  36,  2,   0,   21,  22,  24,  25,  451, 0,   33,  1,   0,   0,   0,   2,   45,  1,   0,   0,   0,
      4,   48,  1,   0,   0,   0,   6,   89,  1,   0,   0,   0,   8,   91,  1,   0,   0,   0,   10,  110, 1,   0,   0,
      0,   12,  184, 1,   0,   0,   0,   14,  212, 1,   0,   0,   0,   16,  280, 1,   0,   0,   0,   18,  289, 1,   0,
      0,   0,   20,  335, 1,   0,   0,   0,   22,  361, 1,   0,   0,   0,   24,  369, 1,   0,   0,   0,   26,  382, 1,
      0,   0,   0,   28,  32,  3,   4,   2,   0,   29,  32,  3,   8,   4,   0,   30,  32,  3,   10,  5,   0,   31,  28,
      1,   0,   0,   0,   31,  29,  1,   0,   0,   0,   31,  30,  1,   0,   0,   0,   32,  35,  1,   0,   0,   0,   33,
      31,  1,   0,   0,   0,   33,  34,  1,   0,   0,   0,   34,  36,  1,   0,   0,   0,   35,  33,  1,   0,   0,   0,
      36,  42,  3,   2,   1,   0,   37,  41,  3,   4,   2,   0,   38,  41,  3,   8,   4,   0,   39,  41,  3,   10,  5,
      0,   40,  37,  1,   0,   0,   0,   40,  38,  1,   0,   0,   0,   40,  39,  1,   0,   0,   0,   41,  44,  1,   0,
      0,   0,   42,  40,  1,   0,   0,   0,   42,  43,  1,   0,   0,   0,   43,  1,   1,   0,   0,   0,   44,  42,  1,
      0,   0,   0,   45,  46,  5,   1,   0,   0,   46,  47,  3,   16,  8,   0,   47,  3,   1,   0,   0,   0,   48,  49,
      5,   12,  0,   0,   49,  50,  5,   25,  0,   0,   50,  54,  5,   54,  0,   0,   51,  53,  3,   6,   3,   0,   52,
      51,  1,   0,   0,   0,   53,  56,  1,   0,   0,   0,   54,  52,  1,   0,   0,   0,   54,  55,  1,   0,   0,   0,
      55,  57,  1,   0,   0,   0,   56,  54,  1,   0,   0,   0,   57,  58,  5,   55,  0,   0,   58,  59,  5,   59,  0,
      0,   59,  5,   1,   0,   0,   0,   60,  61,  3,   26,  13,  0,   61,  66,  5,   25,  0,   0,   62,  63,  5,   60,
      0,   0,   63,  65,  5,   25,  0,   0,   64,  62,  1,   0,   0,   0,   65,  68,  1,   0,   0,   0,   66,  64,  1,
      0,   0,   0,   66,  67,  1,   0,   0,   0,   67,  69,  1,   0,   0,   0,   68,  66,  1,   0,   0,   0,   69,  70,
      5,   59,  0,   0,   70,  90,  1,   0,   0,   0,   71,  72,  5,   25,  0,   0,   72,  73,  5,   50,  0,   0,   73,
      74,  5,   51,  0,   0,   74,  90,  3,   16,  8,   0,   75,  76,  3,   26,  13,  0,   76,  77,  5,   25,  0,   0,
      77,  83,  5,   50,  0,   0,   78,  79,  3,   26,  13,  0,   79,  80,  5,   25,  0,   0,   80,  82,  1,   0,   0,
      0,   81,  78,  1,   0,   0,   0,   82,  85,  1,   0,   0,   0,   83,  81,  1,   0,   0,   0,   83,  84,  1,   0,
      0,   0,   84,  86,  1,   0,   0,   0,   85,  83,  1,   0,   0,   0,   86,  87,  5,   51,  0,   0,   87,  88,  3,
      16,  8,   0,   88,  90,  1,   0,   0,   0,   89,  60,  1,   0,   0,   0,   89,  71,  1,   0,   0,   0,   89,  75,
      1,   0,   0,   0,   90,  7,   1,   0,   0,   0,   91,  92,  3,   26,  13,  0,   92,  93,  5,   25,  0,   0,   93,
      105, 5,   50,  0,   0,   94,  95,  3,   26,  13,  0,   95,  102, 5,   25,  0,   0,   96,  97,  5,   60,  0,   0,
      97,  98,  3,   26,  13,  0,   98,  99,  5,   25,  0,   0,   99,  101, 1,   0,   0,   0,   100, 96,  1,   0,   0,
      0,   101, 104, 1,   0,   0,   0,   102, 100, 1,   0,   0,   0,   102, 103, 1,   0,   0,   0,   103, 106, 1,   0,
      0,   0,   104, 102, 1,   0,   0,   0,   105, 94,  1,   0,   0,   0,   105, 106, 1,   0,   0,   0,   106, 107, 1,
      0,   0,   0,   107, 108, 5,   51,  0,   0,   108, 109, 3,   16,  8,   0,   109, 9,   1,   0,   0,   0,   110, 111,
      3,   26,  13,  0,   111, 114, 5,   25,  0,   0,   112, 113, 5,   46,  0,   0,   113, 115, 3,   14,  7,   0,   114,
      112, 1,   0,   0,   0,   114, 115, 1,   0,   0,   0,   115, 124, 1,   0,   0,   0,   116, 117, 5,   60,  0,   0,
      117, 120, 5,   25,  0,   0,   118, 119, 5,   46,  0,   0,   119, 121, 3,   14,  7,   0,   120, 118, 1,   0,   0,
      0,   120, 121, 1,   0,   0,   0,   121, 123, 1,   0,   0,   0,   122, 116, 1,   0,   0,   0,   123, 126, 1,   0,
      0,   0,   124, 122, 1,   0,   0,   0,   124, 125, 1,   0,   0,   0,   125, 127, 1,   0,   0,   0,   126, 124, 1,
      0,   0,   0,   127, 128, 5,   59,  0,   0,   128, 11,  1,   0,   0,   0,   129, 130, 3,   26,  13,  0,   130, 133,
      5,   25,  0,   0,   131, 132, 5,   46,  0,   0,   132, 134, 3,   14,  7,   0,   133, 131, 1,   0,   0,   0,   133,
      134, 1,   0,   0,   0,   134, 143, 1,   0,   0,   0,   135, 136, 5,   60,  0,   0,   136, 139, 5,   25,  0,   0,
      137, 138, 5,   46,  0,   0,   138, 140, 3,   14,  7,   0,   139, 137, 1,   0,   0,   0,   139, 140, 1,   0,   0,
      0,   140, 142, 1,   0,   0,   0,   141, 135, 1,   0,   0,   0,   142, 145, 1,   0,   0,   0,   143, 141, 1,   0,
      0,   0,   143, 144, 1,   0,   0,   0,   144, 146, 1,   0,   0,   0,   145, 143, 1,   0,   0,   0,   146, 147, 5,
      59,  0,   0,   147, 185, 1,   0,   0,   0,   148, 185, 3,   16,  8,   0,   149, 150, 3,   14,  7,   0,   150, 151,
      5,   59,  0,   0,   151, 185, 1,   0,   0,   0,   152, 153, 5,   14,  0,   0,   153, 154, 5,   50,  0,   0,   154,
      155, 3,   14,  7,   0,   155, 156, 5,   51,  0,   0,   156, 159, 3,   12,  6,   0,   157, 158, 5,   15,  0,   0,
      158, 160, 3,   12,  6,   0,   159, 157, 1,   0,   0,   0,   159, 160, 1,   0,   0,   0,   160, 185, 1,   0,   0,
      0,   161, 162, 5,   17,  0,   0,   162, 163, 5,   50,  0,   0,   163, 164, 3,   14,  7,   0,   164, 165, 5,   51,
      0,   0,   165, 166, 3,   16,  8,   0,   166, 185, 1,   0,   0,   0,   167, 168, 5,   16,  0,   0,   168, 169, 5,
      50,  0,   0,   169, 170, 3,   12,  6,   0,   170, 171, 3,   14,  7,   0,   171, 172, 5,   59,  0,   0,   172, 173,
      3,   14,  7,   0,   173, 174, 5,   51,  0,   0,   174, 175, 3,   12,  6,   0,   175, 185, 1,   0,   0,   0,   176,
      177, 5,   20,  0,   0,   177, 178, 3,   14,  7,   0,   178, 179, 5,   59,  0,   0,   179, 185, 1,   0,   0,   0,
      180, 181, 5,   18,  0,   0,   181, 185, 5,   59,  0,   0,   182, 183, 5,   19,  0,   0,   183, 185, 5,   59,  0,
      0,   184, 129, 1,   0,   0,   0,   184, 148, 1,   0,   0,   0,   184, 149, 1,   0,   0,   0,   184, 152, 1,   0,
      0,   0,   184, 161, 1,   0,   0,   0,   184, 167, 1,   0,   0,   0,   184, 176, 1,   0,   0,   0,   184, 180, 1,
      0,   0,   0,   184, 182, 1,   0,   0,   0,   185, 13,  1,   0,   0,   0,   186, 187, 6,   7,   -1,  0,   187, 213,
      3,   20,  10,  0,   188, 196, 5,   3,   0,   0,   189, 195, 5,   9,   0,   0,   190, 191, 5,   56,  0,   0,   191,
      192, 3,   14,  7,   0,   192, 193, 5,   56,  0,   0,   193, 195, 1,   0,   0,   0,   194, 189, 1,   0,   0,   0,
      194, 190, 1,   0,   0,   0,   195, 198, 1,   0,   0,   0,   196, 194, 1,   0,   0,   0,   196, 197, 1,   0,   0,
      0,   197, 199, 1,   0,   0,   0,   198, 196, 1,   0,   0,   0,   199, 213, 5,   4,   0,   0,   200, 201, 5,   25,
      0,   0,   201, 203, 5,   50,  0,   0,   202, 204, 3,   18,  9,   0,   203, 202, 1,   0,   0,   0,   203, 204, 1,
      0,   0,   0,   204, 205, 1,   0,   0,   0,   205, 213, 5,   51,  0,   0,   206, 207, 7,   0,   0,   0,   207, 213,
      3,   14,  7,   15,  208, 209, 7,   1,   0,   0,   209, 213, 3,   14,  7,   14,  210, 211, 7,   2,   0,   0,   211,
      213, 3,   14,  7,   13,  212, 186, 1,   0,   0,   0,   212, 188, 1,   0,   0,   0,   212, 200, 1,   0,   0,   0,
      212, 206, 1,   0,   0,   0,   212, 208, 1,   0,   0,   0,   212, 210, 1,   0,   0,   0,   213, 277, 1,   0,   0,
      0,   214, 215, 10,  12,  0,   0,   215, 216, 7,   3,   0,   0,   216, 276, 3,   14,  7,   13,  217, 218, 10,  11,
      0,   0,   218, 219, 7,   1,   0,   0,   219, 276, 3,   14,  7,   12,  220, 221, 10,  10,  0,   0,   221, 222, 7,
      4,   0,   0,   222, 276, 3,   14,  7,   11,  223, 224, 10,  9,   0,   0,   224, 225, 7,   5,   0,   0,   225, 276,
      3,   14,  7,   10,  226, 227, 10,  8,   0,   0,   227, 228, 7,   6,   0,   0,   228, 276, 3,   14,  7,   9,   229,
      230, 10,  7,   0,   0,   230, 231, 5,   42,  0,   0,   231, 276, 3,   14,  7,   8,   232, 233, 10,  6,   0,   0,
      233, 234, 5,   44,  0,   0,   234, 276, 3,   14,  7,   7,   235, 236, 10,  5,   0,   0,   236, 237, 5,   43,  0,
      0,   237, 276, 3,   14,  7,   6,   238, 239, 10,  4,   0,   0,   239, 240, 5,   37,  0,   0,   240, 276, 3,   14,
      7,   5,   241, 242, 10,  3,   0,   0,   242, 243, 5,   38,  0,   0,   243, 276, 3,   14,  7,   4,   244, 245, 10,
      2,   0,   0,   245, 246, 5,   57,  0,   0,   246, 247, 3,   14,  7,   0,   247, 248, 5,   58,  0,   0,   248, 249,
      3,   14,  7,   2,   249, 276, 1,   0,   0,   0,   250, 251, 10,  1,   0,   0,   251, 252, 5,   46,  0,   0,   252,
      276, 3,   14,  7,   2,   253, 254, 10,  20,  0,   0,   254, 276, 7,   0,   0,   0,   255, 256, 10,  18,  0,   0,
      256, 257, 5,   49,  0,   0,   257, 258, 5,   25,  0,   0,   258, 260, 5,   50,  0,   0,   259, 261, 3,   18,  9,
      0,   260, 259, 1,   0,   0,   0,   260, 261, 1,   0,   0,   0,   261, 262, 1,   0,   0,   0,   262, 276, 5,   51,
      0,   0,   263, 268, 10,  17,  0,   0,   264, 265, 5,   52,  0,   0,   265, 266, 3,   14,  7,   0,   266, 267, 5,
      53,  0,   0,   267, 269, 1,   0,   0,   0,   268, 264, 1,   0,   0,   0,   269, 270, 1,   0,   0,   0,   270, 268,
      1,   0,   0,   0,   270, 271, 1,   0,   0,   0,   271, 276, 1,   0,   0,   0,   272, 273, 10,  16,  0,   0,   273,
      274, 5,   49,  0,   0,   274, 276, 5,   25,  0,   0,   275, 214, 1,   0,   0,   0,   275, 217, 1,   0,   0,   0,
      275, 220, 1,   0,   0,   0,   275, 223, 1,   0,   0,   0,   275, 226, 1,   0,   0,   0,   275, 229, 1,   0,   0,
      0,   275, 232, 1,   0,   0,   0,   275, 235, 1,   0,   0,   0,   275, 238, 1,   0,   0,   0,   275, 241, 1,   0,
      0,   0,   275, 244, 1,   0,   0,   0,   275, 250, 1,   0,   0,   0,   275, 253, 1,   0,   0,   0,   275, 255, 1,
      0,   0,   0,   275, 263, 1,   0,   0,   0,   275, 272, 1,   0,   0,   0,   276, 279, 1,   0,   0,   0,   277, 275,
      1,   0,   0,   0,   277, 278, 1,   0,   0,   0,   278, 15,  1,   0,   0,   0,   279, 277, 1,   0,   0,   0,   280,
      284, 5,   54,  0,   0,   281, 283, 3,   12,  6,   0,   282, 281, 1,   0,   0,   0,   283, 286, 1,   0,   0,   0,
      284, 282, 1,   0,   0,   0,   284, 285, 1,   0,   0,   0,   285, 287, 1,   0,   0,   0,   286, 284, 1,   0,   0,
      0,   287, 288, 5,   55,  0,   0,   288, 17,  1,   0,   0,   0,   289, 294, 3,   14,  7,   0,   290, 291, 5,   60,
      0,   0,   291, 293, 3,   14,  7,   0,   292, 290, 1,   0,   0,   0,   293, 296, 1,   0,   0,   0,   294, 292, 1,
      0,   0,   0,   294, 295, 1,   0,   0,   0,   295, 19,  1,   0,   0,   0,   296, 294, 1,   0,   0,   0,   297, 298,
      5,   50,  0,   0,   298, 299, 3,   14,  7,   0,   299, 300, 5,   51,  0,   0,   300, 336, 1,   0,   0,   0,   301,
      336, 3,   24,  12,  0,   302, 336, 5,   25,  0,   0,   303, 336, 5,   13,  0,   0,   304, 305, 5,   11,  0,   0,
      305, 308, 3,   26,  13,  0,   306, 307, 5,   50,  0,   0,   307, 309, 5,   51,  0,   0,   308, 306, 1,   0,   0,
      0,   308, 309, 1,   0,   0,   0,   309, 336, 1,   0,   0,   0,   310, 311, 5,   11,  0,   0,   311, 313, 3,   26,
      13,  0,   312, 314, 5,   2,   0,   0,   313, 312, 1,   0,   0,   0,   314, 315, 1,   0,   0,   0,   315, 313, 1,
      0,   0,   0,   315, 316, 1,   0,   0,   0,   316, 317, 1,   0,   0,   0,   317, 318, 3,   22,  11,  0,   318, 336,
      1,   0,   0,   0,   319, 320, 5,   11,  0,   0,   320, 325, 3,   26,  13,  0,   321, 322, 5,   52,  0,   0,   322,
      323, 3,   14,  7,   0,   323, 324, 5,   53,  0,   0,   324, 326, 1,   0,   0,   0,   325, 321, 1,   0,   0,   0,
      326, 327, 1,   0,   0,   0,   327, 325, 1,   0,   0,   0,   327, 328, 1,   0,   0,   0,   328, 332, 1,   0,   0,
      0,   329, 331, 5,   2,   0,   0,   330, 329, 1,   0,   0,   0,   331, 334, 1,   0,   0,   0,   332, 330, 1,   0,
      0,   0,   332, 333, 1,   0,   0,   0,   333, 336, 1,   0,   0,   0,   334, 332, 1,   0,   0,   0,   335, 297, 1,
      0,   0,   0,   335, 301, 1,   0,   0,   0,   335, 302, 1,   0,   0,   0,   335, 303, 1,   0,   0,   0,   335, 304,
      1,   0,   0,   0,   335, 310, 1,   0,   0,   0,   335, 319, 1,   0,   0,   0,   336, 21,  1,   0,   0,   0,   337,
      338, 5,   54,  0,   0,   338, 362, 5,   55,  0,   0,   339, 340, 5,   54,  0,   0,   340, 345, 3,   24,  12,  0,
      341, 342, 5,   60,  0,   0,   342, 344, 3,   24,  12,  0,   343, 341, 1,   0,   0,   0,   344, 347, 1,   0,   0,
      0,   345, 343, 1,   0,   0,   0,   345, 346, 1,   0,   0,   0,   346, 348, 1,   0,   0,   0,   347, 345, 1,   0,
      0,   0,   348, 349, 5,   55,  0,   0,   349, 362, 1,   0,   0,   0,   350, 351, 5,   54,  0,   0,   351, 356, 3,
      22,  11,  0,   352, 353, 5,   60,  0,   0,   353, 355, 3,   22,  11,  0,   354, 352, 1,   0,   0,   0,   355, 358,
      1,   0,   0,   0,   356, 354, 1,   0,   0,   0,   356, 357, 1,   0,   0,   0,   357, 359, 1,   0,   0,   0,   358,
      356, 1,   0,   0,   0,   359, 360, 5,   55,  0,   0,   360, 362, 1,   0,   0,   0,   361, 337, 1,   0,   0,   0,
      361, 339, 1,   0,   0,   0,   361, 350, 1,   0,   0,   0,   362, 23,  1,   0,   0,   0,   363, 370, 5,   7,   0,
      0,   364, 370, 5,   5,   0,   0,   365, 370, 5,   6,   0,   0,   366, 370, 5,   8,   0,   0,   367, 370, 5,   10,
      0,   0,   368, 370, 3,   22,  11,  0,   369, 363, 1,   0,   0,   0,   369, 364, 1,   0,   0,   0,   369, 365, 1,
      0,   0,   0,   369, 366, 1,   0,   0,   0,   369, 367, 1,   0,   0,   0,   369, 368, 1,   0,   0,   0,   370, 25,
      1,   0,   0,   0,   371, 383, 5,   22,  0,   0,   372, 383, 5,   21,  0,   0,   373, 383, 5,   24,  0,   0,   374,
      383, 5,   25,  0,   0,   375, 383, 5,   23,  0,   0,   376, 378, 7,   7,   0,   0,   377, 379, 5,   2,   0,   0,
      378, 377, 1,   0,   0,   0,   379, 380, 1,   0,   0,   0,   380, 378, 1,   0,   0,   0,   380, 381, 1,   0,   0,
      0,   381, 383, 1,   0,   0,   0,   382, 371, 1,   0,   0,   0,   382, 372, 1,   0,   0,   0,   382, 373, 1,   0,
      0,   0,   382, 374, 1,   0,   0,   0,   382, 375, 1,   0,   0,   0,   382, 376, 1,   0,   0,   0,   383, 27,  1,
      0,   0,   0,   39,  31,  33,  40,  42,  54,  66,  83,  89,  102, 105, 114, 120, 124, 133, 139, 143, 159, 184, 194,
      196, 203, 212, 260, 270, 275, 277, 284, 294, 308, 315, 327, 332, 335, 345, 356, 361, 369, 380, 382};
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
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
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
        setState(170);
        antlrcpp::downCast<ForStmtContext *>(_localctx)->conditionExpr = expression(0);
        setState(171);
        match(MxParser::Semicolon);
        setState(172);
        antlrcpp::downCast<ForStmtContext *>(_localctx)->stepExpr = expression(0);
        setState(173);
        match(MxParser::RightParen);
        setState(174);
        statement();
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(176);
        match(MxParser::Return);
        setState(177);
        antlrcpp::downCast<ReturnStmtContext *>(_localctx)->returnExpr = expression(0);
        setState(178);
        match(MxParser::Semicolon);
        break;
      }

      case 8: {
        _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(180);
        match(MxParser::Break);
        setState(181);
        match(MxParser::Semicolon);
        break;
      }

      case 9: {
        _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(182);
        match(MxParser::Continue);
        setState(183);
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
    setState(212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<AtomicExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(187);
        primary();
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(188);
        match(MxParser::FormatQuatation);
        setState(196);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatStringLiteral

               || _la == MxParser::Dollar) {
          setState(194);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case MxParser::FormatStringLiteral: {
              setState(189);
              match(MxParser::FormatStringLiteral);
              break;
            }

            case MxParser::Dollar: {
              setState(190);
              match(MxParser::Dollar);
              setState(191);
              expression(0);
              setState(192);
              match(MxParser::Dollar);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(198);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(199);
        match(MxParser::Quotation);
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<FuncCallExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(200);
        antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
        setState(201);
        match(MxParser::LeftParen);
        setState(203);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
          setState(202);
          arguments();
        }
        setState(205);
        match(MxParser::RightParen);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(206);
        _la = _input->LA(1);
        if (!(_la == MxParser::Increment

              || _la == MxParser::Decrement)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(207);
        expression(15);
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(208);
        _la = _input->LA(1);
        if (!(_la == MxParser::Add

              || _la == MxParser::Sub)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(209);
        expression(14);
        break;
      }

      case 6: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(210);
        _la = _input->LA(1);
        if (!(_la == MxParser::NotLogic

              || _la == MxParser::Not)) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(211);
        expression(13);
        break;
      }

      default:
        break;
    }
    _ctx->stop = _input->LT(-1);
    setState(277);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty()) triggerExitRuleEvent();
        previousContext = _localctx;
        setState(275);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
          case 1: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(214);

            if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
            setState(215);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 1879048192) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(216);
            expression(13);
            break;
          }

          case 2: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(217);

            if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
            setState(218);
            _la = _input->LA(1);
            if (!(_la == MxParser::Add

                  || _la == MxParser::Sub)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(219);
            expression(12);
            break;
          }

          case 3: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(220);

            if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
            setState(221);
            _la = _input->LA(1);
            if (!(_la == MxParser::ShiftRight

                  || _la == MxParser::ShiftLeft)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(222);
            expression(11);
            break;
          }

          case 4: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(223);

            if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
            setState(224);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 32212254720) != 0))) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(225);
            expression(10);
            break;
          }

          case 5: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(226);

            if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
            setState(227);
            _la = _input->LA(1);
            if (!(_la == MxParser::Equal

                  || _la == MxParser::UnEqual)) {
              _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(228);
            expression(9);
            break;
          }

          case 6: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(229);

            if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
            setState(230);
            match(MxParser::And);
            setState(231);
            expression(8);
            break;
          }

          case 7: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(232);

            if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
            setState(233);
            match(MxParser::Xor);
            setState(234);
            expression(7);
            break;
          }

          case 8: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(235);

            if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
            setState(236);
            match(MxParser::Or);
            setState(237);
            expression(6);
            break;
          }

          case 9: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(238);

            if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
            setState(239);
            match(MxParser::AndLogic);
            setState(240);
            expression(5);
            break;
          }

          case 10: {
            auto newContext = _tracker.createInstance<BinaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(241);

            if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
            setState(242);
            match(MxParser::OrLogic);
            setState(243);
            expression(4);
            break;
          }

          case 11: {
            auto newContext = _tracker.createInstance<TenaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(244);

            if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
            setState(245);
            match(MxParser::Question);
            setState(246);
            expression(0);
            setState(247);
            match(MxParser::Colon);
            setState(248);
            expression(2);
            break;
          }

          case 12: {
            auto newContext = _tracker.createInstance<AssignExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(250);

            if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
            setState(251);
            match(MxParser::Assign);
            setState(252);
            expression(2);
            break;
          }

          case 13: {
            auto newContext = _tracker.createInstance<UnaryExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(253);

            if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
            setState(254);
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
            setState(255);

            if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
            setState(256);
            match(MxParser::Dot);
            setState(257);
            antlrcpp::downCast<FuncCallExprContext *>(_localctx)->funcName = match(MxParser::Identifier);
            setState(258);
            match(MxParser::LeftParen);
            setState(260);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245244186088) != 0)) {
              setState(259);
              arguments();
            }
            setState(262);
            match(MxParser::RightParen);
            break;
          }

          case 15: {
            auto newContext = _tracker.createInstance<SubscriptExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(263);

            if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
            setState(268);
            _errHandler->sync(this);
            alt = 1;
            do {
              switch (alt) {
                case 1: {
                  setState(264);
                  match(MxParser::LeftBracket);
                  setState(265);
                  antlrcpp::downCast<SubscriptExprContext *>(_localctx)->index = expression(0);
                  setState(266);
                  match(MxParser::RightBracket);
                  break;
                }

                default:
                  throw NoViableAltException(this);
              }
              setState(270);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
            } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
            break;
          }

          case 16: {
            auto newContext = _tracker.createInstance<MemberExprContext>(
                _tracker.createInstance<ExpressionContext>(parentContext, parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpression);
            setState(272);

            if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
            setState(273);
            match(MxParser::Dot);
            setState(274);
            match(MxParser::Identifier);
            break;
          }

          default:
            break;
        }
      }
      setState(279);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
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
    setState(280);
    match(MxParser::LeftBrace);
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 19598245277691368) != 0)) {
      setState(281);
      statement();
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
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
    setState(289);
    expression(0);
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(290);
      match(MxParser::Comma);
      setState(291);
      expression(0);
      setState(296);
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
    setState(335);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(297);
        match(MxParser::LeftParen);
        setState(298);
        expression(0);
        setState(299);
        match(MxParser::RightParen);
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<MxParser::LiteralPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(301);
        literal();
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<MxParser::VarPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(302);
        match(MxParser::Identifier);
        break;
      }

      case 4: {
        _localctx = _tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(303);
        match(MxParser::This);
        break;
      }

      case 5: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(304);
        match(MxParser::New);
        setState(305);
        type();
        setState(308);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
          case 1: {
            setState(306);
            match(MxParser::LeftParen);
            setState(307);
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
        setState(310);
        match(MxParser::New);
        setState(311);
        type();
        setState(313);
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(312);
          match(MxParser::T__1);
          setState(315);
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MxParser::T__1);
        setState(317);
        array();
        break;
      }

      case 7: {
        _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(319);
        match(MxParser::New);
        setState(320);
        type();
        setState(325);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(321);
              match(MxParser::LeftBracket);
              setState(322);
              expression(0);
              setState(323);
              match(MxParser::RightBracket);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(327);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(332);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(329);
            match(MxParser::T__1);
          }
          setState(334);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
    setState(361);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(337);
        match(MxParser::LeftBrace);
        setState(338);
        match(MxParser::RightBrace);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(339);
        match(MxParser::LeftBrace);
        setState(340);
        literal();
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(341);
          match(MxParser::Comma);
          setState(342);
          literal();
          setState(347);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(348);
        match(MxParser::RightBrace);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(350);
        match(MxParser::LeftBrace);
        setState(351);
        array();
        setState(356);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::Comma) {
          setState(352);
          match(MxParser::Comma);
          setState(353);
          array();
          setState(358);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(359);
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
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::DecimalNumber: {
        _localctx = _tracker.createInstance<MxParser::DecimalLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(363);
        match(MxParser::DecimalNumber);
        break;
      }

      case MxParser::True: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(364);
        match(MxParser::True);
        break;
      }

      case MxParser::False: {
        _localctx = _tracker.createInstance<MxParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(365);
        match(MxParser::False);
        break;
      }

      case MxParser::StringLiteral: {
        _localctx = _tracker.createInstance<MxParser::StringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(366);
        match(MxParser::StringLiteral);
        break;
      }

      case MxParser::Null: {
        _localctx = _tracker.createInstance<MxParser::NullLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(367);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = _tracker.createInstance<MxParser::ArrayLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(368);
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
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
      case 1: {
        enterOuterAlt(_localctx, 1);
        setState(371);
        match(MxParser::Int);
        break;
      }

      case 2: {
        enterOuterAlt(_localctx, 2);
        setState(372);
        match(MxParser::Bool);
        break;
      }

      case 3: {
        enterOuterAlt(_localctx, 3);
        setState(373);
        match(MxParser::String);
        break;
      }

      case 4: {
        enterOuterAlt(_localctx, 4);
        setState(374);
        match(MxParser::Identifier);
        break;
      }

      case 5: {
        enterOuterAlt(_localctx, 5);
        setState(375);
        match(MxParser::Void);
        break;
      }

      case 6: {
        enterOuterAlt(_localctx, 6);
        setState(376);
        _la = _input->LA(1);
        if (!((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 56623104) != 0))) {
          _errHandler->recoverInline(this);
        } else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(378);
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
              setState(377);
              match(MxParser::T__1);
              break;
            }

            default:
              throw NoViableAltException(this);
          }
          setState(380);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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
