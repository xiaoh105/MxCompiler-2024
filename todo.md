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
- [x] IR Generator(8/25 Completed frame)
TODO lists:
  - Correctness Issues
    - [x] Add lvalue/rvalue system to Var.(8/25)
    - [x] Add class functions to FunctionManager
    - [x] Complete construction of jagged array literal(8/25)
    - [x] Add initialization function at the beginning of `main`(8/25)
    - [x] Add `trunc` for boolean variables(since they use `i8` as their type)(8/25)
    - [x] Change `loopCond` and `loopEnd` to stack for loops inside loops.(8/26)
  - Format Issues
    - [x] Remove initializer system for Registers(Since it can't be done with `alloca`)(8/25)
      - [x] Small Optimize: Since it's UB for visiting uninitialized variables, we can remove certain initializations.
    - [x] Move index for local variables into `IRFunctions` instead of inside `VarManager`
  - Optimize Issues
    - [ ] Optimize: Add constant system to IR
    - [ ] Optimize: Replace Mul/Div with multiples of 2 with `<<` and `>>`
    - [ ] Optimize: Mark cmp vars 
    - [ ] Optimize: Expanding loop for short, constant `new` arrays

#### Notes:
- Array representation: An array created by `malloc`. Size is 4 bytes before its beginning. Only C lib can access it.
  - String: An exception. It does not hold an internal size. Instead, it is ended with a `/0`.

#### Some ideas in optimize
- Register Allocation
  - We can consider adding a new benchmark called a virtual register's "preference" for a certain physical register.
  - The following factors can be taken into account:
    - Whether a virtual register is used as a 'call' argument in a function
    - Whether a virtual register is passed in as a function argument
    - Prefer to use temporary registers to avoid saving callee-saved regs in prologue/epilogue
    - Prefer to use callee saved registers to avoid backup caller-saved regs when calling
    - When both two occurs on the above two rules, we prefer the latter(we open a new save reg, and it can be reused)
    - Prefer to reuse caller saved registers instead of opening another one
  - When function calling, we can consider saving all live registers before call.
    - After register allocation, record all registers needed. Only backup all caller-saved registers live at that time