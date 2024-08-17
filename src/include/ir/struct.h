/*
 * Mx Compiler
 * File Name: struct.h
 * Identification: ./src/include/ir/struct.h
 * Function: IR node for structs
 */
#pragma once

/**
 * IR node for structs
 */
class IRStruct {
 public:
  IRStruct() = delete;
  IRStruct(std::string name, std::vector<Type> members) : name_(std::move(name)), members_(std::move(members)) {}
  void PrintDeclare() const { std::cout << "%struct." << name_ << " = type opaque" << std::endl; }
  void PrintDefinition() const {
    std::cout << "%struct." << name_ << " = type { ";
    for (int i = 0; i < members_.size(); i++) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << GetIRTypename(members_[i]);
    }
    std::cout << "}" << std::endl;
  }

 private:
  const std::string name_;
  const std::vector<Type> members_;
};