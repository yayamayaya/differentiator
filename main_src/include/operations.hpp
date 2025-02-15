#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "debugging.hpp"

enum bit_masks
{
    SUM_OP  = 0x50,
    MUL_OP  = 0x60,
    FUNC_OP = 0x10,
};

enum operation_t
{
    ADD         = 0x51,
    SUB         = 0x52,
    MULT        = 0x63,
    DIV         = 0x64,
    POW         = 0x05,
    
    SIN         = 0x10,
    COS         = 0x11,
    TAN         = 0x12,
    COT         = 0x13,
    
    SH          = 0x14,
    CH          = 0x15,
    TH          = 0x16,
    CTH         = 0x17,
    
    LN          = 0x18,
    LG          = 0x19,
    SQRT        = 0x1A,
    
    ASIN        = 0x1B,
    ACOS        = 0x1C,
    ATAN        = 0x1D,
    ACOT        = 0x1E,
    
    OP_BRACK    = 0xF0,
    CL_BRACK    = 0xFF,

    NO_OP       = 0x00
};

struct operation_st
{
    const char*     operation;
    operation_t     operation_number;
    unsigned int    string_length;
};


namespace arithm_operations
{
    operation_t find_operation(const char *string, unsigned int &pos);
}


#endif