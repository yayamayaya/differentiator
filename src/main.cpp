#include "headers/main.h"

int main(int argc, char const *argv[])
{
    _OPEN_LOG("log/diff_log.log");
    LOG("-> starting programm:\n\n");
    clear_all_png();

    token_t *token_arr = {};
    if (tokenizator(&token_arr, EXPR_LOC))
    {
        LOG(">>> tokenization did not work%40s\n\n", "[error]");
        _CLOSE_LOG();
        return 1;
    }
    LOG("\n-> tokenization done, token array pointer is %p;\n\n", token_arr);

    node_t *root = pars_expr(token_arr);
    LOG("\n-> expression was parsed, root pointer is %p\n\n", root);

    calculate(root);
    LOG("\n-> pre-diff calculations were done\n\n");
    _CREATE_GRAPH(root, EXPR);

    node_t *diff_root = differen(root);
    LOG("\n-> expression was differentiated, diff. root pointer is %p\n\n", diff_root);

    calculate(diff_root);
    LOG("\n-> post-diff calculations were done\n\n");
    _CREATE_GRAPH(diff_root, DIFF_EXPR);

    tree_kill(root);
    tree_kill(diff_root);
    free(token_arr);
    LOG("\n-> programm ended successfully");
    _CLOSE_LOG();
    return 0;
}
