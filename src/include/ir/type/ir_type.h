/*
 * Mx Compiler
 * File Name: ir_type.h
 * Identification: ./src/include/ir/type/ir_type.h
 * Function: Manage type information for IR.
 */
#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <ranges>
#include <vector>

#include "utils/scope/type.h"

class IRBaseType;

class IRFunction;

class IRType {
 public:
  IRType() = delete;
  IRType(std::shared_ptr<IRBaseType> base, std::size_t dim = 0) : base_(std::move(base)), dim_(dim) {}
  [[nodiscard]] const std::shared_ptr<IRBaseType> &GetBaseType() const { return base_; }
  [[nodiscard]] std::size_t GetDim() const { return dim_; }
  [[nodiscard]] IRType RemovePtr() const {
    assert(dim_ > 0);
    return {base_, dim_ - 1};
  }
  [[nodiscard]] IRType ToPtr() const {
    assert(dim_ == 0);
    return {base_, 1};
  }
  [[nodiscard]] virtual std::pair<int, IRType> GetMember(const std::string &name) const;
  [[nodiscard]] std::string GetIRTypename() const;
  [[nodiscard]] std::string GetElementIRTypename() const;
  [[nodiscard]] bool IsPtrOf(const IRType &other) const;
  [[nodiscard]] std::size_t GetSize() const;
  bool operator==(const IRType &other) const;
  bool operator!=(const IRType &other) const;

 private:
  const std::shared_ptr<IRBaseType> base_{nullptr};
  std::size_t dim_{0};
};

class IRBaseType {
 public:
  IRBaseType() = default;
  virtual ~IRBaseType() = default;
  [[nodiscard]] virtual std::string GetIRTypename() const = 0;
  [[nodiscard]] virtual std::pair<int, IRType> GetMember(const std::string &name) const = 0;
  [[nodiscard]] virtual bool IsBuiltin() const = 0;
  [[nodiscard]] virtual bool IsTrivial() const = 0;
  virtual void Define() const = 0;
  virtual void SetConstructor(const std::shared_ptr<IRFunction> &func) { constructor_ = func; }
  virtual std::weak_ptr<IRFunction> &GetConstructor() { return constructor_; }
  [[nodiscard]] virtual std::size_t GetSize() const = 0;

 private:
  std::weak_ptr<IRFunction> constructor_;
};

class IRIntType final : public IRBaseType {
 public:
  IRIntType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "i32"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return true; }
  [[nodiscard]] std::size_t GetSize() const override { return 4; }
  void SetConstructor(const std::shared_ptr<IRFunction> &func) override { assert(false); }
  void Define() const override {}
};

class IRBoolType final : public IRBaseType {
 public:
  IRBoolType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "i8"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return true; }
  [[nodiscard]] std::size_t GetSize() const override { return 1; }
  void SetConstructor(const std::shared_ptr<IRFunction> &func) override { assert(false); }
  void Define() const override {}
};

class IRStringType final : public IRBaseType {
 public:
  IRStringType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "ptr"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  [[nodiscard]] std::size_t GetSize() const override { return 4; }
  void SetConstructor(const std::shared_ptr<IRFunction> &func) override { assert(false); }
  void Define() const override {}
};

class IRNullType final : public IRBaseType {
 public:
  IRNullType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "ptr"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  [[nodiscard]] std::size_t GetSize() const override { assert(false); }
  void SetConstructor(const std::shared_ptr<IRFunction> &func) override { assert(false); }
  void Define() const override {}
};

class IRVoidType final : public IRBaseType {
 public:
  IRVoidType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "void"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return true; }
  [[nodiscard]] std::size_t GetSize() const override { assert(false); }
  void SetConstructor(const std::shared_ptr<IRFunction> &func) override { assert(false); }
  void Define() const override {}
};

inline const std::shared_ptr<IRBaseType> kIRIntBase = std::make_shared<IRIntType>();
inline const std::shared_ptr<IRBaseType> kIRBoolBase = std::make_shared<IRBoolType>();
inline const std::shared_ptr<IRBaseType> kIRStringBase = std::make_shared<IRStringType>();
inline const std::shared_ptr<IRBaseType> kIRVoidBase = std::make_shared<IRVoidType>();
inline const std::shared_ptr<IRBaseType> kIRNullBase = std::make_shared<IRNullType>();

inline const IRType kIRIntType(kIRIntBase);
inline const IRType kIRBoolType(kIRBoolBase);
inline const IRType kIRStringType(kIRStringBase);
inline const IRType kIRVoidType(kIRVoidBase);
inline const IRType kIRNullType(kIRNullBase);

