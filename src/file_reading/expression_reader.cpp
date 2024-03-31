#include "../headers/main.h"

node_t *create_expr_tree(const char* expression_file_location)
{
    assert(expression_file_location);

    char *buffer = NULL;
    node_t *tree_root = NULL;

    if (!read_file(&buffer, expression_file_location))
    {
        
        tree_root = create_tree(buffer);

        free(buffer);
    }

    LOG(">> tree was created with the root: %p", tree_root);
    return tree_root;
}

node_t *create_tree(char *buffer)
{
    assert(buffer);

    static int pos = 0;
    double number = 0;
    char character = 0;
    int scanned = 0;
    node_t *node = NULL;

    LOG("> current pos: <%d>, the rest of the expression: <<%s>>\n", pos, buffer + pos);

    if (buffer[pos] == '(')
    {
        LOG("> Found opening bracket on pos: %d\n, rest is: <<%s>>", pos, buffer + pos);
        pos++;

        if(buffer[pos] == ')')
        {
            LOG("> found empty bracket on pos: %d\n, rest is: <<%s>>", pos, buffer + pos);
            pos++;
            return NULL;
        }

        if (calloc_for_node(&node))
            return NULL;

        if (buffer[pos] == '(')
            node->l = create_tree(buffer);        

        sscanf(buffer + pos, "%lf%n", &number, &scanned);  
        if (scanned)
        {
            LOG("> number founded: %lf, on pos: '%d'\n", number, pos);
            pos += scanned;
            node->data.number = number;
            node->data_type = NUMBER;
        }
        else
        {
            sscanf(buffer + pos, "%c%n", &character, &scanned);
            LOG("> scanned character is: '%c', on pos : '%d'\n", character, pos);
            int operation = detect_operation(character);
            if (operation)
            {
                LOG("> operation was found, it's code is '%x'", operation);
                pos++;
                node->data.operation = operation;
                node->data_type = OPERATION;
            }
            else if (buffer[pos] == 'x')
            {
                LOG("> variable was found: %c\n", character);
                pos++;
                node->data.variable = character;
                node->data_type = VARIABLE;
            }
            else
            {
                LOG(">>> Data not defined%40s\n", "[error]");
                pos++;
            }
        }
        if (buffer[pos] == '(')
            node->r = create_tree(buffer);        

        if (buffer[pos] == ')')
        {
            LOG("> found closing bracket\n");
            pos++;
        }
        else
        {
            LOG(">>> syntax error, please check your spelling\n");
            return NULL;
        }

        LOG(">> node was created with the pointer: %p\n", node);     
        return node;           
    }
    else
    {
        LOG(">>> syntax error, please check your spelling%40s\n", "[error]");
        return NULL;
    }

    return NULL;
}

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

    LOG(">>> operation not found%40s\n", "[error]");
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