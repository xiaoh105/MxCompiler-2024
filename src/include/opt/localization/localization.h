/**
 * Mx Compiler
 * File Name: localization.h
 * Identification: ./src/include/opt/localization/localization.h
 * Function: Moves copy of global function to local for pure functions
 */
#pragma once

#include <unordered_set>

#include "ir/function.h"

struct GlobalUsageInfo {
  std::unordered_set<std::shared_ptr<Register>> global_def_;
  std::unordered_set<std::shared_ptr<Register>> global_use_;
};

std::unordered_map<std::shared_ptr<IRFunction>, GlobalUsageInfo> Localization(FunctionManager &func_manager);