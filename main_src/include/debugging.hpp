#ifndef DEBUGGING_FUNCS
#define DEBUGGING_FUNCS

typedef void   no_ret_val_t; 
typedef int    ret_t;

#define LONG_LINE "----------------------------------------------------------------------------------------------------------------\n"

#define _RETURN_ON_TRUE(statement, ret_val, ...)            \
    do                                                      \
    {                                                       \
        if (statement)                                      \
        {                                                   \
            __VA_ARGS__;                                    \
            return ret_val;                                 \
        }                                                   \
    } while (0)


enum RET_VAL
{
    NO_ERR                  = 0,
    END_OF_THE_TREE         = 41,
    NOT_ENOUGH_ARGS         = 42,

    FILE_OPN_ERR            = 71,
    MEM_RLC_ERR             = 72,
    TOKENS_ARR_ALC_ERR      = 73,
    NO_ARGV_STRING_ERR      = 74,
    WRONG_EXPR_ERR          = 75,
    WRONG_TYPE_ERR          = 76,
    OP_WASNT_FOUND_ERR      = 77,
    CALCULATION_ERR         = 78,
    NO_ARG_FOR_OPTION       = 79,
    EMPTY_EXPRESSION_ERR    = 80,
    NO_EXPRESSION_NODE_ERR  = 81,

    FATAL_ERR               = 404,
};


void open_log();

void close_log();

void loggg(const char *format, ...);

void err_log(const char *format);

#define LOG(...)        loggg(__VA_ARGS__)

#define LOG_ERR(...)    err_log(__VA_ARGS__)

#endif