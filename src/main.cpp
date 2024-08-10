#include "ast/ast.h"
#include "frontend/ast_builder.h"
#include "frontend/error_listener.h"
#include "frontend/semantic_checker.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"
#include "utils/error/semantic_error.hpp"

int main() {
  ANTLRInputStream input(std::cin);
  MxLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  tokens.fill();
  MxParser parser(&tokens);
  MxErrorListener error_listener;
  parser.addErrorListener(&error_listener);
  auto root = parser.program();
  try {
    ASTBuilder builder;
    auto ast_root = std::any_cast<std::shared_ptr<RootNode>>(builder.visitProgram(root));
    CheckSemantic(ast_root.get());
  } catch (const SemanticError &err) {
    std::cerr << err.what() << std::endl;
    return 1;
  } catch (std::runtime_error &) {
    throw;
  }
  std::cout << "\033[32mSemantic check passed!\033[0m" << std::endl;
  return 0;
}