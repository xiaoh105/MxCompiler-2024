#include "backend/ir_builder.h"

std::shared_ptr<Var> IRBuilder::ToRightVal(const std::shared_ptr<Var> &var) {
  auto var_const = std::dynamic_pointer_cast<Constant>(var);
  if (var_const != nullptr) {
    return var_const;
  }
  if (var->GetType() == kIRStringType) {
    return var;
  }
  auto var_reg = std::dynamic_pointer_cast<Register>(var);
  auto value = vars_.CreateTmpVar(var->GetType().RemovePtr(), "");
  cur_func_->PushStmt(std::make_unique<LoadStmt>(value, var_reg));
  return value;
}

void IRBuilder::visit(LiteralPrimaryNode *node) {
  switch (node->GetLiteralType()) {
    case LiteralPrimaryNode::kBool:
      node->SetVar(vars_.GetBool(std::get<bool>(node->GetValue())));
      break;
    case LiteralPrimaryNode::kInt:
      node->SetVar(vars_.GetInt(std::get<int>(node->GetValue())));
      break;
    case LiteralPrimaryNode::kNull:
      node->SetVar(vars_.GetNull());
      break;
    case LiteralPrimaryNode::kString:
      node->SetVar(vars_.GetString(std::get<std::string>(node->GetValue())));
      break;
    case LiteralPrimaryNode::kArray: {
      auto &array = std::get<std::shared_ptr<ArrayNode>>(node->GetValue());
      array->accept(this);
      node->SetVar(array->GetVar());
      break;
    }
    case LiteralPrimaryNode::kUnknown:
      assert(false);
  }
}

void IRBuilder::visit(ThisPrimaryNode *node) { node->SetVar(vars_.GetVar("this")); }

void IRBuilder::visit(VarPrimaryNode *node) {
  if (node->IsMember()) {
    if (vars_.HasVar(node->GetName())) {
      node->SetVar(vars_.GetVar(node->GetName()));
    } else {
      auto type = classes_.GetType(node->GetType()->GetTypename()->GetName());
      auto ret = vars_.CreateVar(IRType(type, node->GetType()->GetDim() + 1), node->GetName(), false);
      auto this_ptr = vars_.GetVar("this");
      auto index = type->GetMember(node->GetName()).first;
      cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(
          ret, this_ptr, std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), std::make_shared<Constant>(index)}));
      node->SetVar(std::move(ret));
    }
  } else {
    node->SetVar(vars_.GetVar(node->GetName()));
  }
}

std::shared_ptr<Register> IRBuilder::CreateArray(std::size_t cur_dim, const std::shared_ptr<IRBaseType> &type,
                                                 const std::vector<std::shared_ptr<ExprNode>> &expr, std::size_t dim) {
  auto tmp_var = vars_.CreateTmpVar({type, dim - cur_dim}, "arrayTmp");
  expr[cur_dim]->accept(this);
  auto &cur_len = expr[cur_dim]->GetVar();
  if (cur_dim + 1 == dim && type == kIRBoolBase) {
    cur_func_->PushStmt(std::make_unique<CallStmt>(functions_.GetFunction("builtin.allocArrayBool"), std::vector{{cur_len}}));
    return tmp_var;
  }
  cur_func_->PushStmt(std::make_unique<CallStmt>(functions_.GetFunction("builtin.allocArrayInt"), std::vector{{cur_len}}));
  if (cur_dim + 1 == expr.size()) {
    return tmp_var;
  }
  auto i = vars_.CreateTmpVar(kIRIntType.ToPtr(), "arrayIter");
  cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(tmp_var));
  auto cmp = vars_.CreateTmpVar(kIRBoolType, "cmp");
  auto loop_cond = std::make_shared<Block>(cur_func_->AssignTag("loop.cond"));
  auto loop_body = std::make_shared<Block>(cur_func_->AssignTag("loop.body"));
  auto loop_step = std::make_shared<Block>(cur_func_->AssignTag("loop.step"));
  auto loop_end = std::make_shared<Block>(cur_func_->AssignTag("loop.end"));
  cur_func_->PushBlock(loop_cond);
  cur_func_->PushStmt(std::make_unique<ICmpStmt>(cmp, ICmpStmt::OpType::kSlt, i, cur_len));
  cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cmp, loop_body, loop_end));
  cur_func_->PushBlock(loop_body);
  auto element = CreateArray(cur_dim + 1, type, expr, dim);
  auto ptr_to_element = vars_.CreateTmpVar({type, dim - cur_dim - 1}, "offset");
  cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(ptr_to_element, tmp_var,
                                                          std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), i}));
  cur_func_->PushStmt(std::make_unique<StoreStmt>(element, ptr_to_element));
  return tmp_var;
}

