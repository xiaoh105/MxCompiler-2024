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
  return {id + 10};
}