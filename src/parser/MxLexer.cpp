
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
      "StringLiteral", "FormatStringLiteral", "Null", "ArrayLiteral", "New", 
      "Class", "This", "If", "Else", "For", "While", "Break", "Continue", 
      "Return", "Bool", "Int", "Void", "String", "Identifier", "Add", "Sub", 
      "Mul", "Div", "Mod", "Less", "LessEqual", "Greater", "GreaterEqual", 
      "Equal", "UnEqual", "AndLogic", "OrLogic", "NotLogic", "ShiftRight", 
      "ShiftLeft", "And", "Or", "Xor", "Not", "Assign", "Increment", "Decrement", 
      "Dot", "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
      "RightBrace", "Dollar", "Question", "Colon", "Semicolon", "Comma", 
      "Whitespace", "LineComment", "BlockComment"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int main()'", "'[]'", "'f\"'", "", "'true'", "'false'", "", 
      "", "", "'null'", "", "'new'", "'class'", "'this'", "'if'", "'else'", 
      "'for'", "'while'", "'break'", "'continue'", "'return'", "'bool'", 
      "'int'", "'void'", "'string'", "", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'!'", 
      "'>>'", "'<<'", "'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", 
      "'.'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'$'", "'\\u003F'", 
      "':'", "';'", "','"
    },
    std::vector<std::string>{
      "", "", "", "FormatQuatation", "Quotation", "True", "False", "DecimalNumber", 
      "StringLiteral", "FormatStringLiteral", "Null", "ArrayLiteral", "New", 
      "Class", "This", "If", "Else", "For", "While", "Break", "Continue", 
      "Return", "Bool", "Int", "Void", "String", "Identifier", "Add", "Sub", 
      "Mul", "Div", "Mod", "Less", "LessEqual", "Greater", "GreaterEqual", 
      "Equal", "UnEqual", "AndLogic", "OrLogic", "NotLogic", "ShiftRight", 
      "ShiftLeft", "And", "Or", "Xor", "Not", "Assign", "Increment", "Decrement", 
      "Dot", "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
      "RightBrace", "Dollar", "Question", "Colon", "Semicolon", "Comma", 
      "Whitespace", "LineComment", "BlockComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,64,412,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,
  	1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,5,6,166,8,6,10,6,12,6,169,9,6,1,6,3,6,172,8,6,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,5,7,183,8,7,10,7,12,7,186,9,7,1,7,1,7,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,4,8,200,8,8,11,8,12,8,201,1,9,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,10,5,10,213,8,10,10,10,12,10,216,9,10,1,10,1,10,
  	1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,
  	1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,
  	1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,5,25,298,8,25,10,25,12,25,301,
  	9,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,
  	1,32,1,32,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,37,
  	1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,
  	1,42,1,43,1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,47,1,48,1,48,
  	1,48,1,49,1,49,1,50,1,50,1,51,1,51,1,52,1,52,1,53,1,53,1,54,1,54,1,55,
  	1,55,1,56,1,56,1,56,1,57,1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,61,1,61,
  	1,61,1,61,1,62,1,62,1,62,1,62,5,62,392,8,62,10,62,12,62,395,9,62,1,62,
  	1,62,1,63,1,63,1,63,1,63,5,63,403,8,63,10,63,12,63,406,9,63,1,63,1,63,
  	1,63,1,63,1,63,1,404,0,64,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,
  	43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,
  	33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,
  	89,45,91,46,93,47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,
  	111,56,113,57,115,58,117,59,119,60,121,61,123,62,125,63,127,64,1,0,8,
  	1,0,49,57,1,0,48,57,3,0,32,33,35,91,93,126,4,0,32,33,35,35,37,91,93,126,
  	2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,2,
  	0,10,10,13,13,426,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,
  	1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,
  	0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,
  	0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,
  	1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,
  	0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,
  	0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,
  	1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,
  	0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,
  	0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,
  	105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,
  	115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,
  	125,1,0,0,0,0,127,1,0,0,0,1,129,1,0,0,0,3,140,1,0,0,0,5,143,1,0,0,0,7,
  	148,1,0,0,0,9,152,1,0,0,0,11,157,1,0,0,0,13,171,1,0,0,0,15,173,1,0,0,
  	0,17,189,1,0,0,0,19,203,1,0,0,0,21,208,1,0,0,0,23,219,1,0,0,0,25,223,
  	1,0,0,0,27,229,1,0,0,0,29,234,1,0,0,0,31,237,1,0,0,0,33,242,1,0,0,0,35,
  	246,1,0,0,0,37,252,1,0,0,0,39,258,1,0,0,0,41,267,1,0,0,0,43,274,1,0,0,
  	0,45,279,1,0,0,0,47,283,1,0,0,0,49,288,1,0,0,0,51,295,1,0,0,0,53,302,
  	1,0,0,0,55,304,1,0,0,0,57,306,1,0,0,0,59,308,1,0,0,0,61,310,1,0,0,0,63,
  	312,1,0,0,0,65,314,1,0,0,0,67,317,1,0,0,0,69,319,1,0,0,0,71,322,1,0,0,
  	0,73,325,1,0,0,0,75,328,1,0,0,0,77,331,1,0,0,0,79,334,1,0,0,0,81,336,
  	1,0,0,0,83,339,1,0,0,0,85,342,1,0,0,0,87,344,1,0,0,0,89,346,1,0,0,0,91,
  	348,1,0,0,0,93,350,1,0,0,0,95,352,1,0,0,0,97,355,1,0,0,0,99,358,1,0,0,
  	0,101,360,1,0,0,0,103,362,1,0,0,0,105,364,1,0,0,0,107,366,1,0,0,0,109,
  	368,1,0,0,0,111,370,1,0,0,0,113,372,1,0,0,0,115,375,1,0,0,0,117,377,1,
  	0,0,0,119,379,1,0,0,0,121,381,1,0,0,0,123,383,1,0,0,0,125,387,1,0,0,0,
  	127,398,1,0,0,0,129,130,5,105,0,0,130,131,5,110,0,0,131,132,5,116,0,0,
  	132,133,5,32,0,0,133,134,5,109,0,0,134,135,5,97,0,0,135,136,5,105,0,0,
  	136,137,5,110,0,0,137,138,5,40,0,0,138,139,5,41,0,0,139,2,1,0,0,0,140,
  	141,5,91,0,0,141,142,5,93,0,0,142,4,1,0,0,0,143,144,5,102,0,0,144,145,
  	5,34,0,0,145,146,1,0,0,0,146,147,6,2,0,0,147,6,1,0,0,0,148,149,4,3,0,
  	0,149,150,5,34,0,0,150,151,6,3,1,0,151,8,1,0,0,0,152,153,5,116,0,0,153,
  	154,5,114,0,0,154,155,5,117,0,0,155,156,5,101,0,0,156,10,1,0,0,0,157,
  	158,5,102,0,0,158,159,5,97,0,0,159,160,5,108,0,0,160,161,5,115,0,0,161,
  	162,5,101,0,0,162,12,1,0,0,0,163,167,7,0,0,0,164,166,7,1,0,0,165,164,
  	1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,172,1,0,0,
  	0,169,167,1,0,0,0,170,172,5,48,0,0,171,163,1,0,0,0,171,170,1,0,0,0,172,
  	14,1,0,0,0,173,174,4,7,1,0,174,184,5,34,0,0,175,176,5,92,0,0,176,183,
  	5,110,0,0,177,178,5,92,0,0,178,183,5,92,0,0,179,180,5,92,0,0,180,183,
  	5,34,0,0,181,183,7,2,0,0,182,175,1,0,0,0,182,177,1,0,0,0,182,179,1,0,
  	0,0,182,181,1,0,0,0,183,186,1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,
  	187,1,0,0,0,186,184,1,0,0,0,187,188,5,34,0,0,188,16,1,0,0,0,189,199,4,
  	8,2,0,190,191,5,92,0,0,191,200,5,110,0,0,192,193,5,92,0,0,193,200,5,92,
  	0,0,194,195,5,92,0,0,195,200,5,34,0,0,196,197,5,36,0,0,197,200,5,36,0,
  	0,198,200,7,3,0,0,199,190,1,0,0,0,199,192,1,0,0,0,199,194,1,0,0,0,199,
  	196,1,0,0,0,199,198,1,0,0,0,200,201,1,0,0,0,201,199,1,0,0,0,201,202,1,
  	0,0,0,202,18,1,0,0,0,203,204,5,110,0,0,204,205,5,117,0,0,205,206,5,108,
  	0,0,206,207,5,108,0,0,207,20,1,0,0,0,208,209,5,123,0,0,209,214,3,13,6,
  	0,210,211,5,44,0,0,211,213,3,13,6,0,212,210,1,0,0,0,213,216,1,0,0,0,214,
  	212,1,0,0,0,214,215,1,0,0,0,215,217,1,0,0,0,216,214,1,0,0,0,217,218,5,
  	125,0,0,218,22,1,0,0,0,219,220,5,110,0,0,220,221,5,101,0,0,221,222,5,
  	119,0,0,222,24,1,0,0,0,223,224,5,99,0,0,224,225,5,108,0,0,225,226,5,97,
  	0,0,226,227,5,115,0,0,227,228,5,115,0,0,228,26,1,0,0,0,229,230,5,116,
  	0,0,230,231,5,104,0,0,231,232,5,105,0,0,232,233,5,115,0,0,233,28,1,0,
  	0,0,234,235,5,105,0,0,235,236,5,102,0,0,236,30,1,0,0,0,237,238,5,101,
  	0,0,238,239,5,108,0,0,239,240,5,115,0,0,240,241,5,101,0,0,241,32,1,0,
  	0,0,242,243,5,102,0,0,243,244,5,111,0,0,244,245,5,114,0,0,245,34,1,0,
  	0,0,246,247,5,119,0,0,247,248,5,104,0,0,248,249,5,105,0,0,249,250,5,108,
  	0,0,250,251,5,101,0,0,251,36,1,0,0,0,252,253,5,98,0,0,253,254,5,114,0,
  	0,254,255,5,101,0,0,255,256,5,97,0,0,256,257,5,107,0,0,257,38,1,0,0,0,
  	258,259,5,99,0,0,259,260,5,111,0,0,260,261,5,110,0,0,261,262,5,116,0,
  	0,262,263,5,105,0,0,263,264,5,110,0,0,264,265,5,117,0,0,265,266,5,101,
  	0,0,266,40,1,0,0,0,267,268,5,114,0,0,268,269,5,101,0,0,269,270,5,116,
  	0,0,270,271,5,117,0,0,271,272,5,114,0,0,272,273,5,110,0,0,273,42,1,0,
  	0,0,274,275,5,98,0,0,275,276,5,111,0,0,276,277,5,111,0,0,277,278,5,108,
  	0,0,278,44,1,0,0,0,279,280,5,105,0,0,280,281,5,110,0,0,281,282,5,116,
  	0,0,282,46,1,0,0,0,283,284,5,118,0,0,284,285,5,111,0,0,285,286,5,105,
  	0,0,286,287,5,100,0,0,287,48,1,0,0,0,288,289,5,115,0,0,289,290,5,116,
  	0,0,290,291,5,114,0,0,291,292,5,105,0,0,292,293,5,110,0,0,293,294,5,103,
  	0,0,294,50,1,0,0,0,295,299,7,4,0,0,296,298,7,5,0,0,297,296,1,0,0,0,298,
  	301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,52,1,0,0,0,301,299,1,
  	0,0,0,302,303,5,43,0,0,303,54,1,0,0,0,304,305,5,45,0,0,305,56,1,0,0,0,
  	306,307,5,42,0,0,307,58,1,0,0,0,308,309,5,47,0,0,309,60,1,0,0,0,310,311,
  	5,37,0,0,311,62,1,0,0,0,312,313,5,60,0,0,313,64,1,0,0,0,314,315,5,60,
  	0,0,315,316,5,61,0,0,316,66,1,0,0,0,317,318,5,62,0,0,318,68,1,0,0,0,319,
  	320,5,62,0,0,320,321,5,61,0,0,321,70,1,0,0,0,322,323,5,61,0,0,323,324,
  	5,61,0,0,324,72,1,0,0,0,325,326,5,33,0,0,326,327,5,61,0,0,327,74,1,0,
  	0,0,328,329,5,38,0,0,329,330,5,38,0,0,330,76,1,0,0,0,331,332,5,124,0,
  	0,332,333,5,124,0,0,333,78,1,0,0,0,334,335,5,33,0,0,335,80,1,0,0,0,336,
  	337,5,62,0,0,337,338,5,62,0,0,338,82,1,0,0,0,339,340,5,60,0,0,340,341,
  	5,60,0,0,341,84,1,0,0,0,342,343,5,38,0,0,343,86,1,0,0,0,344,345,5,124,
  	0,0,345,88,1,0,0,0,346,347,5,94,0,0,347,90,1,0,0,0,348,349,5,126,0,0,
  	349,92,1,0,0,0,350,351,5,61,0,0,351,94,1,0,0,0,352,353,5,43,0,0,353,354,
  	5,43,0,0,354,96,1,0,0,0,355,356,5,45,0,0,356,357,5,45,0,0,357,98,1,0,
  	0,0,358,359,5,46,0,0,359,100,1,0,0,0,360,361,5,40,0,0,361,102,1,0,0,0,
  	362,363,5,41,0,0,363,104,1,0,0,0,364,365,5,91,0,0,365,106,1,0,0,0,366,
  	367,5,93,0,0,367,108,1,0,0,0,368,369,5,123,0,0,369,110,1,0,0,0,370,371,
  	5,125,0,0,371,112,1,0,0,0,372,373,5,36,0,0,373,374,6,56,2,0,374,114,1,
  	0,0,0,375,376,5,63,0,0,376,116,1,0,0,0,377,378,5,58,0,0,378,118,1,0,0,
  	0,379,380,5,59,0,0,380,120,1,0,0,0,381,382,5,44,0,0,382,122,1,0,0,0,383,
  	384,7,6,0,0,384,385,1,0,0,0,385,386,6,61,3,0,386,124,1,0,0,0,387,388,
  	5,47,0,0,388,389,5,47,0,0,389,393,1,0,0,0,390,392,8,7,0,0,391,390,1,0,
  	0,0,392,395,1,0,0,0,393,391,1,0,0,0,393,394,1,0,0,0,394,396,1,0,0,0,395,
  	393,1,0,0,0,396,397,6,62,3,0,397,126,1,0,0,0,398,399,5,47,0,0,399,400,
  	5,42,0,0,400,404,1,0,0,0,401,403,9,0,0,0,402,401,1,0,0,0,403,406,1,0,
  	0,0,404,405,1,0,0,0,404,402,1,0,0,0,405,407,1,0,0,0,406,404,1,0,0,0,407,
  	408,5,42,0,0,408,409,5,47,0,0,409,410,1,0,0,0,410,411,6,63,3,0,411,128,
  	1,0,0,0,11,0,167,171,182,184,199,201,214,299,393,404,4,1,2,0,1,3,1,1,
  	56,2,6,0,0
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
    case 56: DollarAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

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
