#ifndef OPERATIONS_H
#define OPERATIONS_H

#define OPERATIONS_NUMBER 20

typedef struct
{
    const char* operation;
    int operation_number;
} operation_t;

enum OPERATIONS
{
    ADD         = 0x01,
    SUB         = 0x02,
    MULT        = 0x03,
    DIV         = 0x04,
    POW         = 0x05,

    SIN         = 0x10,
    COS         = 0x11,
    TAN         = 0x12,
    COT         = 0x13,

    SH          = 0x20,
    CH          = 0x21,
    TH          = 0x22,
    CTH         = 0x23,

    LOG         = 0x30,
    LN          = 0x31,
    LG          = 0x32,

    ASIN        = 0x40,
    ACOS        = 0x41,
    ATAN        = 0x42,
    ACOT        = 0x43,

};

/*#define SUM +
#define SUB -
#define MUL *
#define DIVISION */

extern operation_t operations[OPERATIONS_NUMBER];

#endif