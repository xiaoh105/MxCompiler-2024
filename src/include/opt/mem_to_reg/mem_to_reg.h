/**
 * Mx Compiler
 * File Name: mem_to_reg.h
 * Identification: ./src/include/opt/mem_to_reg.h
 * Function: Functions used for Mem2Reg optimization
 */
#pragma once

#include <memory>

#include "opt/cfg.h"

void MemToReg(ControlFlowGraph &cfg, VarManager &var_manager);

void DestructPhi(ControlFlowGraph &cfg);