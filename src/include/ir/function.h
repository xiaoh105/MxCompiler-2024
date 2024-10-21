/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/include/ir/function.h
 * Function: IR node for functions and IR Function Manager
 */
#pragma once

#include <iostream>

#include "ir/block.h"
#include "ir/type/ir_type.h"
#include "stmt/branch_stmt/br_uncond_stmt.h"

/**
 * IR node for functions
 */
class IRFunction {
 public:
  IRFunction() = delete;
  IRFunction(IRType return_type, std::string name, std::vector<std::pair<IRType, std::string>> args, bool builtin)
      : return_type_(std::move(return_type)),
        name_(std::move(name)),
        arguments_(std::move(args)),
        builtin_(builtin),
        init_block_(std::make_shared<Block>("entry.0")),
        blocks_({init_block_}) {
    ++tag_index_["entry"];
    blocks_.push_back(std::make_shared<Block>("entryEnd.0"));
    ++tag_index_["entryEnd"];
  }
  [[nodiscard]] const std::string &GetName() const { return name_; }
  [[nodiscard]] IRType GetReturnType() const { return return_type_; }
  [[nodiscard]] const std::vector<std::pair<IRType, std::string>> &GetArguments() const { return arguments_; }
  std::shared_ptr<Block> &GetCurBlock() { return blocks_.back(); }
  [[nodiscard]] const std::vector<std::shared_ptr<Block>> &GetBlocks() const { return blocks_; }
  [[nodiscard]] bool IsBuiltin() const { return builtin_; }
  void PushBlock(std::shared_ptr<Block> block) {
    assert(!builtin_);
    blocks_.push_back(std::move(block));
  }
  void PushInitStmt(std::unique_ptr<Stmt> stmt) {
    assert(!builtin_);
    init_block_->Append(std::move(stmt));
  }
  void LinkInitStmt() {
    assert(!builtin_);
    blocks_[0]->Append(std::make_unique<UnconditionalBrStmt>(blocks_[1]));
  }
  void PushStmt(std::unique_ptr<Stmt> stmt) {
    assert(!builtin_);
    blocks_.back()->Append(std::move(stmt));
  }
  void PrintDeclare() const {
    if (!builtin_) {
      return;
    }
    std::cout << "declare " << return_type_.GetIRTypename() << " @" << name_ << "(";
    for (int i = 0; i < arguments_.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << arguments_[i].first.GetIRTypename();
    }
    std::cout << ")" << std::endl;
  }
  void PrintDefine() const {
    if (builtin_) {
      return;
    }
    std::cout << "define " << return_type_.GetIRTypename() << " @" << name_ << "(";
    for (int i = 0; i < arguments_.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      if (arguments_[i].second != "this") {
        std::cout << arguments_[i].first.GetIRTypename() << " %arg." << arguments_[i].second;
      } else {
        std::cout << arguments_[i].first.GetIRTypename() << " %" << arguments_[i].second;
      }
    }
    std::cout << ")" << std::endl;
    std::cout << "{" << std::endl;
    for (const auto &block : blocks_) {
      block->Print();
    }
    std::cout << "}" << std::endl;
  }
  std::string AssignTag(const std::string &name) { return name + "." + std::to_string(tag_index_[name]++); }

 private:
  const IRType return_type_;
  const std::string name_;
  const std::vector<std::pair<IRType, std::string>> arguments_;
  bool builtin_;
  std::shared_ptr<Block> init_block_;
  std::vector<std::shared_ptr<Block>> blocks_;
  std::unordered_map<std::string, int> tag_index_;
};

/**
 * Manager for all functions in IR. All IRFunction instances MUST be constructed by this class.
 */
