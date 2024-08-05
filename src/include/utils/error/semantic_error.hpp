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
    : CompilerError("Semantic error", error_detail, pos) {}
};

/**
 * Multiple definitions for a single variable/function/class.
 */
class MultipleDef : public SemanticError {
public:
  MultipleDef() = delete;
  MultipleDef(const Position &pos) : SemanticError("Multiple Definition", pos) {}
};

/**
 * Denoting that an error is not handled correctly or in the right place.
 */
class UnhandledErr : public SemanticError {
public:
  UnhandledErr() : SemanticError("An error isn't handled corrently", {0, 0, "Unknown"}) {}
  UnhandledErr(const std::string &text) : SemanticError("An error isn't handled correctly", {0, 0, text}) {}
};