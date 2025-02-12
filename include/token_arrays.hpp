#ifndef TOKEN_ARR_HDR
#define TOKEN_ARR_HDR

#include "tree_func.hpp"
#include "debugging.hpp"
#include <memory.h>
#include <stdlib.h>

struct token_t
{
    token_t(): data(), type(0) {}
    ~token_t() {}

public:
    data_t  data;
    int     type;
};

class tokens_arr
{
public:
    tokens_arr(): tokens(new token_t[init_size]), array_size(init_size), token_num(0) {};

    tokens_arr(const tokens_arr& copy): tokens(copy.tokens), array_size(copy.array_size), token_num(copy.token_num) {};

    tokens_arr& operator=(const tokens_arr& copy)
    {
        token_t *new_tokens = new token_t[copy.array_size];
        _RETURN_ON_TRUE(!new_tokens, *this);

        std::copy(copy.tokens, copy.tokens + copy.token_num, new_tokens);
        
        delete [] tokens;

        tokens      = new_tokens;
        array_size  = copy.array_size;
        token_num   = copy.token_num;

        return *this;
    }

    ~tokens_arr ();

    ret_t           add_token(const token_t token);

    unsigned long   tokens_num() {return token_num;}

    token_t        *return_data();
    
    no_ret_val_t    token_dump();
    
private:
    static constexpr long int init_size = 100;

    token_t      *tokens;
    unsigned long array_size;
    unsigned long token_num;
    
    ret_t reallc_up()
    {
        array_size *= 2;
        token_t *arr_holder = new token_t[array_size];
        if (!arr_holder) return MEM_RLC_ERR;

        std::copy(tokens, tokens + token_num, arr_holder);

        delete [] tokens;

        tokens = arr_holder;
        return 0;
    }
};

#endif