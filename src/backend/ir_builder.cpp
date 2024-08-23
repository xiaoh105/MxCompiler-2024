#include "backend/ir_builder.h"

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
      cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(ret));
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
  cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(tmp_var));
  expr[cur_dim]->accept(this);
  auto &cur_len = expr[cur_dim]->GetVar();
  if (cur_dim + 1 == dim && type == kIRBoolBase) {
    cur_func_->PushStmt(std::make_unique<CallStmt>(functions_.GetFunction("allocArrayBool"), std::vector{{cur_len}}));
    return tmp_var;
  }
  cur_func_->PushStmt(std::make_unique<CallStmt>(functions_.GetFunction("allocArrayInt"), std::vector{{cur_len}}));
  if (cur_dim + 1 == expr.size()) {
    return tmp_var;
  }
  auto i = vars_.CreateTmpVar(kIRIntType.ToPtr(), "arrayIter");
  cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(tmp_var));
  auto cmp = vars_.CreateTmpVar(kIRBoolType, "cmp");
  cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(cmp));
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
  cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(ptr_to_element));
  cur_func_->PushStmt(std::make_unique<GetElementPtrStmt>(ptr_to_element, tmp_var, std::vector<std::shared_ptr<Var>>{vars_.GetInt(0), i}));
  cur_func_->PushStmt(std::make_unique<StoreStmt>(element, ptr_to_element));
  return tmp_var;
}


void IRBuilder::visit(NewPrimaryNode *node) {
  if (node->GetNewType() == NewPrimaryNode::NewType::kNewVar) {
    auto type = classes_.GetType(node->GetTypename());
    auto tmp_var = vars_.CreateTmpVar(IRType(type, node->GetType()->GetDim() + 1), "newTmp");
    cur_func_->PushInitStmt(std::make_unique<AllocaStmt>(tmp_var));
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
