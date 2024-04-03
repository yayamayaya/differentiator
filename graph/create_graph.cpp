#include "create_graph.h"

int create_gparh_code(node_t *node, const int PNG_TYPE) //передавать название фотографии через аргумент и объеденять через snprintf
{
    assert(node);

    FILE *gcode = fopen("graph/graphcode.txt", "wb");
    if (!gcode)
    {
        LOG(">>> graphcode file couldn't open%40s\n", "[error]");
        return ERR;
    }
    setbuf(gcode, NULL);

    fprintf(gcode, GPRAPH_CODE_START);
    go_through_tree(gcode, node);
    fprintf(gcode, "}\n");
    LOG(">> tree was read succes fully\n");

    fclose(gcode);
    print_png(PNG_TYPE);

    return NO_ERR;
}

void print_png(const int PNG_TYPE)
{
    static int png_number = 0;
    char png_call[200] = {0};
    switch (PNG_TYPE)
    {
    case EXPR:
        snprintf(png_call, sizeof(png_call), "%s%s", DOT_CALL, "expression.png");
        break;
    case DIFF_EXPR:
        snprintf(png_call, sizeof(png_call), "%s%s", DOT_CALL, "differentiated_expression.png");
        break;
    case OP:
        snprintf(png_call, sizeof(png_call), "%sgraph/operations/operation%d.png", DOT_CALL, png_number);
        break;
    case DIFF_OP:
        snprintf(png_call, sizeof(png_call), "%sgraph/diff_operations/operation%d.png", DOT_CALL, png_number);
        break;
    default:
        LOG(">>> fatal error occured while png printing");
        break;
    }

    png_number++;
    system(png_call);

    return;
}

void clear_all_png()
{
    system("rm -f graph/operations/*");
    system("rm -f graph/diff_operations/*");
    system("rm -f differentiated_expression.png");
    system("rm -f expression.png");
}

int go_through_tree(FILE *gcode, node_t *node)
{
    assert(node);

    if (node->data_type == NUMBER)
        fprintf(gcode, GRAPH_NUMBER_NODE);
    else if (node->data_type == OPERATION)
        fprintf(gcode, GRAPH_OP_NODE);
    else if (node->data_type == VARIABLE)
        fprintf(gcode, GRAPH_VAR_NODE);
    
    
    if (!node->l && !node->r)
    {
        LOG("> the end of the tree found, the object is: %lf\n", node->data.number);
        return ERR;
    }

    if (node->l)
    {
        fprintf(gcode, "\tnode_num%p -> node_num%p;\n", node, node->l);
        go_through_tree(gcode, node->l);
        LOG("> left tree found with the pointer: %p\n", node->l);
    }
    if (node->r)
    {
        fprintf(gcode, "\tnode_num%p -> node_num%p;\n", node, node->r);
        go_through_tree(gcode, node->r);
        LOG("> right tree found with the pointer: %p\n", node->r);
    }
    
    return NO_ERR;
}