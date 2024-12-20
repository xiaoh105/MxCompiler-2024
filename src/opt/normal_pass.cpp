/**
 * Mx Compiler
 * File Name: normal_pass.cpp
 * Identification: ./src/opt/normal_pass.cpp
 * Function: Passes that make minor adjustments to IR
 */
#include <cmath>

#include "asm/instruction/branch.h"
#include "ir/ir.h"
#include "opt/normal_pass.h"

bool IsPosPow2(int x) { return x > 0 && (x & (x - 1)) == 0; }

int GetPow2(int x) {
  assert(IsPosPow2(x));
  int ret = 0;
  while (x != 1) {
    x >>= 1;
    ++ret;
  }
  return ret;
}

void ArithmeticReduction(const std::shared_ptr<IRFunction> &func, VarManager &var_manager) {
  for (const auto &block : func->GetBlocks()) {
    auto &stmts = block->GetStmts();
    for (auto it = stmts.begin(); it != stmts.end(); ++it) {
      auto &stmt = *it;
      if (auto binary_stmt = dynamic_cast<BinaryStmt *>(stmt.get()); binary_stmt != nullptr) {
        auto &lhs = binary_stmt->GetLeft();
        auto &rhs = binary_stmt->GetRight();
        auto op_type = binary_stmt->GetOpType();
        if (op_type == BinaryStmt::OpType::kMul && std::dynamic_pointer_cast<Register>(lhs) == nullptr &&
            std::dynamic_pointer_cast<Register>(rhs) != nullptr) {
          std::swap(lhs, rhs);
        }
        auto lhs_reg = std::dynamic_pointer_cast<Register>(lhs);
        auto rhs_val = std::dynamic_pointer_cast<Constant>(rhs);
        if (lhs_reg == nullptr || rhs_val == nullptr) {
          continue;
        }
        int imm = 0;
        auto &value = rhs_val->GetValue();
        if (std::holds_alternative<bool>(value)) {
          imm = std::get<bool>(value);
        } else if (std::holds_alternative<int>(value)) {
          imm = std::get<int>(value);
        } else {
          continue;
        }
        if (op_type == BinaryStmt::OpType::kMul) {
          if (imm == 0) {
            lhs = rhs = var_manager.GetInt(0);
            binary_stmt->SetOpType(BinaryStmt::OpType::kAdd);
          } else if (imm == 1) {
            rhs = var_manager.GetInt(0);
            binary_stmt->SetOpType(BinaryStmt::OpType::kAdd);
          } else if (imm == -1) {
            rhs = lhs;
            lhs = var_manager.GetInt(0);
            binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
          } else if (IsPosPow2(imm)) {
            rhs = var_manager.GetInt(GetPow2(imm));
            binary_stmt->SetOpType(BinaryStmt::OpType::kShiftL);
          } else if (IsPosPow2(-imm)) {
            auto tmp = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp, BinaryStmt::OpType::kShiftL, lhs,
                                                          var_manager.GetInt(GetPow2(-imm))));
            lhs = var_manager.GetInt(0);
            rhs = tmp;
            binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
          }
        } else if (op_type == BinaryStmt::OpType::kSDiv && IsPosPow2(imm)) {
          if (imm == 1) {
            rhs = var_manager.GetInt(0);
            binary_stmt->SetOpType(BinaryStmt::OpType::kAdd);
          } else if (imm == -1) {
            rhs = lhs;
            lhs = var_manager.GetInt(0);
            binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
          } else if (IsPosPow2(std::abs(imm))) {
            auto pow = GetPow2(imm);
            auto tmp = lhs;
            if (std::abs(imm) != 2) {
              auto tmp0 = var_manager.CreateTmpVar(kIRIntType, "");
              stmts.insert(it, std::make_unique<BinaryStmt>(tmp0, BinaryStmt::OpType::kShiftR, lhs,
                                                            var_manager.GetInt(pow - 1)));
              tmp = tmp0;
            }
            auto tmp1 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp1, BinaryStmt::OpType::kShiftRLogic, tmp,
                                                          var_manager.GetInt(32 - pow)));
            auto tmp2 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp2, BinaryStmt::OpType::kAdd, tmp1, lhs));
            lhs = tmp2;
            rhs = var_manager.GetInt(pow);
            binary_stmt->SetOpType(BinaryStmt::OpType::kShiftR);
            if (imm < 0) {
              auto res = binary_stmt->GetResult();
              auto tmp_res = var_manager.CreateTmpVar(kIRIntType, "");
              binary_stmt->GetResult() = tmp_res;
              stmts.insert(++it,
                           std::make_unique<BinaryStmt>(res, BinaryStmt::OpType::kSub, var_manager.GetInt(0), tmp_res));
              --it;
            }
          } else {
            long long m = 1 + (1ll << 32) / std::abs(imm);
            long long m_prime = m - (1ll << 32);
            assert(m_prime >= INT32_MIN && m_prime <= INT32_MAX);
            auto tmp1 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp1, BinaryStmt::OpType::kMulH, lhs,
                                                          var_manager.GetInt(static_cast<int>(m_prime))));
            auto tmp2 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp2, BinaryStmt::OpType::kAdd, tmp1, lhs));
            auto x_sign = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(
                it, std::make_unique<BinaryStmt>(x_sign, BinaryStmt::OpType::kShiftR, lhs, var_manager.GetInt(31)));
            if (imm > 0) {
              lhs = tmp2;
              rhs = x_sign;
              binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
            } else {
              auto tmp3 = var_manager.CreateTmpVar(kIRIntType, "");
              stmts.insert(it, std::make_unique<BinaryStmt>(tmp3, BinaryStmt::OpType::kSub, tmp2, x_sign));
              lhs = var_manager.GetInt(0);
              rhs = tmp3;
              binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
            }
          }
        } else if (op_type == BinaryStmt::OpType::kSRem) {
          if (IsPosPow2(imm)) {
            auto pow = GetPow2(imm);
            auto tmp = lhs;
            if (imm != 2) {
              auto tmp0 = var_manager.CreateTmpVar(kIRIntType, "");
              stmts.insert(it, std::make_unique<BinaryStmt>(tmp0, BinaryStmt::OpType::kShiftR, lhs,
                                                            var_manager.GetInt(pow - 1)));
              tmp = tmp0;
            }
            auto tmp1 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp1, BinaryStmt::OpType::kShiftRLogic, tmp,
                                                          var_manager.GetInt(32 - pow)));
            auto tmp2 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it, std::make_unique<BinaryStmt>(tmp2, BinaryStmt::OpType::kAdd, tmp1, lhs));
            auto tmp3 = var_manager.CreateTmpVar(kIRIntType, "");
            stmts.insert(it,
                         std::make_unique<BinaryStmt>(tmp3, BinaryStmt::OpType::kAnd, tmp2, var_manager.GetInt(-imm)));
            rhs = tmp3;
            binary_stmt->SetOpType(BinaryStmt::OpType::kSub);
          }
        }
      }
    }
  }
}

