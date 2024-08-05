/*
 * Mx Compiler
 * File Name: position.hpp
 * Identification: ./src/utils/position.hpp
 * Function: Indicate the position of certain token/antlr node.
 */

#pragma once

#include <cstddef>
#include <string>

#include "antlr4-runtime/antlr4-runtime.h"

using namespace antlr4;

/**
 * A class used to indicate the position and text of certian token/context.
 */
class Position {
 public:
  Position() = delete;
  Position(std::size_t row, std::size_t col, const std::string &text) : row_(row), col_(col), text_(text) {}
  Position(const Token *token)
      : row_(token->getLine()), col_(token->getCharPositionInLine()), text_(token->getText()) {}
  Position(const tree::TerminalNode *node) : Position(node->getSymbol()) {}
  Position(const ParserRuleContext *context) : Position(context->start) {
    text_ = context->start->getInputStream()->getText(
        misc::Interval(context->start->getStartIndex(), context->stop->getStopIndex()));
  }
  [[nodiscard]] std::size_t Row() const { return row_; }
  [[nodiscard]] std::size_t Column() const { return col_; }
  [[nodiscard]] const std::string &Text() const { return text_; }
  [[nodiscard]] std::string ToString() const {
    return std::to_string(row_) + ',' + std::to_string(col_) + ": " + text_;
  }

 private:
  std::size_t row_{0};
  std::size_t col_{0};
  std::string text_{};
};