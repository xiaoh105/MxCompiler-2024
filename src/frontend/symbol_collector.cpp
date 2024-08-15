/*
 * Mx Compiler
 * File Name: symbol_collector.cpp
 * Identification: ./src/frontend/symbol_collector.cpp
 * Function: Scan the parser tree and collect all global symbols
 */
#include "frontend/symbol_collector.h"
#include "ast/ast.h"
#include "frontend/class_collector.h"

#include "utils/error/semantic_error.hpp"

SymbolCollector::SymbolCollector() : scope_(nullptr) {}

void SymbolCollector::CollectClass(RootNode *node) {
  ClassCollector collector(global_scope_);
  collector.visit(node);
}

void SymbolCollector::visit(RootNode *node) {
  for (auto &def : node->GetDefNodes()) {
    def->accept(this);
  }
}

void SymbolCollector::visit(ClassDefNode *node) {
  auto &name = node->GetClassName();
  current_class_ = global_scope_.GetType(name).value();
  for (const auto &stmt : node->GetClassStmt()) {
    stmt->accept(this);
  }
  current_class_->CreateIndex();
  current_class_ = nullptr;
}

void SymbolCollector::visit(FunctionDefNode *node) {
  auto &func_name = node->GetFunctionName();
  auto &[ret_name, dim] = node->GetReturnType();
  auto return_typename = global_scope_.GetType(ret_name);
  if (!return_typename.has_value()) {
    throw UndefinedIdentifier(node->GetPos());
  }
  auto return_type = CreateType(std::move(return_typename.value()), dim);
  std::vector<Type> args;
  for (const auto &item : node->GetArguments()) {
    auto [arg_name, arg_dim] = item.first;
    auto arg_typename = global_scope_.GetType(arg_name);
    if (!arg_typename.has_value()) {
      throw UndefinedIdentifier(node->GetPos());
    }
    auto arg_type = CreateType(std::move(arg_typename.value()), arg_dim);
    args.push_back(std::move(arg_type));
  }
  Function func(std::move(return_type), std::move(args));
  if (scope_.HasVar(func_name)) {
    throw MultipleDef(node->GetPos());
  }
  global_scope_.AddFunction(func_name, func, {node->GetPos()});
}

void SymbolCollector::visit(ConstructorClassStmtNode *node) {
  auto &name = node->GetType();
  if (name != current_class_->GetName()) {
    throw InvalidContructor(node->GetPos());
  }
  if (current_class_->HasFunction(name)) {
    throw MultipleDef(node->GetPos());
  }
  Function constructor(kVoidType, {});
  current_class_->AddFunction(name, std::move(constructor));
}

void SymbolCollector::visit(FunctionDefClassStmtNode *node) {
  auto &name = node->GetFuncName();
  if (name == current_class_->GetName()) {
    throw InvalidContructor(node->GetPos());
  }
  if (current_class_->HasFunction(name)) {
    throw MultipleDef(node->GetPos());
  }
  auto &[return_name, return_dim] = node->GetReturnType();
  auto return_typename = global_scope_.GetType(return_name);
  if (!return_typename.has_value()) {
    throw InvalidType(node->GetPos());
  }
  auto return_type = CreateType(std::move(return_typename.value()), return_dim);
  auto &args = node->GetArguments();
  std::vector<Type> ret_args;
  for (const auto &item : args) {
    auto &[arg_name, arg_dim] = item.first;
    auto arg_typename = global_scope_.GetType(arg_name);
    if (!arg_typename.has_value()) {
      throw InvalidType(node->GetPos());
    }
    auto arg_type = CreateType(std::move(arg_typename.value()), arg_dim);
    ret_args.push_back(std::move(arg_type));
  }
  Function func(std::move(return_type), std::move(ret_args));
  current_class_->AddFunction(name, func);
}

void SymbolCollector::visit(VarDefClassStmtNode *node) {
  auto &[type_str, dim] = node->GetTypeName();
  auto type_name = global_scope_.GetType(type_str);
  if (!type_name.has_value()) {
    throw InvalidType(node->GetPos());
  }
  auto type = CreateType(std::move(type_name.value()), dim);
  auto &var_name = node->GetMemberName();
  for (const auto &item : var_name) {
    if (current_class_->HasMember(item)) {
      throw MultipleDef({node->GetPos()});
    }
    current_class_->AddMember(item, type);
  }
}

std::pair<Scope, GlobalScope> CollectSymbol(RootNode *node) {
  SymbolCollector collector;
  collector.CollectClass(node);
  collector.visit(node);
  return {std::move(collector.scope_), std::move(collector.global_scope_)};
}
