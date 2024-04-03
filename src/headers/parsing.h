#ifndef REC_PAR
#define REC_PAR

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "log.h"
#include "operations.h"
#include "create_node.h"
#include "../../graph/create_graph.h"
#include "../parsing/tokenizator.h"

node_t *pars_expr(token_t *token_arr, int *pos);
node_t *pars_mult(token_t *token_arr, int *pos);
node_t *pars_power(token_t *token_arr, int *pos);
node_t *pars_number(token_t *token_arr, int *pos);
int tree_kill(node_t *node);


#endif