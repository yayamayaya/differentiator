#ifndef TOKENIZATOR_H
#define TOKENIZATOR_H

#include "token_arrays.hpp"

enum TOK_ERRORS
{
    SYNTAX_ERR  = 5,
    MEM_ALC_ERR = 15,
};

enum TOKEN_TYPE
{
    SPACE_SYMB      = 0,
    SYNTAX_NOT_DET  = 5,
};

namespace tokenization
{
    ret_t tokenizator(token_t * &token_arr_ptr, const std::string expression);
}


#endif