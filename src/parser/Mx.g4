grammar Mx;

@header {
    import java.util.Stack;
}

@lexer::members {
    int formatMode = 0;
    boolean exprMode = false;
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
    : type Identifier (',' Identifier)* ';'
    | classIdentifier=Identifier '(' ')' suite
    | returnType=type funcName=Identifier '(' (type Identifier)* ')' suite
    ;

funcDef
    : returnType=type funcName=Identifier '(' (type Identifier (',' type Identifier)*)? ')' suite
    ;

varDef
    : type Identifier ('=' expression)? (',' Identifier ('=' expression)?)* ';'
    ;

statement
    : varDef
    | suite
    | expression ';'
    | If '(' expression ')' trueStmt=statement (Else falseStmt=statement)?
    | While '(' expression ')' suite
    | For '(' initializeStmt=statement conditionExpr=expression ';' stepExpr=expression ')' statement
    | Return returnExpr=expression ';'
    | Break ';'
    | Continue ';'
    ;

expression
    : primary
    | 'f"' (FormatStringLiteral | '$' expression '$')* QuotationPriority
    | expression (Increment | Decrement)
    | Identifier '(' arguments? ')'
    | expression '.' Identifier '(' arguments? ')'
    | expression ('[' expression ']')+
    | expression '.' Identifier
    | <assoc=right> (Increment | Decrement) expression
    | <assoc=right> (Add | Sub) expression
    | <assoc=right> (NotLogic | Not) expression
    | expression (Mul | Div | Mod) expression
    | expression (Add | Sub) expression
    | expression (ShiftLeft | ShiftRight) expression
    | expression (Less | LessEqual | Greater | GreaterEqual) expression
    | expression (Equal | UnEqual) expression
    | expression And expression
    | expression Xor expression
    | expression Or expression
    | expression AndLogic expression
    | expression OrLogic expression
    | <assoc=right> expression '?' expression ':' expression
    | expression Assign expression
    ;

suite
    : '{' statement* '}'
    ;

arguments
    : expression (',' expression)*
    ;

primary
    : '(' expression ')'
    | literal
    | Identifier
    | This
    | New type ('('')')?
    | New type '[]' ArrayLiteral
    | New type ('[' expression ']')+ ('[]')*
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
    : Int                                       # builtinType
    | Bool                                      # builtinType
    | String                                    # builtinType
    | Identifier                                # definedType
    | Void                                      # voidType
    | (Int | Bool | String | Identifier)'[]'+   # arrayType
    ;

array
    : '{' '}'
    | ArrayLiteral
    | '{' array (',' array)* '}'
    ;

format: 'f"' (FormatStringLiteral | '{' expression '}')* '"';

// Format quatations
FormatQuatation
    : 'f"'
    {
        formatMode++;
        exprMode = false;
    }
    ;
QuotationPriority
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
ArrayLiteral
    : '{' DecimalNumber (',' DecimalNumber)* '}'
    ;
// Quotations
Quotation : '"';
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
    {
        exprMode = !exprMode;
    }
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