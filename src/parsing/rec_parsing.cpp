#include "../headers/parsing.h"

node_t *pars_expr(token_t *token_arr, int *pos)
{
    assert(token_arr);

    node_t *node = pars_mult(token_arr, pos);

    while (token_arr[*pos].data_type == OPERATION && (token_arr[*pos].data.operation == ADD || token_arr[*pos].data.operation == SUB))
    {
        char cmd = (char)(token_arr[*pos].data.operation);
        (*pos)++;
        fprintf(stderr, "sum_cmd: %d\n", (token_arr + (*pos) - 1)->data.operation);
        node = create_node(cmd, OPERATION, node, pars_mult(token_arr, pos));
    }

    return node;
}

node_t *pars_mult(token_t *token_arr, int *pos)
{
    assert(token_arr);

    node_t *node = pars_power(token_arr, pos);

    while (token_arr[*pos].data_type == OPERATION && (token_arr[*pos].data.operation == MULT || token_arr[*pos].data.operation == DIV))
    {
        char operation = (char)(token_arr[*pos].data.operation);
        (*pos)++;
        fprintf(stderr, "mult_cmd: %d\n", (token_arr + (*pos) - 1)->data.operation);
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
        char operation = (char)(token_arr[*pos].data.operation);
        (*pos)++;
        node = create_node(operation, OPERATION, node, pars_number(token_arr, pos));
    }

    return node;
}

node_t *pars_number(token_t *token_arr, int *pos)
{
    assert(token_arr);
    node_t *node = NULL;

    if (token_arr[*pos].data_type == OPERATION)
    {
        if (token_arr[*pos].data.operation == OP_BRACK)
        {
            (*pos)++;
            node = pars_expr(token_arr, pos);
            if (token_arr[*pos].data.operation != CL_BRACK)
                LOG(">>> closing bracket wasn't found, character is: %#04x%40s\n", token_arr[*pos].data.operation, "[error]");                    
            else
                (*pos)++;            

            return node;
        }
        else
        {
            LOG("> function creation\n");
            char operation = token_arr[*pos].data.operation;
            (*pos)++;            
            node = create_node(operation, OPERATION, pars_expr(token_arr, pos), NULL);
            return node;
        }
    }
    else if (token_arr[*pos].data_type == NUMBER)
    {
        node = create_node(token_arr[*pos].data.number, NUMBER, NULL, NULL);
        (*pos)++;
        return node;
    }
    else if (token_arr[*pos].data_type == VARIABLE)
    {
        char variable = (char)token_arr[*pos].data.variable;
        LOG(">> variable found: <%c>\n", variable);
        node = create_node(variable, VARIABLE, NULL, NULL);
        (*pos)++;
        return node;
    }

    return node;
}

int tree_kill(node_t *node)
{
    assert(node != NULL);

    if (node->l != NULL)
        tree_kill(node->l);
    if (node->r != NULL)
        tree_kill(node->r);

    free(node);

    return 0;
}