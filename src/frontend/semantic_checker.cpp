/*
 * Mx Compiler
 * File Name: semantic_checker.cpp
 * Identification: ./src/frontend/semantic_checker.cpp
 * Function: Scan the parser tree and throw errors if semantic errors exists
 */

#include "frontend/semantic_checker.h"
#include "frontend/symbol_collector.h"
#include "utils/error/semantic_error.hpp"

void CheckSemantic(RootNode *node) {
  auto [scope, global_scope] = CollectSymbol(node);
  SemanticChecker checker(std::move(scope), std::move(global_scope));
  checker.visit(node);
}

SemanticChecker::SemanticChecker(Scope scope, GlobalScope global_scope)
    : scope_(std::move(scope)), global_scope_(std::move(global_scope)) {}

void SemanticChecker::visit(SimpleArrayNode *node) {
  auto elements = node->GetElements();
  for (auto &item : elements) {
    item->accept(this);
  }
  for (int i = 0; i + 1 < elements.size(); ++i) {
    if (elements[i]->GetType() == nullptr || elements[i + 1]->GetType() == nullptr) {
      throw InvalidType(node->GetPos());
    }
    if (*elements[i]->GetType() != *elements[i + 1]->GetType()) {
      throw TypeMismatch(node->GetPos());
    }
  }
  if (elements.empty()) {
    node->SetType(nullptr);
  } else {
    node->SetType(std::make_shared<Type>(CreateType(elements[0]->GetType()->GetTypename(), 1)));
  }
}

void SemanticChecker::visit(JaggedArrayNode *node) {
  auto elements = node->GetElements();
  for (auto &item : elements) {
    item->accept(this);
  }
  std::shared_ptr<Type> type(nullptr);
  for (int i = 0; i < elements.size(); ++i) {
    if (type == nullptr && elements[i]->GetType() != nullptr) {
      type = elements[i]->GetType();
    }
    for (int j = i + 1; j < elements.size(); ++j) {
      if (elements[i]->GetType() != nullptr && elements[j]->GetType() != nullptr) {
        if (*elements[i]->GetType() != *elements[j]->GetType()) {
          throw TypeMismatch(node->GetPos());
        }
      }
    }
  }
  node->SetType(std::make_shared<Type>(CreateType(type->GetTypename(), type->GetDim() + 1)));
}

void SemanticChecker::visit(LiteralPrimaryNode *node) {
  switch (node->GetLiteralType()) {
    case LiteralPrimaryNode::kBool: {
      node->SetType(std::make_shared<Type>(kBoolType));
      break;
    }
    case LiteralPrimaryNode::kInt: {
      node->SetType(std::make_shared<Type>(kIntType));
      break;
    }
    case LiteralPrimaryNode::kNull: {
      node->SetType(std::shared_ptr<Type>(nullptr));
      break;
    }
    case LiteralPrimaryNode::kString: {
      node->SetType(std::make_shared<Type>(kStringType));
      break;
    }
    case LiteralPrimaryNode::kArray: {
      auto array_node = std::get<std::shared_ptr<ArrayNode>>(node->GetValue());
      array_node->accept(this);
      node->SetType(array_node->GetType());
      break;
    }
    case LiteralPrimaryNode::kUnknown: {
      throw std::runtime_error("Invalid literal type");
    }
  }
}

void SemanticChecker::visit(VarPrimaryNode *node) {
  auto &name = node->GetName();
  auto var = scope_.GetVar(name);
  if (var == std::nullopt) {
    throw UndefinedIdentifier(node->GetPos());
  }
  node->SetType(std::make_shared<Type>(std::move(var.value())));
}

void SemanticChecker::visit(ThisPrimaryNode *node) {
  auto var = scope_.GetVar("this");
  if (var == std::nullopt) {
    throw UndefinedIdentifier({node->GetPos()});
  }
  node->SetType(std::make_shared<Type>(std::move(var.value())));
}

