grammar Mx;

@lexer::members {
    int formatMode = 0;
    bool exprMode = false;
}

program
    : (classDef | funcDef | varDef)* mainFunc (classDef | funcDef | varDef)*
    ;

mainFunc
    : 'int main()' suite
    ;

classDef
    : Class classIdentifier=Identifier '{' classStmt* '}' ';'
    ;

classStmt
    : memberType=type Identifier (',' Identifier)* ';'                        # memberDefStmt
    | classIdentifier=Identifier '(' ')' suite                                # constructorDefStmt
    | returnType=type funcName=Identifier '(' (type Identifier)* ')' suite    # funcDefStmt
    ;

funcDef
    : returnType=type funcName=Identifier
      '(' (type Identifier (',' type Identifier)*)? ')' suite
    ;

varDef
    : type Identifier ('=' expression)? (',' Identifier ('=' expression)?)* ';'
    ;

statement
    : type Identifier ('=' expression)? (',' Identifier ('=' expression)?)* ';' # varDefStmt
    | suite                                                                     # suiteStmt
    | expression ';'                                                            # exprStmt
    | If '(' expression ')' trueStmt=statement (Else falseStmt=statement)?      # ifStmt
    | While '(' expression ')' suite                                            # whileStmt
    | For '(' initializeStmt=statement conditionExpr=expression ';'
      stepExpr=expression ')' statement                                         # forStmt
    | Return returnExpr=expression ';'                                          # returnStmt
    | Break ';'                                                                 # breakStmt
    | Continue ';'                                                              # continueStmt
    ;

expression
    : primary                                                               # atomicStmt
    | 'f"' (FormatStringLiteral | '$' expression '$')* Quotation            # formatStmt
    | expression (Increment | Decrement)                                    # unaryStmt
    | funcName=Identifier '(' arguments? ')'                                # funcCallStmt
    | classVar=expression '.' funcName=Identifier '(' arguments? ')'        # funcCallStmt
    | expression ('[' index=expression ']')+                                # subscriptStmt
    | expression '.' Identifier                                             # memberStmt
    | <assoc=right> (Increment | Decrement) expression                      # unaryStmt
    | <assoc=right> (Add | Sub) expression                                  # unaryStmt
    | <assoc=right> (NotLogic | Not) expression                             # unaryStmt
    | expression (Mul | Div | Mod) expression                               # binaryStmt
    | expression (Add | Sub) expression                                     # binaryStmt
    | expression (ShiftLeft | ShiftRight) expression                        # binaryStmt
    | expression (Less | LessEqual | Greater | GreaterEqual) expression     # binaryStmt
    | expression (Equal | UnEqual) expression                               # binaryStmt
    | expression And expression                                             # binaryStmt
    | expression Xor expression                                             # binaryStmt
    | expression Or expression                                              # binaryStmt
    | expression AndLogic expression                                        # binaryStmt
    | expression OrLogic expression                                         # binaryStmt
    | <assoc=right> expression '?' expression ':' expression                # tenaryStmt
    | expression Assign expression                                          # assignStmt
    ;

suite
    : '{' statement* '}'
    ;

arguments
    : expression (',' expression)*
    ;

primary
    : '(' expression ')'                         # parenPrimary
    | literal                                    # literalPrimary
    | Identifier                                 # varPrimary
    | This                                       # thisPrimary
    | New type ('('')')?                         # newPrimary
    | New type '[]' array                        # newPrimary
    | New type ('[' expression ']')+ ('[]')*     # newPrimary
    ;

array
    : '{' '}'
    | '{' literal (',' literal)* '}'
    | '{' array (',' array)* '}'
    ;

literal
    : DecimalNumber     # decimalLiteral
    | True              # boolLiteral
    | False             # boolLiteral
    | StringLiteral     # stringLiteral
    | Null              # nullLiteral
    | array             # arrayLiteral
    ;

type
    : Int
    | Bool
    | String
    | Identifier
    | Void
    | (Int | Bool | String | Identifier)'[]'+
    ;

// Format quatations and Quotations
FormatQuatation
    : 'f"'
    {
        formatMode++;
        exprMode = false;
    }
    ;
Quotation
    : {formatMode > 0 && !exprMode}? '"'
    {
        formatMode--;
        if (formatMode > 0) {
            exprMode = true;
        }
    }
    ;
// Constants and Literals
True : 'true';
False : 'false';
DecimalNumber
    : [1-9][0-9]*
    | '0'
    ;
StringLiteral
    : {formatMode == 0 || exprMode}? '"'('\\n' | '\\\\' | '\\"' | [ !#-[\]-~])*'"'
    ;
FormatStringLiteral
    : {formatMode > 0 && !exprMode}? ('\\n' | '\\\\' | '\\"' | '$$' | [ !#%-[\]-~])+
    ;
Null : 'null';
// Reserved Words
New : 'new';
Class : 'class';
This : 'this';
If : 'if';
Else : 'else';
For : 'for';
While : 'while';
Break : 'break';
Continue : 'continue';
Return : 'return';
// Types and Identifiers
Bool : 'bool';
Int : 'int';
Void : 'void';
String : 'string';
Identifier : [A-Za-z][A-Za-z_0-9]*;
// Arithmetic Operators
Add : '+';
Sub : '-';
Mul : '*';
Div : '/';
Mod : '%';
// Compare Operators
Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';
Equal : '==';
UnEqual : '!=';
// Logic Operators
AndLogic : '&&';
OrLogic : '||';
NotLogic : '!';
// Bitwise Operators
ShiftRight : '>>';
ShiftLeft : '<<';
And : '&';
Or : '|';
Xor : '^';
Not : '~';
// Assign Operators
Assign : '=';
// Increment and Decrement
Increment : '++';
Decrement : '--';
// Member Access Operator
Dot : '.';
// Parens, Branckets and Braces
LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';
// Other Symbols
Dollar
    : '$'
    { exprMode = !exprMode; }
    ;
Question : '?';
Colon : ':';
Semicolon : ';';
Comma : ',';
// Whitespace
Whitespace : [ \n\r\t] -> skip;
// Comments
LineComment : '//' ~[\n\r]* -> skip;
BlockComment : '/*' .*? '*/' -> skip;