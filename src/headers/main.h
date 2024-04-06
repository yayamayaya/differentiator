#ifndef DIFF_HEADER
#define DIFF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "operations.h"
#include "../../graph/create_graph.h"
#include "../simplification/expr_calc.h"
#include "../simplification/simplificate.h"
#include "../differentiation/differentiate.h"
#include "../../../common/tree_func/types.h"
#include "../../../common/file_reading/file_reader.h"
#include "../../../common/log/log.h"
#include "../../../common/tree_func/types.h"
#include "../parsing/parsing.h"
#include "../parsing/tokenizator.h"

enum DIFF_ERRORS
{
    EXPR_FILE_OPEN_ERR      = 101,
    BUFF_MEM_ALC_ERR,
    NODE_MEM_ALC_ERR,
    EMPTY_FILE,
};

#endif