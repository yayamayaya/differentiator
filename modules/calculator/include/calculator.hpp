#ifndef EXPR_CALC
#define EXPR_CALC

#include "tree_func.hpp"

class calculator
{
private:
    node_t *root;

    ret_t calc_status;

    node_t *calculate_tree(node_t *node);

    node_t *make_operation(node_t *node);

    node_t *unary_operation(node_t *node);

    node_t *binary_operation(node_t *node);

public:
    calculator(node_t *tree_root): root(tree_root), calc_status(0) {}

    calculator(const calculator &copy): root(NULL), calc_status(1) 
    {
        (void)copy;
        LOG("> wrong usage of calculator class\n");

        return;
    }

    ~calculator() {};

    calculator &operator=(const calculator &copy)
    {
        (void)copy;
        LOG("> wrong usage of calculator class\n");

        return *this;
    }

    ret_t run_calculator();
};

#endif