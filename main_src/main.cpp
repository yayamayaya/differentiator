#include <iostream>
#include "debugging.hpp"
#include "tokenizator.hpp"
#include "parser.hpp"
#include "simplificate.hpp"
#include "argv_parser.hpp"
#include "calculator.hpp"
#include "differentiator.hpp"

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
    root = simpl.simplificate();
    _RETURN_ON_TRUE(simpl.check_for_zero_div(), WRONG_EXPR_ERR, close_log());

    calculator calc = {root};
    ret_val = calc.run_calculator();
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());

    root->create_gparh_code("before_diff_" + args.give_graphname());

    differentiation_module differ = {root};
    ret_val = differ.run();
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());

    node_t *diffed_root = differ.return_diffed_root();
    
    simplificator diff_simpl = {diffed_root};
    diffed_root = diff_simpl.simplificate();
    _RETURN_ON_TRUE(diff_simpl.check_for_zero_div(), WRONG_EXPR_ERR, close_log());
    
    diffed_root->create_gparh_code("after_diff_" + args.give_graphname());
    
    calculator diff_calc = {diffed_root};
    ret_val = diff_calc.run_calculator();
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());
    
    
    delete root;
    delete diffed_root;

    close_log();

    return 0;
}
