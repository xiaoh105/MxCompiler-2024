/*
 * Mx Compiler
 * File Name: function.h
 * Identification: ./src/include/ir/function.h
 * Function: IR node for functions
 */
#pragma once

#include "ir/block.h"

#include <complex>

/**
 * IR node for functions
 */
class IRFunction {
 public:
  IRFunction() = delete;
  IRFunction(Type return_type, std::string name, std::vector<std::shared_ptr<Register>> args)
      : return_type_(std::move(return_type)), name_(std::move(name)), arguments_(std::move(args)) {}
  [[nodiscard]] const std::string &GetName() const;
  [[nodiscard]] std::string GetReturnType() const;
  void PushBlock(std::shared_ptr<Block> block) {
    blocks_.push_back(std::move(block));
  }
  std::shared_ptr<Block> &GetLastBlock() {
    return blocks_.back();
  }
  void Print() const {
    std::cout << "define " << GetIRTypename(return_type_) << " @" << name_ << "(";
    for (int i = 0; i < arguments_.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << arguments_[i]->GetType() << " " << arguments_[i]->GetName();
    }
    std::cout << ")" << std::endl;
    std::cout << "{" << std::endl;
    for (const auto &block : blocks_) {
      block->Print();
    }
    std::cout << "}" << std::endl;
  }

 private:
  const Type return_type_;
  const std::string name_;
  const std::vector<std::shared_ptr<Register>> arguments_;
  std::vector<std::shared_ptr<Block>> blocks_;
};