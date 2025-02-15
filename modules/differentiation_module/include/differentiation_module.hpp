#ifndef DIFFERENTIATION_MODULE_H
#define DIFFERENTIATION_MODULE_H

#include "debugging.hpp"
#include "tree_func.hpp"

class differentiation_module
{
public:

    differentiation_module(node_t *tree_root = nullptr): root(tree_root), diffed_root(nullptr), error_status(0) {}
    
    ~differentiation_module() {};
    
    ret_t run();
    
    node_t *return_diffed_root() {return diffed_root;}
    
private:
    
    differentiation_module(const differentiation_module &copy): root(nullptr), diffed_root(nullptr), error_status(1)
    {
        (void)copy;
        LOG("> wrong usage of differentiation module\n");
    }
    
    differentiation_module &operator=(const differentiation_module &copy)
    {
        (void)copy;
        LOG("> wrong usage of differentiation module\n");
        
        return *this;
    }

    node_t *find_differential(node_t *node);
    
    node_t *operation_differential(node_t *node);

    node_t *root;

    node_t *diffed_root;

    ret_t error_status;

};

#endif