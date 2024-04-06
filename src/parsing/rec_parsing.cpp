#include "parsing.h"

node_t *write_operation(token_t *token_arr, int *pos);

node_t *pars_expr(token_t *token_arr)
{
    assert(token_arr);

    static int pos = 0;

    node_t *node = pars_mult(token_arr, &pos);

    while (token_arr[pos].data_type == OPERATION && (token_arr[pos].data.operation == ADD || token_arr[pos].data.operation == SUB))
    {
        unsigned char operation = token_arr[pos].data.operation;
        (pos)++;
        node = create_node(operation, OPERATION, node, pars_mult(token_arr, &pos));
    }

    return node;
}

node_t *pars_mult(token_t *token_arr, int *pos)
{
    assert(token_arr);
    assert(pos);

    node_t *node = pars_power(token_arr, pos);

    while (token_arr[*pos].data_type == OPERATION && (token_arr[*pos].data.operation == MULT || token_arr[*pos].data.operation == DIV))
    {
        unsigned char operation = token_arr[*pos].data.operation;
        (*pos)++;
        node = create_node(operation, OPERATION, node, pars_power(token_arr, pos));
    }

    return node;
}

node_t *pars_power(token_t *token_arr, int *pos)
{
    assert(token_arr);

    node_t *node = pars_number(token_arr, pos);

    while (token_arr[*pos].data_type == OPERATION && token_arr[*pos].data.operation == POW)
    {
        unsigned char operation = token_arr[*pos].data.operation;
        (*pos)++;
        node = create_node(operation, OPERATION, node, pars_number(token_arr, pos));
    }

    return node;
}

node_t *pars_number(token_t *token_arr, int *pos)
{
    assert(token_arr);
    assert(pos);
    node_t *node = NULL;

    if (token_arr[*pos].data_type == OPERATION)
        node = write_operation(token_arr, pos);
    else if (token_arr[*pos].data_type == NUMBER)
    {
        node = create_node(token_arr[*pos].data.number, NUMBER, NULL, NULL);
        (*pos)++;
    }
    else if (token_arr[*pos].data_type == VARIABLE)
    {
        unsigned char variable = token_arr[*pos].data.variable;
        LOG(">> variable found: <%c>\n", variable);
        node = create_node(variable, VARIABLE, NULL, NULL);
        (*pos)++;
    }
    else
        LOG(">>> syntax error, parser couldn't parse a number%40s\n", "[error]");

    return node;
}

node_t *write_operation(token_t *token_arr, int *pos)
{
    assert(token_arr);
    assert(pos);
    node_t *node = NULL;

    switch (token_arr[*pos].data.operation)
    {
    case OP_BRACK:
        (*pos)++;
        node = pars_expr(token_arr);
        if (token_arr[*pos].data.operation != CL_BRACK)
            LOG(">>> closing bracket wasn't found, character is: %#04x%40s\n", token_arr[*pos].data.operation, "[error]");                    
        else
            (*pos)++;            

        return node;
    
    case CL_BRACK:
        LOG(">>> lishnee closing bracket, recheck your expression%40s", "[error]");
        (*pos)++;
        return write_operation(token_arr, pos);
    
    case SQRT:
        (*pos)++;
        return create_node((unsigned char)POW, OPERATION, pars_number(token_arr, pos), create_node((double)0.5, NUMBER, NULL, NULL));
    
    default:
        LOG("> function creation\n");
        unsigned char operation = token_arr[*pos].data.operation;
        (*pos)++;            
        return create_node(operation, OPERATION, pars_number(token_arr, pos), NULL);
    }
}