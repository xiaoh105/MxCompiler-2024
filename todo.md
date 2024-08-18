# TODO List and Progress of the Mx Compiler
## Semantic Check
### Tree Generation
- [x] Design the Mx.g4 file.(8/2 completed, 8/4 revised)
### AST Design
- [x] AST Nodes
    - [x] Structure(8/7)
    - [x] Set up virtual functions(i.e. `accept()` & `ASTVisitor`)(8/7)
    - [x] AST Builder(8/9)
- [x] Error Type and Error Reporting(8/5)
  - [x] Position(8/5)
### Semantic Check
- [x] Scope(8/5, 8/9 revised)
- [x] Symbol Collection(8/9)
  - [x] Type Collector(8/9)
  - [x] Function Collector(8/9)
- [x] Semantic Check(8/10)
- [x] Main Function(8/10 done, 8/12 Passes OJ tests)

## Codegen
### AST To IR
- [x] IR Node Design(8/17)
  - [x] Program
  - [x] Function
  - [x] Block
  - [x] Stmt
  - [x] Var
- [ ] IR Generator
  

#### Notes:
  - Class member must be tagged so that IR knows whether to dereference `this`
  - Array is represented by a pointer to an i8 array.
    - Size is stored in the first 4 bytes for efficiency
    - Elements are cast to i8 with `bitcast`, and are cast back in `GEP` and `load/store`
    - As a result, `bool` arrays are represented by `i8` array. They're cast to `i1` with `trunk`
  - Since array constants isn't too long, initializing element by element may be better than using array constant
  - Initializing jagged array MUST NOT be done in a C++-style way(e.g. using `memcpy` or think elements in jagged array are all consecutive). It must be done dim by dim.
  - [x] TODO: Rewrite Type and Get TypeName/DefName functions
  - [ ] TODO: Change AST nodes accordingly
      - [x] TODO: Add "class member" attribute to all VarPrimaryNodes(8/18)
      - [x] TODO: Add "value" attribute to all primary and expr nodes for IR builder(8/18)
  - [ ] TODO: (Optimize) Add `const` attribute to all AST nodes and calculate them in compile time for better efficiency.

### IR To RISC-V