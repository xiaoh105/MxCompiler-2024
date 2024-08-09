/*
 * Mx Compiler
 * File Name: class_collector.cpp
 * Identification: ./src/frontend/class_collector.cpp
 * Function: Scan the parser tree and collect all type information
 */

#include "ast/def_node/class_def_node.h"
#include "ast/root_node.h"
#include "frontend/class_collector.h"

ClassCollector::ClassCollector(GlobalScope &global_scope) : global_scope_(global_scope) {}

void ClassCollector::visit(RootNode *node) {
  for (auto &def : node->GetDefNodes()) {
    def->accept(this);
  }
}

void ClassCollector::visit(ClassDefNode *node) {
  global_scope_.AddType(node->GetClassName(), std::make_shared<Typename>(node->GetClassName()), node->GetPos());
}