#include <utility>

#include "backend/asm_builder.h"
#include "frontend/semantic_checker.h"
#include "frontend/symbol_collector.h"
#include "opt/reg_alloc/reg_alloc.h"

void GenerateAsm(RootNode *root) {
  auto [scope, global_scope] = CollectSymbol(root);
  SemanticChecker checker(std::move(scope), std::move(global_scope));
  checker.visit(root);
  IRBuilder builder(std::move(checker.GetGlobalScope()));
  builder.visit(root);
  AsmBuilder asm_builder(std::move(builder.functions_), std::move(builder.vars_), std::move(builder.classes_));
  asm_builder.Print();
}

AsmBuilder::AsmBuilder(FunctionManager functions, VarManager vars, ClassManager classes)
    : functions_(std::move(functions)), vars_(std::move(vars)), classes_(std::move(classes)) {}

void AsmBuilder::Print() {
  Build();
  std::cout << ".section .text" << std::endl;
  for (const auto &function : asm_functions_) {
    std::cout << ".globl " << function.first << std::endl;
    function.second->Print();
  }
  vars_.PrintAsm();
}

void AsmBuilder::Build() {
  for (const auto &func : std::ranges::views::values(functions_.GetFunctions())) {
    if (func->IsBuiltin()) {
      continue;
    }
    ScanFunction(func);
  }
  for (const auto &func : std::ranges::views::values(functions_.GetFunctions())) {
    if (func->IsBuiltin()) {
      continue;
    }
    BuildFunction(func);
  }
}

void AsmBuilder::ScanFunction(const std::shared_ptr<IRFunction> &function) {
  assert(!asm_functions_.contains(function->GetName()));
  auto [spilled, allocation] = AllocateRegister(function);
  auto func = std::make_shared<AsmFunction>(function, allocation, spilled);
  asm_functions_.emplace(function->GetName(), func);
  func->GenerateHeader();
}

void AsmBuilder::BuildFunction(const std::shared_ptr<IRFunction> &function) {
  auto &func = asm_functions_[function->GetName()];
  cur_func_ = func;
  spilled_registers_ = &cur_func_->GetSpillList();
  allocation_ = &cur_func_->GetAllocation();
  for (const auto &block : function->GetBlocks()) {
    BuildBlock(block);
  }
  cur_func_ = nullptr;
  spilled_registers_ = nullptr;
  allocation_ = nullptr;
}

AsmRegister AsmBuilder::GetRegister(const std::shared_ptr<Var> &var, AsmRegister reg_hint) const {
  auto reg = std::dynamic_pointer_cast<Register>(var);
  if (reg == nullptr) {
    return reg_hint;
  }
  if (allocation_->contains(reg)) {
    return allocation_->at(reg);
  }
  assert(reg->IsGlobal() || spilled_registers_->contains(reg));
  return reg_hint;
}

AsmRegister AsmBuilder::LoadRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg_hint) const {
  if (virtual_reg->IsGlobal()) {
    cur_func_->PushInstruction(std::make_unique<LoadAddrInstruction>(reg_hint, virtual_reg->GetName().substr(1)));
    return reg_hint;
  }
  if (allocation_->contains(virtual_reg)) {
    return allocation_->at(virtual_reg);
  }
  assert(spilled_registers_->contains(virtual_reg));
  auto pos = cur_func_->GetStackManager().GetVirtualRegister(virtual_reg);
  if (pos.GetOffset() < -2048 || pos.GetOffset() > 2047) {
    cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(reg_hint, pos.GetOffset()));
    cur_func_->PushInstruction(
        std::make_unique<RegArithInstruction>(reg_hint, sp, reg_hint, ArithInstruction::ArithType::kAdd));
    cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg_hint, reg_hint, 0, pos.GetLen()));
  } else {
    cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg_hint, sp, pos.GetOffset(), pos.GetLen()));
  }
  return reg_hint;
}

