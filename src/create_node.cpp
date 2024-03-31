//#include "headers/main.h"
#include "headers/create_node.h"

node_t *create_node(double data, int data_type, node_t *left_node, node_t *right_node)
{
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
    {
        LOG(">>> can't allocate memory for node%40s\n", "[error]");
        return NULL;
    }

    node->data_type = data_type;
    node->data.number = data;
    node->l = left_node;
    node->r = right_node;

    return node;
}

node_t *create_node(enum OPERATIONS data, int data_type, node_t *left_node, node_t *right_node)
{
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
    {
        LOG(">>> can't allocate memory for node%40s\n", "[error]");
        return NULL;
    }

    node->data_type = data_type;
    node->data.operation = (char)data;
    node->l = left_node;
    node->r = right_node;

    return node;
}

node_t *create_node(const char data, int data_type, node_t *left_node, node_t *right_node)
{
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
    {
        LOG(">>> can't allocate memory for node%40s\n", "[error]");
        return NULL;
    }

    node->data_type = data_type;
    node->data.variable = data;
    node->l = left_node;
    node->r = right_node;

    return node;
}

