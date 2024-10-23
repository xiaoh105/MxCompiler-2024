#include "ast/ast.h"
#include "backend/asm_builder.h"
#include "frontend/ast_builder.h"
#include "frontend/error_listener.h"
#include "frontend/semantic_checker.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"
#include "utils/error/semantic_error.hpp"

#include "utils/set.h"

bool syntax_only = false;
bool emit_llvm = false;

bool generate_cfg = false;
bool generate_dominator_tree = false;
bool generate_data_flow = true;

bool mem_to_reg = false;

void ParseArgs(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-fsyntax-only")) {
      syntax_only = true;
    } else if (!strcmp(argv[i], "-femit-llvm")) {
      emit_llvm = true;
    } else if (!strcmp(argv[i], "-fmem-to-reg")) {
      mem_to_reg = true;
      generate_cfg = true;
      generate_dominator_tree = true;
    } else {
      assert(false);
    }
  }
}

int main(int argc, char **argv) {
  ParseArgs(argc, argv);
  ANTLRInputStream input(std::cin);
  MxErrorListener error_listener;
  MxLexer lexer(&input);
#ifdef OJ
  lexer.removeErrorListeners();
#endif
  lexer.addErrorListener(&error_listener);
  CommonTokenStream tokens(&lexer);
  tokens.fill();
  MxParser parser(&tokens);
#ifdef OJ
  parser.removeErrorListeners();
#endif
  parser.addErrorListener(&error_listener);
  auto root = parser.program();
  try {
    ASTBuilder builder;
    auto ast_root = std::any_cast<std::shared_ptr<RootNode>>(builder.visitProgram(root));
    if (syntax_only) {
      CheckSemantic(ast_root.get());
    } else if (emit_llvm) {
      GenerateIR(ast_root.get());
    } else {
      GenerateAsm(ast_root.get());
    }
  } catch (const SemanticError &err) {
#ifndef OJ
    std::cerr << err.what() << std::endl;
#else
    std::cout << err.what() << std::endl;
#endif
    return 1;
  } catch (std::runtime_error &) {
    throw;
  }
  return 0;
}