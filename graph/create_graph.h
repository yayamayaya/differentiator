#ifndef GRAPH_CREATE
#define GRAPH_CREATE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/headers/types.h"
#include "../src/headers/log.h"

#define EXPR_LOC "data/expression_to_diff.txt"
#define PNG_LOC "dot graph/graphcode.txt -Tpng -otree.png"

#define GPRAPH_CODE_START   "digraph G\n\
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
#define GRAPH_NUMBER_NODE   "\tnode_num%p [shape = \"record\", color=\"#478056\", label = \"{%.2lf | {NUM | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.number, node, node->l, node->r
#define GRAPH_OP_NODE       "\tnode_num%p [shape = \"record\", color=\"#632b2b\", label = \"{%#04x | {OP | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.operation, node, node->l, node->r
#define GRAPH_VAR_NODE      "\tnode_num%p [shape = \"record\", color=\"#70578a\", label = \"{%c | {VAR | %p} | {%p | %p}}\"];\n", \
                                                                                node, node->data.variable, node, node->l, node->r


#define DOT_CALL    "dot graph/graphcode.txt -Tpng -o"

enum PNG_NAMES
{
    EXPR = 0,
    DIFF_EXPR,
    OP,
    DIFF_OP,
};

enum GRAPH_ERRORS
{
    ERR = 1,
    NO_ERR = 0,
};

int create_gparh_code(node_t *node, const int PNG_TYPE);
void print_png(const int PNG_TYPE);
void clear_all_png();
int go_through_tree(FILE *gcode, node_t *node);

#endif