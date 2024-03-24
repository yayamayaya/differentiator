#ifndef DIFF_HEADER
#define DIFF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../ilab/common/log.h"
#include "operations.h"
#include "../../ilab/stack/stack.h"


#define DEBUG

extern FILE *diff_log;
#define LOG(...)  fprintf(diff_log, __VA_ARGS__)

typedef union
{
    char operation;
    double number;
    char variable;
} data_t;

typedef struct node_t
{
    data_t data;
    char data_type;

    node_t *l;
    node_t *r;
} node_t;

enum DIFF_ERRORS
{
    EXPR_FILE_OPEN_ERR      = 101,
    BUFF_MEM_ALC_ERR,
    NODE_MEM_ALC_ERR,
    TOKEN_MEM_ALC_ERR,
    TOKEN_ARR_NULL,
};

enum DATA_TYPES
{
    NUMBER = 1,
    OPERATION,
    VARIABLE
};

enum DETECT_TOKEN
{
    DETECTED = 1,
    NOT_DETECTED = 0
};

//From file_reader
int read_file(char ***token_arr_ptr, const char *expression_file_loc);
int get_file_size(FILE *expr_file);
int tokenization(char ***token_arr, char *buff, const int buff_size);
int detect_operation(char *buff, int pos);

//From expression_reader
node_t *create_expr_tree(const char* expression_file_location);
node_t *create_tree(char *buffer);
int calloc_for_node(node_t **node);
int detect_operation(const char character);
int tree_kill(node_t *node);




#endif