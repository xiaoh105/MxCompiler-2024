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
- [x] IR Generator(Completed frame)
TODO lists:
  - [ ] Add lvalue/rvalue system to Var.
  - [ ] Add class functions into FunctionManager
  - [ ] Remove initializer system for Registers(Since it can't be done with `alloca`)
    - [ ] Small Optimize: Since it's UB for visiting uninitialized variables, we can remove certain initializations.
  - [ ] Complete construction of jagged array literal
  - [ ] Optimize: Add constant system to IR
  - [ ] Optimize: Replace Mul/Div with multiples of 2 with `<<` and `>>`

#### Notes:
- Array representation: An array created by `malloc`. Size is 4 bytes before its beginning. Only C lib can access it.
  - String: An exception. It does not hold an internal size. Instead, it is ended with a `/0`.

### IR To RISC-V