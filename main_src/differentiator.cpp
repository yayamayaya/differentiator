#include "differentiator.hpp"
#include <iostream>
#include <assert.h>
#include <cmath>
#include "debugging.hpp"
#include "tokenizator.hpp"
#include "parser.hpp"
#include "calculator.hpp"
#include "differentiation_module.hpp"

/*Calculate and simplify given expression in express*/
ret_t differentiator::calculate(const std::string express)
{
    if (express.empty()) 
        return EMPTY_EXPRESSION_ERR;

    destroy_trees();

    LOG(LONG_LINE);
    LOG("> running calculator...\n");
    
    //Read and parse math expression
    token_t *token_arr = NULL;
    return_status = tokenization::tokenizator(token_arr, express);
    _RETURN_ON_TRUE(return_status, return_status);

    parser_ft parser = {token_arr};
    curr_root = parser.pars_expr();
    _RETURN_ON_TRUE(!curr_root, SYNTAX_ERR);
    
    //Optimize and calculate given expression to shorten it
    calculator calc = {curr_root};
    return_status = calc.run_calculator();
    _RETURN_ON_TRUE(return_status, return_status);

    //Print post-calculation picture
    if (!tree_pic_path.empty())
        curr_root->create_gparh_code("before_diff_" + tree_pic_path);

    return return_status;
}

/*Differentiate math expression express, print expression in tree_pic_path
evaluate differentiated expression for x = x_value, print results in tex_path*/
ret_t differentiator::
differentiate(const std::string express)
{
    if (express.empty()) 
        return EMPTY_EXPRESSION_ERR;

    //Read and simplify expression
    calculate(express);
    _RETURN_ON_TRUE(return_status, return_status);

    LOG("> running differentiator...\n");
    //Differentiate expression    
    differentiation_module differ = {curr_root};
    return_status = differ.run();
    _RETURN_ON_TRUE(return_status, return_status);

    old_root  = curr_root;
    curr_root = differ.return_diffed_root();

    //Optimize and calculate differentiated expression
    calculator diff_calc = {curr_root};
    return_status = diff_calc.run_calculator();
    _RETURN_ON_TRUE(return_status, return_status);

    //Print post-differentiation picture
    if (!tree_pic_path.empty())
        curr_root->create_gparh_code("after_diff_" + tree_pic_path);
    
    return return_status;
}

/*Replace x with number_t number and calculate the result*/
number_t differentiator::evaluate_x_value(const number_t number)
{
    if (!curr_root)
    {
        return_status = NO_EXPRESSION_NODE_ERR;
        return NAN;
    }

    curr_root->put_x_value(number);

    calculator calc = {curr_root};
    return_status = calc.run_calculator();
    _RETURN_ON_TRUE(return_status, NAN);

    assert(curr_root->type == NUMBER);

    return curr_root->data.number;
}

no_ret_val_t differentiator::print_results(FILE *file)
{
    assert(file);

    curr_root->print_in_line(file);
    fprintf(file, "\n");

    return;
}

no_ret_val_t differentiator::destroy_trees()
{
    if (old_root)
    {
        delete old_root;
        old_root = nullptr;
    }
    
    if (curr_root)
    {
        delete curr_root;
        curr_root = nullptr;
    }
    
    return;
}

differentiator::~differentiator()
{
    destroy_trees();

    close_log();

    return;
}