void IRBuilder::visit(NewPrimaryNode *node) {
  if (node->GetNewType() == NewPrimaryNode::NewType::kNewVar) {
    auto type = classes_.GetType(node->GetTypename());
    auto tmp_var = vars_.CreateTmpVar(IRType(type, node->GetType()->GetDim() + 1), "newTmp");
    auto constructor = type->GetConstructor();
    if (constructor.use_count() > 0) {
      cur_func_->PushStmt(std::make_unique<CallStmt>(constructor.lock(), std::vector<std::shared_ptr<Var>>{tmp_var}));
    }
    node->SetVar(tmp_var);
  } else if (node->GetNewType() == NewPrimaryNode::NewType::kNewArray) {
    auto base = classes_.GetType(node->GetTypename());
    auto tmp_var = vars_.CreateTmpVar(IRType(base, node->GetDim()), "newTmp");
    node->SetVar(CreateArray(0, base, node->GetExpressions(), node->GetDim()));
  } else {
    auto &literal = node->GetArrayLiteral();
    literal->accept(this);
    node->SetVar(literal->GetVar());
  }
}

void IRBuilder::visit(AtomExprNode *node) {
  auto &primary = node->GetPrimaryNode();
  primary->accept(this);
  node->SetVar(primary->GetVar());
}

void IRBuilder::visit(AssignExprNode *node) {
  auto &lhs = node->GetLeftExprNode();
  auto &rhs = node->GetRightExprNode();
  lhs->accept(this);
  rhs->accept(this);
  auto l_var = std::dynamic_pointer_cast<Register>(node->GetVar());
  auto &r_var = node->GetVar();
  auto r_value = ToRightVal(r_var);
  cur_func_->PushStmt(std::make_unique<StoreStmt>(r_value, l_var));
  node->SetVar(l_var);
}

void IRBuilder::visit(UnaryExprNode *node) {
  auto &expr = node->GetExprNode();
  expr->accept(this);
  auto value = ToRightVal(expr->GetVar());
  switch (node->GetOpType()) {
    case UnaryExprNode::OpType::kPlus: {
      node->SetVar(value);
      break;
    }
    case UnaryExprNode::OpType::kMinus: {
      auto res = vars_.CreateTmpVar(kIRIntType, "");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kSub, vars_.GetInt(0), value));
      node->SetVar(res);
      break;
    }
    case UnaryExprNode::OpType::kPreIncrement: {
      auto dest = std::dynamic_pointer_cast<Register>(expr->GetVar());
      auto res = vars_.CreateTmpVar(kIRIntType, "inc");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kAdd, value, vars_.GetInt(1)));
      cur_func_->PushStmt(std::make_unique<StoreStmt>(res, dest));
      node->SetVar(dest);
      break;
    }
    case UnaryExprNode::OpType::kPreDecrement: {
      auto dest = std::dynamic_pointer_cast<Register>(expr->GetVar());
      auto res = vars_.CreateTmpVar(kIRIntType, "dec");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kSub, value, vars_.GetInt(1)));
      cur_func_->PushStmt(std::make_unique<StoreStmt>(res, dest));
      node->SetVar(dest);
      break;
    }
    case UnaryExprNode::OpType::kSufIncrement: {
      auto dest = std::dynamic_pointer_cast<Register>(expr->GetVar());
      auto res = vars_.CreateTmpVar(kIRIntType, "inc");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kAdd, value, vars_.GetInt(1)));
      cur_func_->PushStmt(std::make_unique<StoreStmt>(res, dest));
      node->SetVar(value);
      break;
    }
    case UnaryExprNode::OpType::kSufDecrement: {
      auto dest = std::dynamic_pointer_cast<Register>(expr->GetVar());
      auto res = vars_.CreateTmpVar(kIRIntType, "dec");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kSub, value, vars_.GetInt(1)));
      cur_func_->PushStmt(std::make_unique<StoreStmt>(res, dest));
      node->SetVar(value);
      break;
    }
    case UnaryExprNode::OpType::kNot: {
      auto res = vars_.CreateTmpVar(kIRIntType, "");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kXor, value, vars_.GetInt(-1)));
      node->SetVar(res);
      break;
    }
    case UnaryExprNode::OpType::kNotLogic: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "");
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kXor, value, vars_.GetInt(1)));
      node->SetVar(res);
      break;
    }
    case UnaryExprNode::OpType::kUnknown: {
      assert(false);
    }
  }
}

