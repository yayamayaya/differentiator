#include <iostream>
#include "debugging.hpp"
#include "tokenizator.hpp"
#include "parser.hpp"
#include "simplificate.hpp"
#include "argv_parser.hpp"
#include "calculator.hpp"

int main(int argc, char const *argv[])
{
    argv_st args = {argc, argv};
    if (!args.check_parse_status()) return NOT_ENOUGH_ARGS;

    open_log();
    LOG(LONG_LINE);
    LOG("> starting programm...\n");
#ifndef TESTING
    clear_old_graphics();
#endif

    token_t *token_arr = NULL;
    ret_t ret_val = tokenization::tokenizator(token_arr, args.give_expr());
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());

    parser_ft parser = {token_arr};
    node_t *root = parser.pars_expr();
    _RETURN_ON_TRUE(!root, SYNTAX_ERR, close_log());
    
    simplificator simpl = {root};
    root = simpl.simplificate(root);
    _RETURN_ON_TRUE(simpl.check_for_zero_div(), WRONG_EXPR_ERR, close_log());

    calculator calc = {root};
    ret_val = calc.run_calculator();
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());

    root->create_gparh_code(args.give_graphname());
    
    /*node_t *diff_root = differen(root);
    LOG("\n-> expression was differentiated, diff. root pointer is %p\n\n", diff_root);

    _CREATE_GRAPH(diff_root, DIFF_EXPR);
    simpl_expr(&diff_root);
    LOG("\n-> post-diff calculations were done\n\n");

    tree_kill(root);
    tree_kill(diff_root);
    free(token_arr);
    LOG("\n-> programm ended successfully");
    _CLOSE_LOG();*/

    delete root;
    close_log();

    return 0;
}
