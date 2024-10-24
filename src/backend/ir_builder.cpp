#include "backend/ir_builder.h"
#include "frontend/semantic_checker.h"
#include "frontend/symbol_collector.h"
#include "opt/cfg.h"
#include "opt/mem_to_reg/mem_to_reg.h"
#include "opt/reg_alloc/reg_alloc.h"

void GenerateIR(RootNode *root) {
  auto [scope, global_scope] = CollectSymbol(root);
  SemanticChecker checker(std::move(scope), std::move(global_scope));
  checker.visit(root);
  IRBuilder builder(std::move(checker.GetGlobalScope()));
  builder.visit(root);
  builder.vars_.DefineGlobal();
  builder.classes_.Define();
  builder.functions_.PrintDeclare();
  builder.functions_.PrintDefine();
}

IRBuilder::IRBuilder(GlobalScope global_scope) {
  classes_.AddType(global_scope.GetTypes());
  for (auto &func : global_scope.GetFunctions()) {
    auto ast_ret_type = func.second.GetReturnType();
    auto ret_base = classes_.GetType(ast_ret_type.GetTypename()->GetName());
    auto ret_type = IRType{ret_base, ast_ret_type.GetDim() + (ret_base->IsTrivial() ? 0 : 1)};
    std::vector<std::pair<IRType, std::string>> args;
    auto &ast_args = func.second.GetArguments();
    auto &ast_arg_name = func.second.GetArgName();
    for (int i = 0; i < ast_args.size(); ++i) {
      auto arg_base = classes_.GetType(ast_args[i].GetTypename()->GetName());
      auto arg_type = IRType{arg_base, ast_args[i].GetDim() + (arg_base->IsTrivial() ? 0 : 1)};
      args.emplace_back(std::move(arg_type), ast_arg_name[i]);
    }
    auto ret = std::make_shared<IRFunction>(std::move(ret_type), func.first, std::move(args), false);
    functions_.DefineFunction(ret);
  }
  for (const auto &type : global_scope.GetTypes()) {
    if (type.first == "string") {
      continue;
    }
    auto this_type = IRType{classes_.GetType(type.first), 1};
    for (const auto &func : type.second->GetFunctions()) {
      auto ast_ret_type = func.second->GetReturnType();
      auto ret_base = classes_.GetType(ast_ret_type.GetTypename()->GetName());
      auto ret_type = IRType{ret_base, ast_ret_type.GetDim() + (ret_base->IsTrivial() ? 0 : 1)};
      std::vector<std::pair<IRType, std::string>> args;
      args.emplace_back(this_type, "this");
      auto &ast_args = func.second->GetArguments();
      auto &ast_arg_name = func.second->GetArgName();
      for (int i = 0; i < ast_args.size(); ++i) {
        auto arg_base = classes_.GetType(ast_args[i].GetTypename()->GetName());
        auto arg_type = IRType{arg_base, ast_args[i].GetDim() + (arg_base->IsTrivial() ? 0 : 1)};
        args.emplace_back(std::move(arg_type), ast_arg_name[i]);
      }
      auto ret = std::make_shared<IRFunction>(std::move(ret_type), "struct." + type.first + "." + func.first,
                                              std::move(args), false);
      functions_.DefineFunction(ret);
      if (func.first == type.first) {
        this_type.GetBaseType()->SetConstructor(ret);
      }
    }
  }
  init_func_ =
      std::make_unique<IRFunction>(kIRVoidType, "global.init", std::vector<std::pair<IRType, std::string>>{}, false);
  functions_.DefineFunction(init_func_);
}

std::shared_ptr<Var> IRBuilder::ToRightVal(const std::shared_ptr<Var> &var) {
  if (!var->IsLValue()) {
    return var;
  }
  auto var_reg = std::dynamic_pointer_cast<Register>(var);
  auto value = vars_.CreateTmpVar(var->GetType().RemovePtr(), "");
  cur_func_->PushStmt(std::make_unique<LoadStmt>(value, var_reg));
  return value;
}

