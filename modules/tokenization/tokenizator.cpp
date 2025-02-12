#include <iostream>
#include <assert.h>
#include <string>
#include "operations.hpp"
#include "debugging.hpp"
#include "tokenizator.hpp"

using std::string;

static token_t detect_token(const string &buff, unsigned int &pos);

ret_t tokenization::tokenizator(token_t *&token_arr, const char *expr_argv)
{
    _RETURN_ON_TRUE(!expr_argv, NO_ARGV_STRING_ERR, LOG("> no argument given\n"));

    LOG("> starting tokenization...\n");

    LOG("> copying expression to a new string\n");
    const string expression = expr_argv;
    _RETURN_ON_TRUE(expression.size() == 0, NO_ARGV_STRING_ERR, LOG("> emtpy string error\n"));
    
    LOG("> initialising token array\n");
    tokens_arr tokens = {};

    LOG("> starting tokens detection\n");
    for (unsigned int pos = 0; pos < expression.size();)
    {
        token_t token = detect_token(expression, pos);
        if (token.type == SPACE_SYMB) 
            continue;

        if (token.type == SYNTAX_NOT_DET) 
            return SYNTAX_ERR;

        if (token.type != SPACE_SYMB)
        {
            _RETURN_ON_TRUE(tokens.add_token(token), MEM_RLC_ERR);

            continue;
        }

        return FATAL_ERR;
    }

    tokens.token_dump();
    LOG("> tokenization is finished\n");

    token_arr = tokens.return_data();

    return 0;
}

static token_t detect_token(const string &buff, unsigned int &pos)
{
    token_t token = {};

    LOG("> current pos: %d, the rest is: %s\n", pos, buff.data() + pos);

    if (isspace(*(buff.data() + pos)))
    {
        pos++;

        token.type = SPACE_SYMB;
        return token;
    }
    
    int n = 0;
    double number = 0;
    sscanf(buff.data() + pos, "%lf%n", &number, &n);
    if (n)
    {
        LOG("> number '%lf' detected\n", number);

        pos += (unsigned int)n;

        token.data.number = number;
        token.type = NUMBER;
        return token;
    }
    
    if (*(buff.data() + pos) == 'x')
    {
        LOG("> variable detected\n");
        
        pos++;
        
        token.data.variable = 1;
        token.type = VARIABLE;

        return token;
    }

    operation_t op_code = arithm_operations::find_operation(buff.data(), pos);
    if (op_code)
    {
        LOG("> operation '%d' detected \n", op_code);

        token.data.operation = op_code;
        token.type = OPERATION;
        return token;
    }    

    LOG("> couldn't detect token, syntax error\n");
    token.type = SYNTAX_NOT_DET;
    return token;
}

