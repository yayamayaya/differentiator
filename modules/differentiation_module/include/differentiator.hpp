#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include "debugging.hpp"
#include "tree_func.hpp"

class differentiation_module
{
public:

    differentiation_module(node_t *tree_root): root(tree_root), diffed_root(nullptr), error_status(0) {}

    differentiation_module(const differentiation_module &copy): root(nullptr), diffed_root(nullptr), error_status(1)
    {
        (void)copy;
        LOG("> wrong usage of differentiation module\n");
    }

    ~differentiation_module() {};

    differentiation_module &operator=(const differentiation_module &copy)
    {
        (void)copy;
        LOG("> wrong usage of differentiation module\n");

        return *this;
    }
    
    ret_t run();

    node_t *return_diffed_root() {return diffed_root;}

private:

    node_t *find_differential(node_t *node);

    node_t *operation_differential(node_t *node);

    node_t *root;

    node_t *diffed_root;

    ret_t error_status;

};

#endif