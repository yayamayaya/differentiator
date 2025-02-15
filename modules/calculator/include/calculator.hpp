#ifndef EXPR_CALC
#define EXPR_CALC

#include "tree_func.hpp"
#include "simplificate.hpp"

class calculator
{
private:
    node_t *root;

    static inline ret_t calc_status = 0;

    node_t *calculate_tree(node_t *node);

    node_t *make_operation(node_t *node);

    node_t *unary_operation(node_t *node);

    node_t *binary_operation(node_t *node);

    calculator(const calculator &copy): root(NULL) 
    {
        (void)copy;
        LOG("> wrong usage of calculator class\n");

        return;
    }
    
    calculator &operator=(const calculator &copy)
    {
        (void)copy;
        LOG("> wrong usage of calculator class\n");
    
        return *this;
    }

public:
    calculator(node_t *tree_root = nullptr): root(tree_root) {}

    ~calculator() {};

    ret_t run_calculator();
};

#endif