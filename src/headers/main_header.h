#ifndef DIFF_HEADER
#define DIFF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "../../../ilab/common/log.h"
#include "operations.h"
#include "../../graph/create_graph.h"
//#include "expr_calc.h"


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
};

enum DATA_TYPES
{
    NUMBER = 1,
    OPERATION,
    VARIABLE
};

//From file_reader
int read_file(char **buffer_ptr, const char *expression_file_loc);
int get_file_size(FILE *expr_file);

//From expression_reader
node_t *create_expr_tree(const char* expression_file_location);
node_t *create_tree(char *buffer);
int calloc_for_node(node_t **node);
int detect_operation(const char character);
int tree_kill(node_t *node);

//From expression calculator
int calculate(node_t *root);
node_t *calculate_tree(node_t *node);
double make_operation(double first_arg, double second_arg, char operation_number);
void op_to_num_node(node_t *node);

//From graph code creator
int create_gparh_code(node_t *node, const int PNG_TYPE);
void print_png(const int PNG_TYPE);
void clear_all_png();
int go_through_tree(FILE *gcode, node_t *node);

//From create_node
node_t *create_node(double data, int data_type, node_t *left_node, node_t *right_node);
node_t *create_node(enum OPERATIONS data, int data_type, node_t *left_node, node_t *right_node);
node_t *create_node(const char data, int data_type, node_t *left_node, node_t *right_node);

//From differentiate
node_t *differen(node_t *node);
node_t *copy_node(node_t *node);

#endif