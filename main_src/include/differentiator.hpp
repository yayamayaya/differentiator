#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include "tree_func.hpp"
#include <cmath>
#include <iostream>

class differentiator
{
public:
    ret_t    calculate(const std::string express);
    
    ret_t    differentiate(const std::string express);

    number_t evaluate_x_value(const number_t x_value);

    no_ret_val_t print_results(FILE *file);

    /*Print pictures of the expression trees in ./tree_graphics/"pic_name"
    you must have dot and it makes programm run much slower*/
    no_ret_val_t turn_on_picture_printing(const std::string pic_name) {tree_pic_path = pic_name;}
    
    differentiator(): old_root(nullptr), curr_root(nullptr)
    {
        clear_old_graphics();

        open_log();
    }

    ~differentiator();
    
private:

    differentiator(const differentiator &copy): old_root(nullptr), curr_root(nullptr)
    {
        (void)copy;
        std::cout << "wrong usage of differentiator class\n";

        return;
    }
    
    differentiator &operator=(const differentiator &copy)
    {
        (void)copy;
        std::cout << "wrong usage of differentiator class\n";

        return *this;
    }

    node_t *old_root;

    node_t *curr_root;

    static inline std::string tree_pic_path = "";

    static inline ret_t return_status       = 0;

    friend class tests;

    no_ret_val_t destroy_trees();
};

#endif