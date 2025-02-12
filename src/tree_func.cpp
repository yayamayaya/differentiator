#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "tree_func.hpp"
#include "debugging.hpp"

node_t::~node_t()
{
    if (l_node) delete l_node;
    if (r_node) delete r_node;

    type   = 0;
    l_node = NULL;
    r_node = NULL;
    return;
}