void IRBuilder::visit(BinaryExprNode *node) {
  auto &lhs = node->GetLeftNode();
  auto &rhs = node->GetRightNode();
  std::shared_ptr<Var> l_var;
  std::shared_ptr<Var> r_var;
  if (node->GetOpType() != BinaryExprNode::OpType::kAndLogic && node->GetOpType() != BinaryExprNode::OpType::kOrLogic) {
    lhs->accept(this);
    rhs->accept(this);
    l_var = ToRightVal(lhs->GetVar());
    r_var = ToRightVal(rhs->GetVar());
  }
  BinaryStmt::OpType op;
  switch (node->GetOpType()) {
    case BinaryExprNode::OpType::kAnd: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kAnd;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kOr: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kOr;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kXor: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kXor;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kSub: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kSub;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kMul: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kMul;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kDiv: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kSDiv;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kMod: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kSRem;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kShiftL: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kShiftL;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kShiftR: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      op = BinaryStmt::OpType::kShiftR;
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kAdd: {
      auto res = vars_.CreateTmpVar(l_var->GetType(), "");
      if (l_var->GetType() == kIRIntType) {
        op = BinaryStmt::OpType::kAdd;
        cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, op, l_var, r_var));
      } else {
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.stringConcatenate"), std::vector{l_var, r_var}));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kEq, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kEq, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kNotEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kNe, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kNe, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kGreater: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSgt, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSgt, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kGreaterEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSge, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSge, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kLess: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSlt, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSlt, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kLessEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSle, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, ICmpStmt::OpType::kSle, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kAndLogic: {
      auto &and_lhs = cur_func_->GetCurBlock();
      auto and_rhs = std::make_shared<Block>(cur_func_->AssignTag("andRhs"));
      auto and_end = std::make_shared<Block>(cur_func_->AssignTag("andEnd"));
      lhs->accept(this);
      l_var = ToRightVal(lhs->GetVar());
      cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(l_var, and_rhs, and_end));
      cur_func_->PushBlock(and_rhs);
      rhs->accept(this);
      r_var = ToRightVal(rhs->GetVar());
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(and_end));
      cur_func_->PushBlock(and_end);
      auto res = vars_.CreateTmpVar(kIRBoolType, "");
      cur_func_->PushStmt(
          std::make_unique<PhiStmt>(res, std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>>{
                                             {vars_.GetBool(false), and_lhs}, {r_var, and_rhs}}));
      node->SetVar(res);
      break;
    }
    case BinaryExprNode::OpType::kOrLogic: {
      auto &or_lhs = cur_func_->GetCurBlock();
      auto or_rhs = std::make_shared<Block>(cur_func_->AssignTag("orRhs"));
      auto or_end = std::make_shared<Block>(cur_func_->AssignTag("orEnd"));
      lhs->accept(this);
      l_var = ToRightVal(lhs->GetVar());
      cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(l_var, or_end, or_rhs));
      cur_func_->PushBlock(or_rhs);
      rhs->accept(this);
      r_var = ToRightVal(rhs->GetVar());
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(or_end));
      cur_func_->PushBlock(or_end);
      auto res = vars_.CreateTmpVar(kIRBoolType, "");
      cur_func_->PushStmt(
          std::make_unique<PhiStmt>(res, std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>>{
                                             {vars_.GetBool(true), or_lhs}, {r_var, or_rhs}}));
      node->SetVar(res);
      break;
    }
    case BinaryExprNode::OpType::kUnknown: {
      assert(false);
    }
  }
}

void IRBuilder::visit(TenaryExprNode *node) {
  auto &cond = node->GetCondition();
  auto &lhs = node->GetThenExpr();
  auto &rhs = node->GetElseExpr();
  cond->accept(this);
  lhs->accept(this);
  rhs->accept(this);
  auto cond_val = ToRightVal(cond->GetVar());
  auto l_val = ToRightVal(lhs->GetVar());
  auto r_val = ToRightVal(rhs->GetVar());
  auto res = vars_.CreateTmpVar(l_val->GetType(), "");
  cur_func_->PushStmt(std::make_unique<SelectStmt>(res, cond_val, l_val, r_val));
  node->SetVar(res);
}

