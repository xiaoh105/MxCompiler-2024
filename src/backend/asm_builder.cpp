#include "backend/asm_builder.h"

AsmBuilder::AsmBuilder(FunctionManager functions, VarManager vars, ClassManager classes)
    : functions_(std::move(functions)), vars_(std::move(vars)), classes_(classes) {}

void AsmBuilder::ScanBlock(const std::shared_ptr<Block>& block) {
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
    } else if (auto load_stmt= dynamic_cast<LoadStmt *>(stmt.get()); load_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(load_stmt->GetResult());
    } else if (auto phi_stmt = dynamic_cast<PhiStmt *>(stmt.get()); phi_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(phi_stmt->GetResult());
    }
  }
}

std::unique_ptr<BasicBlock> AsmBuilder::BuildBlock(const std::shared_ptr<Block> &block) {
  auto ret = std::make_unique<BasicBlock>(block->GetLabel());
  for (const auto &stmt : block->GetStmts()) {
    if (auto alloca_stmt = dynamic_cast<AllocaStmt *>(stmt.get()); alloca_stmt != nullptr) {
      cur_func_->GetStackManager().ReserveVirtualRegister(alloca_stmt->GetResult());
    } else if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
      auto op_type = binary_stmt->GetOpType();
      auto &lhs = binary_stmt->GetLeft();
      auto &rhs = binary_stmt->GetRight();
      auto res = cur_func_->GetStackManager().ReserveVirtualRegister(binary_stmt->GetResult());
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
              cur_func_->PushInstruction(
                  std::make_unique<StoreInstruction>(sp, a(0), res.GetOffset(), MemType::kByte));
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
        cur_func_->PushInstruction(
            std::make_unique<StoreInstruction>(sp, a(0), res.GetOffset(), MemType::kWord));
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
      auto l_pos = cur_func_->GetStackManager().GetVirtualRegister(std::dynamic_pointer_cast<Register>(lhs));
      auto r_pos = cur_func_->GetStackManager().GetVirtualRegister(std::dynamic_pointer_cast<Register>(rhs));
      if (l_val == nullptr && r_val == nullptr) {
        cur_func_->PushInstruction(std::make_unique<LoadInstruction>(a(0), sp, l_pos.GetOffset(), l_pos.GetLen()));
        cur_func_->PushInstruction(std::make_unique<LoadInstruction>(a(1), sp, r_pos.GetOffset(), r_pos.GetLen()));
        cur_func_->PushInstruction(std::make_unique<RegArithInstruction>(a(2), a(0), a(1), arith_type));
        cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, a(2), res.GetOffset(), res.GetLen()));
      } else {
        if (l_val == nullptr) {
          std::swap(l_val, r_val);
          std::swap(l_pos, r_pos);
        }
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
          cur_func_->PushInstruction(std::make_unique<LoadInstruction>(a(0), sp, l_pos.GetOffset(), l_pos.GetLen()));
          cur_func_->PushInstruction(std::make_unique<ImmArithInstruction>(a(1), a(0), imm, arith_type));
          cur_func_->PushInstruction(std::make_unique<StoreInstruction>(sp, a(1), res.GetOffset(), res.GetLen()));
      }
    } else if (auto call_stmt = dynamic_cast<CallStmt *>(stmt.get()); call_stmt != nullptr) {

    }
  }
}
