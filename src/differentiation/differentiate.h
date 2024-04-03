#ifndef DIFFERENT
#define DIFFERENT

#include "../headers/main.h"

#define LEFT node->l
#define RIGHT node->r

#define _NUM(num)               create_node((double)num, NUMBER, NULL, NULL)
#define _ADD(left, right)       create_node((unsigned char)ADD, OPERATION, left, right)
#define _SUB(left, right)       create_node((unsigned char)SUB, OPERATION, left, right)
#define _MULT(left, right)      create_node((unsigned char)MULT, OPERATION, left, right)
#define _DIV(left, right)       create_node((unsigned char)DIV, OPERATION, left, right)
#define _POW(left, right)       create_node((unsigned char)POW, OPERATION, left, right)

#define _SIN(left)              create_node((unsigned char)SIN, OPERATION, left, NULL)
#define _COS(left)              create_node((unsigned char)COS, OPERATION, left, NULL)
#define _TAN(left)              create_node((unsigned char)TAN, OPERATION, left, NULL)
#define _COT(left)              create_node((unsigned char)COT, OPERATION, left, NULL)
#define _SH(left)               create_node((unsigned char)SH, OPERATION, left, NULL)
#define _CH(left)               create_node((unsigned char)CH, OPERATION, left, NULL)
#define _TH(left)               create_node((unsigned char)TH, OPERATION, left, NULL)
#define _CTH(left)              create_node((unsigned char)CTH, OPERATION, left, NULL)
#define _LN(left)               create_node((unsigned char)LN, OPERATION, left, NULL)


#define _MULT_OP()  _ADD(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT)))
#define _DIV_OP()   _DIV(_SUB(_MULT(differen(LEFT), copy_node(RIGHT)), _MULT(copy_node(LEFT), differen(RIGHT))), _POW(copy_node(RIGHT), _NUM(2)))
#define _POW_OP()   _ADD(_MULT(_MULT(_POW(copy_node(LEFT), copy_node(RIGHT)), _LN(copy_node(LEFT))), differen(RIGHT)), _MULT(_MULT(copy_node(RIGHT), _POW(copy_node(LEFT), _SUB(copy_node(RIGHT), _NUM(1)))), differen(LEFT)))
#define _SIN_OP()   _MULT(_COS(copy_node(LEFT)), differen(LEFT));
#define _COS_OP()   _MULT(_MULT(_NUM(-1), _SIN(copy_node(LEFT))), differen(LEFT));
#define _TAN_OP()   _MULT(_DIV(_NUM(1), _POW(_COS(copy_node(LEFT)), _NUM(2))), differen(LEFT));
#define _COT_OP()   _MULT(_MULT(_DIV(_NUM(1), _POW(_SIN(copy_node(LEFT)), _NUM(2))), _NUM(-1)), differen(LEFT));
#define _SH_OP()    _MULT(_CH(copy_node(LEFT)), differen(LEFT));
#define _CH_OP()    _MULT(_SH(copy_node(LEFT)), differen(LEFT));
#define _TH_OP()    _MULT(_DIV(_NUM(1), _POW(_CH(copy_node(LEFT)), _NUM(2))), differen(LEFT));
#define _CTH_OP()   _MULT(_MULT(_DIV(_NUM(1), _POW(_SH(copy_node(LEFT)), _NUM(2))), _NUM(-1)), differen(LEFT));
#define _LOG_OP()   _MULT(_DIV(_NUM(1), _MULT(copy_node(RIGHT), _LN(copy_node(LEFT)))), differen(RIGHT));
#define _LN_OP()    _MULT(_DIV(_NUM(1), copy_node(LEFT)), differen(LEFT))
#define _ASIN_OP()  _MULT(, differen(LEFT))




//#define 


node_t *differen(node_t *node);
node_t *copy_node(node_t *node);

#endif