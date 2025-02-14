#ifndef DIFFERENT_DSL
#define DIFFERENT_DSL

#define LNODE node->l_node
#define RNODE node->r_node

#define _NUM(num)               new node_t(num)
#define _ADD(left, right)       new node_t(ADD,  left, right)
#define _SUB(left, right)       new node_t(SUB,  left, right)
#define _MULT(left, right)      new node_t(MULT, left, right)
#define _DIV(left, right)       new node_t(DIV,  left, right)
#define _POW(left, right)       new node_t(POW,  left, right)

#define _SIN(left)              new node_t(SIN,  left, NULL)
#define _COS(left)              new node_t(COS,  left, NULL)
#define _TAN(left)              new node_t(TAN,  left, NULL)
#define _COT(left)              new node_t(COT,  left, NULL)
#define _SH(left)               new node_t(SH,   left, NULL)
#define _CH(left)               new node_t(CH,   left, NULL)
#define _TH(left)               new node_t(TH,   left, NULL)
#define _CTH(left)              new node_t(CTH,  left, NULL)
#define _LN(left)               new node_t(LN,   left, NULL)

#define _DIFF(node)             find_differential(node)

#define _COPY(node)             new node_t(node)


#define _SUM_OP()   new node_t(node->data.operation, _DIFF(LNODE), _DIFF(RNODE))

#define _MULT_OP()  _ADD(_MULT(_DIFF(LNODE), _COPY(RNODE)), _MULT(_COPY(LNODE), _DIFF(RNODE)))

#define _DIV_OP()   _DIV(_SUB(_MULT(_DIFF(LNODE), _COPY(RNODE)), _MULT(_COPY(LNODE), _DIFF(RNODE))), _POW(_COPY(RNODE), _NUM(2.0)))

#define _POW_OP()   _ADD(_MULT(_MULT(_POW(_COPY(LNODE), _COPY(RNODE)), _LN(_COPY(LNODE))), _DIFF(RNODE)), _MULT(_MULT(_COPY(RNODE), _POW(_COPY(LNODE), _SUB(_COPY(RNODE), _NUM(1.0)))), _DIFF(LNODE)))

#define _SIN_OP()   _MULT(_COS(_COPY(LNODE)), _DIFF(LNODE))

#define _COS_OP()   _MULT(_MULT(_NUM(-1.0), _SIN(_COPY(LNODE))), _DIFF(LNODE))

#define _TAN_OP()   _MULT(_DIV(_NUM(1.0), _POW(_COS(_COPY(LNODE)), _NUM(2.0))), _DIFF(LNODE))

#define _COT_OP()   _MULT(_MULT(_DIV(_NUM(1.0), _POW(_SIN(_COPY(LNODE)), _NUM(2.0))), _NUM(-1.0)), _DIFF(LNODE))

#define _SH_OP()    _MULT(_CH(_COPY(LNODE)), _DIFF(LNODE))

#define _CH_OP()    _MULT(_SH(_COPY(LNODE)), _DIFF(LNODE))

#define _TH_OP()    _MULT(_DIV(_NUM(1.0), _POW(_CH(_COPY(LNODE)), _NUM(2.0))), _DIFF(LNODE))

#define _CTH_OP()   _MULT(_MULT(_DIV(_NUM(1.0), _POW(_SH(_COPY(LNODE)), _NUM(2.0))), _NUM(-1.0)), _DIFF(LNODE))

#define _LOG_OP()   _MULT(_DIV(_NUM(1.0), _MULT(_COPY(RNODE), _LN(_COPY(LNODE)))), _DIFF(RNODE))

#define _LN_OP()    _MULT(_DIV(_NUM(1.0), _COPY(LNODE)), _DIFF(LNODE))

#define _LG_OP()    _MULT(_DIV(_NUM(1.0), _MULT(_COPY(LNODE), _LN(_NUM(10.0)))), _DIFF(LNODE))

#define _ASIN_OP()  _MULT(_DIV(_NUM(1.0), _POW(_SUB(_NUM(1.0), _POW(_COPY(LNODE), _NUM(2.0))), _NUM(0.5))), _DIFF(LNODE))

#define _ACOS_OP()  _MULT(_DIV(_NUM(-1.0), _POW(_SUB(_NUM(1.0), _POW(_COPY(LNODE), _NUM(2.0))), _NUM(0.5))), _DIFF(LNODE))

#define _ATAN_OP()  _MULT(_DIV(_NUM(1.0), _ADD(_NUM(1.0), _POW(_COPY(LNODE), _NUM(2.0)))), _DIFF(LNODE))

#define _ACOT_OP()  _MULT(_DIV(_NUM(-1.0), _ADD(_NUM(1.0), _POW(_COPY(LNODE), _NUM(2.0)))), _DIFF(LNODE))

#endif