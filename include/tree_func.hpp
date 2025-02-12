#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

using number_t    = double;
using operation_t = unsigned char;
using var_t       = char;
using node_type   = unsigned char;

enum DATA_TYPES
{
    NUMBER      = 1,
    OPERATION   = 2,
    VARIABLE    = 3
};

union data_t
{
    data_t() {}

    data_t(number_t num):   number(num)   {}
    
    data_t(operation_t op): operation(op) {}
    
    data_t(var_t var):      variable(var) {}
    
    ~data_t() {}

    number_t        number;
    operation_t     operation;
    var_t           variable;
};

class node_t
{
private:
    data_t      data;
    node_type   type;

public:
    struct node_t *l_node;
    struct node_t *r_node;

    node_t(const number_t number, node_t *l, node_t *r): data({number}), type(NUMBER), l_node(l), r_node(r) {};

    node_t(const operation_t operation, node_t *l, node_t *r): data({operation}), type(OPERATION), l_node(l), r_node(r) {};

    node_t(const var_t variable, node_t *l, node_t *r): data ({variable}), type(VARIABLE), l_node(l), r_node(r) {};

    node_t(const node_t &copy): data(copy.data), type(copy.type), l_node(copy.l_node), r_node(copy.r_node) {};
    
    ~node_t();

    node_t &operator=(const node_t &copy)
    {
        data = copy.data;
        type = copy.type;

        delete l_node;
        delete r_node;

        l_node = copy.l_node;
        r_node = copy.r_node;

        return *this;
    }
};


#endif