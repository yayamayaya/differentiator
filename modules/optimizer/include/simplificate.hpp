#ifndef SIMPLIF_H
#define SIMPLIF_H

#include "tree_func.hpp"

class simplificator
{
private:
    node_t *root;

    bool simplif_continue_status;

    bool zero_div;

    node_t *simplificate(node_t *self);

    node_t *zero_opt(node_t *self);

    node_t *case_zero_on_zero(node_t *self);

    node_t *one_opt(node_t *self);

    node_t *case_one_on_one(node_t *self);

    bool check_node_for_value(const node_t *self, number_t value);

    static constexpr double epsilon = 1.0e-05;

    simplificator(const simplificator& simpl): root(nullptr), simplif_continue_status(false), zero_div(true) 
    {
        (void)simpl;
        LOG("> wrong usage of simplificator class\n");
    }
    
    simplificator &operator=(const simplificator& simpl) 
    {
        (void)simpl;
        LOG("> wrong usage of simplificator class\n");
    
        return *this;
    }

public:

    simplificator(node_t *root_node = nullptr): root(root_node), simplif_continue_status(true), zero_div(false) {};

    ~simplificator() {};

    node_t *simplificate();

    bool check_for_zero_div() {return zero_div;}
};

#endif