#include "create_node.h"

void node_print(const node_t *node);

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

    node_print(node);

    return node;
}

node_t *create_node(const char data, int data_type, node_t *left_node, node_t *right_node)
{
    printf(">> data given is: <%d>\n", data);

    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
    {
        LOG(">>> can't allocate memory for node%40s\n", "[error]");
        return NULL;
    }

    node->data_type = data_type;
    if (node->data_type == VARIABLE)
        node->data.variable = data;
    else if (node->data_type == OPERATION)
        node->data.operation = data;
    
    node->l = left_node;
    node->r = right_node;

    node_print(node);

    return node;
}

void node_print(const node_t *node)
{
    assert(node);

    setbuf(stdout, NULL);

    printf(">> printing node number: %p\n", node);

    switch (node->data_type)
    {
    case NUMBER:
        printf("DATA: <%.2lf>\n", node->data.number);
        break;
    case OPERATION:
        printf("DATA: <%#04x>\n", node->data.operation);
        break;
    case VARIABLE:
        printf("DATA: <%c>\n", node->data.variable);
        break;

    default:
        break;
    }

    printf("DATA_TYPE: <%d>\n", node->data_type);
    printf("LEFT_PTR: <%p>\n", node->l);
    printf("RIGHT_PTR: <%p>\n", node->r);
    printf(">> node was printed.\n\n");
    return;
}