/*
 * Mx Compiler
 * File Name: type.h
 * Identification: ./src/include/utils/scope/type.h
 * Function: Manage type information for AST.
 */

#pragma once

#include <string>
#include <unordered_map>

#include "utils/scope/function.h"

// Enumerate builtin classes and handle Uninitialized situation.
enum TypeInfo : int { kUnknown = 0, kBool, kInt, kVoid, kString, kOther };

class Typename;

class Function;

/**
 * A class used to manage an actual type of a variable/argument.
 * Contains reference to Typename, but also contains the dimision of array.
 */
class Type {
 public:
  Type();
  Type(const Typename &type_name, std::size_t dim = 0, bool any_dim = false);
  [[nodiscard]] std::size_t GetDim() const;
  [[nodiscard]] Typename GetTypename() const;
  void SetDim(std::size_t dim);
  bool operator==(const Type &other) const;
  bool operator!=(const Type &other) const;

 private:
  const Typename &type_name_;
  std::size_t dim_;
  /// Array literal '{}' can be an array of any dimension.
  bool any_dim_;
};

/**
 * A class used to manage the general information of a class.(i.e. when a class is defined)
 */
class Typename {
 public:
  Typename() = default;
  explicit Typename(const std::string &name);
  Typename(const Typename &other) = default;
  Typename(Typename &&other) noexcept = default;
  void AddMember(const std::string &member_name, const Type &type);
  void AddFunction(const std::string &function_name, const Function &function);
  bool HasMember(const std::string &name) const;
  bool HasFunction(const std::string &name) const;
  std::pair<bool, const Type &> GetMember(const std::string &name) const;
  std::pair<bool, const Function &> GetFunction(const std::string &name) const;
  Type CreateType(std::size_t dim = 0) const;
  bool operator==(const Typename &other) const;
  bool operator!=(const Typename &other) const;

 private:
  TypeInfo type_info_{kUnknown};
  const std::string name_{};
  std::unordered_map<std::string, const Type &> member_{};
  std::unordered_map<std::string, const Function &> function_{};
};

Typename GetStringTypename();

const Typename kIntTypename("int");
const Typename kBoolTypename("bool");
const Typename kVoidTypename("void");
const Typename kStringTypename = GetStringTypename();

const Type kIntType(kIntTypename, 0);
const Type kBoolType(kBoolTypename, 0);
const Type kVoidType(kVoidTypename, 0);
const Type kStringType(kStringTypename, 0);