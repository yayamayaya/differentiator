#include "differentiator.hpp"
#include "differentiator_DSL.hpp"
#include "tree_func.hpp"
#include "operations.hpp"
#include <assert.h>

ret_t differentiation_module::run()
{
    LOG("> starting differentiation\n");

    diffed_root = find_differential(root);
    if (error_status) 
        delete root;

    return error_status;
}

node_t *differentiation_module::find_differential(node_t *node)
{
    assert(node);

    switch (node->type)
    {

    case NUMBER:    return new node_t(0.0);
    
    case VARIABLE:  return new node_t(1.0);
    
    case OPERATION: return operation_differential(node);        

    case NO_TYPE:
        [[fallthrough]];
    default:
        LOG("> fatal error, wrong node type\n");
        error_status = WRONG_TYPE_ERR;

        return node;

    }

    return node;
}

node_t *differentiation_module::operation_differential(node_t *node)
{
    assert(node);
    assert(node->type == OPERATION);

    switch (node->data.operation)
    {
    case ADD:
        [[fallthrough]];
    case SUB:   return _SUM_OP  ();
    case MULT:  return _MULT_OP ();
    case DIV:   return _DIV_OP  ();
    case POW:   return _POW_OP  ();
    case SIN:   return _SIN_OP  ();
    case COS:   return _COS_OP  ();
    case TAN:   return _TAN_OP  ();
    case COT:   return _COT_OP  ();
    case SH:    return _SH_OP   ();
    case CH:    return _CH_OP   ();
    case TH:    return _TH_OP   ();
    case CTH:   return _CTH_OP  ();
    case LN:    return _LN_OP   ();
    case LG:    return _LG_OP   ();
    case ASIN:  return _ASIN_OP ();
    case ACOS:  return _ACOS_OP ();
    case ATAN:  return _ATAN_OP ();
    case ACOT:  return _ACOT_OP ();

    case SQRT:
    case OP_BRACK:
    case CL_BRACK:
    case NO_OP:
        [[fallthrough]];
    default:
        LOG("> fatal error, unexisting operation\n");
        error_status = OP_WASNT_FOUND_ERR;

        return node;
    }

    return node;
}