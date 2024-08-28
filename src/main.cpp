#include "ast/ast.h"
#include "frontend/ast_builder.h"
#include "frontend/error_listener.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"
#include "utils/error/semantic_error.hpp"

#include "ir/type/ir_type.h"

#include "backend/asm_builder.h"

int main() {
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
    GenerateAsm(ast_root.get());
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