bool DeadCodeElimination(const std::shared_ptr<IRFunction> &func) {
  ControlFlowGraph cfg(func);
  if (cfg.GetRegisters().empty()) {
    return false;
  }
  bool succeed = false;
  auto &reg_manager = cfg.GetRegManager();
  auto &cfg_nodes = cfg.GetCFGNodes();
  for (auto &node : cfg_nodes) {
    auto live_out = node->GetLiveOut();
    auto &br_stmt = node->GetBlock()->GetBranchStmt();
    live_out |= reg_manager.GetSet(br_stmt->GetUse());
    auto &stmts = node->GetBlock()->GetStmts();
    stmts.reverse();
    for (auto it = stmts.begin(); it != stmts.end();) {
      auto &stmt = *it;
      auto def = stmt->GetDef();
      if (def != nullptr && !def->IsGlobal() && !live_out.Contains(def) &&
          dynamic_cast<CallStmt *>(stmt.get()) == nullptr) {
        it = stmts.erase(it);
        succeed = true;
        continue;
      }
      live_out = reg_manager.GetSet(stmt->GetUse()) | live_out - reg_manager.GetSet({def});
      ++it;
    }
    stmts.reverse();
    auto &phi_stmts = node->GetBlock()->GetPhiStmts();
    for (auto it = phi_stmts.begin(); it != phi_stmts.end();) {
      auto &stmt = *it;
      auto def = stmt->GetDef();
      if (def != nullptr && !live_out.Contains(def)) {
        it = stmts.erase(it);
        succeed = true;
        continue;
      }
      ++it;
    }
  }
  return succeed;
}

