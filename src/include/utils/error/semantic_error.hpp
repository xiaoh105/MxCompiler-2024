/*
 * Mx Compiler
 * File Name: semantic_error.hpp
 * Identification: ./src/utils/error/semantic_error.hpp
 * Function: Contains all sorts of semantic errors in Mx Compiler.
 */
#pragma once

#include "utils/error/compiler_error.hpp"

/**
 * A class used to regulate and report errors for all semantic errors.
 */
class SemanticError : public CompilerError {
 public:
  SemanticError() = delete;
  SemanticError(const std::string &error_detail, const Position &pos)
      : CompilerError("Semantic Error", error_detail, pos) {}
};

/**
 * Multiple definitions for a single variable/function/class.
 */
class MultipleDef : public SemanticError {
 public:
  MultipleDef() = delete;
  MultipleDef(const Position &pos) : SemanticError("Multiple Definitions", pos) {}
};

/**
 * Invalid use of type.(e.g. Declare variable using 'void' or use non-boolean variables as if condition.)
 */
class InvalidType : public SemanticError {
 public:
  InvalidType() = delete;
  InvalidType(const Position &pos) : SemanticError("Invalid Type", pos) {}
};

/**
 * Use of undefined class/function/variable.
 */
class UndefinedIdentifier : public SemanticError {
 public:
  UndefinedIdentifier() = delete;
  UndefinedIdentifier(const Position &pos) : SemanticError("Undefined Identifier", pos) {}
};

/**
 * Invalid constuctor of a certain class.
 */
class InvalidContructor : public SemanticError {
 public:
  InvalidContructor() = delete;
  InvalidContructor(const Position &pos) : SemanticError("Invalid Class Constructor", pos) {}
};

/**
 * Mismatch of operands
 */
class TypeMismatch : public SemanticError {
 public:
  TypeMismatch() = delete;
  TypeMismatch(const Position &pos) : SemanticError("Type Mismatch", pos) {}
};

/**
 * The value/expression used in assign expression is not assignable(i.e. not lvalue)
 */
class NotAssignable : public SemanticError {
 public:
  NotAssignable() = delete;
  NotAssignable(const Position &pos) : SemanticError("Value Is Not Assignable", pos) {}
};

/**
 * Certain class member/method is undefined.
 */
class InvalidMember : public SemanticError {
 public:
  InvalidMember() = delete;
  InvalidMember(const Position &pos) : SemanticError("Class Member/Method Is Invalid", pos) {}
};

/**
 * Trying to visit the index of a non-array type. (e.g. visit a[0][0][0] with int[][] a)
 */
class DimOutOfBound : public SemanticError {
 public:
  DimOutOfBound() = delete;
  DimOutOfBound(const Position &pos) : SemanticError("Dimension Out Of Bound", pos) {}
};

/**
 * Trying to call a function with mismatched arguments.
 */
class InvalidArgs : public SemanticError {
 public:
  InvalidArgs() = delete;
  InvalidArgs(const Position &pos) : SemanticError("Invalid Function Argument", pos) {}
};

/**
 * Invalid control statements(e.g. continue/break outside loop body)
 */
class InvalidControlFlow : public SemanticError {
 public:
  InvalidControlFlow() = delete;
  InvalidControlFlow(const Position &pos) : SemanticError("Invalid Control Flow", pos) {}
};

/**
 * Denoting that an error is not handled correctly or in the right place.
 */
class UnhandledErr : public SemanticError {
 public:
  UnhandledErr() : SemanticError("An error isn't handled corrently", {0, 0, "Unknown"}) {}
  UnhandledErr(const std::string &text) : SemanticError("An error isn't handled correctly", {0, 0, text}) {}
};