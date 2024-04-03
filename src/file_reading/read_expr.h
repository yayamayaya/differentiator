#ifndef READ_EXPR
#define READ_EXPR

#include "../headers/types.h"

node_t *create_expr_tree(const char* expression_file_location);
node_t *create_tree(char *buffer);
int calloc_for_node(node_t **node);
int detect_operation(const char character);
int tree_kill(node_t *node);

#endif