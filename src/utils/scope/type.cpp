/*
 * Mx Compiler
 * File Name: type.cpp
 * Identification: ./src/utils/scope/type.cpp
 * Function: Manage type information for AST.
 */

#include "utils/scope/type.h"
#include "utils/error/semantic_error.hpp"

Typename GetStringTypename() {
  Typename kStr("string");
  Function length(kIntType, {});
  kStr.AddFunction("length", length);
  Function substring(kStringType, {kIntType, kIntType});
  kStr.AddFunction("substring", substring);
  Function parse_int(kIntType, {});
  kStr.AddFunction("parseInt", parse_int);
  Function ord(kIntType, {kIntType});
  kStr.AddFunction("ord", ord);
  return kStr;
}

Typename::Typename(const std::string &name) : name_(name) {
  if (name == "int") {
    type_info_ = kInt;
  } else if (name == "bool") {
    type_info_ = kBool;
  } else if (name == "void") {
    type_info_ = kVoid;
  } else if (name == "string") {
    type_info_ = kString;
  } else {
    type_info_ = kOther;
  }
}

void Typename::AddMember(const std::string &member_name, const Type &type) {
  auto result = member_.emplace(member_name, type).second;
  if (!result) {
    throw UnhandledErr("Add multiple members " + member_name + " for class " + name_ +
                       ", it should be handled in VarDef procedure in classes");
  }
}

void Typename::AddFunction(const std::string &function_name, const Function &function) {
  auto result = function_.emplace(function_name, function).second;
  if (!result) {
    throw UnhandledErr("Add multiple functions " + function_name + " for class " + name_ +
                       ", it should be handled in FuncDef procedure in classes");
  }
}

bool Typename::HasMember(const std::string &name) const { return member_.contains(name); }

std::pair<bool, const Type &> Typename::GetMember(const std::string &name) const {
  auto it = member_.find(name);
  return it == member_.end() ? std::pair{false, Type{}} : std::pair{true, it->second};
}

bool Typename::HasFunction(const std::string &name) const { return function_.contains(name); }

std::pair<bool, const Function &> Typename::GetFunction(const std::string &name) const {
  auto it = function_.find(name);
  return it == function_.end() ? std::pair{false, Function{}} : std::pair{true, it->second};
}

Type Typename::CreateType(std::size_t dim) const { return {*this, dim}; }

bool Typename::operator==(const Typename &other) const { return name_ == other.name_; }

bool Typename::operator!=(const Typename &other) const { return name_ != other.name_; }

Type::Type() : type_name_({}), dim_() {}

Type::Type(const Typename &type_name, std::size_t dim) : type_name_(type_name), dim_(dim) {}

std::size_t Type::GetDim() const { return dim_; }

Typename Type::GetTypename() const { return type_name_; }

bool Type::operator==(const Type &other) const { return type_name_ == other.type_name_ && dim_ == other.dim_; }

bool Type::operator!=(const Type &other) const { return type_name_ != other.type_name_ || dim_ != other.dim_; }
