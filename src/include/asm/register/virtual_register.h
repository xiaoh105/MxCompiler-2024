/*
 * Mx Compiler
 * File Name: virtual_register.h
 * Identification: ./src/include/asm/instruction/virtual_register.h
 * Function: classes for virtual registers and managers
 */
#pragma once

#include <unordered_map>

#include "asm/instruction/mem.h"
#include "ir/var/register.h"

class VirtualRegister {
public:
  VirtualRegister(std::size_t len, std::size_t offset) : len_(len), sp_offset_(offset) {}
  [[nodiscard]] MemType GetLen() const {
    if (len_ == 1) {
      return MemType::kByte;
    }
    if (len_ == 2) {
      return MemType::kHalfWord;
    }
    if (len_ == 4) {
      return MemType::kWord;
    }
    assert(false);
  }
  [[nodiscard]] std::size_t GetOffset() const { return sp_offset_; }

private:
  std::size_t len_;
  std::size_t sp_offset_;
};

class StackManager {
public:
  StackManager() = default;
  void Reset() {
    cur_size_ = 0;
    registers_.clear();
  }
  VirtualRegister ReserveVirtualRegister(const std::shared_ptr<Register> &reg) {
    if (reg->GetType() == kIRBoolType) {
      auto it = registers_.emplace(reg->GetName(), VirtualRegister{1, cur_size_}).first;
      ++cur_size_;
      return it->second;
    }
    if (cur_size_ % 4 != 0) {
      cur_size_ -= cur_size_ % 4;
      cur_size_ += 4;
    }
    auto it = registers_.emplace(reg->GetName(), VirtualRegister{4, cur_size_}).first;
    cur_size_ += 4;
    return it->second;
  }
  std::size_t ReserveRegister(AsmRegister reg) {
    if (cur_size_ % 4 != 0) {
      cur_size_ -= cur_size_ % 4;
      cur_size_ += 4;
    }
    reg_offset_[reg.GetId()] = cur_size_;
    cur_size_ += 4;
    return cur_size_ - 4;
  }
  const std::unordered_map<int, std::size_t> &GetReservedRegs() const {
    return reg_offset_;
  }
  VirtualRegister GetVirtualRegister(const std::shared_ptr<Register> &reg) {
    auto it = registers_.find(reg->GetName());
    if (it != registers_.end()) {
      return it->second;
    }
    assert(false);
  }
  [[nodiscard]] std::size_t GetStackSize() const {
    return cur_size_ + 15 >> 4 << 4;
  }

private:
  std::size_t cur_size_{4};
  std::unordered_map<std::string, VirtualRegister> registers_;
  std::unordered_map<int, std::size_t> reg_offset_;
};