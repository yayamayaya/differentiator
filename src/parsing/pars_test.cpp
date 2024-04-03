#include "../headers/main.h"

int main(int argc, char const *argv[])
{
    _OPEN_LOG("log/pars_test.log");

    token_t *token_arr = NULL;
    tokenizator(&token_arr, "data/expression_to_diff.txt");
    printf("%p\n", token_arr);

    node_t *root = pars_expr(token_arr);

    create_gparh_code(root, EXPR);
    
    free(token_arr);
    tree_kill(root);
    _CLOSE_LOG();
    return 0;
}
