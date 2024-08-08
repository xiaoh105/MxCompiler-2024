# TODO List and Progress of the Mx Compiler
## Semantic Check
### Tree Generation
- [x] Design the Mx.g4 file.(8/2 completed, 8/4 revised)
### AST Design
- [ ] AST Nodes
    - [x] Structure(8/7)
    - [x] Set up virtual functions(i.e. `accept()` & `ASTVisitor`)(8/7)
    - [ ] AST Builder(Parts left: Primary/Array Literal Nodes)
- [x] Error Type and Error Reporting(8/5)
  - [x] Position(8/5)
### Semantic Check
- [x] Scope(8/5)
- [ ] Symbol Collection
  - [ ] Type Collector
  - [ ] Function Collector
- [ ] Semantic Check