#include "expr_calc.h"

int calculate(node_t *root)
{
    assert(root);

    if (root->data_type == NUMBER || root->data_type == VARIABLE)
    {
        LOG(">> Root is not an operation.\n");
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
        node_t *left_node = calculate_tree(node->l);
        node_t *right_node = calculate_tree(node->r);

        if (make_operation(left_node, right_node, node))
            return NULL;
              
        create_gparh_code(root, OP);

        return node;
    }

   return NULL;
}

int make_operation(node_t *left_node, node_t *right_node, node_t *node)
{
    assert(node->data_type == OPERATION);

    double first_arg = 0;
    double second_arg = 0;
    double result = 0;

    /*if (left_node)
        first_arg = left_node->data.number;
    if (right_node)
        second_arg = right_node->data.number;*/
    
    LOG("left node pointer is: %p\n", left_node);
    LOG("right node pointer is: %p\n", right_node);
    LOG("operation number is: %d\n", node->data.operation);
    //LOG("logical ex[]")

    if ((!(node->data.operation & 0xF0)) && (left_node && right_node))
    {
        first_arg = left_node->data.number;
        second_arg = right_node->data.number;

        switch (node->data.operation)
        {
        case ADD:   result = first_arg + second_arg; break;
        case SUB:   result = first_arg - second_arg; break;
        case MULT:  result = first_arg * second_arg; break;
        case DIV:   result = first_arg / second_arg; break;
        case POW:   result = pow(first_arg, second_arg); break;

        default:
            LOG(">>> fatal error in making an operation%40s\n", "[error]");
            return 1;
        }
    }
    else if (left_node)
    {
        first_arg = left_node->data.number;
        switch (node->data.operation)
        {
        case LN:    result = log(first_arg); break;
        case LG:    result = log10(first_arg); break;
        case SIN:   result = sin(first_arg); break;
        case COS:   result = cos(first_arg); break;
        case TAN:   result = tan(first_arg); break;
        case COT:   result = 1 / tan(first_arg); break;
        case SH:    result = sinh(first_arg); break;
        case CH:    result = cosh(first_arg); break;
        case TH:    result = tanh(first_arg); break;
        case CTH:   result = atanh(first_arg); break;
        case ASIN:  result = asin(first_arg); break;
        case ACOS:  result = acos(first_arg); break;
        case ATAN:  result = atan(first_arg); break;
        case ACOT:  result = M_PI_2 - atan(first_arg); break;

        default:
            LOG("unary command wasn't found\n");
            return 0;
        }
    }

    op_to_num_node(node);
    LOG("> node was translated to number\n");
    node->data.number = result;

    LOG("> result of calc is: %lf\n", result);     
        
    return 0;
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