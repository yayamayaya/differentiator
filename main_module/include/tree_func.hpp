#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include "operations.hpp"
#include "tree_graphics.hpp"
#include <string>

using number_t    = double;
using var_t       = char;

enum data_types_t
{
    NUMBER      = 1,
    OPERATION   = 2,
    VARIABLE    = 3,

    NO_TYPE     = 0
};

union data_t
{
    data_t() {}

    data_t(number_t num):        number(num)   {}
    
    data_t(enum operation_t op): operation(op) {}
    
    data_t(var_t var):           variable(var) {}
    
    ~data_t() {}

    number_t             number;
    enum operation_t     operation;
    var_t                variable;
};

class node_t
{
private:
    data_t         data;
    data_types_t   type;

    friend no_ret_val_t go_through_tree(std::FILE *code_file, node_t *node);

public:
    struct node_t *l_node;
    struct node_t *r_node;
    
    node_t(const number_t number): data({number}), type(NUMBER), l_node(nullptr), r_node(nullptr) {};
    
    node_t(const operation_t operation, node_t *l, node_t *r): data({operation}), type(OPERATION), l_node(l), r_node(r) {};
    
    node_t(const var_t variable): data ({variable}), type(VARIABLE), l_node(nullptr), r_node(nullptr) {};
    
    node_t(const node_t &copy): data(copy.data), type(copy.type), l_node(copy.l_node), r_node(copy.r_node) {};

    node_t(const node_t *copy): data(copy->data), type(copy->type), l_node(nullptr), r_node(nullptr)
    {
        if (copy->l_node)
            l_node = new node_t(copy->l_node);
        if (copy->r_node)
            r_node = new node_t(copy->r_node);
        
        return;
    }
        
    no_ret_val_t print_in_line(FILE *file);
    
    node_t(const data_t &c_data, data_types_t c_type): data(c_data), type(c_type), l_node(nullptr), r_node(nullptr) {};

    ~node_t();

    node_t &operator=(const node_t &copy)
    {
        node_t *copied_node = new node_t(copy.data, copy.type);

        copied_node->l_node = copy.l_node;
        copied_node->r_node = copy.r_node;

        delete l_node;
        delete r_node;

        data     = copied_node->data;
        type     = copied_node->type;
        l_node   = copied_node->l_node;
        r_node   = copied_node->r_node;

        return *this;
    }

    node_t *replace_node(const node_t *copy);

    node_t *replace_node(const number_t num);

    no_ret_val_t put_x_value (const number_t num);

    int create_gparh_code(const std::string file_name);

    no_ret_val_t print_binary_op(FILE *file);

    no_ret_val_t print_unary_op(FILE *file);

    no_ret_val_t print_expr_in_brack_if_needed(FILE *file, operation_t parent_op);

    no_ret_val_t check_for_negative_power();

    ret_t check_for_sqrt(FILE *file);

    friend class simplificator;
    friend class calculator;
    friend class differentiation_module;
    friend class differentiator;
};

#endif