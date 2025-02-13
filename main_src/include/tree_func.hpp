#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include "operations.hpp"
#include "tree_graphics.hpp"
#include <string>

using number_t    = double;
//using operation_t = unsigned char;
using var_t       = char;
//using node_type   = unsigned char;

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

    data_t(number_t num):   number(num)   {}
    
    data_t(enum operation_t op): operation(op) {}
    
    data_t(var_t var):      variable(var) {}
    
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
    
    node_t(const number_t &number): data({number}), type(NUMBER), l_node(nullptr), r_node(nullptr) {};
    
    node_t(const operation_t &operation, node_t *l, node_t *r): data({operation}), type(OPERATION), l_node(l), r_node(r) {};
    
    node_t(const var_t &variable): data ({variable}), type(VARIABLE), l_node(nullptr), r_node(nullptr) {};
    
    node_t(const node_t &copy): data(copy.data), type(copy.type), l_node(copy.l_node), r_node(copy.r_node) {};

    node_t(const node_t *copy): data(copy->data), type(copy->type), l_node(nullptr), r_node(nullptr)
    {
        if (copy->l_node)
            l_node = new node_t(copy->l_node);
        if (copy->r_node)
            r_node = new node_t(copy->r_node);

        return;
    }
    
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

    node_t *replace_node(const number_t &num);

    int create_gparh_code(const std::string file_name);

    friend class simplificator;
    friend class calculator;
};


#endif