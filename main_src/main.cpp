#include <iostream>
#include "debugging.hpp"
#include "tokenizator.hpp"
#include "parser.hpp"

//void simpl_expr(node_t **root);

//TO DO: сделать дифференциатор
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "> please, enter the expression as programm parameter\n";
        return 1;
    }

    open_log();
    LOG(LONG_LINE);
    LOG("> starting programm...\n");
    clear_old_graphics();

    token_t *token_arr = NULL;
    ret_t ret_val = tokenization::tokenizator(token_arr, argv[1]);
    _RETURN_ON_TRUE(ret_val, ret_val, close_log());

    parser_ft parser = {token_arr};
    node_t *root = parser.pars_expr();
    
    root->create_gparh_code("parsing_result.png");

    /*simpl_expr(&root);
    LOG("\n-> pre-diff calculations were done\n\n");
    _CREATE_GRAPH(root, EXPR);

    node_t *diff_root = differen(root);
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

/*void simpl_expr(node_t **root)
{
    int flag = 0;
    while (!flag)
    {
        flag = 1;
        calculate(*root);
        //root = simplificate(*root, &flag);
    }
    return;
}*/
