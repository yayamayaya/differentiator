#ifndef GRAPH_CREATE
#define GRAPH_CREATE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/headers/main_header.h"

#define EXPR_LOC "data/expression_to_diff.txt"
#define PNG_LOC "dot graph/graphcode.txt -Tpng -otree.png"

#ifdef DEBUG
#define OPEN_LOG_FILE() diff_log = fopen("log/graph_creation.log", "wb");   \
    if (!diff_log)                                                          \
    {                                                                       \
        fprintf(stderr, ">>> Couldn't open logfile.");                      \
        return ERR;                                                         \
    }                                                                       \
    setbuf(diff_log, NULL)
    
#define CLOSE_LOG_FILE() fclose(diff_log)
#else
#define OPEN_LOG_FILE() do {} while (0)
#define CLOSE_LOG_FILE() do {} while (0)
#endif

//#define SYSTEM_CALL(codeName, pictureName)  "dot  "#codeName"-Tpng -o"#pictureName

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

#endif