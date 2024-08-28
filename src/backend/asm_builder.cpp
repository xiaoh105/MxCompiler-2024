#include "backend/asm_builder.h"

#include <utility>

AsmBuilder::AsmBuilder(FunctionManager functions, VarManager vars, ClassManager classes)
    : functions_(std::move(functions)), vars_(std::move(vars)), classes_(std::move(classes)) {}

void AsmBuilder::ScanFunction(const std::shared_ptr<IRFunction> &function) {
  assert(!asm_functions_.contains(function->GetName()));
  auto func = std::make_shared<AsmFunction>(function);
  asm_functions_.emplace(function->GetName(), func);
  cur_func_ = std::move(func);
  for (const auto &block : function) {
    ScanBlock(block);
  }
  cur_func_ = nullptr;
}

void AsmBuilder::ScanBlock(const std::shared_ptr<Block> &block) {
  for (const auto &stmt : block->GetStmts()) {
    if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(alloca_stmt->GetResult());
    } else if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(binary_stmt->GetResult());
    } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
      auto res = call_stmt->GetResult();
      if (res != nullptr) {
        cur_func_->GetStackManager().ReserveVirtualRegister(res);
      }
    } else if (auto gep_stmt = dynamic_cast<GetElementPtrStmt *>(stmt.get()); gep_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(gep_stmt->GetResult());
    } else if (auto icmp_stmt = dynamic_cast<ICmpStmt *>(stmt.get()); icmp_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(icmp_stmt->GetResult());
    } else if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(load_stmt->GetResult());
    } else if (auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get()); phi_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(phi_stmt->GetResult());
    }
  }
}

void AsmBuilder::LoadRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg) {
  if (virtual_reg->IsGlobal()) {
    cur_func_->PushInstruction(std::make_unique<LoadAddrInstruction>(reg, virtual_reg->GetName().substr(1)));
    auto mem_type = virtual_reg->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
    cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg, reg, 0, mem_type));
  } else {
    auto pos = cur_func_->GetStackManager().GetVirtualRegister(virtual_reg);
    cur_func_->PushInstruction(std::make_unique<LoadInstruction>(reg, sp, pos.GetOffset(), pos.GetLen()));
  }
}

void AsmBuilder::StoreRegister(const std::shared_ptr<Register> &virtual_reg, AsmRegister reg) {
  if (virtual_reg->IsGlobal()) {
    cur_func_->PushInstruction(std::make_unique<LoadAddrInstruction>(t(6), virtual_reg->GetName().substr(1)));
    auto mem_type = virtual_reg->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
    cur_func_->PushInstruction(std::make_unique<StoreInstruction>(t(6), reg, 0, mem_type));
  } else {
    auto pos = cur_func_->GetStackManager().GetVirtualRegister(virtual_reg);
    cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, reg, pos.GetOffset(), pos.GetLen()));
  }
}

