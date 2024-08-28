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
#include "ir/function.h"

class BasicBlock {
 public:
  explicit BasicBlock(std::string tag) : tag_(std::move(tag)) {}
  [[nodiscard]] const std::string &GetTag() const { return tag_; }
  void PushInstruction(std::unique_ptr<AsmInstruction> instruction) { instructions_.push_back(std::move(instruction)); }
  void PushPhiInstruction(std::unique_ptr<AsmInstruction> instruction) {
    phi_instructions_.push_back(std::move(instruction));
  }
  void Print() const {
    std::cout << "." << tag_ << ":" << std::endl;
    for (const auto &instruction : instructions_) {
      instruction->Print();
    }
    for (const auto &phi_instruction : phi_instructions_) {
      phi_instruction->Print();
    }
  }

 private:
  const std::string tag_;
  std::vector<std::unique_ptr<AsmInstruction>> instructions_;
  std::vector<std::unique_ptr<AsmInstruction>> phi_instructions_;
};

class AsmFunction {
 public:
  explicit AsmFunction(const std::shared_ptr<IRFunction> &func)
      : func_name_(func->GetName()),
        func_(func),
        prologue_(std::make_shared<BasicBlock>(func_name_ + ".prologue")),
        epilogue_(std::make_shared<BasicBlock>(func_name_ + ".epilogue")) {
    blocks_index_[func_name_ + ".prologue"] = prologue_;
    blocks_index_[func_name_ + ".epilogue"] = epilogue_;
    auto &args = func->GetArguments();
    for (int i = 8; i < args.size(); ++i) {
      stack_manager_.ReserveVirtualRegister(
          std::make_shared<Register>(args[i].first, "arg." + args[i].second, false, false));
    }
    for (int i = 0; i < std::min(static_cast<int>(args.size()), 8); ++i) {
      stack_manager_.ReserveVirtualRegister(std::make_shared<Register>(
          args[i].first, args[i].second == "this" ? "this" : "arg." + args[i].second, false, false));
    }
  }
  [[nodiscard]] const std::string &GetName() const { return func_name_; }
  void PushInstruction(std::unique_ptr<AsmInstruction> instruction) {
    blocks_.back()->PushInstruction(std::move(instruction));
  }
  void PushPhiInstruction(std::unique_ptr<AsmInstruction> instruction) {
    blocks_.back()->PushPhiInstruction(std::move(instruction));
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
    stack_manager_.ReserveRegister(ra);
    stack_size_ = stack_manager_.GetStackSize();
    prologue_->PushInstruction(std::make_unique<ImmArithInstruction>(sp, sp, -1 * static_cast<int>(stack_size_),
                                                                     ArithInstruction::ArithType::kAdd));
    for (const auto &reg : stack_manager_.GetReservedRegs()) {
      prologue_->PushInstruction(
          std::make_unique<StoreInstruction>(sp, AsmRegister{reg.first}, reg.second, MemType::kWord));
      epilogue_->PushInstruction(
          std::make_unique<LoadInstruction>(AsmRegister{reg.first}, sp, reg.second, MemType::kWord));
    }
    auto &args = func_->GetArguments();
    for (int i = 0; i < std::min(static_cast<int>(args.size()), 8); ++i) {
      auto reg = stack_manager_.GetVirtualRegister(std::make_shared<Register>(
          args[i].first, args[i].second == "this" ? "this" : "arg." + args[i].second, false, false));
      prologue_->PushInstruction(std::make_unique<StoreInstruction>(sp, a(i), reg.GetOffset(), reg.GetLen()));
    }
    epilogue_->PushInstruction(
        std::make_unique<ImmArithInstruction>(sp, sp, stack_size_, ArithInstruction::ArithType::kAdd));
    epilogue_->PushInstruction(std::make_unique<RetInstruction>());
  }
  void Print() const {
    std::cout << func_name_ << ":" << std::endl;
    prologue_->Print();
    for (const auto &block : blocks_) {
      block->Print();
    }
    epilogue_->Print();
  }
  StackManager &GetStackManager() { return stack_manager_; }

 private:
  const std::string func_name_;
  const std::shared_ptr<IRFunction> func_;
  std::size_t stack_size_{-1u};
  std::shared_ptr<BasicBlock> prologue_{nullptr};
  std::shared_ptr<BasicBlock> epilogue_{nullptr};
  std::vector<std::shared_ptr<BasicBlock>> blocks_;
  std::unordered_map<std::string, std::shared_ptr<BasicBlock>> blocks_index_;
  StackManager stack_manager_;
};