void IRBuilder::visit(SimpleArrayNode *node) {
  auto base = classes_.GetType(node->GetType()->GetTypename()->GetName());
  auto &elements = node->GetElements();
  if (base != kIRStringBase) {
    auto res = vars_.CreateTmpVar({base, 1}, "");
    cur_func_->PushStmt(
        std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.allocArray"),
                                   std::vector<std::shared_ptr<Var>>{vars_.GetInt(static_cast<int>(elements.size()))}));
    for (int i = 0; i < elements.size(); ++i) {
      if (base == kIRIntBase) {
        auto ptr = vars_.CreateTmpVar({base, 1}, "");
        cur_func_->PushStmt(
            std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
        int val = std::get<int>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
        cur_func_->PushStmt(std::make_unique<StoreStmt>(vars_.GetInt(val), ptr));
      } else {
        auto ptr = vars_.CreateTmpVar({base, 1}, "");
        cur_func_->PushStmt(
            std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
        bool val = std::get<bool>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
        cur_func_->PushStmt(std::make_unique<StoreStmt>(vars_.GetBool(val), ptr));
      }
    }
    node->SetVar(res);
  } else {
    auto res = vars_.CreateTmpVar({base, 2}, "");
    cur_func_->PushStmt(
        std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.allocArray"),
                                   std::vector<std::shared_ptr<Var>>{vars_.GetInt(static_cast<int>(elements.size()))}));
    for (int i = 0; i < elements.size(); ++i) {
      auto ptr = vars_.CreateTmpVar({base, 2}, "");
      cur_func_->PushStmt(
          std::make_unique<GetElementPtrStmt>(ptr, res, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
      std::string str = std::get<std::string>(std::dynamic_pointer_cast<LiteralPrimaryNode>(elements[i])->GetValue());
      auto val = vars_.GetString(str)->GetVar();
      cur_func_->PushStmt(std::make_unique<StoreStmt>(val, ptr));
    }
    node->SetVar(res);
  }
}

void IRBuilder::visit(JaggedArrayNode *node) {
  auto &elements = node->GetElements();
  auto type = IRType{elements[0]->GetVar()->GetType().GetBaseType(), elements[0]->GetVar()->GetType().GetDim() + 1};
  auto tmp_var = vars_.CreateTmpVar(type, "arrayTmp");
  cur_func_->PushStmt(std::make_unique<CallStmt>(tmp_var, functions_.GetFunction("builtin.allocArray"),
                                                 std::vector<std::shared_ptr<Var>>{elements.size()}));
  for (int i = 0; i < elements.size(); ++i) {
    auto ptr = vars_.CreateTmpVar(type, "arrayTmp");
    elements[i]->accept(this);
    auto val = elements[i]->GetVar();
    cur_func_->PushStmt(
        std::make_unique<GetElementPtrStmt>(ptr, tmp_var, std::vector<std::shared_ptr<Var>>{vars_.GetInt(i)}));
    cur_func_->PushStmt(std::make_unique<StoreStmt>(val, ptr));
  }
  node->SetVar(tmp_var);
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
      node->SetVar(vars_.GetString(std::get<std::string>(node->GetValue()))->GetVar());
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
    const auto &type = classes_.GetType(node->GetType()->GetTypename()->GetName());
    auto ret =
        vars_.CreateTmpVar(IRType(type, node->GetType()->GetDim() + (type->IsTrivial() ? 1 : 2)), "member", true);
    auto this_ptr = vars_.GetVar("this");
    auto index = cur_type_->GetMember(node->GetName()).first;
    cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(
        ret, this_ptr, std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), std::make_shared<Constant>(index)}));
    node->SetVar(std::move(ret));
  } else {
    node->SetVar(vars_.GetVar(node->GetName()));
  }
}

