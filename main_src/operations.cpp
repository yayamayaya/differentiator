#include "operations.hpp"
#include <iostream>
#include <string.h>

static constexpr int operations_number = 22;

static constexpr operation_st operations[operations_number] = 
{
    {"+",       ADD,        1},
    {"-",       SUB,        1},
    {"*",       MULT,       1},
    {"/",       DIV,        1},
    {"^",       POW,        1},
    {"sqrt",    SQRT,       4},
    {"sin",     SIN,        3},
    {"cos",     COS,        3},
    {"tg",      TAN,        2},
    {"ctg",     COT,        3},
    {"sh",      SH,         2},
    {"ch",      CH,         2},
    {"th",      TH,         2},
    {"cth",     CTH,        3},
    {"ln",      LN,         2},
    {"lg",      LG,         2},
    {"arcsin",  ASIN,       6},
    {"arccos",  ACOS,       6},
    {"arctg",   ATAN,       5},
    {"arcctg",  ACOT,       6},
    {"(",       OP_BRACK,   1},
    {")",       CL_BRACK,   1},
};

operation_t arithm_operations::find_operation(const char *string, unsigned int &pos)
{
    for (int op_num = 0; op_num < operations_number; op_num++)
        if (!strncmp(operations[op_num].operation, string + pos, operations[op_num].string_length))
        {
            pos += operations[op_num].string_length;
            return operations[op_num].operation_number;
        }

    return NO_OP;
}