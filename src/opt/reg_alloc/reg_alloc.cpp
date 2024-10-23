#include "opt/reg_alloc/reg_alloc.h"

std::unordered_map<std::size_t, std::size_t> machine_reg_id;
std::size_t temp_cnt;

std::shared_ptr<Register> GetMachineRegister(AsmRegister reg) {
  auto reg_id = reg.GetId();
  auto cnt = machine_reg_id[reg_id]++;
  return std::make_shared<MachineRegister>(kIRIntType, "reg" + std::to_string(reg_id) + "." + std::to_string(cnt), false,
                                           false, reg);
}

std::shared_ptr<Register> GetTempRegister() {
  return std::make_shared<Register>(kIRIntType, "regSaveTemp." + std::to_string(temp_cnt++), false, false);
}

void AddMachineRegister(const std::shared_ptr<IRFunction> &func) {
  auto end_block = std::make_shared<Block>("epilogue");
  std::vector<std::pair<std::shared_ptr<Var>, std::weak_ptr<Block>>> phi_info;
  for (const auto &block : func->GetBlocks()) {
    auto &branch_stmt = block->GetBranchStmt();
    if (auto ret_stmt = dynamic_cast<RetStmt *>(branch_stmt.get()); ret_stmt != nullptr) {
      phi_info.emplace_back(ret_stmt->GetRet(), block);
      branch_stmt = std::make_unique<UnconditionalBrStmt>(end_block);
    }
  }
  std::shared_ptr<Register> ret_val{nullptr};
  if (func->GetReturnType() != kIRVoidType) {
    ret_val = std::make_shared<Register>(func->GetReturnType(), "return.value", false, false);
    end_block->AppendPhi(std::make_unique<PhiStmt>(ret_val, std::move(phi_info)));
  }
  auto entry_block = func->GetBlocks()[0];
  std::list<std::unique_ptr<Stmt>> prologue_stmts;
  for (const auto &asm_reg : callee_saved_registers) {
    auto machine_reg = GetMachineRegister(asm_reg);
    auto temp_reg = GetTempRegister();
    prologue_stmts.push_front(std::make_unique<DefStmt>(machine_reg));
    prologue_stmts.push_back(std::make_unique<MoveStmt>(temp_reg, machine_reg));
    end_block->Append(std::make_unique<MoveStmt>(machine_reg, temp_reg));
  }
  end_block->Append(std::make_unique<RetStmt>(ret_val));
  func->PushBlock(std::move(end_block));
  entry_block->GetStmts().splice(entry_block->GetStmts().cbegin(), prologue_stmts);
  for (const auto &block : func->GetBlocks()) {
    auto &stmts = block->GetStmts();
    for (auto it = stmts.begin(); it != stmts.end(); ++it) {
      if (auto call_stmt = dynamic_cast<CallStmt *>(it->get()); call_stmt != nullptr) {
        auto next_it = ++it;
        --it;
        std::list<std::shared_ptr<Stmt>> save_stmts;
        for (const auto &asm_reg : caller_saved_registers) {
          auto temp_reg = GetTempRegister();
          auto machine_reg = GetMachineRegister(asm_reg);
          save_stmts.push_front(std::make_unique<DefStmt>(machine_reg));
          save_stmts.push_back(std::make_unique<MoveStmt>(temp_reg, machine_reg));
          stmts.insert(next_it, std::make_unique<MoveStmt>(machine_reg, temp_reg));
        }
      }
    }
  }
}
