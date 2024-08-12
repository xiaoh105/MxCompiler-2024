cmake_minimum_required(VERSION 3.29)
project(MxCompiler)

set(CMAKE_CXX_STANDARD 23)

option(ENABLE_OJ_MODE "Enable running mode on the judger" OFF)

include_directories(src/include)
include_directories(/usr/include/antlr4-runtime)

if (ENABLE_OJ_MODE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
  add_definitions(-DOJ)
endif ()

add_executable(MxCompiler src/main.cpp
        src/parser/MxParser.cpp
        src/parser/MxLexer.cpp
        src/parser/MxVisitor.cpp
        src/parser/MxBaseVisitor.cpp
        src/parser/MxBaseVisitor.cpp
        src/utils/scope/type.cpp
        src/utils/scope/function.cpp
        src/utils/scope/scope.cpp
        src/frontend/ast_builder.cpp
        src/frontend/class_collector.cpp
        src/frontend/symbol_collector.cpp
        src/frontend/semantic_checker.cpp)

target_link_libraries(MxCompiler antlr4-runtime)