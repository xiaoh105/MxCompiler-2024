/*
 * Mx Compiler
 * File Name: ir.h
 * Identification: ./src/include/ir/ir.h
 * Function: Include all the headers in directory 'ir'
 */
#pragma once

#include "ir/stmt/stmt.h"
#include "ir/stmt/alloca_stmt.h"
#include "ir/stmt/binary_stmt.h"
#include "ir/stmt/call_stmt.h"
#include "ir/stmt/gep_stmt.h"
#include "ir/stmt/icmp_stmt.h"
#include "ir/stmt/load_stmt.h"
#include "ir/stmt/move_stmt.h"
#include "ir/stmt/phi_stmt.h"
#include "ir/stmt/select_stmt.h"
#include "ir/stmt/store_stmt.h"

#include "ir/stmt/branch_stmt/branch_stmt.h"
#include "ir/stmt/branch_stmt/br_cond_stmt.h"
#include "ir/stmt/branch_stmt/br_uncond_stmt.h"
#include "ir/stmt/branch_stmt/ret_stmt.h"
#include "ir/stmt/branch_stmt/unreachable.h"

#include "ir/var/var.h"
#include "ir/var/constant.h"
#include "ir/var/register.h"
#include "ir/var/var_manager.h"

#include "ir/type/ir_type.h"

#include "ir/block.h"
#include "ir/function.h"