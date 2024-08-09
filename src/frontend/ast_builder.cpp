#include <memory>

#include "ast/ast.h"
#include "frontend/ast_builder.h"

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx) {
  std::vector<std::shared_ptr<DefNode>> definitions;
  auto func_def = ctx->funcDef();
  for (const auto &item : func_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto var_def = ctx->varDef();
  for (const auto &item : var_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto class_def = ctx->classDef();
  for (const auto &item : class_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto main_func = ctx->mainFunc();
  auto main_func_body = std::any_cast<std::shared_ptr<StmtNode>>(main_func->accept(this));
  return std::make_shared<RootNode>(Position{ctx}, std::move(main_func_body), std::move(definitions));
}

std::any ASTBuilder::visitMainFunc(MxParser::MainFuncContext *ctx) {
  auto function = ctx->suite();
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(function->accept(this));
  return std::shared_ptr(std::move(func_body));
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
  auto name = ctx->classIdentifier->getText();
  auto stmts = ctx->classStmt();
  std::vector<std::shared_ptr<ClassStmtNode>> return_stmts;
  for (const auto &item : stmts) {
    auto ret = std::any_cast<std::shared_ptr<ClassStmtNode>>(item->accept(this));
    return_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<DefNode>(new ClassDefNode({ctx}, std::move(name), std::move(return_stmts)));
}

std::any ASTBuilder::visitMemberDefStmt(MxParser::MemberDefStmtContext *ctx) {
  auto type_name = std::any_cast<std::string>(ctx->memberType->accept(this));
  auto name = ctx->Identifier();
  std::vector<std::string> ret_name;
  for (const auto &item : name) {
    ret_name.push_back(item->getText());
  }
  return std::shared_ptr<ClassStmtNode>(new VarDefClassStmtNode({ctx}, std::move(type_name), std::move(ret_name)));
}

std::any ASTBuilder::visitConstructorDefStmt(MxParser::ConstructorDefStmtContext *ctx) {
  auto class_name = ctx->classIdentifier->getText();
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<ClassStmtNode>(
      new ConstructorClassStmtNode({ctx}, std::move(class_name), std::move(func_body)));
}

std::any ASTBuilder::visitFuncDefStmt(MxParser::FuncDefStmtContext *ctx) {
  auto return_type = ctx->returnType->getText();
  auto func_name = ctx->funcName->getText();
  auto arg_type = ctx->type();
  auto arg_name = ctx->Identifier();
  std::vector<std::pair<std::string, std::string>> arguments;
  if (arg_type.size() != arg_name.size() + 1) {
    throw std::runtime_error("Arg type number does not match arg name number in Method definition");
  }
  for (int i = 0; i < arg_name.size(); ++i) {
    arguments.emplace_back(arg_type[i + 1]->getText(), arg_name[i]->getText());
  }
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<ClassStmtNode>(new FunctionDefClassStmtNode(
      {ctx}, std::move(func_name), std::move(return_type), std::move(arguments), std::move(func_body)));
}

std::any ASTBuilder::visitFuncDef(MxParser::FuncDefContext *ctx) {
  auto return_type = ctx->returnType->getText();
  auto func_name = ctx->funcName->getText();
  auto arg_type = ctx->type();
  auto arg_name = ctx->Identifier();
  std::vector<std::pair<std::string, std::string>> arguments;
  if (arg_type.size() != arg_name.size() + 1) {
    throw std::runtime_error("Arg type number does not match arg name number in Method definition");
  }
  for (int i = 0; i < arg_name.size(); ++i) {
    arguments.emplace_back(arg_type[i + 1]->getText(), arg_name[i]->getText());
  }
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<DefNode>(new FunctionDefNode({ctx}, std::move(func_name), std::move(return_type),
                                                      std::move(arguments), std::move(func_body)));
}

std::any ASTBuilder::visitVarDef(MxParser::VarDefContext *ctx) {
  std::string type_name = ctx->type()->getText();
  auto var_name = ctx->Identifier();
  auto var_value = ctx->expression();
  int pos = 0;
  std::vector<std::string> ret_name;
  std::vector<std::shared_ptr<ExprNode>> ret_val;
  for (const auto &item : var_name) {
    ret_name.push_back(item->getText());
    if (pos < ret_val.size() && item->getSourceInterval().b + 2 == var_value[pos]->getSourceInterval().a) {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(var_value[pos]->accept(this));
      ret_val.push_back(std::move(ret));
      ++pos;
    } else {
      ret_val.push_back(nullptr);
    }
  }
  assert(ret_name.size() == ret_val.size());
  return std::shared_ptr<DefNode>(new VarDefNode({ctx}, std::move(type_name), std::move(ret_name), std::move(ret_val)));
}

std::any ASTBuilder::visitVarDefStmt(MxParser::VarDefStmtContext *ctx) {
  std::string type_name = ctx->type()->getText();
  auto var_name = ctx->Identifier();
  auto var_value = ctx->expression();
  int pos = 0;
  std::vector<std::string> ret_name;
  std::vector<std::shared_ptr<ExprNode>> ret_val;
  for (const auto &item : var_name) {
    ret_name.push_back(item->getText());
    if (pos < ret_val.size() && item->getSourceInterval().b + 2 == var_value[pos]->getSourceInterval().a) {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(var_value[pos]->accept(this));
      ret_val.push_back(std::move(ret));
      ++pos;
    } else {
      ret_val.push_back(nullptr);
    }
  }
  assert(ret_name.size() == ret_val.size());
  return std::shared_ptr<StmtNode>(
      new VarDefStmtNode({ctx}, std::move(type_name), std::move(ret_name), std::move(ret_val)));
}

std::any ASTBuilder::visitSuiteStmt(MxParser::SuiteStmtContext *ctx) { return ctx->suite()->accept(this); }

std::any ASTBuilder::visitSuite(MxParser::SuiteContext *ctx) {
  auto stmts = ctx->statement();
  std::vector<std::shared_ptr<StmtNode>> ret_stmts;
  for (const auto &item : stmts) {
    auto ret = std::any_cast<std::shared_ptr<StmtNode>>(item->accept(this));
    ret_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<StmtNode>(new SuiteStmtNode({ctx}, std::move(ret_stmts)));
}

std::any ASTBuilder::visitExprStmt(MxParser::ExprStmtContext *ctx) {
  auto expr_node = ctx->expression();
  auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr_node->accept(this));
  return std::shared_ptr<StmtNode>(new ExprStmtNode({ctx}, std::move(ret)));
}

std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {
  auto condition = ctx->expression();
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto true_stmt = ctx->trueStmt;
  auto true_stmt_ret = std::any_cast<std::shared_ptr<StmtNode>>(true_stmt->accept(this));
  auto false_stmt = ctx->falseStmt;
  std::shared_ptr<StmtNode> false_stmt_ret = nullptr;
  if (false_stmt) {
    false_stmt_ret = std::any_cast<std::shared_ptr<StmtNode>>(false_stmt->accept(this));
  }
  return std::shared_ptr<StmtNode>(
      new IfStmtNode({ctx}, std::move(condition_ret), std::move(true_stmt_ret), std::move(false_stmt_ret)));
}

std::any ASTBuilder::visitWhileStmt(MxParser::WhileStmtContext *ctx) {
  auto condition = ctx->expression();
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto suite = ctx->suite();
  auto suite_ret = std::any_cast<std::shared_ptr<StmtNode>>(suite->accept(this));
  return std::shared_ptr<StmtNode>(new WhileStmtNode({ctx}, std::move(condition_ret), std::move(suite_ret)));
}

std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx) {
  auto initialize_stmt = ctx->initializeStmt;
  auto initialize_ret = std::any_cast<std::shared_ptr<StmtNode>>(initialize_stmt->accept(this));
  auto condition_expr = ctx->conditionExpr;
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition_expr->accept(this));
  auto step_expr = ctx->stepExpr;
  auto step_ret = std::any_cast<std::shared_ptr<ExprNode>>(step_expr->accept(this));
  auto loop_stmt = ctx->statement().back();
  auto loop_ret = std::any_cast<std::shared_ptr<StmtNode>>(loop_stmt->accept(this));
  return std::shared_ptr<StmtNode>(new ForStmtNode({ctx}, std::move(initialize_ret), std::move(condition_ret),
                                                   std::move(step_ret), std::move(loop_ret)));
}

std::any ASTBuilder::visitReturnStmt(MxParser::ReturnStmtContext *ctx) {
  auto expr = ctx->expression();
  std::shared_ptr<ExprNode> ret = nullptr;
  if (expr != nullptr) {
    ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  }
  return std::shared_ptr<StmtNode>(new ControlStmtNode({ctx}, ControlStmtNode::StmtType::kReturn, ret));
}

std::any ASTBuilder::visitBreakStmt(MxParser::BreakStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new ControlStmtNode({ctx}, ControlStmtNode::StmtType::kBreak));
}

std::any ASTBuilder::visitContinueStmt(MxParser::ContinueStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new ControlStmtNode({ctx}, ControlStmtNode::StmtType::kContinue));
}

