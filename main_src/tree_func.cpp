#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include "tree_func.hpp"
#include "debugging.hpp"

node_t *node_t::replace_node(const node_t *copy)
{
    assert(copy);

    node_t *new_r_node = nullptr;
    node_t *new_l_node = nullptr;

    if (copy->l_node)
        new_l_node = new node_t(copy->l_node);
    if (copy->r_node)
        new_r_node = new node_t(copy->r_node);
        
    data    = copy->data;
    type    = copy->type;
    
    delete l_node;
    delete r_node;

    l_node  = new_l_node;
    r_node  = new_r_node;

    return this;
}

node_t *node_t::replace_node(const number_t num)
{
    delete l_node;
    delete r_node;

    data    = num;
    type    = NUMBER;
    l_node  = nullptr;
    r_node  = nullptr;

    return this;
}

no_ret_val_t node_t::put_x_value (const number_t num)
{
    assert(!std::isnan(num));

    if (type == VARIABLE)
    {
        assert(!l_node && !r_node);

        replace_node(num);

        return;
    }

    if (l_node) 
        l_node->put_x_value(num);
    if (r_node)
        r_node->put_x_value(num);
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

