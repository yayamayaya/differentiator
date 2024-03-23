#ifndef OPERATIONS_H
#define OPERATIONS_H

#define OPERATIONS_NUMBER 4

typedef struct
{
    const char* operation;
    int operation_number;
} operation_t;

enum OPERATIONS
{
    PLUS        = 0x01,
    MINUS       = 0x02,
    MULT        = 0x03,
    DIV         = 0x04,
};

extern operation_t operations[OPERATIONS_NUMBER];

#endif