void SemanticChecker::visit(NewPrimaryNode *node) {
  auto &type_name = node->GetTypename();
  auto type = global_scope_.GetType(type_name);
  if (type == std::nullopt) {
    throw UndefinedIdentifier(node->GetPos());
  }
  if (*type.value() == *kVoidTypename) {
    throw InvalidType(node->GetPos());
  }
  switch (node->GetNewType()) {
    case NewPrimaryNode::NewType::kNewVar: {
      node->SetType(std::make_shared<Type>(CreateType(std::move(type.value()))));
      break;
    }
    case NewPrimaryNode::NewType::kNewArray: {
      auto &expr = node->GetExpressions();
      for (const auto &item : expr) {
        item->accept(this);
        if (*item->GetType() != kIntType) {
          throw InvalidType(node->GetPos());
        }
      }
      node->SetType(std::make_shared<Type>(CreateType(std::move(type.value()), node->GetDim())));
      break;
    }
    case NewPrimaryNode::NewType::kNewArrayLiteral: {
      auto &array = node->GetArrayLiteral();
      array->accept(this);
      auto node_type = CreateType(std::move(type.value()), node->GetDim());
      if (node_type != *array->GetType()) {
        throw TypeMismatch({node->GetPos()});
      }
      node->SetType(std::make_shared<Type>(std::move(node_type)));
      break;
    }
    case NewPrimaryNode::NewType::kUnknown: {
      throw std::runtime_error("Invalid new type");
    }
  }
}

void SemanticChecker::visit(AtomExprNode *node) {
  auto &primary = node->GetPrimaryNode();
  primary->accept(this);
  node->SetType(primary->GetType());
  node->SetAssignable(primary->IsAssignable());
  node->SetNull(primary->IsNull());
}

void SemanticChecker::visit(AssignExprNode *node) {
  auto &lhs = node->GetLeftExprNode();
  auto &rhs = node->GetRightExprNode();
  lhs->accept(this);
  rhs->accept(this);
  if (!lhs->IsAssignable()) {
    throw NotAssignable(node->GetPos());
  }
  auto &left_type = lhs->GetType();
  auto &right_type = rhs->GetType();
  if ((left_type->GetDim() > 0 || left_type->GetDim() == 0 && *left_type != kIntType && *left_type != kBoolType) &&
      rhs->IsNull()) {
    node->SetType(left_type);
    return;
  }
  if (left_type == nullptr || right_type == nullptr) {
    throw InvalidType(node->GetPos());
  }
  if (*left_type != *right_type) {
    throw TypeMismatch(node->GetPos());
  }
  node->SetType(left_type);
  node->SetAssignable(false);
  node->SetNull(false);
}

