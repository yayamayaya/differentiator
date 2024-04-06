#ifndef REC_PAR
#define REC_PAR

#include <stdio.h>
#include <stdlib.h>
#include "../../../common/tree_func/types.h"
#include "../../../common/log/log.h"
#include "../headers/operations.h"
#include "../../../common/tree_func/types.h"
#include "../../graph/create_graph.h"
#include "tokenizator.h"

node_t *pars_expr(token_t *token_arr);
node_t *pars_mult(token_t *token_arr, int *pos);
node_t *pars_power(token_t *token_arr, int *pos);
node_t *pars_number(token_t *token_arr, int *pos);

#endif