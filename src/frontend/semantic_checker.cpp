/*
 * Mx Compiler
 * File Name: semantic_checker.cpp
 * Identification: ./src/frontend/semantic_checker.cpp
 * Function: Scan the parser tree and throw errors if semantic errors exists
 */

#include "frontend/semantic_checker.h"
#include "utils/error/semantic_error.hpp"

SemanticChecker::SemanticChecker(Scope scope, GlobalScope global_scope)
    : scope_(std::move(scope)), global_scope_(std::move(global_scope)) {}

void SemanticChecker::visit(LiteralPrimaryNode *node) {
  switch (node->GetLiteralType()) {
    case LiteralPrimaryNode::kBool:
      node->SetType(std::make_shared<Type>(kBoolType));
      break;
    case LiteralPrimaryNode::kInt:
      node->SetType(std::make_shared<Type>(kIntType));
      break;
    case LiteralPrimaryNode::kNull:
      node->SetType(std::make_shared<Type>(nullptr));
      break;
    case LiteralPrimaryNode::kString:
      node->SetType(std::make_shared<Type>(kStringType));
      break;
    case LiteralPrimaryNode::kArray:
      auto array_node = std::get<std::shared_ptr<ArrayNode>>(node->GetValue());
      array_node->accept(this);
      node->SetType(array_node->GetType());
      break;
    case LiteralPrimaryNode::kUnknown:
      throw std::runtime_error("Invalid literal type");
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
  switch (node->GetNewType()) {
    case NewPrimaryNode::NewType::kNewVar: {
      node->SetType(std::make_shared<Type>(CreateType(std::move(type.value()))));
      break;
    }
    case NewPrimaryNode::NewType::kNewArray: {
      auto expr = node->GetExpressions();
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
      auto array = node->GetArrayLiteral();
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
  auto lhs = node->GetLeftExprNode();
  auto rhs = node->GetRightExprNode();
  lhs->accept(this);
  rhs->accept(this);
  if (!lhs->IsAssignable()) {
    throw NotAssignable(node->GetPos());
  }
  auto &left_type = lhs->GetType();
  auto &right_type = rhs->GetType();
  if (left_type->GetDim() > 0 && rhs->IsNull()) {
    node->SetType(left_type);
    return;
  }
  if (*left_type != *right_type) {
    throw TypeMismatch(node->GetPos());
  }
  node->SetType(left_type);
  node->SetAssignable(false);
  node->SetNull(false);
}

void SemanticChecker::visit(UnaryExprNode *node) {
  auto expr = node->GetExprNode();
  expr->accept(this);
  switch (node->GetOpType()) {
    case UnaryExprNode::OpType::kNot:
    case UnaryExprNode::OpType::kPlus:
    case UnaryExprNode::OpType::kMinus:
    case UnaryExprNode::OpType::kPreIncrement:
    case UnaryExprNode::OpType::kPreDecrement:
    case UnaryExprNode::OpType::kSufIncrement:
    case UnaryExprNode::OpType::kSufDecrement: {
      if (expr->GetType() == nullptr || *expr->GetType() != kIntType) {
        throw TypeMismatch(node->GetPos());
      }
      expr->SetType(std::make_shared<Type>(kIntType));
      expr->SetAssignable(false);
      expr->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kNotLogic: {
      if (expr->GetType() == nullptr || *expr->GetType() != kBoolType) {
        throw TypeMismatch(node->GetPos());
      }
      expr->SetType(std::make_shared<Type>(kBoolType));
      expr->SetAssignable(false);
      expr->SetNull(false);
      break;
    }
    case UnaryExprNode::OpType::kUnknown: {
      throw std::runtime_error("Invalid unary operator type");
    }
  }
}

void SemanticChecker::visit(BinaryExprNode *node) {
  auto lhs = node->GetLeftNode();
  auto rhs = node->GetRightNode();
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
      if (left_type == nullptr && (right_type != nullptr && right_type->GetDim() == 0)) {
        throw InvalidType(node->GetPos());
      }
      if (right_type == nullptr && (left_type != nullptr && left_type->GetDim() == 0)) {
        throw InvalidType(node->GetPos());
      }
      if (left_type != right_type) {
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
  auto condition = node->GetCondition();
  condition->accept(this);
  auto then_expr = node->GetThenExpr();
  then_expr->accept(this);
  auto else_expr = node->GetElseExpr();
  else_expr->accept(this);
  auto condition_type = condition->GetType();
  if (condition_type == nullptr || *condition_type != kBoolType) {
    throw InvalidType(node->GetPos());
  }
  auto then_type = then_expr->GetType();
  auto else_type = else_expr->GetType();
  if (then_type == nullptr && else_type == nullptr) {
    node->SetType(nullptr);
    node->SetAssignable(false);
    node->SetNull(true);
    return;
  }
  if (then_type == nullptr || else_type == nullptr) {
    throw TypeMismatch(node->GetPos());
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
  auto expr_type = expr->GetType();
  if (expr_type == nullptr) {
    throw InvalidMember(node->GetPos());
  }
  auto member = expr_type->GetTypename()->GetMember(member_name);
  if (member == std::nullopt) {
    throw InvalidMember(node->GetPos());
  }
  node->SetType(std::make_shared<Type>(std::move(member.value())));
  node->SetAssignable(true);
  node->SetNull(false);
}