void RemoveRedundantJump(const std::shared_ptr<AsmFunction> &func) {
  auto &blocks = func->GetBlocks();
  for (auto it = blocks.begin(); it != blocks.end(); ++it) {
    auto next_it = ++it;
    --it;
    if (next_it != blocks.end()) {
      auto &block = *it;
      auto &next_block = *next_it;
      auto j_stmt = dynamic_cast<JInstruction *>(block->GetInstructions().back().get());
      if (j_stmt != nullptr && j_stmt->GetLabel() == next_block->GetLabel()) {
        block->GetInstructions().pop_back();
      }
    }
  }
}

void RemoveRedundantInstruction(const std::shared_ptr<AsmFunction> &func) {
  for (auto &block : func->GetBlocks()) {
    auto &stmts = block->GetInstructions();
    for (auto it = stmts.begin(); it != stmts.end();) {
      auto &stmt = *it;
      if (auto move_stmt = dynamic_cast<MoveInstruction *>(stmt.get()); move_stmt != nullptr) {
        if (move_stmt->GetDestReg() == move_stmt->GetSrcReg()) {
          it = stmts.erase(it);
          continue;
        }
      }
      if (auto imm_arith_stmt = dynamic_cast<ImmArithInstruction *>(stmt.get()); imm_arith_stmt != nullptr) {
        if (imm_arith_stmt->GetDestReg() == imm_arith_stmt->GetSrcReg() && imm_arith_stmt->GetImm() == 0 &&
            (imm_arith_stmt->GetArithType() == ArithInstruction::ArithType::kAdd ||
             imm_arith_stmt->GetArithType() == ArithInstruction::ArithType::kSub)) {
          it = stmts.erase(it);
          continue;
        }
      }
      ++it;
    }
  }
}

bool RemoveDeadInstruction(const std::shared_ptr<AsmFunction> &func) {
  bool succeed = false;
  auto &blocks = func->GetBlocks();
  for (const auto &block : blocks) {
    auto &stmts = block->GetInstructions();
    std::unordered_map<int, std::list<std::unique_ptr<AsmInstruction>>::iterator> stmt_map;
    for (auto it = stmts.begin(); it != stmts.end(); ++it) {
      auto &stmt = *it;
      auto def = stmt->GetDestId();
      auto use = stmt->GetSrcId();
      for (auto reg : use) {
        stmt_map.erase(reg);
      }
      if (auto call_stmt = dynamic_cast<CallInstruction *>(stmt.get()); call_stmt != nullptr) {
        for (auto reg : caller_saved_registers) {
          if (stmt_map.contains(reg.GetId())) {
            succeed = true;
            stmts.erase(stmt_map.at(reg.GetId()));
            stmt_map.erase(reg.GetId());
          }
        }
      } else {
        if (def != -1) {
          if (stmt_map.contains(def)) {
            succeed = true;
            stmts.erase(stmt_map.at(def));
          }
          stmt_map[def] = it;
        }
      }
    }
  }
  return succeed;
}

void DeadAsmElimination(const std::shared_ptr<AsmFunction> &func) {
  RemoveRedundantJump(func);
  RemoveRedundantInstruction(func);
  while (RemoveDeadInstruction(func)) {}
}
