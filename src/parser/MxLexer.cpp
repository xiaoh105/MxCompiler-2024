
// Generated from Mx.g4 by ANTLR 4.13.1


#include "parser/MxLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MxLexerStaticData final {
  MxLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxLexerStaticData(const MxLexerStaticData&) = delete;
  MxLexerStaticData(MxLexerStaticData&&) = delete;
  MxLexerStaticData& operator=(const MxLexerStaticData&) = delete;
  MxLexerStaticData& operator=(MxLexerStaticData&&) = delete;

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
    std::vector<std::string>{
      "T__0", "T__1", "FormatQuatation", "Quotation", "True", "False", "DecimalNumber", 
      "StringLiteral", "FormatStringLiteral", "Null", "New", "Class", "This", 
      "If", "Else", "For", "While", "Break", "Continue", "Return", "Bool", 
      "Int", "Void", "String", "Identifier", "Add", "Sub", "Mul", "Div", 
      "Mod", "Less", "LessEqual", "Greater", "GreaterEqual", "Equal", "UnEqual", 
      "AndLogic", "OrLogic", "NotLogic", "ShiftRight", "ShiftLeft", "And", 
      "Or", "Xor", "Not", "Assign", "Increment", "Decrement", "Dot", "LeftParen", 
      "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
      "Dollar", "Question", "Colon", "Semicolon", "Comma", "Whitespace", 
      "LineComment", "BlockComment"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int main()'", "'[]'", "'f\"'", "", "'true'", "'false'", "", 
      "", "", "'null'", "'new'", "'class'", "'this'", "'if'", "'else'", 
      "'for'", "'while'", "'break'", "'continue'", "'return'", "'bool'", 
      "'int'", "'void'", "'string'", "", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'!'", 
      "'>>'", "'<<'", "'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", 
      "'.'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'$'", "'\\u003F'", 
      "':'", "';'", "','"
    },
    std::vector<std::string>{
      "", "", "", "FormatQuatation", "Quotation", "True", "False", "DecimalNumber", 
      "StringLiteral", "FormatStringLiteral", "Null", "New", "Class", "This", 
      "If", "Else", "For", "While", "Break", "Continue", "Return", "Bool", 
      "Int", "Void", "String", "Identifier", "Add", "Sub", "Mul", "Div", 
      "Mod", "Less", "LessEqual", "Greater", "GreaterEqual", "Equal", "UnEqual", 
      "AndLogic", "OrLogic", "NotLogic", "ShiftRight", "ShiftLeft", "And", 
      "Or", "Xor", "Not", "Assign", "Increment", "Decrement", "Dot", "LeftParen", 
      "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
      "Dollar", "Question", "Colon", "Semicolon", "Comma", "Whitespace", 
      "LineComment", "BlockComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,63,399,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,
  	2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,
  	5,6,164,8,6,10,6,12,6,167,9,6,1,6,3,6,170,8,6,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,5,7,181,8,7,10,7,12,7,184,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,4,8,198,8,8,11,8,12,8,199,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,
  	1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,24,1,24,5,24,285,8,24,10,24,12,24,288,9,24,
  	1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,
  	1,31,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,
  	1,36,1,37,1,37,1,37,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,40,1,41,1,41,
  	1,42,1,42,1,43,1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,46,1,47,1,47,1,47,
  	1,48,1,48,1,49,1,49,1,50,1,50,1,51,1,51,1,52,1,52,1,53,1,53,1,54,1,54,
  	1,55,1,55,1,55,1,56,1,56,1,57,1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,60,
  	1,60,1,61,1,61,1,61,1,61,5,61,379,8,61,10,61,12,61,382,9,61,1,61,1,61,
  	1,62,1,62,1,62,1,62,5,62,390,8,62,10,62,12,62,393,9,62,1,62,1,62,1,62,
  	1,62,1,62,1,391,0,63,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,
  	45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,
  	34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,
  	91,46,93,47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,
  	56,113,57,115,58,117,59,119,60,121,61,123,62,125,63,1,0,8,1,0,49,57,1,
  	0,48,57,3,0,32,33,35,91,93,126,4,0,32,33,35,35,37,91,93,126,2,0,65,90,
  	97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,2,0,10,10,13,
  	13,412,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,
  	11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,
  	0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,
  	0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,
  	43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,
  	0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,
  	0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,
  	75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,
  	0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,
  	0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,
  	0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,
  	0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,
  	1,127,1,0,0,0,3,138,1,0,0,0,5,141,1,0,0,0,7,146,1,0,0,0,9,150,1,0,0,0,
  	11,155,1,0,0,0,13,169,1,0,0,0,15,171,1,0,0,0,17,187,1,0,0,0,19,201,1,
  	0,0,0,21,206,1,0,0,0,23,210,1,0,0,0,25,216,1,0,0,0,27,221,1,0,0,0,29,
  	224,1,0,0,0,31,229,1,0,0,0,33,233,1,0,0,0,35,239,1,0,0,0,37,245,1,0,0,
  	0,39,254,1,0,0,0,41,261,1,0,0,0,43,266,1,0,0,0,45,270,1,0,0,0,47,275,
  	1,0,0,0,49,282,1,0,0,0,51,289,1,0,0,0,53,291,1,0,0,0,55,293,1,0,0,0,57,
  	295,1,0,0,0,59,297,1,0,0,0,61,299,1,0,0,0,63,301,1,0,0,0,65,304,1,0,0,
  	0,67,306,1,0,0,0,69,309,1,0,0,0,71,312,1,0,0,0,73,315,1,0,0,0,75,318,
  	1,0,0,0,77,321,1,0,0,0,79,323,1,0,0,0,81,326,1,0,0,0,83,329,1,0,0,0,85,
  	331,1,0,0,0,87,333,1,0,0,0,89,335,1,0,0,0,91,337,1,0,0,0,93,339,1,0,0,
  	0,95,342,1,0,0,0,97,345,1,0,0,0,99,347,1,0,0,0,101,349,1,0,0,0,103,351,
  	1,0,0,0,105,353,1,0,0,0,107,355,1,0,0,0,109,357,1,0,0,0,111,359,1,0,0,
  	0,113,362,1,0,0,0,115,364,1,0,0,0,117,366,1,0,0,0,119,368,1,0,0,0,121,
  	370,1,0,0,0,123,374,1,0,0,0,125,385,1,0,0,0,127,128,5,105,0,0,128,129,
  	5,110,0,0,129,130,5,116,0,0,130,131,5,32,0,0,131,132,5,109,0,0,132,133,
  	5,97,0,0,133,134,5,105,0,0,134,135,5,110,0,0,135,136,5,40,0,0,136,137,
  	5,41,0,0,137,2,1,0,0,0,138,139,5,91,0,0,139,140,5,93,0,0,140,4,1,0,0,
  	0,141,142,5,102,0,0,142,143,5,34,0,0,143,144,1,0,0,0,144,145,6,2,0,0,
  	145,6,1,0,0,0,146,147,4,3,0,0,147,148,5,34,0,0,148,149,6,3,1,0,149,8,
  	1,0,0,0,150,151,5,116,0,0,151,152,5,114,0,0,152,153,5,117,0,0,153,154,
  	5,101,0,0,154,10,1,0,0,0,155,156,5,102,0,0,156,157,5,97,0,0,157,158,5,
  	108,0,0,158,159,5,115,0,0,159,160,5,101,0,0,160,12,1,0,0,0,161,165,7,
  	0,0,0,162,164,7,1,0,0,163,162,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,
  	165,166,1,0,0,0,166,170,1,0,0,0,167,165,1,0,0,0,168,170,5,48,0,0,169,
  	161,1,0,0,0,169,168,1,0,0,0,170,14,1,0,0,0,171,172,4,7,1,0,172,182,5,
  	34,0,0,173,174,5,92,0,0,174,181,5,110,0,0,175,176,5,92,0,0,176,181,5,
  	92,0,0,177,178,5,92,0,0,178,181,5,34,0,0,179,181,7,2,0,0,180,173,1,0,
  	0,0,180,175,1,0,0,0,180,177,1,0,0,0,180,179,1,0,0,0,181,184,1,0,0,0,182,
  	180,1,0,0,0,182,183,1,0,0,0,183,185,1,0,0,0,184,182,1,0,0,0,185,186,5,
  	34,0,0,186,16,1,0,0,0,187,197,4,8,2,0,188,189,5,92,0,0,189,198,5,110,
  	0,0,190,191,5,92,0,0,191,198,5,92,0,0,192,193,5,92,0,0,193,198,5,34,0,
  	0,194,195,5,36,0,0,195,198,5,36,0,0,196,198,7,3,0,0,197,188,1,0,0,0,197,
  	190,1,0,0,0,197,192,1,0,0,0,197,194,1,0,0,0,197,196,1,0,0,0,198,199,1,
  	0,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,18,1,0,0,0,201,202,5,110,0,
  	0,202,203,5,117,0,0,203,204,5,108,0,0,204,205,5,108,0,0,205,20,1,0,0,
  	0,206,207,5,110,0,0,207,208,5,101,0,0,208,209,5,119,0,0,209,22,1,0,0,
  	0,210,211,5,99,0,0,211,212,5,108,0,0,212,213,5,97,0,0,213,214,5,115,0,
  	0,214,215,5,115,0,0,215,24,1,0,0,0,216,217,5,116,0,0,217,218,5,104,0,
  	0,218,219,5,105,0,0,219,220,5,115,0,0,220,26,1,0,0,0,221,222,5,105,0,
  	0,222,223,5,102,0,0,223,28,1,0,0,0,224,225,5,101,0,0,225,226,5,108,0,
  	0,226,227,5,115,0,0,227,228,5,101,0,0,228,30,1,0,0,0,229,230,5,102,0,
  	0,230,231,5,111,0,0,231,232,5,114,0,0,232,32,1,0,0,0,233,234,5,119,0,
  	0,234,235,5,104,0,0,235,236,5,105,0,0,236,237,5,108,0,0,237,238,5,101,
  	0,0,238,34,1,0,0,0,239,240,5,98,0,0,240,241,5,114,0,0,241,242,5,101,0,
  	0,242,243,5,97,0,0,243,244,5,107,0,0,244,36,1,0,0,0,245,246,5,99,0,0,
  	246,247,5,111,0,0,247,248,5,110,0,0,248,249,5,116,0,0,249,250,5,105,0,
  	0,250,251,5,110,0,0,251,252,5,117,0,0,252,253,5,101,0,0,253,38,1,0,0,
  	0,254,255,5,114,0,0,255,256,5,101,0,0,256,257,5,116,0,0,257,258,5,117,
  	0,0,258,259,5,114,0,0,259,260,5,110,0,0,260,40,1,0,0,0,261,262,5,98,0,
  	0,262,263,5,111,0,0,263,264,5,111,0,0,264,265,5,108,0,0,265,42,1,0,0,
  	0,266,267,5,105,0,0,267,268,5,110,0,0,268,269,5,116,0,0,269,44,1,0,0,
  	0,270,271,5,118,0,0,271,272,5,111,0,0,272,273,5,105,0,0,273,274,5,100,
  	0,0,274,46,1,0,0,0,275,276,5,115,0,0,276,277,5,116,0,0,277,278,5,114,
  	0,0,278,279,5,105,0,0,279,280,5,110,0,0,280,281,5,103,0,0,281,48,1,0,
  	0,0,282,286,7,4,0,0,283,285,7,5,0,0,284,283,1,0,0,0,285,288,1,0,0,0,286,
  	284,1,0,0,0,286,287,1,0,0,0,287,50,1,0,0,0,288,286,1,0,0,0,289,290,5,
  	43,0,0,290,52,1,0,0,0,291,292,5,45,0,0,292,54,1,0,0,0,293,294,5,42,0,
  	0,294,56,1,0,0,0,295,296,5,47,0,0,296,58,1,0,0,0,297,298,5,37,0,0,298,
  	60,1,0,0,0,299,300,5,60,0,0,300,62,1,0,0,0,301,302,5,60,0,0,302,303,5,
  	61,0,0,303,64,1,0,0,0,304,305,5,62,0,0,305,66,1,0,0,0,306,307,5,62,0,
  	0,307,308,5,61,0,0,308,68,1,0,0,0,309,310,5,61,0,0,310,311,5,61,0,0,311,
  	70,1,0,0,0,312,313,5,33,0,0,313,314,5,61,0,0,314,72,1,0,0,0,315,316,5,
  	38,0,0,316,317,5,38,0,0,317,74,1,0,0,0,318,319,5,124,0,0,319,320,5,124,
  	0,0,320,76,1,0,0,0,321,322,5,33,0,0,322,78,1,0,0,0,323,324,5,62,0,0,324,
  	325,5,62,0,0,325,80,1,0,0,0,326,327,5,60,0,0,327,328,5,60,0,0,328,82,
  	1,0,0,0,329,330,5,38,0,0,330,84,1,0,0,0,331,332,5,124,0,0,332,86,1,0,
  	0,0,333,334,5,94,0,0,334,88,1,0,0,0,335,336,5,126,0,0,336,90,1,0,0,0,
  	337,338,5,61,0,0,338,92,1,0,0,0,339,340,5,43,0,0,340,341,5,43,0,0,341,
  	94,1,0,0,0,342,343,5,45,0,0,343,344,5,45,0,0,344,96,1,0,0,0,345,346,5,
  	46,0,0,346,98,1,0,0,0,347,348,5,40,0,0,348,100,1,0,0,0,349,350,5,41,0,
  	0,350,102,1,0,0,0,351,352,5,91,0,0,352,104,1,0,0,0,353,354,5,93,0,0,354,
  	106,1,0,0,0,355,356,5,123,0,0,356,108,1,0,0,0,357,358,5,125,0,0,358,110,
  	1,0,0,0,359,360,5,36,0,0,360,361,6,55,2,0,361,112,1,0,0,0,362,363,5,63,
  	0,0,363,114,1,0,0,0,364,365,5,58,0,0,365,116,1,0,0,0,366,367,5,59,0,0,
  	367,118,1,0,0,0,368,369,5,44,0,0,369,120,1,0,0,0,370,371,7,6,0,0,371,
  	372,1,0,0,0,372,373,6,60,3,0,373,122,1,0,0,0,374,375,5,47,0,0,375,376,
  	5,47,0,0,376,380,1,0,0,0,377,379,8,7,0,0,378,377,1,0,0,0,379,382,1,0,
  	0,0,380,378,1,0,0,0,380,381,1,0,0,0,381,383,1,0,0,0,382,380,1,0,0,0,383,
  	384,6,61,3,0,384,124,1,0,0,0,385,386,5,47,0,0,386,387,5,42,0,0,387,391,
  	1,0,0,0,388,390,9,0,0,0,389,388,1,0,0,0,390,393,1,0,0,0,391,392,1,0,0,
  	0,391,389,1,0,0,0,392,394,1,0,0,0,393,391,1,0,0,0,394,395,5,42,0,0,395,
  	396,5,47,0,0,396,397,1,0,0,0,397,398,6,62,3,0,398,126,1,0,0,0,10,0,165,
  	169,180,182,197,199,286,380,391,4,1,2,0,1,3,1,1,55,2,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxlexerLexerStaticData = staticData.release();
}

}

