#include "create_graph.h"

int create_gparh_code();
int go_through_tree(FILE *gcode, node_t *node);

int main()
{
    OPEN_LOG_FILE();
    if (create_gparh_code())
        return ERR;
    LOG("> graphcode created successfully\n");

    system(PNG_LOC);
    LOG(">>> graph was created, eop%s", "[success]");
    CLOSE_LOG_FILE();

    return NO_ERR;
}

int create_gparh_code()
{
    node_t *root = create_expr_tree(EXPR_LOC);
    if (!root)
    {
        LOG(">>> couldn't create an expression tree%40s\n", "[error]");
        return ERR;
    }

    FILE *gcode = fopen("graph/graphcode.txt", "wb");
    if (!gcode)
    {
        LOG(">>> graphcode file couldn't open%40s\n", "[error]");
        return ERR;
    }
    setbuf(gcode, NULL);

    fprintf(gcode, GPRAPH_CODE_START);
    go_through_tree(gcode, root);
    fprintf(gcode, "}\n");
    LOG(">> tree was read succesfully\n");

    fclose(gcode);
    tree_kill(root);

    return NO_ERR;
}

int go_through_tree(FILE *gcode, node_t *node)
{
    assert(node);

    if (node->data_type == NUMBER)
        fprintf(gcode, GRAPH_NUMBER_NODE);
    else if (node->data_type == OPERATION)
        fprintf(gcode, GRAPH_OP_NODE);
    
    if (!node->l && !node->r)
    {
        LOG("> the end of the tree found, the object is: %lf\n", node->data.number);
        return 1;
    }

    if (node->l)
    {
        fprintf(gcode, "\t%d -> %d;\n", node, node->l);
        go_through_tree(gcode, node->l);
        LOG("> left tree found with the pointer: %p\n", node->l);
    }
    if (node->r)
    {
        fprintf(gcode, "\t%d -> %d;\n", node, node->r);
        go_through_tree(gcode, node->r);
        LOG("> right tree found with the pointer: %p\n", node->r);
    }
    
    return 0;
}