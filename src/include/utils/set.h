/**
 * Mx Compiler
 * File Name: set.h
 * Identification: ./src/include/utils/set.h
 * Function: A simple set that supports intersect, union and difference.
 */
#pragma once

#include <unordered_map>
#include <semaphore>

#include "utils/bitset.h"

template <class T>
class Set;

template <class T>
class SetManager {
  friend class Set<T>;
public:
  SetManager() = default;
  ~SetManager() = default;
  void AddElement(const std::shared_ptr<T> &item) {
    assert(!map_.contains(item));
    assert(!locked_);
    elements_.push_back(item);
    map_.emplace(item, cnt_++);
  }
  [[nodiscard]] size_t Size() const { return cnt_; }
  Set<T> EmptySet();
  Set<T> WholeSet();
  Set<T> GetSet(const std::vector<std::shared_ptr<T>> &elements);

private:
  std::size_t cnt_{0};
  std::vector<std::shared_ptr<T>> elements_;
  std::unordered_map<std::shared_ptr<T>, std::size_t> map_;
  bool locked_{false};
};

template <class T>
class Set {
 public:
  class iterator {
   public:
    iterator() = delete;
    iterator(Set *base, std::size_t pos) : base_(base), pos_(pos) {
      while (pos_ < base_->manager_->cnt_ && !base_->state_.test(pos_)) {
        ++pos_;
      }
    }
    iterator(const iterator &other) = default;
    iterator &operator=(const iterator &other) = default;
    iterator &operator++() {
      assert(pos_ < base_->manager_->cnt_);
      ++pos_;
      while (pos_ < base_->manager_->cnt_ && !base_->state_.test(pos_)) {
        ++pos_;
      }
      return *this;
    }
    iterator &operator--() {
      assert(pos_ > 0);
      --pos_;
      while (pos_ != 0 && !base_->state_.test(pos_)) {
        --pos_;
      }
      return *this;
    }
    std::shared_ptr<T> operator*() {
      assert(pos_ < base_->manager_->cnt_);
      return base_->manager_->elements_[pos_];
    }
    bool operator==(const iterator &other) const {
      return base_ == other.base_ && pos_ == other.pos_;
    }
    bool operator!=(const iterator &other) const {
      return base_ != other.base_ || pos_ != other.pos_;
    }

   private:
    Set *base_;
    std::size_t pos_;
  };
  Set() : state_(0), manager_(nullptr) {}
  Set(std::size_t size, SetManager<T> *manager, bool whole_set = false) : state_(size), manager_(manager) {
    if (whole_set) {
      state_.set();
    }
  }
  Set(const Set &other) = default;
  Set(Set &&other) = default;
  ~Set() = default;
  [[nodiscard]] bool Contains(const std::shared_ptr<T> &key) const {
    auto it = manager_->map_.find(key);
    assert(it != manager_->map_.end());
    return state_.test(it->second);
  }
  Set &AddElement(const std::shared_ptr<T> &key) {
    assert(manager_->map_.contains(key));
    state_.set(manager_->map_[key]);
    return *this;
  }
  Set &RemoveElement(const std::shared_ptr<T> &key) {
    assert(manager_->map_.contains(key));
    state_.reset(manager_->map_.at(key));
    return *this;
  }
  Set &Intersect(const Set &other) {
    assert(manager_ == other.manager_);
    state_ &= other.state_;
    return *this;
  }
  Set &Union(const Set &other) {
    assert(manager_ == other.manager_);
    state_ |= other.state_;
    return *this;
  }
  Set &Difference(const Set &other) {
    assert(manager_ == other.manager_);
    state_ -= other.state_;
    return *this;
  }
  Set &operator=(const Set &other) = default;
  Set &operator=(Set &&other) = default;
  Set &operator&=(const Set &other) {
    assert(manager_ == other.manager_);
    state_ &= other.state_;
    return *this;
  }
  Set &operator|=(const Set &other) {
    assert(manager_ == other.manager_);
    state_ |= other.state_;
    return *this;
  }
  Set &operator-=(const Set &other) {
    assert(manager_ == other.manager_);
    state_ -= other.state_;
    return *this;
  }
  Set operator&(const Set &other) const {
    auto ret = *this;
    ret &= other;
    return ret;
  }
  Set operator|(const Set &other) const {
    auto ret = *this;
    ret |= other;
    return ret;
  }
  Set operator-(const Set &other) const {
    auto ret = *this;
    ret -= other;
    return ret;
  }
  bool operator==(const Set &other) const {
    return state_ == other.state_ && manager_ == other.manager_;
  }
  bool operator!=(const Set &other) const {
    return state_ != other.state_ || manager_ != other.manager_;
  }
  [[nodiscard]] std::size_t Size() const { return state_.count(); }
  iterator begin() { return iterator(this, 0); }
  iterator cbegin() { return iterator(this, 0); }
  iterator end() { return iterator(this, manager_->cnt_); }
  iterator cend() { return iterator(this, manager_->cnt_); }

 private:
  dynamic_bitset state_;
  SetManager<T> *manager_;
};

template <class T>
Set<T> SetManager<T>::EmptySet() {
  return Set<T>(elements_.size(), this);
}

template <class T>
Set<T> SetManager<T>::WholeSet() {
  return Set<T>(elements_.size(), this, true);
}

template <class T>
Set<T> SetManager<T>::GetSet(const std::vector<std::shared_ptr<T>> &elements) {
  auto ret = EmptySet();
  for (const auto &element : elements) {
    if (element == nullptr) {
      continue;
    }
    ret.AddElement(element);
  }
  return ret;
}
