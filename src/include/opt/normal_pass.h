/**
 * Mx Compiler
 * File Name: normal_pass.h
 * Identification: ./src/include/opt/normal_pass.h
 * Function: Passes that make minor adjustments to IR
 */
#pragma once

#include <memory>

class IRFunction;
class VarManager;

void ArithmeticReduction(const std::shared_ptr<IRFunction> &func, VarManager& var_manager);