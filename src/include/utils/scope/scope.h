/*
* Mx Compiler
 * File Name: scope.h
 * Identification: ./src/include/utils/scope/scope.h
 * Function: Manage scope information.
 */
#pragma once

#include <unordered_map>

#include "utils/position.hpp"
#include "utils/scope/function.h"
#include "utils/scope/type.h"

class GlobalScope {
public:
  GlobalScope();
  GlobalScope(const GlobalScope &other) = delete;
  GlobalScope(GlobalScope &&other) noexcept = delete;
  void AddType(const std::string &name, const Typename &type, const Position &pos);
  void AddFunction(const std::string &name, const Function &function, const Position &pos);
  [[nodiscard]] bool HasType(const std::string &name) const;
  [[nodiscard]] bool HasFunction(const std::string &name) const;
  std::pair<bool, const Type &> GetType(const std::string &name) const;
  std::pair<bool, const Function &> GetFunction(const std::string &name) const;
  GlobalScope &operator=(const GlobalScope &other) = delete;
  GlobalScope &operator=(GlobalScope &&other) noexcept = delete;

private:
  std::unordered_map<std::string, const Typename &> type_;
  std::unordered_map<std::string, const Function &> function_;
};

class Scope {
public:
  Scope() = delete;
  Scope(const GlobalScope &global_scope, std::unique_ptr<Scope> parent_scope = nullptr);
  Scope(const Scope &other) = delete;
  Scope(Scope &&other) noexcept;
  void DefineVar(const std::string &name, const Type &type, const Position &pos);
  [[nodiscard]] bool HasVar(const std::string &name) const;
  [[nodiscard]] std::pair<bool, const Type &> GetVar(const std::string &name) const;
  Scope &operator=(const Scope &other) = delete;
  Scope &operator=(Scope &&other) noexcept;
  [[nodiscard]] const std::unique_ptr<Scope> &GetParent() const;

private:
  const GlobalScope &global_scope_;
  std::unordered_map<std::string, Type> local_;
  std::unique_ptr<Scope> parent_scope_;
};
