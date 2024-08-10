/*
 * Mx Compiler
 * File Name: error_listener.cpp
 * Identification: ./src/include/frontend/error_listener
 * Function: Listen to the error reported by ANTLR parser
 */

#pragma once

#include "antlr4-runtime.h"

/**
 * A class for error listening and reporting
 */
class MxErrorListener : public BaseErrorListener {
 public:
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                   const std::string &msg, std::exception_ptr e) override {
    exit(1);
  }
};