#ifndef REC_PAR
#define REC_PAR

#include "tree_func.hpp"
#include "tokenizator.hpp"
#include "debugging.hpp"

class parser_ft
{
public:
    parser_ft(): tokens(NULL), curr_tok(0), syntax_error(false) {LOG("> neyavnaya initialisation of parser structure\n");}

    parser_ft(const parser_ft &ref): tokens(NULL), curr_tok(0), syntax_error(false) {(void)ref; LOG("> wrong usage of parser structure");}

    parser_ft(const token_t *token_arr): tokens(token_arr), curr_tok(0), syntax_error(false) {}

    ~parser_ft()
    {
        delete [] tokens;
        
        tokens      = NULL;
        curr_tok    = 0;
    }

    parser_ft &operator=(const parser_ft &ref)
    {
        (void)ref;

        LOG("> wrong usage of parser structure\n");
        return *this;
    }

    node_t *pars_expr();
    
private:
    const token_t *tokens;
    unsigned int   curr_tok;
    bool           syntax_error;

    node_t *pars_mult();
    
    node_t *pars_power();

    node_t *pars_number();

    node_t *pars_operation();

    node_t *pars_op_brack();

    node_t *pars_cl_brack();

    node_t *pars_sqrt();
};


#endif