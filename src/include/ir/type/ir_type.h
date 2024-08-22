/*
 * Mx Compiler
 * File Name: ir_type.h
 * Identification: ./src/include/ir/type/ir_type.h
 * Function: Manage type information for IR.
 */
#pragma once

#include <cassert>
#include <ranges>

class IRBaseType;

class IRFunction;

class IRType {
 public:
  IRType() = delete;
  IRType(std::shared_ptr<IRBaseType> base, std::size_t dim = 0) : base_(std::move(base)), dim_(dim) {}
  [[nodiscard]] const std::shared_ptr<IRBaseType> &GetBaseType() const { return base_; }
  [[nodiscard]] IRType RemovePtr() const {
    assert(dim_ > 0);
    return {base_, dim_ - 1};
  }
  [[nodiscard]] IRType ToPtr() const {
    assert(dim_ == 0);
    return {base_, 1};
  }
  bool operator==(const IRType &other) const { return base_ == other.base_ && dim_ == other.dim_; }
  bool operator!=(const IRType &other) const { return base_ != other.base_ || dim_ != other.dim_; }
  [[nodiscard]] virtual std::pair<int, IRType> GetMember(const std::string &name) const;
  [[nodiscard]] std::string GetIRTypename() const;
  [[nodiscard]] std::string GetElementIRTypename() const;
  [[nodiscard]] bool IsPtrOf(const IRType &other) const;

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
};

class IRIntType final : public IRBaseType {
 public:
  IRIntType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "i32"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return true; }
  void Define() const override {}
};

class IRBoolType final : public IRBaseType {
 public:
  IRBoolType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "i8"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return true; }
  void Define() const override {}
};

class IRStringType final : public IRBaseType {
 public:
  IRStringType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "ptr"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  void Define() const override {}
};

class IRNullType final : public IRBaseType {
 public:
  IRNullType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "ptr"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  void Define() const override {}
};

class IRVoidType final : public IRBaseType {
 public:
  IRVoidType() = default;
  [[nodiscard]] std::string GetIRTypename() const override { return "void"; }
  [[nodiscard]] std::pair<int, IRType> GetMember(const std::string &name) const override { assert(false); }
  [[nodiscard]] bool IsBuiltin() const override { return true; }
  [[nodiscard]] bool IsTrivial() const override { return false; }
  void Define() const override {}
};

class IRCustomType final : public IRBaseType {
 public:
  IRCustomType() = delete;
  IRCustomType(std::string name) : class_name_(std::move(name)) {}
  void SetMembers(std::vector<std::pair<std::string, IRType>> member) { member_ = std::move(member); }
  [[nodiscard]] std::string GetIRTypename() const override { return class_name_; }
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
    std::cout << class_name_ << " = type { ";
    for (int i = 0; i < member_.size(); ++i) {
      if (i != 0) {
        std::cout << ", ";
      }
      std::cout << member_[i].second.GetIRTypename() << " ";
    }
    std::cout << " }" << std::endl;
  }

 private:
  const std::string class_name_;
  std::vector<std::pair<std::string, IRType>> member_;
};

const std::shared_ptr<IRBaseType> kIRIntBase = std::make_shared<IRIntType>(IRIntType());
const std::shared_ptr<IRBaseType> kIRBoolBase = std::make_shared<IRBoolType>(IRBoolType());
const std::shared_ptr<IRBaseType> kIRStringBase = std::make_shared<IRStringType>(IRStringType());
const std::shared_ptr<IRBaseType> kIRVoidBase = std::make_shared<IRVoidType>(IRVoidType());
const std::shared_ptr<IRBaseType> kIRNullBase = std::make_shared<IRNullType>(IRNullType());

const IRType kIRIntType(kIRIntBase);
const IRType kIRBoolType(kIRBoolBase);
const IRType kIRStringType(kIRStringBase);
const IRType kIRVoidType(kIRVoidBase);
const IRType kIRNullType(kIRNullBase);

class ClassManager {
 public:
  ClassManager() {
    class_["int"] = kIRIntBase;
    class_["bool"] = kIRBoolBase;
    class_["string"] = kIRStringBase;
    class_["null"] = kIRNullBase;
    class_["void"] = kIRVoidBase;
  }
  std::shared_ptr<IRBaseType> GetType(const std::string &name) { return class_[name]; }
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
      class_[name] = std::make_shared<IRCustomType>(name);
    }
    for (const auto &type : type_name) {
      auto cur_type = std::dynamic_pointer_cast<IRCustomType>(class_[type.first]);
      std::vector<std::pair<std::string, IRType>> members;
      for (const auto &member : type.second->GetMembers()) {
        members.emplace_back(member.first,
                             IRType(GetType(member.second->GetTypename()->GetName()), member.second->GetDim()));
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

inline bool IRType::IsPtrOf(const IRType &other) const {
  return base_ == other.base_ && dim_ == other.dim_ + 1;
}
