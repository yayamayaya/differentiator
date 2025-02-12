#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "debugging.hpp"
#include "tree_func.hpp"

struct operation_st
{
    const char*     operation;
    operation_t     operation_number;
    unsigned int    string_length;
};

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

    LN          = 0x31,
    LG          = 0x32,
    SQRT        = 0x33,

    ASIN        = 0x40,
    ACOS        = 0x41,
    ATAN        = 0x42,
    ACOT        = 0x43,

    OP_BRACK    = 0xF0,
    CL_BRACK    = 0xFF,

};

namespace arithm_operations
{
    operation_t find_operation(const char *string, unsigned int &pos);
}


#endif