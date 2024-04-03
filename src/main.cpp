#include "headers/main.h"

int main(int argc, char const *argv[])
{
    //fprintf(stderr, ">> starting programm\n");
    //clear_all_png();
    _OPEN_LOG("log/diff_log.log");
    //fprintf(stderr, "//diff_log = %p\n", diff_log);

    node_t *root = create_expr_tree("data/expression_to_diff.txt");
    calculate(root);
    LOG("> starting differentiation\n");
    node_t *diff_root = differen(root);
    calculate(diff_root);
    LOG(">differentiation done\n");
    fprintf(stderr, ">> calculation done\n");
    create_gparh_code(root, EXPR);
    create_gparh_code(diff_root, DIFF_EXPR);
    //system(PNG_LOC);
    //Напечатать дерево
    //Записать полученное дерево в файл
    tree_kill(root);
    tree_kill(diff_root);
    _CLOSE_LOG();
    return 0;
}
