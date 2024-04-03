#include "../headers/main.h"

int main(int argc, char const *argv[])
{
    diff_log = fopen("log/pars_test.log", "wb");
    if (!diff_log)
    {
        fprintf(stderr, ">>> can't open logfile");
        return 15;
    }
    

    token_t *token_arr = NULL;
    tokenizator(&token_arr, "data/expression_to_diff.txt");
    printf("%p\n", token_arr);

    int pos = 0;
    node_t *root = pars_expr(token_arr, &pos);

    create_gparh_code(root, EXPR);

    /*for (int i = 0; i < 15; i++)
        fprintf(stderr, "<%d> - %d\n", (token_arr + i)->data.operation, (token_arr + i)->data_type);*/
    
    free(token_arr);
    tree_kill(root);
    fclose(diff_log);

    return 0;
}
