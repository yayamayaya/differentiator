#ifndef DIFFERENT
#define DIFFERENT

#include "main.h"

#define LEFT node->l
#define RIGHT node->r

#define _NUM(num)               create_node((double)num, NUMBER, NULL, NULL)
#define _ADD(left, right)       create_node(ADD, OPERATION, left, right)
#define _SUB(left, right)       create_node(SUB, OPERATION, left, right)
#define _MULT(left, right)      create_node(MULT, OPERATION, left, right)
#define _DIV(left, right)       create_node(DIV, OPERATION, left, right)
#define _POW(left, right)       create_node(POW, OPERATION, left, right)


#define _MULT_OP()  _ADD(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT)))
#define _DIV_OP()   _DIV(_SUB(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT))), _POW(copy_node(RIGHT), _NUM(2)))
//#define 


node_t *differen(node_t *node);
node_t *copy_node(node_t *node);

#endif