void AsmBuilder::BuildBlock(const std::shared_ptr<Block> &block) {
  auto ret = std::make_unique<BasicBlock>(block->GetLabel());
  cur_func_->PushBlock(std::move(ret));
  for (const auto &stmt : block->GetStmts()) {
    if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
      auto op_type = binary_stmt->GetOpType();
      auto &lhs = binary_stmt->GetLeft();
      auto &rhs = binary_stmt->GetRight();
      auto res = binary_stmt->GetResult();
      auto l_val = std::dynamic_pointer_cast<Constant>(lhs);
      auto r_val = std::dynamic_pointer_cast<Constant>(rhs);
      if (l_val != nullptr && r_val != nullptr) {
        int val;
        switch (op_type) {
          case BinaryStmt::OpType::kAdd:
            val = std::get<int>(l_val->GetValue()) + std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kSub:
            val = std::get<int>(l_val->GetValue()) - std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kMul:
            val = std::get<int>(l_val->GetValue()) * std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kSDiv:
            val = std::get<int>(l_val->GetValue()) / std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kSRem:
            val = std::get<int>(l_val->GetValue()) % std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kAnd:
            val = std::get<int>(l_val->GetValue()) & std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kOr:
            val = std::get<int>(l_val->GetValue()) | std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kXor:
            if (l_val->GetType() == kIRBoolType) {
              auto tmp = std::get<bool>(l_val->GetValue()) ^ std::get<bool>(r_val->GetValue());
              cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), tmp));
              StoreRegister(res, a(0));
              continue;
            }
            val = std::get<int>(l_val->GetValue()) ^ std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kShiftL:
            val = std::get<int>(l_val->GetValue()) << std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kShiftR:
            val = std::get<int>(l_val->GetValue()) >> std::get<int>(r_val->GetValue());
            break;
          case BinaryStmt::OpType::kUnknown:
            assert(false);
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), val));
        StoreRegister(res, a(0));
        continue;
      }
      ArithInstruction::ArithType arith_type;
      switch (op_type) {
        case BinaryStmt::OpType::kAdd:
          arith_type = ArithInstruction::ArithType::kAdd;
          break;
        case BinaryStmt::OpType::kSub:
          arith_type = ArithInstruction::ArithType::kSub;
          break;
        case BinaryStmt::OpType::kMul:
          arith_type = ArithInstruction::ArithType::kMul;
          break;
        case BinaryStmt::OpType::kAnd:
          arith_type = ArithInstruction::ArithType::kAnd;
          break;
        case BinaryStmt::OpType::kOr:
          arith_type = ArithInstruction::ArithType::kOr;
          break;
        case BinaryStmt::OpType::kXor:
          arith_type = ArithInstruction::ArithType::kXor;
          break;
        case BinaryStmt::OpType::kShiftL:
          arith_type = ArithInstruction::ArithType::kShiftL;
          break;
        case BinaryStmt::OpType::kShiftR:
          arith_type = ArithInstruction::ArithType::kShiftR;
          break;
        case BinaryStmt::OpType::kSDiv:
          arith_type = ArithInstruction::ArithType::kDiv;
          break;
        case BinaryStmt::OpType::kSRem:
          arith_type = ArithInstruction::ArithType::kRem;
          break;
        case BinaryStmt::OpType::kUnknown:
          assert(false);
      }
      auto l_pos = std::dynamic_pointer_cast<Register>(lhs);
      auto r_pos = std::dynamic_pointer_cast<Register>(rhs);
      if (l_val == nullptr) {
        LoadRegister(l_pos, a(0));
        if (r_val == nullptr) {
          LoadRegister(r_pos, a(1));
          cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(a(0), a(0), a(1), arith_type));
        } else {
          int imm;
          if (r_val->GetType() == kIRBoolType) {
            imm = std::get<bool>(r_val->GetValue());
          } else {
            imm = std::get<int>(r_val->GetValue());
          }
          if (arith_type == ArithInstruction::ArithType::kSub) {
            imm = -imm;
            arith_type = ArithInstruction::ArithType::kAdd;
          }
          cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(a(0), a(0), imm, arith_type));
        }
        StoreRegister(res, a(0));
      } else {
        int imm;
        if (l_val->GetType() == kIRBoolType) {
          imm = std::get<bool>(l_val->GetValue());
        } else {
          imm = std::get<int>(l_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), imm));
        LoadRegister(r_pos, a(1));
        cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(a(0), a(0), a(1), arith_type));
        StoreRegister(res, a(0));
      }
    } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {
      auto func = call_stmt->GetFunction().lock();
      auto &args = call_stmt->GetArguments();
      int stack_size = -static_cast<int>(asm_functions_[func->GetName()]->GetStackSize());
      int stack_offset = 0;
      for (int i = 0; i < args.size(); ++i) {
        auto cur_arg = std::dynamic_pointer_cast<Register>(args[i]);
        if (i < 8) {
          LoadRegister(cur_arg, a(i));
        } else {
          int offset;
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
          LoadRegister(cur_arg, t(0));
          auto mem_type = cur_arg->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
          cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, t(0), offset, mem_type));
        }
      }
      cur_func_->PushInstruction(std::make_unique<CallInstruction>(func->GetName()));
    } else if (auto gep_stmt = dynamic_cast<GetElementPtrStmt *>(stmt.get()); gep_stmt != nullptr) {
      auto &index = gep_stmt->GetIndex();
      auto res = gep_stmt->GetResult();
      auto &ir_ptr = gep_stmt->GetPtr();
      auto ptr = ir_ptr;
      assert(!index.empty() && index.size() <= 2);
      if (index.size() == 2) {
        assert(std::get<int>(std::dynamic_pointer_cast<Constant>(index[0])->GetValue()) == 0);
        int member_id = std::get<int>(std::dynamic_pointer_cast<Constant>(index[1])->GetValue());
        auto type = std::dynamic_pointer_cast<IRCustomType>(ir_ptr->GetType().GetBaseType());
        auto offset = type->GetOffset(member_id);
        LoadRegister(ptr, a(0));
        cur_func_->PushInstruction(
            std::make_unique<ImmArithInstruction>(a(0), a(0), offset, ArithInstruction::ArithType::kAdd));
        StoreRegister(res, a(0));
      } else {
        auto type = ir_ptr->GetType();
        LoadRegister(ptr, a(0));
        if (type.RemovePtr() == kIRBoolType) {
          auto index_val = std::dynamic_pointer_cast<Constant>(index[0]);
          if (index_val != nullptr) {
            cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(
                a(0), a(0), std::get<int>(index_val->GetValue()), ArithInstruction::ArithType::kAdd));
          } else {
            auto index_pos =
                cur_func_->GetStackManager().GetVirtualRegister(std::dynamic_pointer_cast<Register>(index[0]));
            cur_func_->PushInstruction(
                std::make_unique<LoadInstruction>(a(1), sp, index_pos.GetOffset(), index_pos.GetLen()));
            cur_func_->PushInstruction(
                std::make_unique<RegArithInstruction>(a(0), a(0), a(1), ArithInstruction::ArithType::kAdd));
          }
          StoreRegister(res, a(0));
        } else {
          auto index_val = std::dynamic_pointer_cast<Constant>(index[0]);
          if (index_val != nullptr) {
            cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(
                a(0), a(0), std::get<int>(index_val->GetValue()) << 2, ArithInstruction::ArithType::kAdd));
          } else {
            auto index_pos =
                cur_func_->GetStackManager().GetVirtualRegister(std::dynamic_pointer_cast<Register>(index[0]));
            cur_func_->PushInstruction(
                std::make_unique<LoadInstruction>(a(1), sp, index_pos.GetOffset(), index_pos.GetLen()));
            cur_func_->PushInstruction(
                std::make_unique<ImmArithInstruction>(a(1), a(1), 2, ArithInstruction::ArithType::kShiftL));
            cur_func_->PushInstruction(
                std::make_unique<RegArithInstruction>(a(0), a(0), a(1), ArithInstruction::ArithType::kAdd));
          }
          StoreRegister(res, a(0));
        }
      }
    } else if (auto icmp_stmt = dynamic_cast<ICmpStmt *>(stmt.get()); icmp_stmt != nullptr) {
      auto &res = icmp_stmt->GetResult();
      auto &lhs = icmp_stmt->GetLhs();
      auto &rhs = icmp_stmt->GetRhs();
      auto tag = tag_index_++;
      auto lhs_val = std::dynamic_pointer_cast<Constant>(lhs);
      if (lhs_val != nullptr) {
        int val;
        if (lhs_val->GetType() == kIRBoolType) {
          val = std::get<bool>(lhs_val->GetValue());
        } else {
          val = std::get<int>(lhs_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), val));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(lhs), a(0));
      }
      auto rhs_val = std::dynamic_pointer_cast<Constant>(rhs);
      if (rhs_val != nullptr) {
        int val;
        if (rhs_val->GetType() == kIRBoolType) {
          val = std::get<bool>(rhs_val->GetValue());
        } else {
          val = std::get<int>(rhs_val->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(1), val));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(rhs), a(1));
      }
      switch (icmp_stmt->GetOpType()) {
        case ICmpStmt::OpType::kEq:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(0),
                                                                         a(1), BranchInstruction::BranchType::kEq));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kNe:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(0),
                                                                         a(1), BranchInstruction::BranchType::kNe));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kSlt:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(0),
                                                                         a(1), BranchInstruction::BranchType::kLt));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kSge:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(0),
                                                                         a(1), BranchInstruction::BranchType::kGe));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kSle:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(1),
                                                                         a(0), BranchInstruction::BranchType::kGe));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kSgt:
          cur_func_->PushInstruction(std::make_unique<BranchInstruction>("branch_true" + std::to_string(tag), a(1),
                                                                         a(0), BranchInstruction::BranchType::kLt));
          cur_func_->PushInstruction(std::make_unique<JInstruction>("branch_false" + std::to_string(tag)));
          break;
        case ICmpStmt::OpType::kUnknown:
          assert(false);
      }
      cur_func_->PushBlock(std::make_shared<BasicBlock>("branch_true" + std::to_string(tag)));
      cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), 1));
      StoreRegister(res, a(0));
      cur_func_->PushInstruction(std::make_unique<JInstruction>(".branch_end" + std::to_string(tag)));
      cur_func_->PushBlock(std::make_shared<BasicBlock>("branch_false" + std::to_string(tag)));
      cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(0), 0));
      StoreRegister(res, a(0));
      cur_func_->PushBlock(std::make_shared<BasicBlock>("branch_end" + std::to_string(tag)));
    } else if (auto load_stmt = dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      auto &res = load_stmt->GetResult();
      auto &ptr = load_stmt->GetPtr();
      LoadRegister(ptr, a(0));
      auto mem_type = res->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
      cur_func_->PushInstruction(std::make_unique<LoadInstruction>(a(0), a(0), 0, mem_type));
      StoreRegister(res, a(0));
    } else if (auto store_stmt = dynamic_cast<StoreStmt *>(stmt.get()); store_stmt != nullptr) {
      auto &val = store_stmt->GetValue();
      auto &ptr = store_stmt->GetPtr();
      LoadRegister(ptr, a(0));
      auto mem_type = val->GetType() == kIRBoolType ? MemType::kByte : MemType::kWord;
      if (auto val_const = std::dynamic_pointer_cast<Constant>(val); val_const != nullptr) {
        int imm;
        if (val_const->GetType() == kIRBoolType) {
          imm = std::get<bool>(val_const->GetValue());
        } else {
          imm = std::get<int>(val_const->GetValue());
        }
        cur_func_->PushInstruction(std::make_unique<LoadImmInstruction>(a(1), imm));
      } else {
        LoadRegister(std::dynamic_pointer_cast<Register>(val), a(1));
      }
      cur_func_->PushInstruction(std::make_unique<StoreInstruction>(a(0), a(1), 0, mem_type));
    } else if (auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get()); phi_stmt != nullptr) {
      auto res = cur_func_->GetStackManager().GetVirtualRegister(phi_stmt->GetResult());
      auto &blocks = phi_stmt->GetBlocks();
      for (const auto &item : blocks) {
        auto var = item.first;
        auto src_block = item.second.lock()->GetLabel();
        if (auto val = std::dynamic_pointer_cast<Constant>(var); val != nullptr) {
          int imm;
          if (val->GetType() == kIRBoolType) {
            imm = std::get<bool>(val->GetValue());
          } else {
            imm = std::get<int>(val->GetValue());
          }
          cur_func_->PushInstruction(src_block, std::make_unique<LoadImmInstruction>(a(0), imm));
          cur_func_->PushInstruction(src_block, std::make_unique<StoreInstruction>(sp, a(0), res.GetOffset(), res.GetLen()));
        } else {
          auto reg = cur_func_->GetStackManager().GetVirtualRegister(std::dynamic_pointer_cast<Register>(val));
          cur_func_->PushInstruction(src_block, std::make_unique<LoadInstruction>(a(0), sp, reg.GetOffset(), reg.GetLen()));
          cur_func_->PushInstruction(src_block, std::make_unique<StoreInstruction>(sp, a(0), res.GetOffset(), res.GetLen()));
        }
      }
    }
  }
  auto &branch_stmt = block->GetBranchStmt();
  if (auto br_cond_stmt = dynamic_cast<ConditionalBrStmt *>(branch_stmt.get()); br_cond_stmt != nullptr) {
    auto &cond = br_cond_stmt->GetCondition();
    auto true_block = br_cond_stmt->GetTrueBlock().lock();
    auto false_block = br_cond_stmt->GetFalseBlock().lock();
    if (auto cond_val = std::dynamic_pointer_cast<Constant>(cond); cond_val != nullptr) {
      if (std::get<bool>(cond_val->GetValue()) == true) {
        cur_func_->PushInstruction(std::make_unique<JInstruction>(true_block->GetLabel()));
      } else {
        cur_func_->PushInstruction(std::make_unique<JInstruction>(false_block->GetLabel()));
      }
    } else {
      auto cond_reg = std::dynamic_pointer_cast<Register>(cond);
      LoadRegister(cond_reg, a(0));
      cur_func_->PushInstruction(std::make_unique<BranchInstruction>(false_block->GetLabel(), a(0), zero, BranchInstruction::BranchType::kEq));
      cur_func_->PushInstruction(std::make_unique<JInstruction>(true_block->GetLabel()));
    }
  } else if (auto br_uncond_stmt = dynamic_cast<UnconditionalBrStmt *>(branch_stmt.get()); br_uncond_stmt != nullptr) {
    auto dest_block = br_uncond_stmt->GetBlock().lock();
    cur_func_->PushInstruction(std::make_unique<JInstruction>(dest_block->GetLabel()));
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
        LoadRegister(std::dynamic_pointer_cast<Register>(ret_var), a(0));
      }
    }
    cur_func_->PushInstruction(std::make_unique<JInstruction>("epilogue"));
  }
}