std::shared_ptr<Register> IRBuilder::CreateArray(std::size_t cur_dim, const std::shared_ptr<IRBaseType> &type,
                                                 const std::vector<std::shared_ptr<ExprNode>> &expr, std::size_t dim) {
  auto tmp_var = vars_.CreateTmpVar({type, dim - cur_dim + (type->IsTrivial() ? 0 : 1)}, "arrayTmp");
  expr[cur_dim]->accept(this);
  auto cur_len = ToRightVal(expr[cur_dim]->GetVar());
  cur_func_->PushStmt(
      std::make_unique<CallStmt>(tmp_var, functions_.GetFunction("builtin.allocArray"), std::vector{{cur_len}}));
  if (cur_dim + 1 == expr.size()) {
    return tmp_var;
  }
  auto i = vars_.CreateTmpVar(kIRIntType.ToPtr(), "arrayIter", true);
  cur_func_->PushStmt(std::make_unique<AllocaStmt>(i));
  auto cmp = vars_.CreateTmpVar(kIRBoolType, "cmp");
  auto loop_cond = std::make_shared<Block>(cur_func_->AssignTag("loopCond"));
  auto loop_body = std::make_shared<Block>(cur_func_->AssignTag("loopBody"));
  auto loop_step = std::make_shared<Block>(cur_func_->AssignTag("loopStep"));
  auto loop_end = std::make_shared<Block>(cur_func_->AssignTag("loopEnd"));
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_cond));
  cur_func_->PushBlock(loop_cond);
  auto i_value = ToRightVal(i);
  cur_func_->PushStmt(std::make_unique<ICmpStmt>(cmp, zext_cnt_++, ICmpStmt::OpType::kSlt, i_value, cur_len));
  cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cmp, trunc_cnt_++, loop_body, loop_end));
  cur_func_->PushBlock(loop_body);
  auto element = CreateArray(cur_dim + 1, type, expr, dim);
  auto ptr_to_element = vars_.CreateTmpVar({type, dim - cur_dim + (type->IsTrivial() ? 0 : 1)}, "offset");
  cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(ptr_to_element, tmp_var, std::vector{i_value}));
  cur_func_->PushStmt(std::make_unique<StoreStmt>(element, ptr_to_element));
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_step));
  cur_func_->PushBlock(loop_step);
  auto new_i = vars_.CreateTmpVar(kIRIntType, "");
  cur_func_->PushStmt(std::make_unique<BinaryStmt>(new_i, BinaryStmt::OpType::kAdd, i_value, vars_.GetInt(1)));
  cur_func_->PushStmt(std::make_unique<StoreStmt>(new_i, i));
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_cond));
  cur_func_->PushBlock(loop_end);
  return tmp_var;
}

void IRBuilder::visit(NewPrimaryNode *node) {
  if (node->GetNewType() == NewPrimaryNode::NewType::kNewVar) {
    auto type = classes_.GetType(node->GetTypename());
    auto tmp_var = vars_.CreateTmpVar(IRType(type, node->GetType()->GetDim() + (type->IsTrivial() ? 0 : 1)), "newTmp");
    cur_func_->PushStmt(
        std::make_unique<CallStmt>(tmp_var, functions_.GetFunction("malloc"),
                                   std::vector<std::shared_ptr<Var>>{vars_.GetInt(static_cast<int>(type->GetSize()))}));
    auto constructor = type->GetConstructor();
    if (constructor.use_count() > 0) {
      cur_func_->PushStmt(std::make_unique<CallStmt>(constructor.lock(), std::vector<std::shared_ptr<Var>>{tmp_var}));
    }
    node->SetVar(tmp_var);
  } else if (node->GetNewType() == NewPrimaryNode::NewType::kNewArray) {
    auto base = classes_.GetType(node->GetTypename());
    auto tmp_var = vars_.CreateTmpVar(IRType(base, node->GetDim() + (base->IsTrivial() ? 0 : 1)), "newTmp");
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
  auto l_var = std::dynamic_pointer_cast<Register>(lhs->GetVar());
  auto &r_var = rhs->GetVar();
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
      cur_func_->PushStmt(std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kXor, value, vars_.GetBool(true)));
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
        cur_func_->PushStmt(std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.stringConcatenate"),
                                                       std::vector{l_var, r_var}));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kEq, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kEq, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kNotEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kNe, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kNe, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kGreater: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSgt, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSgt, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kGreaterEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSge, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSge, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kLess: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSlt, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSlt, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kLessEqual: {
      auto res = vars_.CreateTmpVar(kIRBoolType, "cmpRes");
      if (l_var->GetType() != kIRStringType.ToPtr()) {
        cur_func_->PushStmt(std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSle, l_var, r_var));
      } else {
        auto func_ret = vars_.CreateTmpVar(kIRIntType, "");
        cur_func_->PushStmt(
            std::make_unique<CallStmt>(func_ret, functions_.GetFunction("strcmp"), std::vector{l_var, r_var}));
        cur_func_->PushStmt(
            std::make_unique<ICmpStmt>(res, zext_cnt_++, ICmpStmt::OpType::kSle, func_ret, vars_.GetInt(0)));
      }
      node->SetVar(std::move(res));
      break;
    }
    case BinaryExprNode::OpType::kAndLogic: {
      auto and_rhs = std::make_shared<Block>(cur_func_->AssignTag("andRhs"));
      auto and_end = std::make_shared<Block>(cur_func_->AssignTag("andEnd"));
      lhs->accept(this);
      l_var = ToRightVal(lhs->GetVar());
      cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(l_var, trunc_cnt_++, and_rhs, and_end));
      auto and_lhs = cur_func_->GetCurBlock();
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
      auto or_rhs = std::make_shared<Block>(cur_func_->AssignTag("orRhs"));
      auto or_end = std::make_shared<Block>(cur_func_->AssignTag("orEnd"));
      lhs->accept(this);
      l_var = ToRightVal(lhs->GetVar());
      cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(l_var, trunc_cnt_++, or_end, or_rhs));
      auto or_lhs = cur_func_->GetCurBlock();
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
  auto lhs_block = std::make_shared<Block>(cur_func_->AssignTag("ternaryLhs"));
  auto rhs_block = std::make_shared<Block>(cur_func_->AssignTag("ternaryRhs"));
  auto end_block = std::make_shared<Block>(cur_func_->AssignTag("ternaryEnd"));
  cond->accept(this);
  cur_func_->PushStmt(
      std::make_unique<ConditionalBrStmt>(ToRightVal(cond->GetVar()), trunc_cnt_++, lhs_block, rhs_block));
  cur_func_->PushBlock(lhs_block);
  lhs->accept(this);
  auto l_val = lhs->GetVar() ? ToRightVal(lhs->GetVar()) : nullptr;
  auto l_jmp = cur_func_->GetCurBlock();
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(end_block));
  cur_func_->PushBlock(rhs_block);
  rhs->accept(this);
  auto r_val = rhs->GetVar() ? ToRightVal(rhs->GetVar()) : nullptr;
  auto r_jmp = cur_func_->GetCurBlock();
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(end_block));
  cur_func_->PushBlock(end_block);
  if (l_val) {
    std::shared_ptr<Register> res;
    if (l_val->GetType() != kIRNullType) {
      res = vars_.CreateTmpVar(l_val->GetType(), "");
    } else if (r_val->GetType() != kIRNullType) {
      res = vars_.CreateTmpVar(r_val->GetType(), "");
    } else {
      node->SetVar(vars_.GetNull());
      return;
    }
    cur_func_->PushStmt(std::make_unique<PhiStmt>(
        res, std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>>{{l_val, l_jmp}, {r_val, r_jmp}}));
    node->SetVar(res);
  }
}

