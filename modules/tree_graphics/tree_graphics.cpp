/*#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tree_graphics.h"


no_ret_val_t print_png();

int create_gparh_code(node_t *root)
{
    assert(root);

    FILE *code_file = fopen("graph/graphcode.txt", "wb");
    _RETURN_ON_TRUE(!code_file, FILE_OPN_ERR, LOG_ERR("> couldn't open graph code file:"));

    setbuf(code_file, NULL);

    LOG("> generating graphviz code");
    fprintf(code_file, GPRAPH_CODE_START);
    go_through_tree(code_file, root);
    fprintf(code_file, GRAPH_CODE_END);
    LOG(">> tree was read succesfully\n");

    fclose(code_file);

    print_png();

    return NO_ERR;
}

int go_through_tree(FILE *code_file, node_t *node)
{
    assert(code_file);
    assert(node);

    if      (node->type == NUMBER)
        fprintf(code_file, GRAPH_NUMBER_NODE);
    else if (node->type == OPERATION)
        fprintf(code_file, GRAPH_OP_NODE);
    else if (node->type == VARIABLE)
        fprintf(code_file, GRAPH_VAR_NODE);
    
    if (!node->l_node && !node->r_node)
        LOG("> the end of the tree found, the object is: %lf\n", node->data.number);

    if (node->l_node)
    {
        fprintf(code_file, LEFT_NODE);
        go_through_tree(code_file, node->l_node);
        LOG("> left tree found with the pointer: %p\n", node->l_node);
    }
    if (node->r_node)
    {
        fprintf(code_file, RIGHT_NODE);
        go_through_tree(code_file, node->r_node);
        LOG("> right tree found with the pointer: %p\n", node->r_node);
    }
    
    return NO_ERR;
}

no_ret_val_t print_png()
{
    system(PRINT_CMD);

    return;
}

no_ret_val_t clear_old_graphics()
{
    DIR *dir = opendir(GRAPHICS_DIR);
    if (!dir)
    {
#ifdef GRAPH
        LOG("> no old graphics folder present, creating graphics folder...");
        int ret_val = mkdir(GRAPHICS_DIR, 0666);
        if (ret_val == -1) LOG_ERR("> dir create error:");
#endif
        return;
    }
    
    _RETURN_ON_TRUE(chdir(GRAPHICS_DIR) == -1,, LOG_ERR("> chdir error:"));

    while (1)
    {
        struct dirent *dir_info = readdir(dir);
        if (!dir_info) break;
        if (dir_info->d_type == DT_REG)
            unlink(dir_info->d_name);
    }

    closedir(dir);

    chdir("../");
    return;
}*/