/*
 * Mx Compiler
 * File Name: asm_function.h
 * Identification: ./src/include/asm/asm_function.h
 * Function: Functions in assembly
 */
#pragma once

#include "asm/instruction/arith.h"
#include "asm/instruction/instruction.h"
#include "asm/instruction/mem.h"
#include "asm/register/virtual_register.h"
#include "ir/function.h"
#include "ir/stmt/call_stmt.h"
#include "opt/reg_alloc/spill_graph.h"

class BasicBlock {
 public:
  explicit BasicBlock(std::string tag) : tag_(std::move(tag)) {}
  [[nodiscard]] const std::string &GetTag() const { return tag_; }
  std::list<std::unique_ptr<AsmInstruction>> &GetInstructions() { return instructions_; }
  void PushInstruction(std::unique_ptr<AsmInstruction> instruction) { instructions_.push_back(std::move(instruction)); }
  [[nodiscard]] const std::string &GetLabel() const { return tag_; }
  void Print() const {
    std::cout << "." << tag_ << ":" << std::endl;
    for (const auto &instruction : instructions_) {
      instruction->Print();
    }
  }

 private:
  const std::string tag_;
  std::list<std::unique_ptr<AsmInstruction>> instructions_;
};

class AsmFunction {
 public:
  explicit AsmFunction(const std::shared_ptr<IRFunction> &func,
                       std::unordered_map<std::shared_ptr<Register>, AsmRegister> allocation,
                       std::unordered_set<std::shared_ptr<Register>> spilled_regs,
                       std::unordered_map<CallStmt *, FunctionCallInfo> call_info)
      : func_name_(func->GetName()),
        func_(func),
        prologue_(std::make_shared<BasicBlock>(func_name_ + ".prologue")),
        allocation_(std::move(allocation)),
        spilled_regs_(std::move(spilled_regs)),
        call_info_(std::move(call_info)) {
    blocks_index_[func_name_ + ".prologue"] = prologue_;
    auto &arg_var = func->GetArgumentVars();
    for (std::size_t i = 8; i < arg_var.size(); ++i) {
      stack_manager_.ReserveVirtualRegister(arg_var[i]);
    }
    for (std::size_t i = 0; i < std::min(arg_var.size(), 8ul); ++i) {
      if (!allocation_.contains(arg_var[i])) {
        assert(spilled_regs_.contains(arg_var[i]));
        stack_manager_.ReserveVirtualRegister(arg_var[i]);
      }
    }
    for (const auto &reg : spilled_regs_) {
      stack_manager_.ReserveVirtualRegister(reg);
    }
    std::unordered_set<int> used_reg;
    for (const auto &machine_reg : allocation_ | std::views::values) {
      used_reg.insert(machine_reg.GetId());
    }
    for (const auto &reg : caller_saved_registers) {
      if (used_reg.contains(reg.GetId())) {
        backup_caller_list_.insert(reg.GetId());
      }
    }
    backup_callee_list_.insert(ra.GetId());
    for (const auto &reg : callee_saved_registers) {
      if (used_reg.contains(reg.GetId())) {
        backup_callee_list_.insert(reg.GetId());
      }
    }
  }
  std::list<std::shared_ptr<BasicBlock>> &GetBlocks() { return blocks_; }
  [[nodiscard]] const std::string &GetName() const { return func_name_; }
  void PushInstruction(std::unique_ptr<AsmInstruction> instruction) {
    blocks_.back()->PushInstruction(std::move(instruction));
  }
  void PushInstruction(const std::string &block_name, std::unique_ptr<AsmInstruction> instruction) {
    assert(blocks_index_.contains(block_name));
    blocks_index_[block_name]->PushInstruction(std::move(instruction));
  }
  void PushBlock(std::shared_ptr<BasicBlock> block) {
    blocks_index_[block->GetTag()] = block;
    blocks_.push_back(std::move(block));
  }
  [[nodiscard]] std::size_t GetStackSize() const { return stack_size_; }
  void GenerateHeader() {
    for (const auto &used_reg : backup_caller_list_) {
      stack_manager_.ReserveRegister({used_reg});
    }
    for (const auto &used_reg : backup_callee_list_) {
      stack_manager_.ReserveRegister({used_reg});
    }
    stack_size_ = stack_manager_.GetStackSize();
    if (stack_size_ >= 2048) {
      prologue_->PushInstruction(std::make_unique<LoadImmInstruction>(t(0), -1 * stack_size_));
      prologue_->PushInstruction(
          std::make_unique<RegArithInstruction>(sp, sp, t(0), ArithInstruction::ArithType::kAdd));
    } else {
      prologue_->PushInstruction(std::make_unique<ImmArithInstruction>(sp, sp, -1 * static_cast<int>(stack_size_),
                                                                       ArithInstruction::ArithType::kAdd));
    }
    for (const auto &reg : backup_callee_list_) {
      auto offset = stack_manager_.GetMachineRegister(reg);
      if (offset >= 2048) {
        prologue_->PushInstruction(std::make_unique<LoadImmInstruction>(t(0), offset));
        prologue_->PushInstruction(std::make_unique<RegArithInstruction>(t(0), sp, t(0), ArithInstruction::ArithType::kAdd));
        prologue_->PushInstruction(std::make_unique<StoreInstruction>(t(0), reg, 0, MemType::kWord));
      } else {
        prologue_->PushInstruction(
        std::make_unique<StoreInstruction>(sp, reg, stack_manager_.GetMachineRegister(reg), MemType::kWord));
      }
    }
    auto &arg_var = func_->GetArgumentVars();
    int cnt = 0;
    std::vector<std::pair<int, int>> move_list;
    for (int i = 0; i < std::min(static_cast<int>(arg_var.size()), 8); ++i) {
      if (spilled_regs_.contains(arg_var[i])) {
        auto offset = stack_manager_.GetVirtualRegister(arg_var[i]);
        prologue_->PushInstruction(
            std::make_unique<StoreInstruction>(sp, a(i), offset.GetOffset(), offset.GetLen()));
      } else {
        auto pos = allocation_.at(arg_var[i]);
        if (pos == a(i)) {
          continue;
        }
        if (pos.GetId() <= a(7).GetId() && pos.GetId() > a(i).GetId()) {
          move_list.emplace_back(pos.GetId(), t(cnt).GetId());
          prologue_->PushInstruction(std::make_unique<MoveInstruction>(t(cnt), a(i)));
          ++cnt;
        } else {
          prologue_->PushInstruction(std::make_unique<MoveInstruction>(pos, a(i)));
        }
      }
    }
    for (const auto &[dest, val] : move_list) {
      prologue_->PushInstruction(std::make_unique<MoveInstruction>(x(dest), x(val)));
    }
    for (int i = 8; i < arg_var.size(); ++i) {
      if (allocation_.contains(arg_var[i])) {
        auto offset = stack_manager_.GetVirtualRegister(arg_var[i]);
        prologue_->PushInstruction(std::make_unique<LoadInstruction>(allocation_.at(arg_var[i]), sp, offset.GetOffset(), offset.GetLen()));
      }
    }
  }
  void Print() const {
    std::cout << func_name_ << ":" << std::endl;
    prologue_->Print();
    for (const auto &block : blocks_) {
      block->Print();
    }
  }
  StackManager &GetStackManager() { return stack_manager_; }
  [[nodiscard]] auto &GetAllocation() const { return allocation_; }
  [[nodiscard]] auto &GetSpillList() const { return spilled_regs_; }
  [[nodiscard]] auto &GetFunctionCallInfo() const { return call_info_; }
  [[nodiscard]] auto &GetBackupCallerList() const { return backup_caller_list_; }
  [[nodiscard]] auto &GetBackupCalleeList() const { return backup_callee_list_; }

 private:
  const std::string func_name_;
  const std::shared_ptr<IRFunction> func_;
  std::size_t stack_size_{-1u};
  std::shared_ptr<BasicBlock> prologue_{nullptr};
  std::list<std::shared_ptr<BasicBlock>> blocks_;
  std::unordered_map<std::string, std::shared_ptr<BasicBlock>> blocks_index_;
  std::unordered_map<std::shared_ptr<Register>, AsmRegister> allocation_;
  std::unordered_set<std::shared_ptr<Register>> spilled_regs_;
  std::unordered_map<CallStmt *, FunctionCallInfo> call_info_;
  std::unordered_set<int> backup_caller_list_{};
  std::unordered_set<int> backup_callee_list_{};
  StackManager stack_manager_;
};