void IRBuilder::visit(FunctionCallExprNode *node) {
  auto base_expr = node->GetBaseExpr();
  auto &args = node->GetArguments();
  std::vector<std::shared_ptr<Var>> arg_var;
  std::string func_name = node->GetFuncName();
  if (base_expr != nullptr) {
    base_expr->accept(this);
    auto this_ptr = ToRightVal(base_expr->GetVar());
    if (this_ptr->GetType().GetBaseType()->IsTrivial() && this_ptr->GetType().GetDim() >= 1 ||
        !this_ptr->GetType().GetBaseType()->IsTrivial() && this_ptr->GetType().GetDim() >= 2) {
      auto res = vars_.CreateTmpVar(kIRIntType, "");
      cur_func_->PushStmt(
          std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.getSize"), std::vector{this_ptr}));
      node->SetVar(res);
      return;
    }
    if (this_ptr->GetType() != kIRStringType.ToPtr()) {
      func_name = this_ptr->GetType().GetBaseType()->GetIRTypename().substr(1) + "." + node->GetFuncName();
    } else {
      func_name = this_ptr->GetType().GetBaseType()->GetIRTypename() + "." + node->GetFuncName();
    }
    arg_var.push_back(std::move(this_ptr));
  } else if (cur_type_ != nullptr &&
             functions_.HasFunction(cur_type_->GetIRTypename().substr(1) + "." + node->GetFuncName())) {
    func_name = cur_type_->GetIRTypename().substr(1) + "." + node->GetFuncName();
    arg_var.push_back(vars_.GetVar("this"));
  }
  for (const auto &arg : args) {
    arg->accept(this);
    auto arg_val = ToRightVal(arg->GetVar());
    arg_var.push_back(std::move(arg_val));
  }
  auto &func = functions_.GetFunction(func_name);
  if (func->GetReturnType() == kIRVoidType) {
    cur_func_->PushStmt(std::make_unique<CallStmt>(func, std::move(arg_var)));
  } else {
    auto res = vars_.CreateTmpVar(func->GetReturnType(), "");
    cur_func_->PushStmt(std::make_unique<CallStmt>(res, func, std::move(arg_var)));
    node->SetVar(res);
  }
}

void IRBuilder::visit(MemberExprNode *node) {
  auto &expr = node->GetExprNode();
  expr->accept(this);
  auto expr_val = std::dynamic_pointer_cast<Register>(ToRightVal(expr->GetVar()));
  auto [index, member_type] = expr_val->GetType().GetBaseType()->GetMember(node->GetMemberName());
  auto res = vars_.CreateTmpVar({member_type.GetBaseType(), member_type.GetDim() + 1}, "member", true);
  cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(
      res, expr_val, std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), vars_.GetInt(index)}));
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
    base_var = std::dynamic_pointer_cast<Register>(ToRightVal(base_var));
    res = vars_.CreateTmpVar(base_var->GetType(), "", true);
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
        res = vars_.CreateTmpVar(kIRStringType.ToPtr(), "");
        if (tmp->GetType() == kIRBoolType) {
          cur_func_->PushStmt(
              std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.printBool"), std::vector{tmp}));
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
        rhs = vars_.CreateTmpVar(kIRStringType.ToPtr(), "");
        if (tmp->GetType() == kIRBoolType) {
          cur_func_->PushStmt(
              std::make_unique<CallStmt>(rhs, functions_.GetFunction("builtin.printBool"), std::vector{tmp}));
        } else {
          cur_func_->PushStmt(std::make_unique<CallStmt>(rhs, functions_.GetFunction("toString"), std::vector{tmp}));
        }
      }
      res = vars_.CreateTmpVar(kIRStringType, "");
      cur_func_->PushStmt(std::make_unique<CallStmt>(res, functions_.GetFunction("builtin.stringConcatenate"),
                                                     std::vector<std::shared_ptr<Var>>{lhs, rhs}));
    }
  }
  node->SetVar(res);
}

