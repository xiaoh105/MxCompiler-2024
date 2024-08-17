/*
 * Mx Compiler
 * File Name: type.cpp
 * Identification: ./src/utils/scope/type.cpp
 * Function: Manage type information for AST.
 */

#include <ranges>

#include "utils/scope/type.h"
#include "utils/error/semantic_error.hpp"
#include "utils/scope/function.h"

std::shared_ptr<Typename> GetStringTypename() {
  std::shared_ptr<Typename> str = std::make_shared<Typename>("string");
  Type str_type(str, 0);
  Function length(kIntType, {});
  str->AddFunction("length", length);
  Function substring(str_type, {kIntType, kIntType});
  str->AddFunction("substring", substring);
  Function parse_int(kIntType, {});
  str->AddFunction("parseInt", parse_int);
  Function ord(kIntType, {kIntType});
  str->AddFunction("ord", ord);
  return std::move(str);
}

Typename::Typename(std::string name) : name_(std::move(name)) {
  if (name_ == "int") {
    type_info_ = kInt;
  } else if (name_ == "bool") {
    type_info_ = kBool;
  } else if (name_ == "void") {
    type_info_ = kVoid;
  } else if (name_ == "string") {
    type_info_ = kString;
  } else {
    type_info_ = kOther;
  }
}

const std::string &Typename::GetName() const { return name_; }

void Typename::CreateIndex() {
  int index = 0;
  for (const auto &name : std::views::keys(member_)) {
    index_.emplace(name, index++);
  }
}

void Typename::AddMember(std::string member_name, Type type) {
  auto result = member_.emplace(std::move(member_name), std::make_unique<Type>(std::move(type))).second;
  if (!result) {
    throw UnhandledErr("Add multiple members " + member_name + " for class " + name_ +
                       ", it should be handled in VarDef procedure in classes");
  }
}

void Typename::AddFunction(std::string function_name, Function function) {
  auto result = function_.emplace(std::move(function_name), std::make_unique<Function>(std::move(function))).second;
  if (!result) {
    throw UnhandledErr("Add multiple functions " + function_name + " for class " + name_ +
                       ", it should be handled in FuncDef procedure in classes");
  }
}

bool Typename::HasMember(const std::string &name) const { return member_.contains(name); }

std::optional<Type> Typename::GetMember(const std::string &name) const {
  auto it = member_.find(name);
  return it == member_.end() ? std::nullopt : std::optional(*it->second);
}

int Typename::GetMemberIndex(const std::string &name) const { return index_.at(name); }

bool Typename::HasFunction(const std::string &name) const { return function_.contains(name); }

std::optional<Function> Typename::GetFunction(const std::string &name) const {
  auto it = function_.find(name);
  return it == function_.end() ? std::nullopt : std::optional(*it->second);
}

const std::unordered_map<std::string, std::shared_ptr<Type>> &Typename::GetMembers() const { return member_; }

bool Typename::operator==(const Typename &other) const { return name_ == other.name_; }

bool Typename::operator!=(const Typename &other) const { return name_ != other.name_; }

Type CreateType(std::shared_ptr<Typename> type_name, std::size_t dim) { return {std::move(type_name), dim}; }

Type::Type() : type_name_({}), dim_() {}

Type::Type(std::shared_ptr<Typename> type_name, std::size_t dim)
    : type_name_(std::move(type_name)), dim_(dim) {}

std::size_t Type::GetDim() const { return dim_; }

const std::shared_ptr<Typename> &Type::GetTypename() const { return type_name_; }

bool Type::operator==(const Type &other) const {
  return *type_name_ == *other.type_name_ && dim_ == other.dim_;
}

bool Type::operator!=(const Type &other) const {
  return *type_name_ != *other.type_name_ || dim_ != other.dim_;
}

std::string GetIRTypename(const Type &type) {
  if (type.GetDim() > 0 || type == kStringType) {
    return "ptr";
  }
  if (type == kIntType) {
    return "i32";
  }
  if (type == kBoolType) {
    return "i1";
  }
  if (type == kVoidType) {
    return "void";
  }
  return "%struct." + type.GetTypename()->GetName();
}
