#pragma once

#include "utils/error/compiler_error.h"

class SemanticError : public CompilerError {

};

class MultipleDef : public SemanticError {

};

class UnhandledErr : public SemanticError {

};