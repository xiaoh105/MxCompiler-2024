/**
 * Mx Compiler
 * File Name: bitset.h
 * Identification: ./src/include/utils/bitset.h
 * Function: A simple bitset whose size can be determined at runtime.
 */
#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <string>

/**
 * A simple bitset whose size can be determined at runtime.
 */
class dynamic_bitset {
 public:
  class reference {
   public:
    reference() = delete;
    reference(dynamic_bitset *bitset, std::size_t pos) : base_(bitset), index_(pos >> 6), bit_pos_(pos & 63) {}
    reference(const reference &other) = default;
    reference(reference &&other) = default;
    ~reference() = default;
    reference &operator=(const reference &other) {
      if (this == &other) {
        return *this;
      }
      return *this = static_cast<bool>(other);
    }
    reference &operator=(bool x) {
      if (x) {
        uint64_t mask = 1ull << bit_pos_;
        base_->data_[index_] |= mask;
      } else {
        uint64_t mask = ~(1ull << bit_pos_);
        base_->data_[index_] &= mask;
      }
      return *this;
    }
    operator bool() const {  // NOLINT
      return base_->data_[index_] >> bit_pos_ & 1;
    }
    bool operator~() const { return !static_cast<bool>(base_->data_[index_] >> bit_pos_ & 1); }
    reference &flip() {
      base_->data_[index_] ^= 1ull << bit_pos_;
      return *this;
    }

