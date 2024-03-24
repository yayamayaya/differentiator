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
    MULT        = 0x04,
    DIV         = 0x08,


//Приоритеты операций
    M_D         = 0xC,
    P_M         = 0x3,

};

extern operation_t operations[OPERATIONS_NUMBER];

#endif