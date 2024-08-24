/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/include/ir/function.h
 * Function: IR node for functions and IR Function Manager
 */
#pragma once

#include "ir/block.h"
#include "ir/type/ir_type.h"

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
  }
  [[nodiscard]] const std::string &GetName() const { return name_; }
  [[nodiscard]] IRType GetReturnType() const { return return_type_; }
  [[nodiscard]] const std::vector<std::pair<IRType, std::string>> &GetArguments() const { return arguments_; }
  std::shared_ptr<Block> &GetCurBlock() { return blocks_.back(); }
  void PushBlock(std::shared_ptr<Block> block) {
    assert(!builtin_);
    blocks_.push_back(std::move(block));
  }
  void PushInitStmt(std::unique_ptr<Stmt> stmt) {
    assert(!builtin_);
    init_block_->Append(std::move(stmt));
  }
  void PushStmt(std::unique_ptr<Stmt> stmt) {
    assert(!builtin_);
    blocks_.back()->Append(std::move(stmt));
  }
  void PrintDeclare() const {
    std::cout << "declare " << return_type_.GetIRTypename() << " @" << name_ << "(";
    for (int i = 0; i < arguments_.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << arguments_[i].first.GetIRTypename() << " " << arguments_[i].second;
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
      std::cout << arguments_[i].first.GetIRTypename() << " " << arguments_[i].second;
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
    auto getString =
        std::make_shared<IRFunction>(kIRStringType, "getString", std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("getString", std::move(getString));
    auto getInt =
        std::make_shared<IRFunction>(kIRIntType, "getInt", std::vector<std::pair<IRType, std::string>>{}, true);
    functions_.emplace("getInt", std::move(getInt));
    auto toString = std::make_shared<IRFunction>(kIRStringType, "toString",
                                                 std::vector<std::pair<IRType, std::string>>{{kIRIntType, "i"}}, true);
    auto printBool =
      std::make_shared<IRFunction>(kIRVoidType, "builtin.printBool", std::vector<std::pair<IRType, std::string>>{{kIRBoolType, "val"}}, true);
    functions_.emplace("builtin.printBool", std::move(printBool));
    auto allocArrayInt =
        std::make_shared<IRFunction>(kIRIntType.ToPtr(), "builtin.allocArrayInt",
                                     std::vector<std::pair<IRType, std::string>>{{kIRIntType, "len"}}, true);
    functions_.emplace("builtin.allocArrayInt", std::move(allocArrayInt));
    auto allocArrayBool =
        std::make_shared<IRFunction>(kIRBoolType.ToPtr(), "builtin.allocArrayBool",
                                     std::vector<std::pair<IRType, std::string>>{{kIRIntType, "len"}}, true);
    functions_.emplace("builtin.allocArrayBool", std::move(allocArrayBool));
    auto strcmp =
      std::make_shared<IRFunction>(kIRIntType, "strcmp", std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str1"}, {kIRStringType, "str2"}}, true);
    functions_.emplace("strcmp", std::move(strcmp));
    auto stringConcatenate = std::make_shared<IRFunction>(
        kIRStringType, "builtin.stringConcatenate",
        std::vector<std::pair<IRType, std::string>>{{kIRStringType, "str1"}, {kIRStringType, "str2"}}, true);
    functions_.emplace("builtin.stringConcatenate", std::move(stringConcatenate));
  }
  void DefineFunction(std::shared_ptr<IRFunction> function) {
    auto res = functions_.emplace(function->GetName(), std::move(function)).second;
    assert(res);
  }
  const std::shared_ptr<IRFunction> &GetFunction(const std::string &name) const { return functions_.at(name); }
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
