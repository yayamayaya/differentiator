#ifndef IN_LINE_DSL_H
#define IN_LINE_DSL_H

#define _CASE(arg) case arg: _##arg(); break;

#define _PRINT(arg) fprintf(file, arg)

#define _CHECK_FOR_BRACKETS_THEN_PRINT(arg)\
    if (arg->type == OPERATION)       \
    {                                 \
        _OP_BRACK();                  \
    }                                 \
                                      \
    arg->print_in_line(file);         \
                                      \
    if (arg->type == OPERATION)       \
    {                                 \
        _CL_BRACK();                  \
    }

#define _OP_BRACK() _PRINT("(")

#define _CL_BRACK() _PRINT(")")

#define _ADD() _PRINT(" + ")

#define _SUB() _PRINT(" - ")

#define _MULT() _PRINT(" * ")

#define _DIV() _PRINT(" / ")

#define _POW() _PRINT("^")

#define _SIN() _PRINT("sin")

#define _COS() _PRINT("cos")

#define _TAN() _PRINT("tan")

#define _COT() _PRINT("cot")

#define _SH()  _PRINT("sh")

#define _CH()  _PRINT("ch")

#define _TH()  _PRINT("th")

#define _CTH() _PRINT("cth")

#define _LN()  _PRINT("ln")

#define _LG()  _PRINT("lg")

#define _SQRT() _PRINT("sqrt")

#define _ASIN() _PRINT("arcsin")

#define _ACOS() _PRINT("arccos")

#define _ATAN() _PRINT("arctan")

#define _ACOT() _PRINT("arcctg")

#endif