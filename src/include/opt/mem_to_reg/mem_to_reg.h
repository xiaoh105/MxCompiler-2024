/**
 * Mx Compiler
 * File Name: mem_to_reg.h
 * Identification: ./src/include/opt/mem_to_reg.h
 * Function: Functions used for Mem2Reg optimization
 */
#pragma once

#include <memory>

#include "opt/cfg.h"

void MemToReg(const std::vector<std::shared_ptr<CFGNode>> &cfg_nodes, VarManager &var_manager);