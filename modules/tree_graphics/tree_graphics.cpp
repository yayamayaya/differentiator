#include <iostream>
#include <assert.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tree_graphics.hpp"

no_ret_val_t print_png(const std::string file_name);

no_ret_val_t go_through_tree(FILE *code_file, node_t *node);

int node_t::create_gparh_code(const std::string file_name)
{
    FILE *code_file = std::fopen("tree_graphics/graphcode.txt", "wb");
    _RETURN_ON_TRUE(!code_file, FILE_OPN_ERR, LOG_ERR("> couldn't open graph code file:"));

    setbuf(code_file, NULL);

    LOG("> generating graphviz code\n");
    fprintf(code_file, GPRAPH_CODE_START);
    go_through_tree(code_file, this);
    fprintf(code_file, GRAPH_CODE_END);
    LOG(">> tree was read succesfully\n");

    fclose(code_file);

    print_png(file_name);
    return NO_ERR;
}

no_ret_val_t go_through_tree(FILE *code_file, node_t *node)
{
    assert(code_file);
    assert(node);

    if      (node->type == NUMBER)
        fprintf(code_file, GRAPH_NUMBER_NODE);
    else if (node->type == OPERATION)
        fprintf(code_file, GRAPH_OP_NODE);
    else if (node->type == VARIABLE)
        fprintf(code_file, GRAPH_VAR_NODE);

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
    
    return;
}

no_ret_val_t print_png(const std::string file_name)
{
    std::string cmd = DOT_CALL + file_name;

    std::system(cmd.c_str());

    return;
}

no_ret_val_t clear_old_graphics()
{
    DIR *dir = opendir(GRAPHICS_DIR); 
    if (!dir)
    {
        LOG("> no old graphics folder present, creating graphics folder...\n");
        int ret_val = mkdir(GRAPHICS_DIR, 0777);
        if (ret_val == -1) LOG_ERR("> dir create error:");

        clear_old_graphics();
        return;
    }
    
    _RETURN_ON_TRUE(chdir(GRAPHICS_DIR) == -1,, 
        LOG_ERR("> chdir error:");
        closedir(dir));
    
    while (1)
    {
        struct dirent *dir_info = readdir(dir);
        if (!dir_info) break;
        if (dir_info->d_type == DT_REG)
        unlink(dir_info->d_name);
    }
    
    closedir(dir);
    
    chdir("./..");
    return;
}