MxLexer::MxLexer(CharStream *input) : Lexer(input) {
  MxLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mxlexerLexerStaticData->atn, mxlexerLexerStaticData->decisionToDFA, mxlexerLexerStaticData->sharedContextCache);
}

MxLexer::~MxLexer() {
  delete _interpreter;
}

std::string MxLexer::getGrammarFileName() const {
  return "Mx.g4";
}

const std::vector<std::string>& MxLexer::getRuleNames() const {
  return mxlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MxLexer::getChannelNames() const {
  return mxlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MxLexer::getModeNames() const {
  return mxlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MxLexer::getVocabulary() const {
  return mxlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxLexer::getSerializedATN() const {
  return mxlexerLexerStaticData->serializedATN;
}

const atn::ATN& MxLexer::getATN() const {
  return *mxlexerLexerStaticData->atn;
}


void MxLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 2: FormatQuatationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: QuotationAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: DollarAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool MxLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return QuotationSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 7: return StringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 8: return FormatStringLiteralSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
    case 2:  exprMode = !exprMode;  break;

  default:
    break;
  }
}


bool MxLexer::QuotationSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return formatMode > 0 && !exprMode;

  default:
    break;
  }
  return true;
}

bool MxLexer::StringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return formatMode == 0 || exprMode;

  default:
    break;
  }
  return true;
}

bool MxLexer::FormatStringLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return formatMode > 0 && !exprMode;

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
