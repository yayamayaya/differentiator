#include "../headers/differentiate.h"

node_t *differen(node_t *node)
{
    assert(node);
    //static node_t *root = node;

    //create_gparh_code(root, DIFF_OP);

    switch (node->data_type)
    {
    case NUMBER:
        LOG("> NUMBER was found and diffed\n");
        return create_node((double)0, NUMBER, NULL, NULL);
    case VARIABLE:
        LOG("> VARIABLE was found and diffed\n");
        return create_node((double)1, NUMBER, NULL, NULL);
    case OPERATION:
        LOG("> OPERATION was found for diffing\n");
        switch (node->data.operation)
        {
        case PLUS:
        case MINUS:
            return create_node(node->data.operation, OPERATION, differen(node->l), differen(node->r));

        case MULT: return _MULT_OP();

        case DIV: return _DIV_OP();
        
        default:
            return NULL;
        }
        break;
    default:
        return NULL;
        //break;
    }
}

node_t *copy_node(node_t *node)
{
    assert(node);
    
    node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
    if (!new_node)
    {
        LOG(">>> can't allocate memory for copying node%40s\n", "[error]");
        return NULL;
    }

    new_node->data = node->data;
    new_node->data_type = node->data_type;
    if (node->l)
        new_node->l = copy_node(node->l);
    if (node->r)
        new_node->r = copy_node(node->r);
    
    return new_node;
}