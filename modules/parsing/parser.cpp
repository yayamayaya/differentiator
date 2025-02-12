#include "parser.hpp"
#include "operations.hpp"
#include <assert.h>

node_t *parser_ft::pars_expr()
{
    assert(tokens);

    LOG("> starting parsing\n");
    node_t *node = pars_mult();

    LOG("> curr tok: %d\n", curr_tok);

    while (tokens[curr_tok].type == OPERATION 
        && (tokens[curr_tok].data.operation == ADD 
            || tokens[curr_tok].data.operation == SUB))
    {
        operation_t operation = tokens[curr_tok].data.operation;
        
        curr_tok++;

        LOG("> curr tok: %d\n", curr_tok);

        node = new node_t(operation, node, pars_mult());
        _RETURN_ON_TRUE(!node, NULL, LOG_ERR("> new error\n"));
    }

    _RETURN_ON_TRUE(syntax_error, NULL, delete node);
    LOG("> parsing finished\n");
    return node;
}

node_t *parser_ft::pars_mult()
{
    node_t *node = pars_power();

    while (tokens[curr_tok].type == OPERATION 
        && (tokens[curr_tok].data.operation == MULT 
            || tokens[curr_tok].data.operation == DIV))
    {
        operation_t operation = tokens[curr_tok].data.operation;
        
        curr_tok++;

        node = new node_t(operation, node, pars_power());
        _RETURN_ON_TRUE(!node, NULL, LOG_ERR("> new error\n"));
    }

    return node;
}

node_t *parser_ft::pars_power()
{
    node_t *node = pars_number();

    while (tokens[curr_tok].type == OPERATION 
        && tokens[curr_tok].data.operation == POW)
    {
        operation_t operation = tokens[curr_tok].data.operation;
        
        curr_tok++;
        
        node = new node_t(operation, node, pars_number());
        _RETURN_ON_TRUE(!node, NULL, LOG_ERR("> new error\n"));
    }

    return node;
}

node_t *parser_ft::pars_number()
{
    switch (tokens[curr_tok].type)
    {
    case OPERATION: return pars_operation();

    case NUMBER:    return new node_t(tokens[curr_tok++].data.number);

    case VARIABLE:  return new node_t(tokens[curr_tok++].data.variable);
    
    default: break;
    }

    LOG("> syntax error, please check your spelling\n");
    
    syntax_error = true;

    return NULL;
}

node_t *parser_ft::pars_op_brack()
{
    curr_tok++;

    node_t *node = pars_expr();

    if (tokens[curr_tok].data.operation != CL_BRACK)
    {
        LOG("> closing bracket wasn't found, check your spelling\n");                    

        syntax_error = true;

        delete [] node;

        return NULL;
    }

    curr_tok++;

    return node;
}

node_t *parser_ft::pars_cl_brack()
{
    LOG("> lishnee closing bracket, check your spelling\n");

    syntax_error = true;

    return NULL;
}

node_t *parser_ft::pars_sqrt()
{
    curr_tok++;

    return new node_t(POW, pars_number(), new node_t(0.5));
}

node_t *parser_ft::pars_operation()
{
    operation_t operation = tokens[curr_tok].data.operation;
    unsigned char sw_value = operation;

    switch (sw_value)
    {
    case OP_BRACK: return pars_op_brack();
    
    case CL_BRACK: return pars_cl_brack();

    case SQRT:     return pars_sqrt();

    default:       break;
    }

    curr_tok++;

    return new node_t(operation, pars_number(), NULL);
}