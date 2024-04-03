#ifndef DIFF_HEADER
#define DIFF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//#include "../../../ilab/common/log.h"
#include "operations.h"
#include "../../graph/create_graph.h"
#include "read_expr.h"
#include "expr_calc.h"
#include "differentiate.h"
#include "create_node.h"
#include "file_reader.h"
#include "types.h"
#include "log.h"
#include "parsing.h"
#include "../parsing/tokenizator.h"

#define DEBUG

enum DIFF_ERRORS
{
    EXPR_FILE_OPEN_ERR      = 101,
    BUFF_MEM_ALC_ERR,
    NODE_MEM_ALC_ERR,
};

//From file_reader

//From expression_reader


//From expression calculator


//From graph code creator


//From create_node

//From differentiate


#endif