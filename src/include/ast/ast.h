/*
 * Mx Compiler
 * File Name: ast.h
 * Identification: ./src/include/ast/ast.h
 * Function: Include all the headers in directory 'ast'
 */
#pragma once

#include "ast/ast_node.h"
#include "ast/ast_visitor.h"
#include "ast/root_node.h"

#include "array_node/array_node.h"
#include "array_node/jagged_array_node.h"
#include "array_node/simple_array_node.h"

#include "def_node/class_def_node.h"
#include "def_node/def_node.h"
#include "def_node/function_def_node.h"
#include "def_node/var_def_node.h"

#include "expr_node/assign_expr_node.h"
#include "expr_node/atom_expr_node.h"
#include "expr_node/binary_expr_node.h"
#include "expr_node/expr_node.h"
#include "expr_node/format_expr_node.h"
#include "expr_node/function_call_expr_node.h"
#include "expr_node/member_expr_node.h"
#include "expr_node/subscript_expr_node.h"
#include "expr_node/tenary_expr_node.h"
#include "expr_node/unary_expr_node.h"

#include "primary_node/literal_primary_node.h"
#include "primary_node/new_primary_node.h"
#include "primary_node/primary_node.h"
#include "primary_node/this_primary_node.h"
#include "primary_node/var_primary_node.h"

#include "stmt_node/control_stmt_node.h"
#include "stmt_node/expr_stmt_node.h"
#include "stmt_node/for_stmt_node.h"
#include "stmt_node/if_stmt_node.h"
#include "stmt_node/stmt_node.h"
#include "stmt_node/suite_stmt_node.h"
#include "stmt_node/var_def_stmt_node.h"
#include "stmt_node/while_stmt_node.h"

#include "stmt_node/class_stmt_node/class_stmt_node.h"
#include "stmt_node/class_stmt_node/constructor_class_stmt_node.h"
#include "stmt_node/class_stmt_node/function_def_class_stmt_node.h"
#include "stmt_node/class_stmt_node/var_def_class_stmt_node.h"