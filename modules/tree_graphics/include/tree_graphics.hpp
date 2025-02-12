#ifndef GRAPH_CREATE
#define GRAPH_CREATE

#include "debugging.hpp"
#include "tree_func.hpp"

#define GRAPHICS_DIR        "./tree_graphics/"
#define GRAPH_CODE_LOCATION "tree_graphics/graph_code"

#define GPRAPH_CODE_START \
"digraph G\n\
{\n\
    graph [dpi = 1000];\n\
    bgcolor = \"#9F8C76\"\n\
\n\
    node[shape = \"box\", style = \"rounded, filled\",\n\
    height = 1, width = 2,\n\
    fillcolor = \"#F5F5DC\",\n\
    fontsize = 17,\n\
    fontname = \"Courier New\",\n\
    fontcolor = \"#1a1718\",\n\
    penwidth = 2, color = \"#1a1718\"\n\
    ]\n\n\
"
#define GRAPH_CODE_END "}\n"

#define GRAPH_NUMBER_NODE   "\tnode_num%p [shape = \"record\", color=\"#478056\", label = \"{%.2lf | {NUM | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.number, node, node->l_node, node->r_node
#define GRAPH_OP_NODE       "\tnode_num%p [shape = \"record\", color=\"#632b2b\", label = \"{%d | {OP | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.operation, node, node->l_node, node->r_node
#define GRAPH_VAR_NODE      "\tnode_num%p [shape = \"record\", color=\"#70578a\", label = \"{%d | {VAR | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.variable, node, node->l_node, node->r_node


#define LEFT_NODE           "\tnode_num%p -> node_num%p;\n", node, node->l_node
#define RIGHT_NODE          "\tnode_num%p -> node_num%p;\n", node, node->r_node

#define DOT_CALL    "dot tree_graphics/graphcode.txt -Tpng -o./tree_graphics/"

//#define GRAPH

#ifdef GRAPH
#define _CREATE_GRAPH(arg1, arg2)\
    create_gparh_code(arg1, arg2)
#else
#define _CREATE_GRAPH(arg1, arg2)
#endif

no_ret_val_t clear_old_graphics();

#endif