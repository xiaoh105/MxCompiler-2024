cmake_minimum_required(VERSION 3.29)
project(MxCompiler)

set(CMAKE_CXX_STANDARD 23)

include_directories(/usr/include/antlr4-runtime)
include_directories(src/include)

add_executable(MxCompiler src/main.cpp
        src/parser/MxParser.cpp
        src/parser/MxLexer.cpp
        src/parser/MxVisitor.cpp
        src/parser/MxBaseVisitor.cpp
        src/parser/MxBaseVisitor.cpp)
