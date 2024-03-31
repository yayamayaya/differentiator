#include "headers/main.h"

FILE *diff_log = NULL;

operation_t operations[OPERATIONS_NUMBER] = 
{
    {"+", ADD},
    {"-", SUB},
    {"*", MULT},
    {"/", DIV},
    {"^", POW},
    {"sin", SIN},
    {"cos", COS},
    {"tg", TAN},
    {"ctg", COT},
    {"sh", SH},
    {"ch", CH},
    {"th", TH},
    {"cth", CTH},
    {"log", LOG},
    {"ln", LN},
    {"lg", LG},
    {"arcsin", ASIN},
    {"arccos", ACOS},
    {"arctg", ATAN},
    {"arcctg", ACOT}
};