void IRBuilder::visit(EmptyStmtNode *node) {}

void IRBuilder::visit(ExprStmtNode *node) { node->GetExprNode()->accept(this); }

void IRBuilder::visit(IfStmtNode *node) {
  auto &cond = node->GetCondition();
  cond->accept(this);
  auto cond_val = ToRightVal(cond->GetVar());
  auto then_block = std::make_shared<Block>(cur_func_->AssignTag("ifThen"));
  auto else_block = std::make_shared<Block>(cur_func_->AssignTag("ifElse"));
  auto end_block = std::make_shared<Block>(cur_func_->AssignTag("ifEnd"));
  if (node->GetElseStmt() != nullptr) {
    cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cond_val, trunc_cnt_++, then_block, else_block));
    cur_func_->PushBlock(then_block);
    node->GetThenStmt()->accept(this);
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(end_block));
    cur_func_->PushBlock(else_block);
    node->GetElseStmt()->accept(this);
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(end_block));
    cur_func_->PushBlock(end_block);
  } else {
    cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cond_val, trunc_cnt_++, then_block, end_block));
    cur_func_->PushBlock(then_block);
    node->GetThenStmt()->accept(this);
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(end_block));
    cur_func_->PushBlock(end_block);
  }
}

void IRBuilder::visit(SuiteStmtNode *node) {
  for (const auto &stmt : node->GetStatements()) {
    stmt->accept(this);
  }
}

void IRBuilder::visit(ControlStmtNode *node) {
  switch (node->GetStmtType()) {
    case ControlStmtNode::StmtType::kContinue: {
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_step_.top()));
      break;
    }
    case ControlStmtNode::StmtType::kBreak: {
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_end_.top()));
      break;
    }
    case ControlStmtNode::StmtType::kReturn: {
      auto &expr = node->GetReturnExpr();
      if (expr == nullptr) {
        cur_func_->PushStmt(std::make_unique<RetStmt>());
      } else {
        expr->accept(this);
        auto ret_val = ToRightVal(expr->GetVar());
        cur_func_->PushStmt(std::make_unique<RetStmt>(ret_val));
      }
      break;
    }
    case ControlStmtNode::StmtType::kUnknown: {
      assert(false);
    }
  }
}

