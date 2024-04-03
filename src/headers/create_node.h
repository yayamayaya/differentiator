#ifndef NODE_CR
#define NODE_CR


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"
#include "operations.h"
#include "log.h"

node_t *create_node(double data, int data_type, node_t *left_node, node_t *right_node);
//node_t *create_node(enum OPERATIONS data, int data_type, node_t *left_node, node_t *right_node);
node_t *create_node(const char data, int data_type, node_t *left_node, node_t *right_node);

#endif