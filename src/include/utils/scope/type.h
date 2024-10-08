/*
 * Mx Compiler
 * File Name: type.h
 * Identification: ./src/include/utils/scope/type.h
 * Function: Manage type information for AST.
 */

#pragma once

#include <memory>
#include <string>
#include <optional>
#include <unordered_map>
#include <vector>

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
  Type(std::shared_ptr<Typename> type_name, std::size_t dim = 0);
  [[nodiscard]] std::size_t GetDim() const;
  [[nodiscard]] const std::shared_ptr<Typename> &GetTypename() const;
  bool operator==(const Type &other) const;
  bool operator!=(const Type &other) const;

 private:
  const std::shared_ptr<Typename> type_name_;
  std::size_t dim_;
};

Type CreateType(std::shared_ptr<Typename> type_name, std::size_t dim = 0);

/**
 * A class used to manage the general information of a class.(i.e. when a class is defined)
 */
class Typename {
 public:
  Typename() = default;
  explicit Typename(std::string name);
  Typename(const Typename &other) = default;
  Typename(Typename &&other) noexcept = default;
  const std::string &GetName() const;
  void AddMember(std::string member_name, Type type);
  void AddFunction(std::string function_name, Function function);
  bool HasMember(const std::string &name) const;
  bool HasFunction(const std::string &name) const;
  std::optional<Type> GetMember(const std::string &name) const;
  std::optional<Function> GetFunction(const std::string &name) const;
  [[nodiscard]] const std::unordered_map<std::string, std::shared_ptr<Type>> &GetMembers() const;
  [[nodiscard]] const std::unordered_map<std::string, std::shared_ptr<Function>> &GetFunctions() const;
  bool operator==(const Typename &other) const;
  bool operator!=(const Typename &other) const;

 private:
  TypeInfo type_info_{kUnknown};
  const std::string name_{};
  std::unordered_map<std::string, std::shared_ptr<Type>> member_{};
  std::unordered_map<std::string, std::shared_ptr<Function>> function_{};
  std::unordered_map<std::string, int> index_{};
};

std::shared_ptr<Typename> GetStringTypename();

std::string GetIRTypename(const Type &type);

const std::shared_ptr<Typename> kIntTypename = std::make_shared<Typename>("int");
const std::shared_ptr<Typename> kBoolTypename = std::make_shared<Typename>("bool");
const std::shared_ptr<Typename> kVoidTypename = std::make_shared<Typename>("void");
const std::shared_ptr<Typename> kStringTypename = GetStringTypename();

const Type kIntType(kIntTypename, 0);
const Type kBoolType(kBoolTypename, 0);
const Type kVoidType(kVoidTypename, 0);
const Type kStringType(kStringTypename, 0);