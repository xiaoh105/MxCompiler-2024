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
  GlobalScope(GlobalScope &&other) noexcept = default;
  void AddType(std::string name, std::shared_ptr<Typename> type, const Position &pos);
  void AddFunction(std::string name, Function function, const Position &pos);
  [[nodiscard]] bool HasType(const std::string &name) const;
  [[nodiscard]] bool HasFunction(const std::string &name) const;
  std::optional<std::shared_ptr<Typename>> GetType(const std::string &name);
  std::optional<Function> GetFunction(const std::string &name);
  GlobalScope &operator=(const GlobalScope &other) = delete;
  GlobalScope &operator=(GlobalScope &&other) noexcept = default;

 private:
  std::unordered_map<std::string, std::shared_ptr<Typename>> type_;
  std::unordered_map<std::string, Function> function_;
};

class Scope {
 public:
  Scope() = delete;
  Scope(std::unique_ptr<Scope> parent_scope = nullptr);
  Scope(const Scope &other) = delete;
  Scope(Scope &&other) noexcept;
  void DefineVar(std::string name, Type type, const Position &pos);
  [[nodiscard]] bool HasVar(const std::string &name) const;
  [[nodiscard]] std::optional<Type> GetVar(const std::string &name) const;
  [[nodiscard]] int GetIndex(const std::string &name);
  Scope &operator=(const Scope &other) = delete;
  Scope &operator=(Scope &&other) noexcept;
  std::unique_ptr<Scope> &GetParent();

 private:
  std::shared_ptr<std::unordered_map<std::string, int>> index_;
  std::unordered_map<std::string, Type> local_;
  std::unordered_map<std::string, int> current_index_;
  std::unique_ptr<Scope> parent_scope_;
};
