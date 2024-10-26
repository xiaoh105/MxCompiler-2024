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
  type_.emplace("void", kVoidTypename);

  Function print(kVoidType, std::vector<std::string>{"str"}, {kStringType});
  function_.emplace("print", print);
  Function println(kVoidType, std::vector<std::string>{"str"}, {kStringType});
  function_.emplace("println", println);
  Function print_int(kVoidType, std::vector<std::string>{"val"}, {kIntType});
  function_.emplace("printInt", print_int);
  Function println_int(kVoidType, std::vector<std::string>{"val"}, {kIntType});
  function_.emplace("printlnInt", println_int);
  Function get_string(kStringType, {}, {});
  function_.emplace("getString", get_string);
  Function get_int(kIntType, {}, {});
  function_.emplace("getInt", get_int);
  Function to_string(kStringType, std::vector<std::string>{"val"}, {kIntType});
  function_.emplace("toString", to_string);
}

void GlobalScope::AddType(std::string name, std::shared_ptr<Typename> type, const Position &pos) {
  if (function_.contains(name)) {
    throw MultipleDef(pos);
  }
  auto result = type_.emplace(std::move(name), std::move(type)).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

void GlobalScope::AddFunction(std::string name, Function function, const Position &pos) {
  if (type_.contains(name)) {
    throw MultipleDef(pos);
  }
  auto result = function_.emplace(std::move(name), std::move(function)).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

bool GlobalScope::HasType(const std::string &name) const { return type_.contains(name); }

std::optional<std::shared_ptr<Typename>> GlobalScope::GetType(const std::string &name) {
  auto it = type_.find(name);
  return it == type_.end() ? std::nullopt : std::optional(it->second);
}

std::unordered_map<std::string, std::shared_ptr<Typename>> &GlobalScope::GetTypes() { return type_; }

bool GlobalScope::HasFunction(const std::string &name) const { return function_.contains(name); }

std::optional<Function> GlobalScope::GetFunction(const std::string &name) {
  auto it = function_.find(name);
  return it == function_.end() ? std::nullopt : std::optional(it->second);
}

std::unordered_map<std::string, Function> &GlobalScope::GetFunctions() { return function_; }

Scope::Scope(std::unique_ptr<Scope> parent_scope, bool is_class)
    : parent_scope_(std::move(parent_scope)), class_member_(is_class) {
  if (parent_scope_ == nullptr) {
    index_ = std::make_shared<std::unordered_map<std::string, int>>(std::unordered_map<std::string, int>{});
  } else {
    index_ = parent_scope_->index_;
  }
}

Scope::Scope(Scope &&other) noexcept
    : index_(std::move(other.index_)),
      local_(std::move(other.local_)),
      current_index_(std::move(other.current_index_)),
      parent_scope_(std::move(other.parent_scope_)),
      class_member_(other.class_member_) {}

void Scope::DefineVar(std::string name, Type type, const Position &pos) {
  current_index_.emplace(name, index_->operator[](name)++);
  auto result = local_.emplace(std::move(name), std::move(type)).second;
  if (!result) {
    throw MultipleDef(pos);
  }
}

bool Scope::HasVar(const std::string &name) const { return local_.contains(name); }

std::optional<Type> Scope::GetVar(const std::string &name) const {
  auto it = local_.find(name);
  if (it != local_.end()) {
    return it->second;
  }
  return parent_scope_ == nullptr ? std::nullopt : std::optional(parent_scope_->GetVar(name));
}

bool Scope::IsClassMember(const std::string &name) const {
  return local_.contains(name) ? class_member_ : parent_scope_->IsClassMember(name);
}

int Scope::GetIndex(const std::string &name) {
  auto it = current_index_.find(name);
  if (it != current_index_.end()) {
    return it->second;
  }
  return parent_scope_->GetIndex(name);
}

std::unique_ptr<Scope> &Scope::GetParent() { return parent_scope_; }

Scope &Scope::operator=(Scope &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  index_ = std::move(other.index_);
  local_ = std::move(other.local_);
  current_index_ = std::move(other.current_index_);
  class_member_ = other.class_member_;
  parent_scope_ = std::move(other.parent_scope_);
  return *this;
}
