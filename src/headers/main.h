#ifndef DIFF_HEADER
#define DIFF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "operations.h"
#include "../../graph/create_graph.h"
#include "../file_reading/read_expr.h"
#include "../simplification/expr_calc.h"
#include "../differentiation/differentiate.h"
#include "../create_node.h"
#include "../file_reading/file_reader.h"
#include "types.h"
#include "log.h"
#include "../parsing/parsing.h"
#include "../parsing/tokenizator.h"

//#define DEBUG

enum DIFF_ERRORS
{
    EXPR_FILE_OPEN_ERR      = 101,
    BUFF_MEM_ALC_ERR,
    NODE_MEM_ALC_ERR,
};

#endif