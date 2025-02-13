#include <iostream>
#include "argv_parser.hpp"

argv_st::argv_st(const int argc, const char *argv[]): expr(), graphic_name(), tex_output_name(), parsed_status(false)
{
#ifdef GRAPH
    if (argc != 4)
    {
        std::cout << "you must enter expression, graphics filename and tex filename\n";
        return;
    }

    expr            = argv[1];
    graphic_name    = argv[2];
    tex_output_name = argv[3];

    parsed_status = true;
#else
    if (argc != 3)
    {
        std::cout << "you must enter expression and tex filename\n";
        return;
    }

    expr = argv[1];
    expr = argv[2];

    parsed_status = true;
#endif
    
}