class IRCustomType final : public IRBaseType {
 public:
  IRCustomType() = delete;
  IRCustomType(std::string name) : class_name_("struct." + std::move(name)) {}
  void SetMembers(std::vector<std::pair<std::string, IRType>> member) {
    member_ = std::move(member);
    for (const auto &item : member_) {
      if (item.second == kIRBoolType) {
        offset_.push_back(size_);
        ++size_;
      } else {
        if (size_ % 4 != 0) {
          size_ -= size_ % 4;
          size_ += 8;
        } else {
          size_ += 4;
        }
        offset_.push_back(size_ - 4);
      }
    }
  }
  [[nodiscard]] std::string GetIRTypename() const override { return "%" + class_name_; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override {
    for (int i = 0; i < member_.size(); ++i) {
      if (name == member_[i].first) {
        return {i, member_[i].second};
      }
    }
    assert(false);
  }
  [[nodiscard]] bool IsBuiltin() const override { return false; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  void Define() const override {
    std::cout << "%" << class_name_ << " = type { ";
    for (int i = 0; i < member_.size(); ++i) {
      if (i != 0) {
        std::cout << ", ";
      }
      std::cout << member_[i].second.GetIRTypename();
    }
    std::cout << " }" << std::endl;
  }
  [[nodiscard]] std::size_t GetSize() const override { return size_; }
  [[nodiscard]] std::size_t GetOffset(int index) const { return offset_[index]; }

 private:
  const std::string class_name_;
  std::vector<std::pair<std::string, IRType>> member_;
  std::vector<std::size_t> offset_;
  std::size_t size_{0};
};

class ClassManager {
 public:
  ClassManager() {
    class_["int"] = kIRIntBase;
    class_["bool"] = kIRBoolBase;
    class_["string"] = kIRStringBase;
    class_["null"] = kIRNullBase;
    class_["void"] = kIRVoidBase;
  }
  std::shared_ptr<IRBaseType> GetType(const std::string &name) {
    assert(class_.contains(name));
    return class_[name];
  }
  IRType CreateType(const std::string &name, std::size_t dim = 0) {
    if ((name == "null" || name == "void") && dim == 0) {
      assert(false);
    }
    return {class_[name], dim};
  }
  IRType CreatePtr(const std::string &name) {
    if (name == "null" || name == "void") {
      assert(false);
    }
    return {class_[name], 1};
  }
  void AddType(const std::unordered_map<std::string, std::shared_ptr<Typename>> &type_name) {
    for (const auto &name : std::views::keys(type_name)) {
      if (name == "int" || name == "bool" || name == "void" || name == "string") {
        continue;
      }
      class_[name] = std::make_shared<IRCustomType>(name);
    }
    for (const auto &type : type_name) {
      if (type.first == "int" || type.first == "bool" || type.first == "void" || type.first == "string") {
        continue;
      }
      auto cur_type = std::dynamic_pointer_cast<IRCustomType>(class_[type.first]);
      std::vector<std::pair<std::string, IRType>> members;
      for (const auto &member : type.second->GetMembers()) {
        auto base = GetType(member.second->GetTypename()->GetName());
        members.emplace_back(member.first, IRType(base, member.second->GetDim() + (base->IsTrivial() ? 0 : 1)));
      }
      cur_type->SetMembers(std::move(members));
    }
  }
  void Define() {
    for (const auto &type : std::views::values(class_)) {
      type->Define();
    }
  }

 private:
  std::unordered_map<std::string, std::shared_ptr<IRBaseType>> class_;
};

inline std::pair<int, IRType> IRType::GetMember(const std::string &name) const { return base_->GetMember(name); }

[[nodiscard]] inline std::string IRType::GetIRTypename() const { return dim_ == 0 ? base_->GetIRTypename() : "ptr"; }

inline std::string IRType::GetElementIRTypename() const {
  assert(dim_ > 0);
  return dim_ - 1 == 0 ? base_->GetIRTypename() : "ptr";
}

inline bool IRType::IsPtrOf(const IRType &other) const { return base_ == other.base_ && dim_ == other.dim_ + 1; }

inline std::size_t IRType::GetSize() const { return dim_ == 0 ? base_->GetSize() : 4; }

inline bool IRType::operator==(const IRType &other) const {
  return base_ == other.base_ && dim_ == other.dim_;
}

inline bool IRType::operator!=(const IRType &other) const {
  return base_->GetIRTypename() != other.base_->GetIRTypename() || dim_ != other.dim_;
}