void IRBuilder::visit(WhileStmtNode *node) {
  auto &cond = node->GetCondition();
  auto &stmts = node->GetLoopStmt();
  auto loop_cond = std::make_shared<Block>(cur_func_->AssignTag("loopCond"));
  auto loop_body = std::make_shared<Block>(cur_func_->AssignTag("loopBody"));
  auto loop_end = std::make_shared<Block>(cur_func_->AssignTag("loopEnd"));
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_cond));
  cur_func_->PushBlock(loop_cond);
  cond->accept(this);
  auto cond_var = ToRightVal(cond->GetVar());
  cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cond_var, trunc_cnt_++, loop_body, loop_end));
  cur_func_->PushBlock(loop_body);
  loop_step_.push(loop_cond);
  loop_end_.push(loop_end);
  stmts->accept(this);
  cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(loop_cond));
  cur_func_->PushBlock(loop_end);
  loop_step_.pop();
  loop_end_.pop();
}

void IRBuilder::visit(ForStmtNode *node) {
  node->GetInitializeStmt()->accept(this);
  auto &cond = node->GetCondition();
  auto &body = node->GetLoop();
  auto &step = node->GetStep();
  auto cond_block = std::make_shared<Block>(cur_func_->AssignTag("loopCond"));
  auto body_block = std::make_shared<Block>(cur_func_->AssignTag("loopBody"));
  auto step_block = std::make_shared<Block>(cur_func_->AssignTag("loopStep"));
  auto end_block = std::make_shared<Block>(cur_func_->AssignTag("loopEnd"));
  if (node->GetStep() != nullptr) {
    loop_step_.push(step_block);
  } else if (node->GetCondition() != nullptr) {
    loop_step_.push(cond_block);
  } else {
    loop_step_.push(body_block);
  }
  loop_end_.push(end_block);
  if (cond != nullptr) {
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(cond_block));
    cur_func_->PushBlock(cond_block);
    cond->accept(this);
    auto cond_var = ToRightVal(cond->GetVar());
    cur_func_->PushStmt(std::make_unique<ConditionalBrStmt>(cond_var, trunc_cnt_++, body_block, end_block));
  } else {
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(body_block));
  }
  cur_func_->PushBlock(body_block);
  body->accept(this);
  if (step != nullptr) {
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(step_block));
    cur_func_->PushBlock(step_block);
    step->accept(this);
  } else {
    if (cond != nullptr) {
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(cond_block));
    } else {
      cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(body_block));
    }
  }
  if (cond != nullptr) {
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(cond_block));
  } else {
    cur_func_->PushStmt(std::make_unique<UnconditionalBrStmt>(body_block));
  }
  loop_step_.pop();
  loop_end_.pop();
  cur_func_->PushBlock(end_block);
}

void IRBuilder::visit(VarDefStmtNode *node) {
  auto base = classes_.GetType(node->GetType().first);
  auto dim = base->IsTrivial() ? node->GetType().second + 1 : node->GetType().second + 2;
  IRType type(std::move(base), dim);
  auto &var_name = node->GetVarName();
  auto &initializer = node->GetInitialValue();
  for (int i = 0; i < var_name.size(); ++i) {
    auto reg = vars_.CreateVar(type, var_name[i], false);
    cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(reg));
    auto &expr = initializer[i];
    if (expr != nullptr) {
      expr->accept(this);
      auto var = ToRightVal(expr->GetVar());
      cur_func_->PushStmt(std::make_unique<StoreStmt>(var, reg));
    }
  }
}

void IRBuilder::visit(VarDefNode *node) {
  auto base = classes_.GetType(node->GetTypename().first);
  auto dim = base->IsTrivial() ? node->GetTypename().second + 1 : node->GetTypename().second + 2;
  IRType type(std::move(base), dim);
  auto &var_name = node->GetVarName();
  auto &initializer = node->GetInitialValue();
  cur_func_ = init_func_;
  vars_.EnterInitFunc();
  for (int i = 0; i < var_name.size(); ++i) {
    auto reg = vars_.CreateVar(type, var_name[i], true);
    auto &expr = initializer[i];
    if (expr != nullptr) {
      expr->accept(this);
      auto var = ToRightVal(expr->GetVar());
      cur_func_->PushStmt(std::make_unique<StoreStmt>(var, reg));
    }
  }
  vars_.LeaveInitFunc();
  cur_func_ = nullptr;
}

