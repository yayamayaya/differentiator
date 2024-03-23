#include "main_header.h"

int main(int argc, char const *argv[])
{
    node_t *root = create_expr_tree("../data/expression_to_diff.txt");
    //Сделать действия
    //Напечатать дерево
    //Записать полученное дерево в файл
    tree_kill(root);
    return 0;
}
