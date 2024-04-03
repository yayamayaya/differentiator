#ifndef TYPES
#define TYPES

typedef union
{
    unsigned char operation;
    double number;
    char variable;
} data_t;

typedef struct node_t
{
    data_t data;
    char data_type;

    node_t *l;
    node_t *r;
} node_t;

enum DATA_TYPES
{
    NUMBER = 1,
    OPERATION,
    VARIABLE
};

#endif