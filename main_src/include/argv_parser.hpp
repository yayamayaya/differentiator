#ifndef ARGV_PARSER_H
#define ARGV_PARSER_H

#include <string>

class argv_st
{
private:
    std::string expr;

    std::string graphic_name;

    std::string tex_output_name;

    bool parsed_status;
    
public:
    argv_st(const int argc, const char *argv[]);

    ~argv_st() {};

    std::string give_expr()      {return expr;}

    std::string give_graphname() {return graphic_name;}

    std::string give_texname()   {return tex_output_name;}

    bool check_parse_status()    {return parsed_status;}
};


#endif