void IRBuilder::visit(FunctionDefNode *node) {
  cur_func_ = functions_.GetFunction(node->GetFunctionName());
  vars_.EnterNewFunc();
  std::vector<std::shared_ptr<Register>> arg_vars;
  for (const auto &arg : cur_func_->GetArguments()) {
    auto arg_val = vars_.CreateVar(arg.first, "arg." + arg.second, false);
    arg_vars.push_back(arg_val);
    auto arg_addr = vars_.CreateVar({arg.first.GetBaseType(), arg.first.GetDim() + 1}, arg.second, false);
    cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(arg_addr));
    cur_func_->PushStmt(std::make_unique<StoreStmt>(arg_val, arg_addr));
  }
  cur_func_->SetArgumentVars(std::move(arg_vars));
  if (node->GetFunctionName() == "main") {
    cur_func_->PushStmt(std::make_unique<CallStmt>(init_func_, std::vector<std::shared_ptr<Var>>{}));
  }
  node->GetFunctionBody()->accept(this);
  if (node->GetFunctionName() == "main") {
    cur_func_->PushStmt(std::make_unique<RetStmt>(vars_.GetInt(0)));
  }
  if (cur_func_->GetReturnType() == kIRVoidType) {
    cur_func_->PushStmt(std::make_unique<RetStmt>());
  } else {
    cur_func_->PushStmt(std::make_unique<Unreachable>());
  }
  cur_func_->LinkInitStmt();
  cur_func_ = nullptr;
}

void IRBuilder::visit(ClassDefNode *node) {
  auto base = classes_.GetType(node->GetClassName());
  cur_type_ = base;
  for (const auto &stmt : node->GetClassStmt()) {
    stmt->accept(this);
  }
  cur_type_ = nullptr;
}

void IRBuilder::visit(VarDefClassStmtNode *node) {}

void IRBuilder::visit(ConstructorClassStmtNode *node) {
  auto &constructor = cur_type_->GetConstructor();
  cur_func_ = constructor.lock();
  vars_.EnterNewFunc();
  vars_.CreateVar({cur_type_, 1}, "this", false, false);
  node->GetFunctionBody()->accept(this);
  cur_func_->PushStmt(std::make_unique<RetStmt>());
  cur_func_->LinkInitStmt();
  cur_func_ = nullptr;
}

void IRBuilder::visit(FunctionDefClassStmtNode *node) {
  auto &func = functions_.GetFunction(cur_type_->GetIRTypename().substr(1) + "." + node->GetFuncName());
  cur_func_ = func;
  vars_.EnterNewFunc();
  std::vector<std::shared_ptr<Register>> arg_var;
  for (const auto &arg : cur_func_->GetArguments()) {
    if (arg.second == "this") {
      auto arg_val = vars_.CreateVar({cur_type_, 1}, "this", false, false);
      arg_var.push_back(arg_val);
      continue;
    }
    auto arg_val = vars_.CreateVar(arg.first, "arg." + arg.second, false, false);
    arg_var.push_back(arg_val);
    auto arg_addr = vars_.CreateVar({arg.first.GetBaseType(), arg.first.GetDim() + 1}, arg.second, false);
    cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(arg_addr));
    cur_func_->PushStmt(std::make_unique<StoreStmt>(arg_val, arg_addr));
  }
  cur_func_->SetArgumentVars(std::move(arg_var));
  node->GetFunctionBody()->accept(this);
  if (cur_func_->GetReturnType() == kIRVoidType) {
    cur_func_->PushStmt(std::make_unique<RetStmt>());
  } else {
    cur_func_->PushStmt(std::make_unique<Unreachable>());
  }
  cur_func_->LinkInitStmt();
  cur_func_ = nullptr;
}

extern bool generate_cfg;
extern bool mem_to_reg;

void IRBuilder::visit(RootNode *node) {
  for (const auto &def : node->GetDefNodes()) {
    def->accept(this);
  }
  init_func_->PushStmt(std::make_unique<RetStmt>());
  init_func_->LinkInitStmt();
  if (generate_cfg) {
    for (const auto &func : functions_.GetFunctions()) {
      if (func.second->IsBuiltin()) {
        continue;
      }
      ControlFlowGraph cfg(func.second);
      if (mem_to_reg) {
        MemToReg(cfg, vars_);
      }
      AllocaRegister(func.second);
    }
  }
}
