#include "headers/main.h"

FILE *diff_log = NULL;

operation_t operations[OPERATIONS_NUMBER] = 
{
    {"+", ADD, 1},
    {"-", SUB, 1},
    {"*", MULT, 1},
    {"/", DIV, 1},
    {"^", POW, 1},
    //{"sqrt", SQRT, 4},
    {"sin", SIN, 3},
    {"cos", COS, 3},
    {"tg", TAN, 2},
    {"ctg", COT, 3},
    {"sh", SH, 2},
    {"ch", CH, 2},
    {"th", TH, 2},
    {"cth", CTH, 3},
    {"log", LOG, 3},
    {"ln", LN, 2},
    {"lg", LG, 2},
    {"arcsin", ASIN, 6},
    {"arccos", ACOS, 6},
    {"arctg", ATAN, 5},
    {"arcctg", ACOT, 6},
    {"(", OP_BRACK, 1},
    {")", CL_BRACK, 1},
};