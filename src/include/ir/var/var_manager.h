/*
 * Mx Compiler
 * File Name: var_manager.h
 * Identification: ./src/include/ir/var/var_manager.h
 * Function: Manager for both registers and constants
 */
#pragma once

#include "ir/var/constant.h"
#include "ir/var/register.h"

/**
 * Manager for registers and constants. All Register/Constant instances MUST be constructed by this class.
 */
class VarManager {
public:
  VarManager() = default;
  const std::shared_ptr<Constant> &GetNull() const { return null_const_; }
  const std::shared_ptr<Constant> &GetBool(bool value) { return value ? true_const_ : false_const_; }
  const std::shared_ptr<Constant> &GetInt(int value) {
    auto it = int_const_.find(value);
    if (it == int_const_.end()) {
      auto ret = std::make_shared<Constant>(value);
      return int_const_.emplace(value, std::move(ret)).first->second;
    }
    return it->second;
  }
  const std::shared_ptr<Register> &CreateVar(IRType type, const std::string &name, bool global, bool lvalue = true) {
    auto ret = std::make_shared<Register>(std::move(type), name, global, lvalue);
    if (global) {
      return global_reg_.emplace(name, std::move(ret)).first->second;
    }
    return local_reg_.emplace(name, std::move(ret)).first->second;
  }
  const std::shared_ptr<Register> &CreateTmpVar(IRType type, const std::string &tag, bool lvalue = false) {
    auto name = (tag.empty() ? "" : tag + ".") + std::to_string(var_index_[tag]++);
    auto ret = std::make_shared<Register>(std::move(type), name, false, lvalue);
    return local_reg_.emplace(std::move(name), std::move(ret)).first->second;
  }
  bool HasVar(const std::string &name) {
    return local_reg_.contains(name) || global_reg_.contains(name);
  }
  const std::shared_ptr<Register> &GetVar(const std::string &name) {
    auto it = local_reg_.find(name);
    if (it != local_reg_.end()) {
      return it->second;
    }
    return global_reg_.find(name)->second;
  }
  void EnterNewFunc() {
    local_reg_.clear();
    var_index_.clear();
  }
  void EnterInitFunc() {
    local_reg_ = std::move(init_local_reg_);
    var_index_ = std::move(init_var_index_);
  }
  void LeaveInitFunc() {
    init_local_reg_ = std::move(local_reg_);
    init_var_index_ = std::move(var_index_);
    local_reg_.clear();
    var_index_.clear();
  }
  const std::shared_ptr<Constant> &GetString(const std::string &value) {
    auto it = string_const_.find(value);
    if (it == string_const_.end()) {
      std::string name = "strConst." + std::to_string(string_const_.size());
      auto var = CreateVar(kIRStringType.ToPtr(), name, true, false);
      var->SetConst(true);
      auto ret = std::make_shared<Constant>(std::move(var), value);
      return string_const_.emplace(value, std::move(ret)).first->second;
    }
    return it->second;
  }
  void DefineGlobal() {
    for (const auto &item : std::ranges::views::values(global_reg_)) {
      if (item->GetName().starts_with("@strConst.")) {
        continue;
      }
      std::cout << item->GetName() << " = global " << item->GetType().RemovePtr().GetIRTypename() << " zeroinitializer" << std::endl;
    }
    for (const auto &[name, item] : string_const_) {
      std::cout << item->GetName() << " = global [" << name.size() + 1 << " x i8] [";
      for (int i = 0; i <= name.size(); ++i) {
        if (i != 0) {
          std::cout << ", ";
        }
        std::cout << (i == name.size() ? "i8 0" : "i8 " + std::to_string(name[i]));
      }
      std::cout << "]" << std::endl;
    }
  }
  void PrintAsm() const {
    std::cout << ".section .bss" << std::endl;
    for (const auto &item : std::ranges::views::values(global_reg_)) {
      if (item->GetName().starts_with("@strConst.")) {
        continue;
      }
      if (item->GetType().RemovePtr() != kIRBoolType) {
        std::cout << ".align 2" << std::endl;
      }
      std::cout << item->GetName().substr(1) << ":" << std::endl;
      std::cout << ".zero " << (item->GetType().RemovePtr() == kIRBoolType ? 1 : 4) << std::endl;
    }
    std::cout << ".section .rodata" << std::endl;
    for (const auto &[name, item] : string_const_) {
      std::cout << item->GetName().substr(1) << ":" << std::endl;
      std::cout << ".asciz \"" << name << "\"" << std::endl;
    }
  }

private:
  std::shared_ptr<Constant> null_const_{std::make_shared<Constant>(nullptr)};
  std::shared_ptr<Constant> true_const_{std::make_shared<Constant>(true)};
  std::shared_ptr<Constant> false_const_{std::make_shared<Constant>(false)};
  std::unordered_map<int, std::shared_ptr<Constant>> int_const_;
  std::unordered_map<std::string, std::shared_ptr<Constant>> string_const_;
  std::unordered_map<std::string, std::shared_ptr<Register>> global_reg_;
  std::unordered_map<std::string, int> var_index_;
  std::unordered_map<std::string, int> init_var_index_;
  std::unordered_map<std::string, std::shared_ptr<Register>> local_reg_;
  std::unordered_map<std::string, std::shared_ptr<Register>> init_local_reg_;
};