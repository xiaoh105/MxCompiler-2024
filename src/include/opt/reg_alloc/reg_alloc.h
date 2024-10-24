/**
 * Mx Compiler
 * File Name: reg_alloc.h
 * Identification: ./src/include/opt/reg_alloc/reg_alloc.h
 * Function: Register allocation
 */
#pragma once

#include "asm/register/register.h"
#include "ir/ir.h"

class MachineRegister : public Register {
 public:
  MachineRegister() = delete;
  MachineRegister(IRType type, std::string name, bool global, bool lvalue, AsmRegister asm_reg);
  [[nodiscard]] AsmRegister GetAsmRegister() const;

 private:
  AsmRegister asm_reg_;
};

void AddMachineRegister(const std::shared_ptr<IRFunction> &func);

using AllocationInfo = std::pair<std::unordered_set<std::shared_ptr<Register>>,
                                 std::unordered_map<std::shared_ptr<Register>, AsmRegister>>;

AllocationInfo AllocaRegister(const std::shared_ptr<IRFunction> &func);