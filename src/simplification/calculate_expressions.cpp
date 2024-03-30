#include "../headers/expr_calc.h"

int calculate(node_t *root)
{
    assert(root);

    if (root->data_type == NUMBER || root->data_type == VARIABLE)
    {
        LOG(">>> Root is not an operation.\n");
        return NUMBER_IN_ROOT;        
    }

    calculate_tree(root);

    return 0;
}

node_t *calculate_tree(node_t *node)
{
    static node_t *root = node;
    assert(root);

    if (!node)
    {
        LOG("> Node has not been operated on, returning NULL\n");
        return NULL;
    }

    if (node->data_type == NUMBER)
    {
        LOG("> Number %lf founded\n", node->data.number);
        return node;        
    }
    else if (node->data_type == VARIABLE)  
    {
        LOG("> Variable found: %c\n", node->data.variable);
        return NULL;
    }
    else if (node->data_type == OPERATION)
    {
        node_t *leftNode = calculate_tree(node->l);
        node_t *rightNode = calculate_tree(node->r);

        LOG("> Nodes on node %p was calculated\n", node);
        
        if (!leftNode || !rightNode)
        {
            LOG("> One of the child nodes returned NULL, operation will not be executed\n");
            return NULL;
        }

        double result = make_operation(leftNode->data.number, rightNode->data.number, node->data.operation);
        LOG("> result of calc is: %lf\n", result);

        op_to_num_node(node);
        LOG("> node was translated to number\n");
        node->data.number = result;

        create_gparh_code(root, OP);

        return node;
    }

   return NULL;
}

double make_operation(double first_arg, double second_arg, char operation_number)
{
    switch (operation_number)
    {
    case PLUS:
        return first_arg + second_arg;
    case MINUS:
        return first_arg - second_arg;
    case MULT:
        return first_arg * second_arg;
    case DIV:
        return first_arg / second_arg;
    default:
        LOG(">>> fatal error in making an operation%40s\n", "[error]");
        return 0;
    }
}

void op_to_num_node(node_t *node)
{
    node->data.operation = 0;
    node->data_type = NUMBER;

    free(node->l);
    free(node->r);

    node->l = NULL;
    node->r = NULL;
}