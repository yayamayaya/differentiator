#include "simplificate.hpp"
#include <assert.h>
#include <iostream>
#include <cmath>

node_t *simplificator::simplificate()
{
    return simplificate(root);
}

node_t *simplificator::simplificate(node_t *self)
{
    if (self == NULL) return NULL;
    if (self == root) simplif_continue_status = false;

    if (self->type == OPERATION)
        self = zero_opt(self);        
    if (self->type == OPERATION)
        self = one_opt(self);

    _RETURN_ON_TRUE(!self,    NULL);
    _RETURN_ON_TRUE(zero_div, NULL);

    LOG("> calling recursive simplification\n");

    self->l_node = simplificate(self->l_node);
    self->r_node = simplificate(self->r_node);

    if (self == root && simplif_continue_status) 
        self = simplificate(self);

    return self;
} 

node_t *simplificator::zero_opt(node_t *self)
{
    assert(self);
    assert(self->type == OPERATION);

    if (!self->l_node || !self->r_node) return self;

    node_t *node_without_zero   = NULL;

    LOG("> checking node %p for zero optimization\n", self);

    bool l_node_zero = check_node_for_value(self->l_node, 0);
    bool r_node_zero = check_node_for_value(self->r_node, 0);

    if (l_node_zero && r_node_zero)
        return case_zero_on_zero(self);
    if (l_node_zero)
        node_without_zero = self->r_node;      
    if (r_node_zero)
        node_without_zero = self->l_node;

    if (!node_without_zero) return self;
    
    char sw_value = self->data.operation;
    switch (sw_value)
    {
    case ADD:
    case SUB:
        simplif_continue_status = true;
        
        return self->replace_node(node_without_zero);

    case DIV:
        if (node_without_zero == self->l_node)
        {
            printf("> you can't divide on zero!\n");
            zero_div = true;
            return self;
        }
        [[fallthrough]];
    case MULT:
        simplif_continue_status = true;

        return self->replace_node(0.0);

    case POW:
        simplif_continue_status = true;

        if (node_without_zero == self->r_node)
            return self->replace_node(0.0);
        else
            return self->replace_node(1.0);
        
    default:
        break;
    }
    
    return self;
}

node_t *simplificator::case_zero_on_zero(node_t *self)
{
    assert(self->type == OPERATION);

    char sw_value = self->data.operation;
    switch (sw_value)
    {

    case ADD:
    case SUB:
    case MULT:
        return self->replace_node(0.0);

    case DIV:
        std::cout << "> zero on zero division\n";
        zero_div = true;
        
        return self;
    
    case POW:
        return self->replace_node(1.0);

    default:
        break;

    }

    return self;
}

node_t *simplificator::one_opt(node_t *self)
{    
    assert(self);
    assert(self->type == OPERATION);

    if (!self->l_node || !self->r_node) return self;

    node_t *node_without_one    = NULL;

    LOG("> checking node %p for zero optimization\n", self);

    bool l_node_one = check_node_for_value(self->l_node, 1);
    bool r_node_one = check_node_for_value(self->r_node, 1);

    if (l_node_one && r_node_one)
        return case_one_on_one(self);
    if (l_node_one)
        node_without_one = self->r_node;      
    if (r_node_one)
        node_without_one = self->l_node;

    if (!node_without_one) return self;

    char sw_value = self->data.operation;
    switch (sw_value)
    {
    case DIV:
        if (node_without_one == self->r_node)
            return self;
        [[fallthrough]];
    case MULT:
        simplif_continue_status = true;

        return self->replace_node(node_without_one);

    case POW:
        simplif_continue_status = true;
        
        if (node_without_one == self->r_node)
            return self->replace_node(1.0);
        else
            return self->replace_node(node_without_one);
        
    default:
        break;
    }
    
    return self;
}

node_t *simplificator::case_one_on_one(node_t *self)
{
    assert(self->type == OPERATION);

    char sw_value = self->data.operation;
    switch (sw_value)
    {

    case ADD:   return self->replace_node(2.0);

    case SUB:   return self->replace_node(0.0);

    case POW:
    case DIV:
    case MULT:  return self->replace_node(1.0);

    default:
        LOG("> fatal error");
        break;
    }

    return NULL;
}

bool simplificator::check_node_for_value(const node_t *self, number_t value)
{
    assert(self);

    return self->type == NUMBER && fabs(self->data.number - value) < epsilon;
}

