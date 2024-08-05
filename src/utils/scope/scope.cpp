/*
 * Mx Compiler
 * File Name: scope.cpp
 * Identification: ./src/utils/scope/scope.h
 * Function: Manage scope information.
 */
#include "utils/scope/scope.h"
#include "utils/error/semantic_error.hpp"

GlobalScope::GlobalScope() {
  type_.emplace("int", kIntTypename);
  type_.emplace("bool", kBoolTypename);
  type_.emplace("string", kStringTypename);

  Function print(kVoidType, {kStringType});
  function_.emplace("print", print);
  Function println(kVoidType, {kStringType});
  function_.emplace("println", println);
  Function print_int(kVoidType, {kIntType});
  function_.emplace("printInt", print_int);
  Function println_int(kVoidType, {kIntType});
  function_.emplace("printlnInt", println_int);
  Function get_string(kStringType, {});
  function_.emplace("getString", get_string);
  Function get_int(kIntType, {});
  function_.emplace("getInt", get_int);
  Function to_string(kStringType, {kIntType});
  function_.emplace("toString", to_string);
}

void GlobalScope::AddType(const std::string &name, const Typename &type, const Position &pos) {
  if (function_.contains(name)) {
    throw MultipleDef(pos);
  }
  auto result = type_.emplace(name, type).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

void GlobalScope::AddFunction(const std::string &name, const Function &function, const Position &pos) {
  if (type_.contains(name)) {
    throw MultipleDef(pos);
  }
  auto result = function_.emplace(name, function).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

bool GlobalScope::HasType(const std::string &name) const { return type_.contains(name); }

std::pair<bool, const Type &> GlobalScope::GetType(const std::string &name) const {
  using return_type = std::pair<bool, const Type &>;
  auto it = type_.find(name);
  return it == type_.end() ? return_type{false, {}} : return_type{true, it->second};
}

bool GlobalScope::HasFunction(const std::string &name) const { return function_.contains(name); }

std::pair<bool, const Function &> GlobalScope::GetFunction(const std::string &name) const {
  using return_type = std::pair<bool, const Function &>;
  auto it = function_.find(name);
  return it == function_.end() ? return_type{false, {}} : return_type{true, it->second};
}

Scope::Scope(const GlobalScope &global_scope, std::unique_ptr<Scope> parent_scope)
    : global_scope_(global_scope), parent_scope_(std::move(parent_scope)) {}

Scope::Scope(Scope &&other) noexcept
    : global_scope_(other.global_scope_),
      local_(std::move(other.local_)),
      parent_scope_(std::move(other.parent_scope_)) {}

void Scope::DefineVar(const std::string &name, const Type &type, const Position &pos) {
  if (global_scope_.HasFunction(name)) {
    throw MultipleDef(pos);
  }
  auto result = local_.emplace(name, type).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

bool Scope::HasVar(const std::string &name) const { return local_.contains(name); }

std::pair<bool, const Type &> Scope::GetVar(const std::string &name) const {
  using return_type = std::pair<bool, const Type &>;
  auto it = local_.find(name);
  if (it != local_.end()) {
    return {true, it->second};
  }
  return parent_scope_ == nullptr ? return_type{false, {}} : parent_scope_->GetVar(name);
}

const std::unique_ptr<Scope> &Scope::GetParent() const { return parent_scope_; }

Scope &Scope::operator=(Scope &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  local_ = std::move(other.local_);
  parent_scope_ = std::move(other.parent_scope_);
  return *this;
}
