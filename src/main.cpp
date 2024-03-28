#include "main_header.h"

int main(int argc, char const *argv[])
{
    fprintf(stderr, ">> starting programm\n");
    diff_log = fopen("log/diff_log.txt", "wb");
    if (!diff_log)                                                          \
    {                                                                       \
        fprintf(stderr, ">>> Couldn't open logfile.");                      \
        return ERR;                                                         \
    } 
    setbuf(diff_log, NULL);
    fprintf(stderr, "//diff_log = %p\n", diff_log);

    node_t *root = create_expr_tree("data/expression_to_diff.txt");
    calculate(root);
    fprintf(stderr, ">> calculation done\n");
    create_gparh_code(root);
    system(PNG_LOC);
    //Напечатать дерево
    //Записать полученное дерево в файл
    tree_kill(root);
    fclose(diff_log);
    return 0;
}
