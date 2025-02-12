#include <iostream>
#include "token_arrays.hpp"

tokens_arr::~tokens_arr()
{
    token_num = 0;
    delete [] tokens;
}

token_t *tokens_arr::return_data() 
{
    token_t *returning_data = new token_t[token_num + 1];
    _RETURN_ON_TRUE(!returning_data, NULL);

    std::copy(tokens, tokens + token_num, returning_data);

    return returning_data;
}

ret_t tokens_arr::add_token(const token_t token)
{
    if (token_num == array_size)
        if (reallc_up())
            return MEM_RLC_ERR;

    tokens[token_num] = token;
    token_num++;

    return 0;
}

no_ret_val_t tokens_arr::token_dump()
{
    LOG("> token dump start:\n");
    for (unsigned long pos = 0; pos < token_num; pos++)
    {
        switch (tokens[pos].type)
        {
        case NUMBER:
            LOG("> NUMBER: <%.02lf>\n", tokens[pos].data.number);
            break;

        case OPERATION:
            LOG("> OPERATION: <%#04x>\n", tokens[pos].data.operation);
            break;
        
        case VARIABLE:
            LOG("> VARIABLE: <x>\n");
            break;
        
        default:
            LOG("> fatal error\n");
            break;
        }
    }

    LOG("> token dump ended.\n");
    return;
}