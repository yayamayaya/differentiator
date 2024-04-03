#include "differentiate.h"

node_t *differen(node_t *node)
{
    assert(node);
    //static node_t *root = node;

    //_CREATE_GRAPH()

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
        case ADD:
        case SUB:
            return create_node((unsigned char)node->data.operation, OPERATION, differen(node->l), differen(node->r));

        case MULT:  return _MULT_OP();
        case DIV:   return _DIV_OP();
        case POW:   return _POW_OP();
        case SIN:   return _SIN_OP();
        case COS:   return _COS_OP();
        case TAN:   return _TAN_OP();
        case COT:   return _COT_OP();
        case SH:    return _SH_OP();
        case CH:    return _CH_OP();
        case TH:    return _TH_OP();
        case CTH:   return _CTH_OP();
        case LN:    return _LN_OP();
        case ASIN:  return _ASIN_OP();
        case ACOS:  return _ACOS_OP();
        case ATAN:  return _ATAN_OP();
        case ACOT:  return _ACOT_OP();

        default:
            LOG(">>> fatal error occured: operation was not found: %#04x%40s\n", node->data.operation, "[error]");
            return NULL;
        }
        break;
    default:
        LOG(">>> fatal error occured: node data type was not found: %d%40s\n", node->data_type, "[error]");
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