void IRBuilder::visit(FunctionCallExprNode *node) {
  auto base_expr = node->GetBaseExpr();
  auto &args = node->GetArguments();
  std::vector<std::shared_ptr<Var>> arg_var;
  if (base_expr != nullptr) {
    base_expr->accept(this);
    auto this_ptr = ToRightVal(base_expr->GetVar());
    arg_var.push_back(std::move(this_ptr));
  }
  for (const auto &arg : args) {
    arg->accept(this);
    auto arg_val = ToRightVal(arg->GetVar());
    arg_var.push_back(std::move(arg_val));
  }
  auto res = vars_.CreateTmpVar(kIRBoolType, "");
  cur_func_->PushStmt(std::make_unique<CallStmt>(res, functions_.GetFunction(node->GetFuncName()), std::move(arg_var)));
  node->SetVar(res);
}

void IRBuilder::visit(MemberExprNode *node) {
  auto &expr = node->GetExprNode();
  expr->accept(this);
  auto expr_val = std::dynamic_pointer_cast<Register>(ToRightVal(expr->GetVar()));
  auto &[index, member_type] = expr_val->GetType().GetBaseType()->GetMember(node->GetMemberName());
  auto res = vars_.CreateTmpVar(member_type, "member");
  cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(res, expr_val, std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), vars_.GetInt(index)}));
  node->SetVar(res);
}

void IRBuilder::visit(SubscriptExprNode *node) {
  auto &base = node->GetBaseExpr();
  auto &index = node->GetIndexExpr();
  base->accept(this);
  auto base_var = std::dynamic_pointer_cast<Register>(ToRightVal(base->GetVar()));
  std::shared_ptr<Register> res;
  for (const auto &item : index) {
    item->accept(this);
    auto index_var = ToRightVal(item->GetVar());
    res = vars_.CreateTmpVar(base_var->GetType().RemovePtr(), "");
    cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(res, base_var, std::vector{index_var}));
    base_var = res;
  }
  node->SetVar(res);
}

void IRBuilder::visit(FormatExprNode *node) {
  auto &elements = node->GetElements();
  std::shared_ptr<Register> res{nullptr};
  for (const auto &item : elements) {
    if (res == nullptr) {
      if (std::holds_alternative<std::string>(item)) {
        res = std::dynamic_pointer_cast<Register>(vars_.GetString(std::get<std::string>(item))->GetVar());
      } else {
        auto &expr = std::get<std::shared_ptr<ExprNode>>(item);
        expr->accept(this);
        auto tmp = ToRightVal(expr->GetVar());
        res = vars_.CreateTmpVar(tmp->GetType(), "");
        if (tmp->GetType() == kIRBoolType) {
          cur_func_->PushStmt(std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.printBool"), std::vector{tmp}));
        } else {
          cur_func_->PushStmt(std::make_unique<CallStmt>(res, functions_.GetFunction("toString"), std::vector{tmp}));
        }
      }
    } else {
      auto lhs = std::move(res);
      std::shared_ptr<Register> rhs;
      if (std::holds_alternative<std::string>(item)) {
        rhs = std::dynamic_pointer_cast<Register>(vars_.GetString(std::get<std::string>(item))->GetVar());
      } else {
        auto &expr = std::get<std::shared_ptr<ExprNode>>(item);
        expr->accept(this);
        auto tmp = ToRightVal(expr->GetVar());
        rhs = vars_.CreateTmpVar(tmp->GetType(), "");
        if (tmp->GetType() == kIRBoolType) {
          cur_func_->PushStmt(std::make_unique<CallStmt>(rhs, functions_.GetFunction("builtin.printBool"), std::vector{tmp}));
        } else {
          cur_func_->PushStmt(std::make_unique<CallStmt>(rhs, functions_.GetFunction("toString"), std::vector{tmp}));
        }
      }
      res = vars_.CreateTmpVar(kIRStringType, "");
      cur_func_->PushStmt(std::make_unique<CallStmt>(rhs, functions_.GetFunction("builtin.stringConcatenate"), std::vector<std::shared_ptr<Var>>{lhs, rhs}));
    }
  }
  node->SetVar(res);
}