void AsmBuilder::StoreRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg,
                               AsmRegister temp_reg) const {
  if (virtual_reg->IsGlobal()) {
    cur_func_->PushInstruction(std::make_unique<LoadAddrInstruction>(temp_reg, virtual_reg->GetName().substr(1)));
    auto mem_type = virtual_reg->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
    cur_func_->PushInstruction(std::make_unique<StoreInstruction>(temp_reg, reg, 0, mem_type));
  } else if (!allocation_->contains(virtual_reg)) {
    assert(spilled_registers_->contains(virtual_reg));
    auto pos = cur_func_->GetStackManager().GetVirtualRegister(virtual_reg);
    if (pos.GetOffset() < -2048 || pos.GetOffset() > 2047) {
      cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(temp_reg, pos.GetOffset()));
      cur_func_->PushInstruction(
          std::make_unique<RegArithInstruction>(temp_reg, sp, temp_reg, ArithInstruction::ArithType::kAdd));
      cur_func_->PushInstruction(std::make_unique<StoreInstruction>(temp_reg, reg, 0, pos.GetLen()));
    } else {
      cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, reg, pos.GetOffset(), pos.GetLen()));
    }
  }
}

void AsmBuilder::StoreRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg) const {
  assert(!virtual_reg->IsGlobal());
  if (!allocation_->contains(virtual_reg)) {
    assert(spilled_registers_->contains(virtual_reg));
    auto pos = cur_func_->GetStackManager().GetVirtualRegister(virtual_reg);
    assert(pos.GetOffset() >= -2048 && pos.GetOffset() <= 2047);
    cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, reg, pos.GetOffset(), pos.GetLen()));
  }
}

