#ifndef DIFFERENT
#define DIFFERENT

#include "main_header.h"

#define LEFT node->l
#define RIGHT node->r

#define _NUM(num)               create_node((double)num, NUMBER, NULL, NULL)
#define _PLUS(left, right)      create_node(PLUS, OPERATION, left, right)
#define _MINUS(left, right)     create_node(MINUS, OPERATION, left, right)
#define _MULT(left, right)      create_node(MULT, OPERATION, left, right)
#define _DIV(left, right)       create_node(DIV, OPERATION, left, right)
#define _POW(left, right)       create_node(POW, OPERATION, left, right)


#define _MULT_OP()  _PLUS(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT)))
#define _DIV_OP()   _DIV(_MINUS(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT))), _POW(copy_node(RIGHT), _NUM(2)))
//#define 


#endif