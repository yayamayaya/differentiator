#include "main_header.h"

node_t *create_expr_tree(const char* expression_file_location)
{
    assert(expression_file_location);

    char **tokens = NULL;
    node_t *tree_root = NULL;

    if (!read_file(&tokens, expression_file_location))
    {
        tree_root = create_tree(tokens);

        free(*tokens);
        free(tokens);
    }

    LOG(">> tree was created with the root: %p", tree_root);
    return tree_root;
}

node_t *create_tree(char **tokens)
{
    assert(tokens);

    static int pos = 0;
    double number = 0;
    char character = 0;
    int scanned = 0;
    node_t *node = NULL;

    static Stack <node_t *> treeStack= {};

    if (*tokens[pos] == '(')
        if(treeStack.stackPush(create_tree(tokens)))
    
    sscanf(tokens[pos], "%lf%n", &number, &scanned);
    if (scanned)
    {
        calloc_for_node(&node);
        node->data.number = number;
        node->data_type = NUMBER;
        treeStack.stackPush(node);
    }
    character = detect_operation(*tokens[pos]);
    if (character & M_D)
    {
        calloc_for_node(&node);
        node->data.operation = character;
        node->data_type = OPERATION;
        treeStack.stackPop(&node->l);
        node->r
    }
    
    
    
}

int


int calloc_for_node(node_t **node)
{
    *node = (node_t *)calloc(1, sizeof(node_t));
    if (!node)
    {
        LOG(">>> can't allocate memory for node%40s\n", "[error]");
        return NODE_MEM_ALC_ERR;
    }

    return 0;
}

int detect_operation(const char character)
{
    for (int i = 0; i < OPERATIONS_NUMBER; i++)
        if (character == *operations[i].operation)
            return operations[i].operation_number;

    LOG("> operation not found\n");
    return 0;
}

int tree_kill(node_t *node)
{
    assert(node != NULL);

    if (node->l != NULL)
        tree_kill(node->l);
    if (node->r != NULL)
        tree_kill(node->r);

    free(node);

    return 0;
}