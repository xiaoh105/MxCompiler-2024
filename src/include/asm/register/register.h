/*
 * Mx Compiler
 * File Name: register.h
 * Identification: ./src/include/asm/instruction/register.h
 * Function: classes for registers
 */
#pragma once

#include <cassert>
#include <string>

class AsmRegister {
 public:
  AsmRegister(int id) : id_(id) { assert(id >= 0 && id < 32); }
  AsmRegister(const AsmRegister &other) = default;
  AsmRegister &operator=(const AsmRegister &other) = default;
  [[nodiscard]] int GetId() const { return id_; }
  [[nodiscard]] std::string GetName() const {
    switch (id_) {
      case 0:
        return "x0";
      case 1:
        return "ra";
      case 2:
        return "sp";
      case 3:
      case 4:
        assert(false);
      case 5:
      case 6:
      case 7:
        return "t" + std::to_string(id_ - 5);
      case 8:
        return "s0";
      case 9:
        return "s1";
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
        return "a" + std::to_string(id_ - 10);
      case 28:
      case 29:
      case 30:
      case 31:
        return "t" + std::to_string(id_ - 25);
      default:
        return "s" + std::to_string(id_ - 16);
    }
  }

 private:
  int id_;
};

inline AsmRegister zero(0);
inline AsmRegister ra(1);
inline AsmRegister sp(2);

constexpr AsmRegister a(int id) {
  assert(id >= 0 && id < 8);
  return {id + 10};
}

constexpr AsmRegister t(int id) {
  assert(id >= 0 && id < 7);
  if (id <= 2) {
    return {id + 5};
  }
  return {id + 25};
}

constexpr AsmRegister s(int id) {
  assert(id >= 0 && id < 12);
  if (id <= 2) {
    return {id + 8};
  }
  return {id + 16};
}

constexpr AsmRegister x(int id) {
  assert(id >= 0 && id < 32);
  return {id};
}

constexpr std::size_t kAvailableRegisters = 26;

inline AsmRegister caller_saved_registers[] = {a(0), a(1), a(2), a(3), a(4), a(5), a(6), a(7), t(3), t(4), t(5), t(6)};
inline AsmRegister callee_saved_registers[] = {x(3), x(4), s(0), s(1), s(2), s(3),  s(4),
                                               s(5), s(6), s(7), s(8), s(9), s(10), s(11)};