void SemanticChecker::visit(UnaryExprNode *node) {
  auto &expr = node->GetExprNode();
  expr->accept(this);
  switch (node->GetOpType()) {
    case UnaryExprNode::OpType::kNot:
    case UnaryExprNode::OpType::kPlus:
    case UnaryExprNode::OpType::kMinus: {
      if (expr->GetType() == nullptr || *expr->GetType() != kIntType) {
        throw TypeMismatch(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kIntType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kSufIncrement:
    case UnaryExprNode::OpType::kSufDecrement: {
      if (expr->GetType() == nullptr || *expr->GetType() != kIntType) {
        throw TypeMismatch(node->GetPos());
      }
      if (!expr->IsAssignable()) {
        throw NotAssignable(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kIntType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kPreIncrement:
    case UnaryExprNode::OpType::kPreDecrement: {
      if (expr->GetType() == nullptr || *expr->GetType() != kIntType) {
        throw TypeMismatch(node->GetPos());
      }
      if (!expr->IsAssignable()) {
        throw NotAssignable(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kIntType));
      node->SetAssignable(true);
      node->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kNotLogic: {
      if (expr->GetType() == nullptr || *expr->GetType() != kBoolType) {
        throw TypeMismatch(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kBoolType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kUnknown: {
      throw std::runtime_error("Invalid unary operator type");
    }
  }
}

void SemanticChecker::visit(BinaryExprNode *node) {
  auto &lhs = node->GetLeftNode();
  auto &rhs = node->GetRightNode();
  lhs->accept(this);
  rhs->accept(this);
  auto &left_type = lhs->GetType();
  auto &right_type = rhs->GetType();
  switch (node->GetOpType()) {
    case BinaryExprNode::OpType::kAdd: {
      if (left_type == nullptr || right_type == nullptr) {
        throw InvalidType(node->GetPos());
      }
      if (*left_type != *right_type) {
        throw TypeMismatch(node->GetPos());
      }
      if (*left_type != kIntType && *left_type != kStringType) {
        throw InvalidType(node->GetPos());
      }
      node->SetType(left_type);
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case BinaryExprNode::OpType::kSub:
    case BinaryExprNode::OpType::kMul:
    case BinaryExprNode::OpType::kDiv:
    case BinaryExprNode::OpType::kMod:
    case BinaryExprNode::OpType::kAnd:
    case BinaryExprNode::OpType::kOr:
    case BinaryExprNode::OpType::kXor:
    case BinaryExprNode::OpType::kShiftL:
    case BinaryExprNode::OpType::kShiftR: {
      if (left_type == nullptr || right_type == nullptr) {
        throw InvalidType(node->GetPos());
      }
      if (*left_type != *right_type) {
        throw TypeMismatch(node->GetPos());
      }
      if (*left_type != kIntType) {
        throw InvalidType(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kIntType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case BinaryExprNode::OpType::kLess:
    case BinaryExprNode::OpType::kGreater:
    case BinaryExprNode::OpType::kLessEqual:
    case BinaryExprNode::OpType::kGreaterEqual: {
      if (left_type == nullptr || right_type == nullptr) {
        throw InvalidType(node->GetPos());
      }
      if (*left_type != *right_type) {
        throw TypeMismatch(node->GetPos());
      }
      if (*left_type != kIntType && *left_type != kStringType) {
        throw InvalidType(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kBoolType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case BinaryExprNode::OpType::kEqual:
    case BinaryExprNode::OpType::kNotEqual: {
      if (left_type == nullptr && right_type != nullptr && (*right_type == kIntType || *right_type == kBoolType)) {
        throw InvalidType(node->GetPos());
      }
      if (right_type == nullptr && left_type != nullptr && (*left_type == kIntType || *left_type == kBoolType)) {
        throw InvalidType(node->GetPos());
      }
      if (left_type != nullptr && right_type != nullptr && *left_type != *right_type) {
        throw TypeMismatch(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kBoolType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case BinaryExprNode::OpType::kAndLogic:
    case BinaryExprNode::OpType::kOrLogic: {
      if (left_type == nullptr || right_type == nullptr) {
        throw InvalidType(node->GetPos());
      }
      if (*left_type != *right_type) {
        throw TypeMismatch(node->GetPos());
      }
      if (*left_type != kBoolType) {
        throw InvalidType(node->GetPos());
      }
      node->SetType(std::make_shared<Type>(kBoolType));
      node->SetAssignable(false);
      node->SetNull(false);
      break;
    }
    case BinaryExprNode::OpType::kUnknown: {
      throw std::runtime_error("Invalid binary operator type");
    }
  }
}

void SemanticChecker::visit(TenaryExprNode *node) {
  auto &condition = node->GetCondition();
  condition->accept(this);
  auto &then_expr = node->GetThenExpr();
  then_expr->accept(this);
  auto &else_expr = node->GetElseExpr();
  else_expr->accept(this);
  auto condition_type = condition->GetType();
  if (condition_type == nullptr || *condition_type != kBoolType) {
    throw InvalidType(node->GetPos());
  }
  auto &then_type = then_expr->GetType();
  auto &else_type = else_expr->GetType();
  if (then_type == nullptr && else_type == nullptr) {
    node->SetType(nullptr);
    node->SetAssignable(false);
    node->SetNull(true);
    return;
  }
  if (then_type == nullptr) {
    if (else_type->GetDim() == 0 && (*else_type == kIntType || *else_type == kBoolType)) {
      throw TypeMismatch(node->GetPos());
    }
    node->SetType(else_type);
    node->SetAssignable(false);
    node->SetNull(false);
    return;
  }
  if (else_type == nullptr) {
    if (then_type->GetDim() == 0 && (*then_type == kIntType || *then_type == kBoolType)) {
      throw TypeMismatch(node->GetPos());
    }
    node->SetType(then_type);
    node->SetAssignable(false);
    node->SetNull(false);
    return;
  }
  if (*then_type != *else_type) {
    throw TypeMismatch(node->GetPos());
  }
  node->SetType(then_type);
  node->SetAssignable(false);
  node->SetNull(false);
}

void SemanticChecker::visit(MemberExprNode *node) {
  auto &expr = node->GetExprNode();
  expr->accept(this);
  auto &member_name = node->GetMemberName();
  auto &expr_type = expr->GetType();
  if (expr_type == nullptr) {
    throw InvalidMember(node->GetPos());
  }
  if (expr_type->GetDim() > 0) {
    throw InvalidType(node->GetPos());
  }
  auto member = expr_type->GetTypename()->GetMember(member_name);
  if (member == std::nullopt) {
    throw InvalidMember(node->GetPos());
  }
  node->SetType(std::make_shared<Type>(std::move(member.value())));
  node->SetAssignable(true);
  node->SetNull(false);
}

void SemanticChecker::visit(FormatExprNode *node) {
  auto &elements = node->GetElements();
  for (const auto &item : elements) {
    if (std::holds_alternative<std::shared_ptr<ExprNode>>(item)) {
      auto expr = std::get<std::shared_ptr<ExprNode>>(item);
      expr->accept(this);
      auto expr_type = expr->GetType();
      if (expr_type == nullptr || (*expr_type != kIntType && *expr_type != kBoolType && *expr_type != kStringType)) {
        throw InvalidType(node->GetPos());
      }
    }
  }
  node->SetType(std::make_shared<Type>(kStringType));
  node->SetAssignable(false);
  node->SetNull(false);
}

void SemanticChecker::visit(SubscriptExprNode *node) {
  auto &base = node->GetBaseExpr();
  auto &index = node->GetIndexExpr();
  base->accept(this);
  auto base_type = base->GetType();
  if (base_type == nullptr || base_type->GetDim() < index.size()) {
    throw DimOutOfBound(node->GetPos());
  }
  for (auto &item : index) {
    item->accept(this);
    auto type = item->GetType();
    if (type == nullptr || *type != kIntType) {
      throw InvalidType(node->GetPos());
    }
  }
  node->SetType(std::make_shared<Type>(CreateType(base_type->GetTypename(), base_type->GetDim() - index.size())));
  node->SetAssignable(true);
  node->SetNull(false);
}

void SemanticChecker::visit(FunctionCallExprNode *node) {
  auto &base = node->GetBaseExpr();
  auto &func_name = node->GetFuncName();
  auto &arguments = node->GetArguments();
  std::shared_ptr<Function> func(nullptr);
  if (base != nullptr) {
    base->accept(this);
    auto &base_type = base->GetType();
    if (base_type == nullptr) {
      throw InvalidType(node->GetPos());
    }
    if (base_type->GetDim() > 0) {
      if (func_name == "size" && arguments.empty()) {
        node->SetType(std::make_shared<Type>(kIntType));
        node->SetAssignable(false);
        node->SetNull(false);
        return;
      }
      throw InvalidType(node->GetPos());
    }
    auto func_opt = base_type->GetTypename()->GetFunction(func_name);
    if (func_opt == std::nullopt) {
      throw InvalidMember(node->GetPos());
    }
    if (func_opt.value().GetReturnType().GetTypename() == nullptr) {
      assert(false);
    }
    func = std::make_shared<Function>(std::move(func_opt.value()));
  } else {
    auto func_opt = global_scope_.GetFunction(func_name);
    if (func_opt != std::nullopt) {
      func = std::make_shared<Function>(std::move(func_opt.value()));
    }
    if (current_class_ != nullptr) {
      auto method_opt = current_class_->GetFunction(func_name);
      if (method_opt != std::nullopt) {
        func = std::make_shared<Function>(std::move(method_opt.value()));
      }
    }
    if (func == nullptr) {
      throw UndefinedIdentifier(node->GetPos());
    }
  }
  if (arguments.size() != func->GetArgNum()) {
    throw InvalidArgs(node->GetPos());
  }
  auto func_args = func->GetArguments();
  for (int i = 0; i < arguments.size(); ++i) {
    arguments[i]->accept(this);
    auto type = arguments[i]->GetType();
    if (type == nullptr && (func_args[i] == kIntType || func_args[i] == kBoolType) ||
        type != nullptr && *type != func_args[i]) {
      throw InvalidArgs(node->GetPos());
    }
  }
  node->SetType(std::make_shared<Type>(func->GetReturnType()));
  node->SetAssignable(false);
  node->SetNull(false);
  assert(node->GetType()->GetTypename() != nullptr);
}

void SemanticChecker::visit(EmptyStmtNode *node) {}

void SemanticChecker::visit(SuiteStmtNode *node) {
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  for (auto &stmt : node->GetStatements()) {
    stmt->accept(this);
  }
  scope_ = std::move(*scope_.GetParent());
}

void SemanticChecker::visit(IfStmtNode *node) {
  auto &condition = node->GetCondition();
  condition->accept(this);
  if (condition->GetType() == nullptr || *condition->GetType() != kBoolType) {
    throw InvalidType(node->GetPos());
  }
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  node->GetThenStmt()->accept(this);
  scope_ = std::move(*scope_.GetParent());
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  if (auto else_stmt = node->GetElseStmt()) {
    else_stmt->accept(this);
  }
  scope_ = std::move(*scope_.GetParent());
}

void SemanticChecker::visit(ExprStmtNode *node) { node->GetExprNode()->accept(this); }

void SemanticChecker::visit(WhileStmtNode *node) {
  auto &condition = node->GetCondition();
  condition->accept(this);
  ++inside_loop_;
  if (condition->GetType() == nullptr || *condition->GetType() != kBoolType) {
    throw InvalidType(node->GetPos());
  }
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  node->GetLoopStmt()->accept(this);
  --inside_loop_;
  scope_ = std::move(*scope_.GetParent());
}

void SemanticChecker::visit(VarDefStmtNode *node) {
  auto &[type_name, dim] = node->GetType();
  if (type_name == "void") {
    throw InvalidType(node->GetPos());
  }
  auto type_opt = global_scope_.GetType(type_name);
  if (type_opt == std::nullopt) {
    throw UndefinedIdentifier(node->GetPos());
  }
  auto type = CreateType(std::move(type_opt.value()), dim);
  auto &var_name = node->GetVarName();
  auto &expr = node->GetInitialValue();
  for (int i = 0; i < var_name.size(); ++i) {
    if (expr[i] != nullptr) {
      expr[i]->accept(this);
      if (expr[i]->GetType() == nullptr) {
        if (dim == 0 && (type == kIntType && type == kBoolType)) {
          throw TypeMismatch(node->GetPos());
        }
      } else if (*expr[i]->GetType() != type) {
        throw TypeMismatch(node->GetPos());
      }
    }
    scope_.DefineVar(var_name[i], type, node->GetPos());
  }
}

void SemanticChecker::visit(ControlStmtNode *node) {
  auto control_type = node->GetStmtType();
  switch (control_type) {
    case ControlStmtNode::StmtType::kContinue:
    case ControlStmtNode::StmtType::kBreak: {
      if (inside_loop_ == 0) {
        throw InvalidControlFlow(node->GetPos());
      }
      break;
    }
    case ControlStmtNode::StmtType::kReturn: {
      auto expr = node->GetReturnExpr();
      if (expr == nullptr) {
        if (*return_type_ != kVoidType) {
          throw TypeMismatch(node->GetPos());
        }
      } else {
        expr->accept(this);
        if (expr->GetType() != nullptr && *expr->GetType() != *return_type_) {
          throw TypeMismatch(node->GetPos());
        }
        if (expr->GetType() == nullptr && (*return_type_ == kIntType || *return_type_ == kBoolType)) {
          throw TypeMismatch(node->GetPos());
        }
      }
      break;
    }
    case ControlStmtNode::StmtType::kUnknown: {
      throw std::runtime_error("Invalid control statement type");
    }
  }
}

void SemanticChecker::visit(ForStmtNode *node) {
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  node->GetInitializeStmt()->accept(this);
  auto &condition = node->GetCondition();
  if (condition) {
    condition->accept(this);
    if (condition->GetType() == nullptr || *condition->GetType() != kBoolType) {
      throw InvalidType(node->GetPos());
    }
  }
  auto step = node->GetStep();
  if (step) {
    step->accept(this);
  }
  ++inside_loop_;
  node->GetLoop()->accept(this);
  --inside_loop_;
  scope_ = {std::move(*scope_.GetParent())};
}

void SemanticChecker::visit(ClassDefNode *node) {
  auto &type_name = node->GetClassName();
  auto type = global_scope_.GetType(type_name);
  if (type == std::nullopt) {
    throw std::runtime_error("Unidentified class name");
  }
  current_class_ = std::move(type.value());
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  scope_.DefineVar("this", CreateType(current_class_, 0), node->GetPos());
  for (const auto &member : current_class_->GetMembers()) {
    scope_.DefineVar(member.first, *member.second, node->GetPos());
  }
  for (auto &stmt : node->GetClassStmt()) {
    stmt->accept(this);
  }
  scope_ = std::move(*scope_.GetParent());
  current_class_ = nullptr;
}

void SemanticChecker::visit(FunctionDefNode *node) {
  auto &func_name = node->GetFunctionName();
  auto func = global_scope_.GetFunction(func_name);
  if (func == std::nullopt) {
    throw std::runtime_error("Unidentified function name");
  }
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  return_type_ = std::make_shared<Type>(func.value().GetReturnType());
  for (const auto &arg : node->GetArguments()) {
    auto &[arg_type, arg_name] = arg;
    auto type_name = global_scope_.GetType(arg_type.first);
    if (type_name == std::nullopt) {
      throw std::runtime_error("Unidentified arg type");
    }
    auto type = CreateType(std::move(type_name.value()), arg_type.second);
    scope_.DefineVar(arg_name, std::move(type), node->GetPos());
  }
  node->GetFunctionBody()->accept(this);
  scope_ = std::move(*scope_.GetParent());
}

void SemanticChecker::visit(VarDefNode *node) {
  auto &[type_name, dim] = node->GetTypename();
  auto type = global_scope_.GetType(type_name);
  if (type == std::nullopt) {
    throw std::runtime_error("Undefined type");
  }
  auto var_type = CreateType(std::move(type.value()), dim);
  auto &var_name = node->GetVarName();
  auto &expr = node->GetInitialValue();
  for (int i = 0; i < var_name.size(); ++i) {
    scope_.DefineVar(var_name[i], var_type, node->GetPos());
    if (expr[i] == nullptr) {
      continue;
    }
    expr[i]->accept(this);
    if (expr[i]->GetType() == nullptr) {
      if (dim == 0 && (var_type == kIntType || var_type == kBoolType)) {
        throw TypeMismatch(node->GetPos());
      }
    } else if (*expr[i]->GetType() != var_type) {
      throw TypeMismatch(node->GetPos());
    }
  }
}

void SemanticChecker::visit(VarDefClassStmtNode *node) {}

void SemanticChecker::visit(ConstructorClassStmtNode *node) {
  return_type_ = std::make_shared<Type>(kVoidType);
  node->GetFunctionBody()->accept(this);
  return_type_ = nullptr;
}

void SemanticChecker::visit(FunctionDefClassStmtNode *node) {
  scope_ = {std::make_unique<Scope>(std::move(scope_))};
  auto func = current_class_->GetFunction(node->GetFuncName());
  if (func == std::nullopt) {
    throw std::runtime_error("Unidentified method name");
  }
  for (auto &item : node->GetArguments()) {
    auto &[type_name, var_name] = item;
    auto type_opt = global_scope_.GetType(type_name.first);
    if (type_opt == std::nullopt) {
      throw std::runtime_error("Invalid arg type");
    }
    auto type = CreateType(std::move(type_opt.value()), type_name.second);
    scope_.DefineVar(var_name, std::move(type), node->GetPos());
  }
  return_type_ = std::make_shared<Type>(func->GetReturnType());
  node->GetFunctionBody()->accept(this);
  scope_ = std::move(*scope_.GetParent());
}

void SemanticChecker::visit(RootNode *node) {
  for (auto &def : node->GetDefNodes()) {
    def->accept(this);
  }
}