class FunctionManager {
 public:
  FunctionManager() {
    auto print = std::make_shared<IRFunction>(
        kIRVoidType, "print", std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str"}}, true);
    functions_.emplace("print", std::move(print));
    auto println = std::make_shared<IRFunction>(
        kIRVoidType, "println", std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str"}}, true);
    functions_.emplace("println", std::move(println));
    auto printInt = std::make_shared<IRFunction>(kIRVoidType, "printInt",
                                                 std::vector<std::pair<IRType, std::string>>{{kIRIntType, "n"}}, true);
    functions_.emplace("printInt", std::move(printInt));
    auto printlnInt = std::make_shared<IRFunction>(
        kIRVoidType, "printlnInt", std::vector<std::pair<IRType, std::string>>{{kIRIntType, "n"}}, true);
    functions_.emplace("printlnInt", std::move(printlnInt));
    auto getString = std::make_shared<IRFunction>(kIRStringType.ToPtr(), "getString",
                                                  std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("getString", std::move(getString));
    auto getInt =
        std::make_shared<IRFunction>(kIRIntType, "getInt", std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("getInt", std::move(getInt));
    auto toString = std::make_shared<IRFunction>(kIRStringType.ToPtr(), "toString",
                                                 std::vector<std::pair<IRType, std::string>>{{kIRIntType, "i"}}, true);
    functions_.emplace("toString", std::move(toString));
    auto length =
        std::make_shared<IRFunction>(kIRIntType, "ptr.length", std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("ptr.length", std::move(length));
    auto substring = std::make_shared<IRFunction>(
        kIRStringType.ToPtr(), "ptr.substring",
        std::vector<std::pair<IRType, std::string>>{{kIRIntType, "start"}, {kIRIntType, "end"}}, true);
    functions_.emplace("ptr.substring", std::move(substring));
    auto parseInt =
        std::make_shared<IRFunction>(kIRIntType, "ptr.parseInt", std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("ptr.parseInt", std::move(parseInt));
    auto ord = std::make_shared<IRFunction>(kIRIntType, "ptr.ord",
                                            std::vector<std::pair<IRType, std::string>>{{kIRIntType, "pos"}}, true);
    functions_.emplace("ptr.ord", std::move(ord));
    auto getSize = std::make_shared<IRFunction>(
        kIRIntType, "builtin.getSize", std::vector<std::pair<IRType, std::string>>{{kIRIntType.ToPtr(), "ptr"}}, true);
    functions_.emplace("builtin.getSize", std::move(getSize));
    auto printBool = std::make_shared<IRFunction>(
        kIRVoidType, "builtin.printBool", std::vector<std::pair<IRType, std::string>>{{kIRBoolType, "val"}}, true);
    functions_.emplace("builtin.printBool", std::move(printBool));
    auto allocArray =
        std::make_shared<IRFunction>(kIRIntType.ToPtr(), "builtin.allocArray",
                                     std::vector<std::pair<IRType, std::string>>{{kIRIntType, "len"}}, true);
    functions_.emplace("builtin.allocArray", std::move(allocArray));
    auto strcmp = std::make_shared<IRFunction>(
        kIRIntType, "strcmp",
        std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str1"}, {kIRStringType, "str2"}}, true);
    functions_.emplace("strcmp", std::move(strcmp));
    auto malloc = std::make_shared<IRFunction>(kIRIntType.ToPtr(), "malloc",
                                               std::vector<std::pair<IRType, std::string>>{{kIRIntType, "size"}}, true);
    functions_.emplace("malloc", std::move(malloc));
    auto stringConcatenate = std::make_shared<IRFunction>(
        kIRStringType, "builtin.stringConcatenate",
        std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str1"}, {kIRStringType, "str2"}}, true);
    functions_.emplace("builtin.stringConcatenate", std::move(stringConcatenate));
  }
  void DefineFunction(const std::shared_ptr<IRFunction> &function) {
    functions_.emplace(function->GetName(), function).second;
  }
  [[nodiscard]] bool HasFunction(const std::string &name) const { return functions_.contains(name); }
  const std::shared_ptr<IRFunction> &GetFunction(const std::string &name) const { return functions_.at(name); }
  [[nodiscard]] const std::unordered_map<std::string, std::shared_ptr<IRFunction>> &GetFunctions() const { return functions_; }
  void PrintDeclare() {
    for (const auto &func : std::ranges::views::values(functions_)) {
      func->PrintDeclare();
    }
  }
  void PrintDefine() {
    for (const auto &func : std::ranges::views::values(functions_)) {
      func->PrintDefine();
    }
  }

 private:
  std::unordered_map<std::string, std::shared_ptr<IRFunction>> functions_;
};
