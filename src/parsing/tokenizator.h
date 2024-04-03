#ifndef TOKENIZATOR_H
#define TOKENIZATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "../headers/log.h"
#include "../headers/types.h"
#include "../headers/operations.h"
#include "../file_reading/file_reader.h"

typedef struct
{
    data_t data;
    int data_type;
} token_t;

int tokenizator(token_t **token_arr_ptr, const char *file_name);
token_t *token_realloc(token_t *token_arr, int arr_size);
token_t detect_token(char *buff, int *pos);

#endif