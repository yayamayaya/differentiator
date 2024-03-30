#include "headers/main_header.h"

FILE *diff_log = NULL;

operation_t operations[OPERATIONS_NUMBER] = 
{
    {"+", PLUS},
    {"-", MINUS},
    {"*", MULT},
    {"/", DIV},
    {"^", POW},
};