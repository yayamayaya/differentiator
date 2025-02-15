#include "tree_func.hpp"
#include "in_line_DSL.hpp"
#include <assert.h>
#include <iostream>

no_ret_val_t node_t::print_in_line(FILE *file)
{
    assert(file);

    if (type == NUMBER)
        fprintf(file, "%.2lf", data.number);

    if (type == VARIABLE)
        fprintf(file, "x");

    if ((type == OPERATION))
    {
        if (r_node && l_node)
            print_binary_op(file);
        else if (l_node)
            print_unary_op(file);
        else
            return;
    }
}

no_ret_val_t node_t::print_binary_op(FILE *file)
{
    assert(r_node);
    assert(l_node);
    assert(type == OPERATION);

    _CHECK_FOR_BRACKETS_THEN_PRINT(l_node);
    
    unsigned int op = data.operation;
    switch (op)
    {
    _CASE(ADD);
    _CASE(SUB);
    _CASE(MULT);
    _CASE(DIV);
    _CASE(POW);
    
    default:           
        break;
    }

    _CHECK_FOR_BRACKETS_THEN_PRINT(r_node);
}

no_ret_val_t node_t::print_unary_op(FILE *file)
{
    assert(l_node);
    assert(type == OPERATION);

    unsigned int op = data.operation;
    switch (op)
    {
    _CASE(SIN);
    _CASE(COS);
    _CASE(TAN);
    _CASE(COT);
    _CASE(SH);
    _CASE(CH);
    _CASE(TH);
    _CASE(CTH);
    _CASE(LN);
    _CASE(LG);
    _CASE(SQRT);
    _CASE(ASIN);
    _CASE(ACOS);
    _CASE(ATAN);
    _CASE(ACOT);

    default:           
        break;
    }

    _OP_BRACK();
    
    l_node->print_in_line(file);

    _CL_BRACK();
}

no_ret_val_t print_expr_in_brack_if_needed()
{
    
}