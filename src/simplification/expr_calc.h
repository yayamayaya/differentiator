#ifndef EXPR_CALC
#define EXPR_CALC

#include "../headers/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum CALC_ERRORS
{
    NUMBER_IN_ROOT = 501,

};

int calculate(node_t *root);
node_t *calculate_tree(node_t *node);
double make_operation(double first_arg, double second_arg, char operation_number);
void op_to_num_node(node_t *node);

#endif