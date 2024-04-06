#ifndef EXPR_CALC
#define EXPR_CALC

#include "../headers/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _USE_MATH_DEFINES

enum CALC_ERRORS
{
    NUMBER_IN_ROOT = 501,

};

int calculate(node_t *root);
node_t *calculate_tree(node_t *node);
int make_operation(node_t *left_node, node_t *right_node, node_t *node);
void op_to_num_node(node_t *node);

#endif