void AsmBuilder::BuildBlock(const std::shared_ptr<Block> &block) {
  auto ret = std::make_unique<BasicBlock>(cur_func_->GetName() + "." + block->GetLabel());
  cur_func_->PushBlock(std::move(ret));
  for (const auto &stmt : block->GetStmts()) {
    if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
      auto res = cur_func_->GetStackManager().GetVirtualRegister(alloca_stmt->GetResult());
      auto val = cur_func_->GetStackManager().GetAllocSpace(alloca_stmt->GetResult());
      cur_func_->PushInstruction(
          std::make_unique<ImmArithInstruction>(a(0), sp, val.GetOffset(), ArithInstruction::ArithType::kAdd));
      cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, a(0), res.GetOffset(), res.GetLen()));
    } else if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
      auto op_type = binary_stmt->GetOpType();
      auto &lhs = binary_stmt->GetLeft();
      auto &rhs = binary_stmt->GetRight();
      auto res = binary_stmt->GetResult();
      auto l_val = std::dynamic_pointer_cast<Constant>(lhs);
      auto r_val = std::dynamic_pointer_cast<Constant>(rhs);
      auto dest = GetRegister(res, t(0));
      int imm1 = 1, imm2 = 1;
      int result = 0;
      if (l_val != nullptr) {
        if (l_val->GetType() == kIRBoolType) {
          imm1 = std::get<bool>(l_val->GetValue());
        } else {
          imm1 = std::get<int>(l_val->GetValue());
        }
      }
      if (r_val != nullptr) {
        if (r_val->GetType() == kIRBoolType) {
          imm2 = std::get<bool>(r_val->GetValue());
        } else {
          imm2 = std::get<int>(r_val->GetValue());
        }
      }
      bool force_reg_op = false;
      bool can_swap = true;
      ArithInstruction::ArithType arith_type;
      switch (op_type) {
        case BinaryStmt::OpType::kAdd:
          arith_type = ArithInstruction::ArithType::kAdd;
          result = imm1 + imm2;
          break;
        case BinaryStmt::OpType::kSub:
          arith_type = ArithInstruction::ArithType::kSub;
          result = imm1 - imm2;
          can_swap = false;
          break;
        case BinaryStmt::OpType::kMul:
          arith_type = ArithInstruction::ArithType::kMul;
          result = imm1 * imm2;
          force_reg_op = true;
          break;
        case BinaryStmt::OpType::kAnd:
          arith_type = ArithInstruction::ArithType::kAnd;
          result = imm1 & imm2;
          break;
        case BinaryStmt::OpType::kOr:
          arith_type = ArithInstruction::ArithType::kOr;
          result = imm1 | imm2;
          break;
        case BinaryStmt::OpType::kXor:
          arith_type = ArithInstruction::ArithType::kXor;
          result = imm1 ^ imm2;
          break;
        case BinaryStmt::OpType::kShiftL:
          arith_type = ArithInstruction::ArithType::kShiftL;
          result = imm1 << imm2;
          can_swap = false;
          break;
        case BinaryStmt::OpType::kShiftR:
          arith_type = ArithInstruction::ArithType::kShiftR;
          result = imm1 >> imm2;
          can_swap = false;
          break;
        case BinaryStmt::OpType::kSDiv:
          arith_type = ArithInstruction::ArithType::kDiv;
          result = imm2 == 0 ? 114514 : imm1 / imm2;
          force_reg_op = true;
          break;
        case BinaryStmt::OpType::kSRem:
          arith_type = ArithInstruction::ArithType::kRem;
          result = imm2 == 0 ? 114514 : imm1 % imm2;
          force_reg_op = true;
          break;
        case BinaryStmt::OpType::kUnknown:
          assert(false);
      }
      auto l_reg = std::dynamic_pointer_cast<Register>(lhs);
      auto r_reg = std::dynamic_pointer_cast<Register>(rhs);
      if (l_val != nullptr && r_val != nullptr) {
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(dest, result));
      } else if (l_val == nullptr && r_val == nullptr || force_reg_op || l_val != nullptr && !can_swap) {
        AsmRegister src1 = GetRegister(lhs, t(1));
        if (l_reg != nullptr) {
          LoadRegister(l_reg, t(1));
        } else {
          cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(src1, imm1));
        }
        AsmRegister src2 = GetRegister(rhs, t(2));
        if (r_reg != nullptr) {
          LoadRegister(r_reg, t(2));
        } else {
          cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(src2, imm2));
        }
        cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(dest, src1, src2, arith_type));
      } else if (l_val == nullptr) {
        AsmRegister src1 = LoadRegister(l_reg, t(1));
        if (arith_type == ArithInstruction::ArithType::kSub) {
          arith_type = ArithInstruction::ArithType::kAdd;
          imm2 = -imm2;
        }
        if (imm2 < -2048 || imm2 > 2047) {
          AsmRegister src2 = t(2);
          cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(src2, imm2));
          cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(dest, src1, src2, arith_type));
        } else {
          cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(dest, src1, imm2, arith_type));
        }
      } else {
        AsmRegister src1 = LoadRegister(r_reg, t(1));
        if (arith_type == ArithInstruction::ArithType::kSub) {
          arith_type = ArithInstruction::ArithType::kAdd;
          imm1 = -imm1;
        }
        if (imm1 < -2048 || imm1 > 2047) {
          AsmRegister src2 = t(2);
          cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(src2, imm1));
          cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(dest, src1, src2, arith_type));
        } else {
          cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(dest, src1, imm1, arith_type));
        }
      }
      StoreRegister(res, dest, t(1));
    } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
      auto func = call_stmt->GetFunction().lock();
      auto &args = call_stmt->GetArguments();
      int stack_size = func->IsBuiltin() ? 0 : -static_cast<int>(asm_functions_[func->GetName()]->GetStackSize());
      int stack_offset = 0;
      for (auto arg_used : cur_func_->GetBackupCallerList()) {
        AsmRegister reg(arg_used);
        auto offset = cur_func_->GetStackManager().GetMachineRegister(reg);
        cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, reg, offset, MemType::kWord));
      }
      for (int i = 0; i < args.size(); ++i) {
        auto cur_arg = std::dynamic_pointer_cast<Register>(args[i]);
        if (i < 8) {
          if (cur_arg != nullptr) {
            auto reg = LoadRegister(cur_arg, a(i));
            if (reg != a(i)) {
              cur_func_->PushInstruction(std::make_unique<MoveInstruction>(a(i), reg));
            }
          } else {
            int val;
            auto arg_val = std::dynamic_pointer_cast<Constant>(args[i]);
            if (arg_val->GetType() == kIRBoolType) {
              val = std::get<bool>(arg_val->GetValue());
            } else {
              val = std::get<int>(arg_val->GetValue());
            }
            cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(i), val));
          }
        } else {
          int offset;
          if (cur_arg != nullptr) {
            if (cur_arg->GetType() == kIRBoolType) {
              offset = stack_offset + stack_size;
              stack_offset++;
            } else {
              if (stack_offset % 4 != 0) {
                stack_offset = stack_offset >> 4 << 4;
              }
              offset = stack_offset + stack_size;
              stack_offset += 4;
            }
            auto reg = LoadRegister(cur_arg, t(0));
            auto mem_type = cur_arg->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
            cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, reg, offset, mem_type));
          } else {
            auto cur_val = std::dynamic_pointer_cast<Constant>(args[i]);
            if (cur_val->GetType() == kIRBoolType) {
              offset = stack_offset + stack_size;
              stack_offset++;
            } else {
              if (stack_offset % 4 != 0) {
                stack_offset = stack_offset >> 4 << 4;
              }
              offset = stack_offset + stack_size;
              stack_offset += 4;
            }
            int imm;
            if (cur_val->GetType() == kIRBoolType) {
              imm = std::get<bool>(cur_val->GetValue());
            } else {
              imm = std::get<int>(cur_val->GetValue());
            }
            cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(t(0), imm));
            auto mem_type = cur_val->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
            cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, t(0), offset, mem_type));
          }
        }
      }
      cur_func_->PushInstruction(std::make_unique<CallInstruction>(func->GetName()));
      auto &res = call_stmt->GetResult();
      if (res != nullptr) {
        auto dest = GetRegister(call_stmt->GetResult(), t(0));
        if (dest != a(0)) {
          cur_func_->PushInstruction(std::make_unique<MoveInstruction>(dest, a(0)));
        }
        for (auto item : cur_func_->GetBackupCallerList()) {
          AsmRegister reg(item);
          if (reg == dest) {
            continue;
          }
          auto offset = cur_func_->GetStackManager().GetMachineRegister(reg);
          cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg, sp, offset, MemType::kWord));
        }
        StoreRegister(res, dest, t(1));
      } else {
        for (auto item : cur_func_->GetBackupCallerList()) {
          AsmRegister reg(item);
          auto offset = cur_func_->GetStackManager().GetMachineRegister(reg);
          cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg, sp, offset, MemType::kWord));
        }
      }
    } else if (auto gep_stmt = dynamic_cast<GetElementPtrStmt *>(stmt.get()); gep_stmt != nullptr) {
      auto &index = gep_stmt->GetIndex();
      auto res = gep_stmt->GetResult();
      auto &ir_ptr = gep_stmt->GetPtr();
      auto ptr = ir_ptr;
      if (ptr == nullptr) {
        continue;
      }
      assert(!index.empty() && index.size() <= 2);
      if (index.size() == 2) {
        assert(std::get<int>(std::dynamic_pointer_cast<Constant>(index[0])->GetValue()) == 0);
        int member_id = std::get<int>(std::dynamic_pointer_cast<Constant>(index[1])->GetValue());
        auto type = std::dynamic_pointer_cast<IRCustomType>(ir_ptr->GetType().GetBaseType());
        auto offset = type->GetOffset(member_id);
        auto reg = LoadRegister(ptr, t(1));
        auto dest = GetRegister(res, t(0));
        cur_func_->PushInstruction(
            std::make_unique<ImmArithInstruction>(dest, reg, offset, ArithInstruction::ArithType::kAdd));
        StoreRegister(res, dest, t(1));
      } else {
        auto type = ir_ptr->GetType();
        auto ptr_reg = LoadRegister(ptr, t(1));
        auto dest = GetRegister(res, t(0));
        if (type.RemovePtr() == kIRBoolType) {
          auto index_val = std::dynamic_pointer_cast<Constant>(index[0]);
          if (index_val != nullptr) {
            cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(
                dest, ptr_reg, std::get<int>(index_val->GetValue()), ArithInstruction::ArithType::kAdd));
          } else {
            auto index_reg = LoadRegister(std::dynamic_pointer_cast<Register>(index[0]), t(2));
            cur_func_->PushInstruction(
                std::make_unique<RegArithInstruction>(dest, ptr_reg, index_reg, ArithInstruction::ArithType::kAdd));
          }
          StoreRegister(res, dest, t(2));
        } else {
          auto index_val = std::dynamic_pointer_cast<Constant>(index[0]);
          if (index_val != nullptr) {
            cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(
                dest, ptr_reg, std::get<int>(index_val->GetValue()) << 2, ArithInstruction::ArithType::kAdd));
          } else {
            auto index_reg = LoadRegister(std::dynamic_pointer_cast<Register>(index[0]), t(2));
            cur_func_->PushInstruction(
                std::make_unique<ImmArithInstruction>(t(2), index_reg, 2, ArithInstruction::ArithType::kShiftL));
            cur_func_->PushInstruction(
                std::make_unique<RegArithInstruction>(dest, ptr_reg, t(2), ArithInstruction::ArithType::kAdd));
          }
          StoreRegister(res, dest, t(2));
        }
      }
    } else if (auto icmp_stmt = dynamic_cast<ICmpStmt *>(stmt.get()); icmp_stmt != nullptr) {
      auto &res = icmp_stmt->GetResult();
      auto &lhs = icmp_stmt->GetLhs();
      auto &rhs = icmp_stmt->GetRhs();
      auto lhs_val = std::dynamic_pointer_cast<Constant>(lhs);
      auto rhs_val = std::dynamic_pointer_cast<Constant>(rhs);
      AsmRegister l_reg = GetRegister(lhs, t(1));
      AsmRegister r_reg = GetRegister(rhs, t(2));
      if (lhs_val != nullptr) {
        int val;
        if (lhs_val->GetType() == kIRBoolType) {
          val = std::get<bool>(lhs_val->GetValue());
        } else {
          val = std::get<int>(lhs_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(l_reg, val));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(lhs), t(1));
      }
      if (rhs_val != nullptr) {
        int val;
        if (rhs_val->GetType() == kIRBoolType) {
          val = std::get<bool>(rhs_val->GetValue());
        } else {
          val = std::get<int>(rhs_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(r_reg, val));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(rhs), t(2));
      }
      auto dest = LoadRegister(res, t(0));
      cur_func_->PushInstruction(
          std::make_unique<RegArithInstruction>(dest, l_reg, r_reg, ArithInstruction::ArithType::kSub));
      switch (icmp_stmt->GetOpType()) {
        case ICmpStmt::OpType::kEq:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kEqz));
          break;
        case ICmpStmt::OpType::kNe:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kNez));
          break;
        case ICmpStmt::OpType::kSlt:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kLtz));
          break;
        case ICmpStmt::OpType::kSgt:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kGtz));
          break;
        case ICmpStmt::OpType::kSle:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kGtz));
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kEqz));
          break;
        case ICmpStmt::OpType::kSge:
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kLtz));
          cur_func_->PushInstruction(std::make_unique<CmpZInstruction>(dest, dest, CmpZInstruction::CmpType::kEqz));
          break;
        case ICmpStmt::OpType::kUnknown:
          assert(false);
      }
      StoreRegister(res, dest, t(1));
    } else if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      auto &res = load_stmt->GetResult();
      auto &ptr = load_stmt->GetPtr();
      auto ptr_reg = LoadRegister(ptr, t(1));
      auto mem_type = res->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
      auto dest = LoadRegister(res, t(0));
      cur_func_->PushInstruction(std::make_unique<LoadInstruction>(dest, ptr_reg, 0, mem_type));
      StoreRegister(res, dest, t(2));
    } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
      auto &val = store_stmt->GetValue();
      auto &ptr = store_stmt->GetPtr();
      auto ptr_reg = LoadRegister(ptr, t(1));
      auto val_reg = GetRegister(val, t(2));
      auto mem_type = val->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
      if (auto val_const = std::dynamic_pointer_cast<Constant>(val); val_const != nullptr) {
        int imm;
        if (val_const->GetType() == kIRBoolType) {
          imm = std::get<bool>(val_const->GetValue());
        } else {
          imm = std::get<int>(val_const->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(val_reg, imm));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(val), t(2));
      }
      cur_func_->PushInstruction(std::make_unique<StoreInstruction>(ptr_reg, val_reg, 0, mem_type));
    } else if (auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get()); phi_stmt != nullptr) {
      assert(false);
    } else if (auto move_stmt = dynamic_cast<MoveStmt *>(stmt.get()); move_stmt != nullptr) {
      auto source = move_stmt->GetSrc();
      auto res = move_stmt->GetDest();
      auto dest = GetRegister(res, t(0));
      if (auto src_val = std::dynamic_pointer_cast<Constant>(res); src_val != nullptr) {
        int imm;
        if (src_val->GetType() == kIRBoolType) {
          imm = std::get<bool>(src_val->GetValue());
        } else {
          imm = std::get<int>(src_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(dest, imm));
      } else {
        auto src = LoadRegister(std::dynamic_pointer_cast<Register>(source), t(1));
        cur_func_->PushInstruction(std::make_unique<MoveInstruction>(dest, src));
      }
      StoreRegister(res, dest, t(2));
    }
  }
  auto &branch_stmt = block->GetBranchStmt();
  if (auto br_cond_stmt = dynamic_cast<ConditionalBrStmt *>(branch_stmt.get()); br_cond_stmt != nullptr) {
    auto &cond = br_cond_stmt->GetCondition();
    auto cond_var = std::dynamic_pointer_cast<Register>(cond);
    if (cond_var != nullptr) {
      auto cond_reg = LoadRegister(cond_var, t(2));
      if (cond_reg != t(2)) {
        cur_func_->PushInstruction(std::make_unique<MoveInstruction>(t(2), cond_reg));
      }
    }
  }
  std::list<std::pair<std::shared_ptr<Register>, std::shared_ptr<Register>>> move_list;
  for (const auto &stmt : block->GetMoveStmts()) {
    if (auto move_stmt = dynamic_cast<MoveStmt *>(stmt.get()); move_stmt != nullptr) {
      auto source = move_stmt->GetSrc();
      auto res = move_stmt->GetDest();
      auto dest = GetRegister(res, t(0));
      if (auto src_val = std::dynamic_pointer_cast<Constant>(source); src_val != nullptr) {
        int imm;
        if (src_val->GetType() == kIRBoolType) {
          imm = std::get<bool>(src_val->GetValue());
        } else {
          imm = std::get<int>(src_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(dest, imm));
        StoreRegister(res, dest, t(1));
      } else {
        move_list.emplace_back(res, std::dynamic_pointer_cast<Register>(source));
      }
    } else {
      assert(false);
    }
  }
  std::shared_ptr<Register> temp_dest{nullptr}, temp_cycle{nullptr};
  while (!move_list.empty()) {
    bool remove_link = false;
    for (auto it = move_list.begin(); it != move_list.end(); ++it) {
      auto &move = *it;
      bool has_ref = false;
      for (auto &item : move_list) {
        if (!(item.first == temp_dest && item.second == temp_cycle) && item.second == move.first) {
          has_ref = true;
          break;
        }
      }
      if (has_ref) {
        continue;
      }
      remove_link = true;
      auto dest = move.first;
      auto src = move.second;
      if (dest == temp_dest && src == temp_cycle) {
        if (allocation_->contains(dest)) {
          auto dest_reg = allocation_->at(dest);
          cur_func_->PushInstruction(std::make_unique<MoveInstruction>(dest_reg, t(1)));
        } else {
          StoreRegister(dest, t(1), t(0));
        }
        temp_dest = nullptr;
        temp_cycle = nullptr;
      } else if (allocation_->contains(src)) {
        AsmRegister src_reg = allocation_->at(src);
        if (allocation_->contains(dest)) {
          AsmRegister dest_reg = allocation_->at(dest);
          cur_func_->PushInstruction(std::make_unique<MoveInstruction>(dest_reg, src_reg));
        } else {
          StoreRegister(dest, src_reg, t(0));
        }
      } else {
        LoadRegister(src, t(0));
        if (allocation_->contains(dest)) {
          AsmRegister dest_reg = allocation_->at(dest);
          cur_func_->PushInstruction(std::make_unique<MoveInstruction>(dest_reg, t(0)));
        } else {
          // Consider add stack register coalescing and remove this unsafe part
          if (temp_cycle != nullptr) {
            StoreRegister(dest, t(0));
          } else {
            StoreRegister(dest, t(0), t(1));
          }
        }
      }
      move_list.erase(it);
      break;
    }
    if (remove_link) {
      continue;
    }
    assert(temp_dest == nullptr && temp_cycle == nullptr);
    auto dest = move_list.begin()->first;
    auto src = move_list.begin()->second;
    if (allocation_->contains(src)) {
      auto old_reg = allocation_->at(src);
      cur_func_->PushInstruction(std::make_unique<MoveInstruction>(t(1), old_reg));
    } else {
      LoadRegister(src, t(1));
    }
    temp_cycle = nullptr;
    temp_dest = nullptr;
  }
  if (auto br_cond_stmt = dynamic_cast<ConditionalBrStmt *>(branch_stmt.get()); br_cond_stmt != nullptr) {
    auto &cond = br_cond_stmt->GetCondition();
    auto true_block = br_cond_stmt->GetTrueBlock().lock();
    auto false_block = br_cond_stmt->GetFalseBlock().lock();
    if (auto cond_val = std::dynamic_pointer_cast<Constant>(cond); cond_val != nullptr) {
      if (std::get<bool>(cond_val->GetValue()) == true) {
        cur_func_->PushInstruction(std::make_unique<JInstruction>(cur_func_->GetName() + "." + true_block->GetLabel()));
      } else {
        cur_func_->PushInstruction(
            std::make_unique<JInstruction>(cur_func_->GetName() + "." + false_block->GetLabel()));
      }
    } else {
      cur_func_->PushInstruction(std::make_unique<BranchInstruction>(
          cur_func_->GetName() + "." + true_block->GetLabel(), t(2), zero, BranchInstruction::BranchType::kNe));
      cur_func_->PushInstruction(std::make_unique<JInstruction>(cur_func_->GetName() + "." + false_block->GetLabel()));
    }
  } else if (auto br_uncond_stmt = dynamic_cast<UnconditionalBrStmt *>(branch_stmt.get()); br_uncond_stmt != nullptr) {
    auto dest_block = br_uncond_stmt->GetBlock().lock();
    cur_func_->PushInstruction(std::make_unique<JInstruction>(cur_func_->GetName() + "." + dest_block->GetLabel()));
  } else if (auto ret_stmt = dynamic_cast<RetStmt *>(branch_stmt.get()); ret_stmt != nullptr) {
    auto &ret_var = ret_stmt->GetRet();
    if (ret_var != nullptr) {
      if (auto ret_val = std::dynamic_pointer_cast<Constant>(ret_var); ret_val != nullptr) {
        int imm;
        if (ret_val->GetType() == kIRBoolType) {
          imm = std::get<bool>(ret_val->GetValue());
        } else {
          imm = std::get<int>(ret_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), imm));
      } else {
        auto reg = LoadRegister(std::dynamic_pointer_cast<Register>(ret_var), a(0));
        if (reg != a(0)) {
          cur_func_->PushInstruction(std::make_unique<MoveInstruction>(a(0), reg));
        }
      }
    }
    for (const auto &reg : cur_func_->GetBackupCalleeList()) {
      auto offset = cur_func_->GetStackManager().GetMachineRegister(reg);
      cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg, sp, offset, MemType::kWord));
    }
    auto stack_size = cur_func_->GetStackManager().GetStackSize();
    if (stack_size > 2047) {
      cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(t(0), stack_size));
      cur_func_->PushInstruction(
          std::make_unique<RegArithInstruction>(sp, sp, t(0), ArithInstruction::ArithType::kAdd));
    } else {
      cur_func_->PushInstruction(
          std::make_unique<ImmArithInstruction>(sp, sp, stack_size, ArithInstruction::ArithType::kAdd));
    }
    cur_func_->PushInstruction(std::make_unique<RetInstruction>());
  }
}
