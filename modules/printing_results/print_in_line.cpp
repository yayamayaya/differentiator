#include "tree_func.hpp"
#include "in_line_DSL.hpp"
#include <cmath>
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

    check_for_negative_power();

    if (check_for_sqrt(file))
        return;

    l_node->print_expr_in_brack_if_needed(file, data.operation);
    
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

    r_node->print_expr_in_brack_if_needed(file, data.operation);
}

ret_t node_t::check_for_sqrt(FILE *file)
{
    if (data.operation != POW || r_node->type != NUMBER || fabs(r_node->data.number - 0.5) >= 1.0e-5)
        return 0;

    delete r_node;

    data    = SQRT;
    type    = OPERATION;
    r_node  = nullptr;

    print_in_line(file);

    return 1;
}

no_ret_val_t node_t::check_for_negative_power()
{
    if (data.operation != POW || r_node->type != NUMBER || r_node->data.number >= 0)
        return;

    r_node->replace_node(0 - r_node->data.number);

    node_t *this_copy = new node_t{this};

    delete l_node;
    delete r_node;

    data    = DIV;
    type    = OPERATION;
    l_node  = new node_t{1.0};
    r_node  = this_copy;
}

no_ret_val_t node_t::print_expr_in_brack_if_needed(FILE *file, operation_t parent_op)
{
    if ((type != OPERATION) || ((data.operation & parent_op) & 0xF0) || (data.operation & FUNC_OP))
    {
        print_in_line(file);

        return;
    }
    
    _OP_BRACK();
    
    print_in_line(file);

    _CL_BRACK();
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

