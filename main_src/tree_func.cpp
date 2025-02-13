#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "tree_func.hpp"
#include "debugging.hpp"

node_t *node_t::replace_node(const node_t *copy)
{
    node_t *repl_node = new node_t(copy);

    delete l_node;
    delete r_node;

    data    = repl_node->data;
    type    = repl_node->type;
    l_node  = repl_node->l_node;
    r_node  = repl_node->r_node;

    delete repl_node;

    return this;
}

node_t *node_t::replace_node(const number_t &num)
{
    delete l_node;
    delete r_node;

    data    = num;
    type    = NUMBER;
    l_node  = nullptr;
    r_node  = nullptr;

    return this;
}

node_t::~node_t()
{
    if (l_node) delete l_node;
    if (r_node) delete r_node;

    type   = NO_TYPE;
    l_node = NULL;
    r_node = NULL;
    return;
}