std::any ASTBuilder::visitAtomicExpr(MxParser::AtomicExprContext *ctx) {
  auto primary = ctx->primary();
  auto ret = std::any_cast<std::shared_ptr<PrimaryNode>>(primary->accept(this));
  return std::shared_ptr<ExprNode>(new AtomExprNode({ctx}, std::move(ret)));
}

std::any ASTBuilder::visitUnaryExpr(MxParser::UnaryExprContext *ctx) {
  auto expr = ctx->expression();
  auto expr_ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  using UnaryExprNode::OpType;
  OpType op_type;
  if (ctx->Add()) {
    op_type = OpType::kPlus;
  } else if (ctx->Sub()) {
    op_type = OpType::kMinus;
  } else if (ctx->Not()) {
    op_type = OpType::kNot;
  } else if (ctx->NotLogic()) {
    op_type = OpType::kNotLogic;
  } else if (auto increment = ctx->Increment()) {
    op_type =
        expr->getSourceInterval().a < increment->getSourceInterval().a ? OpType::kPreIncrement : OpType::kSufIncrement;
  } else if (auto decrement = ctx->Decrement()) {
    op_type =
        expr->getSourceInterval().a < decrement->getSourceInterval().a ? OpType::kPreDecrement : OpType::kSufDecrement;
  } else {
    throw std::runtime_error("No valid operator for unary expr");
  }
  return std::shared_ptr<ExprNode>(new UnaryExprNode({ctx}, op_type, std::move(expr_ret)));
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  using BinaryExprNode::OpType;
  OpType op_type;
  if (ctx->Add()) {
    op_type = OpType::kAdd;
  } else if (ctx->Sub()) {
    op_type = OpType::kSub;
  } else if (ctx->Mul()) {
    op_type = OpType::kMul;
  } else if (ctx->Div()) {
    op_type = OpType::kDiv;
  } else if (ctx->Mod()) {
    op_type = OpType::kMod;
  } else if (ctx->And()) {
    op_type = OpType::kAnd;
  } else if (ctx->Or()) {
    op_type = OpType::kOr;
  } else if (ctx->Xor()) {
    op_type = OpType::kXor;
  } else if (ctx->AndLogic()) {
    op_type = OpType::kAndLogic;
  } else if (ctx->OrLogic()) {
    op_type = OpType::kOrLogic;
  } else if (ctx->ShiftLeft()) {
    op_type = OpType::kShiftL;
  } else if (ctx->ShiftRight()) {
    op_type = OpType::kShiftR;
  } else if (ctx->Equal()) {
    op_type = OpType::kEqual;
  } else if (ctx->UnEqual()) {
    op_type = OpType::kNotEqual;
  } else if (ctx->Less()) {
    op_type = OpType::kLess;
  } else if (ctx->Greater()) {
    op_type = OpType::kGreater;
  } else if (ctx->LessEqual()) {
    op_type = OpType::kLessEqual;
  } else if (ctx->GreaterEqual()) {
    op_type = OpType::kGreaterEqual;
  } else {
    throw std::runtime_error("Invalid binary operator");
  }
  return std::shared_ptr<ExprNode>(new BinaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitTenaryExpr(MxParser::TenaryExprContext *ctx) {
  auto expr = ctx->expression();
  auto condition = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto true_expr = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  auto false_expr = std::any_cast<std::shared_ptr<ExprNode>>(expr[2]->accept(this));
  return std::shared_ptr<ExprNode>(
      new TenaryExprNode({ctx}, std::move(condition), std::move(true_expr), std::move(false_expr)));
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  return std::shared_ptr<ExprNode>(new AssignExprNode({ctx}, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitMemberExpr(MxParser::MemberExprContext *ctx) {
  auto expr = ctx->expression();
  auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  std::string member = ctx->Identifier()->getText();
  return std::shared_ptr<ExprNode>(new MemberExprNode({ctx}, std::move(ret), std::move(member)));
}

std::any ASTBuilder::visitSubscriptExpr(MxParser::SubscriptExprContext *ctx) {
  auto expr = ctx->expression();
  auto base = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  std::vector<std::shared_ptr<ExprNode>> index;
  for (int i = 1; i < expr.size(); ++i) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[i]->accept(this));
    index.push_back(std::move(ret));
  }
  return std::shared_ptr<ExprNode>(new SubscriptExprNode({ctx}, std::move(base), std::move(index)));
}

std::any ASTBuilder::visitFormatExpr(MxParser::FormatExprContext *ctx) {
  auto literal = ctx->FormatStringLiteral();
  auto expr = ctx->expression();
  auto pos1 = 0, pos2 = 0;
  std::vector<std::variant<std::string, std::shared_ptr<ExprNode>>> format;
  while (pos1 < literal.size() && pos2 < expr.size()) {
    if (literal[pos1]->getSourceInterval().a < expr[pos2]->getSourceInterval().a) {
      format.emplace_back(literal[pos1]->getText());
      ++pos1;
    } else {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[pos2]->accept(this));
      format.emplace_back(std::move(ret));
      ++pos2;
    }
  }
  while (pos1 < literal.size()) {
    format.emplace_back(literal[pos1]->getText());
    ++pos1;
  }
  while (pos2 < expr.size()) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[pos2]->accept(this));
    format.emplace_back(std::move(ret));
    ++pos2;
  }
  return std::shared_ptr<ExprNode>(new FormatExprNode({ctx}, std::move(format)));
}

std::any ASTBuilder::visitFuncCallExpr(MxParser::FuncCallExprContext *ctx) {
  auto func_name = ctx->funcName->getText();
  auto arguments = ctx->arguments();
  auto ret_arg = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(arguments->accept(this));
  auto class_var = ctx->classVar;
  std::shared_ptr<ExprNode> ret_val = nullptr;
  if (class_var) {
    ret_val = std::any_cast<std::shared_ptr<ExprNode>>(class_var->accept(this));
  }
  return std::shared_ptr<ExprNode>(
      new FunctionCallExprNode({ctx}, std::move(ret_val), std::move(func_name), std::move(ret_arg)));
}