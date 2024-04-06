#ifndef TOKENIZATOR_H
#define TOKENIZATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "../../../common/log/log.h"
#include "../../../common/tree_func/types.h"
#include "../headers/operations.h"
#include "../../../common/file_reading/file_reader.h"

typedef struct
{
    data_t data;
    int data_type;
} token_t;

enum TOK_ERRORS
{
    SYNTAX_ERR = 5,
    MEM_ALC_ERR = 15,
};

enum TOKEN_TYPE
{
    SPACE_SYMB = 0,
    SYNTAX_NOT_DET = 5,
};

int tokenizator(token_t **token_arr_ptr, const char *file_name);
token_t *token_realloc(token_t *token_arr, int arr_size);
token_t detect_token(char *buff, int *pos);

#endif