   private:
    dynamic_bitset *base_{nullptr};
    std::size_t index_{-1u};
    std::size_t bit_pos_{-1u};
  };
  dynamic_bitset() = delete;
  dynamic_bitset(std::size_t size) : size_(size) {  // NOLINT
    assert(size_ > 0);
    std::size_t len = ((size - 1) >> 6) + 1;
    data_ = new uint64_t[len]{};  // NOLINT
  }
  dynamic_bitset(const dynamic_bitset &other) : size_(other.size_) {
    std::size_t len = ((other.size_ - 1) >> 6) + 1;
    data_ = new uint64_t[len];
    std::memcpy(data_, other.data_, len * sizeof(uint64_t));
  }
  dynamic_bitset(dynamic_bitset &&other) noexcept : size_(other.size_) {
    data_ = other.data_;
    other.data_ = nullptr;
  }
  ~dynamic_bitset() { delete[] data_; }
  dynamic_bitset &operator=(const dynamic_bitset &other) {
    if (this == &other) {
      return *this;
    }
    delete[] data_;
    size_ = other.size_;
    std::size_t len = ((size_ - 1) >> 6) + 1;
    data_ = new uint64_t[len];
    std::memcpy(data_, other.data_, len * sizeof(uint64_t));
    return *this;
  }
  dynamic_bitset &operator=(dynamic_bitset &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    delete[] data_;
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
  }
  [[nodiscard]] std::size_t size() const { return size_; }
  reference operator[](std::size_t pos) { return __get_mutable(pos); }
  [[nodiscard]] bool test(std::size_t pos) const { return __get(pos); }
  [[nodiscard]] bool all() const {
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len - 1; ++i) {
      if (data_[i] != UINT64_MAX) {
        return false;
      }
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      return data_[len - 1] == UINT64_MAX;
    }
    return (data_[len - 1] & ((1ull << bit_width) - 1)) == (1ull << bit_width) - 1ull;
  }
  [[nodiscard]] bool none() const {
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len - 1; ++i) {
      if (data_[i] != 0) {
        return false;
      }
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      return data_[len - 1] == 0;
    }
    return (data_[len - 1] & ((1ull << bit_width) - 1)) == 0;
  }
  [[nodiscard]] bool any() const {
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len - 1; ++i) {
      if (data_[i] != 0) {
        return true;
      }
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      return data_[len - 1] != 0;
    }
    return (data_[len - 1] & ((1ull << bit_width) - 1)) != 0;
  }
  [[nodiscard]] std::size_t count() const {
    auto len = ((size_ - 1) >> 6) + 1;
    std::size_t count = 0;
    for (auto i = 0u; i < len - 1; ++i) {
      count += std::popcount(data_[i]);
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      return count + std::popcount(data_[len - 1]);
    }
    return count + std::popcount(data_[len - 1] & ((1ull << bit_width) - 1ull));
  }
  dynamic_bitset &operator&=(const dynamic_bitset &other) {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      data_[i] &= other.data_[i];
    }
    return *this;
  }
  friend dynamic_bitset operator&(const dynamic_bitset &lhs, const dynamic_bitset &rhs) {
    auto res = lhs;
    res &= rhs;
    return res;
  }
  dynamic_bitset &operator|=(const dynamic_bitset &other) {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      data_[i] |= other.data_[i];
    }
    return *this;
  }
  friend dynamic_bitset operator|(const dynamic_bitset &lhs, const dynamic_bitset &rhs) {
    auto res = lhs;
    res |= rhs;
    return res;
  }
  dynamic_bitset &operator^=(const dynamic_bitset &other) {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      data_[i] ^= other.data_[i];
    }
    return *this;
  }
  bool operator==(const dynamic_bitset &other) const {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      if (data_[i] != other.data_[i]) {
        return false;
      }
    }
    return true;
  }
  bool operator!=(const dynamic_bitset &other) const {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      if (data_[i] != other.data_[i]) {
        return true;
      }
    }
    return false;
  }
  friend dynamic_bitset operator^(const dynamic_bitset &lhs, const dynamic_bitset &rhs) {
    auto res = lhs;
    res ^= rhs;
    return res;
  }
  dynamic_bitset operator~() const {
    dynamic_bitset ret(size_);
    std::size_t len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len - 1; ++i) {
      ret.data_[i] = ~data_[i];
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      ret.data_[len - 1] = ~data_[len - 1];
    } else {
      ret.data_[len - 1] = ~data_[len - 1] & ((1ull << bit_width) - 1ull);
    }
    return ret;  // NOLINT
  }
  dynamic_bitset &operator-=(const dynamic_bitset &other) {
    assert(size_ == other.size_);
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len; ++i) {
      data_[i] &= ~other.data_[i];
    }
    return *this;
  }
  friend dynamic_bitset operator-(const dynamic_bitset &lhs, const dynamic_bitset &rhs) {
    auto res = lhs;
    res -= rhs;
    return res;
  }
  dynamic_bitset &set() {
    auto len = ((size_ - 1) >> 6) + 1;
    std::memset(data_, 0xff, len * sizeof(uint64_t));
    auto bit_width = size_ & 63;
    if (bit_width != 0) {
      data_[len - 1] = (1ull << bit_width) - 1ull;
    }
    return *this;
  }
  dynamic_bitset &set(std::size_t pos, bool value = true) {
    __get_mutable(pos) = value;
    return *this;
  }
  dynamic_bitset &reset() {
    auto len = ((size_ - 1) >> 6) + 1;
    std::memset(data_, 0, len * sizeof(uint64_t));
    return *this;
  }
  dynamic_bitset &reset(std::size_t pos) {
    __get_mutable(pos) = false;
    return *this;
  }
  dynamic_bitset &flip() {
    auto len = ((size_ - 1) >> 6) + 1;
    for (auto i = 0u; i < len - 1; ++i) {
      data_[i] = ~data_[i];
    }
    auto bit_width = size_ & 63;
    if (bit_width == 0) {
      data_[len - 1] = ~data_[len - 1];
    } else {
      data_[len - 1] = ~data_[len - 1] & ((1ull << bit_width) - 1ull);
    }
    return *this;
  }
  dynamic_bitset &flip(std::size_t pos) {
    __get_mutable(pos) = !__get_mutable(pos);
    return *this;
  }
  [[nodiscard]] std::string to_string(const std::string &zero = "0", const std::string &one = "1") const {
    std::string ret;
    for (int i = static_cast<int>(size_) - 1; i >= 0; --i) {
      ret += __get(i) ? one : zero;
    }
    return ret;
  }

 private:
  [[nodiscard]] bool __get(std::size_t pos) const {
    assert(pos < size_);
    auto index = pos >> 6;
    auto bit_pos = pos & 63u;
    return data_[index] >> bit_pos & 1;
  }
  reference __get_mutable(std::size_t pos) {
    assert(pos < size_);
    return reference{this, pos};
  }
  std::size_t size_{0};
  uint64_t *data_;
};