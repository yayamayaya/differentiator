#ifndef TESTS_H
#define TESTS_H

#include <string>

#define _RUN_TEST(arg) system(arg)

#define PROG_CALL   "./run.sh",

#define TEST_1  PROG_CALL "",

#define TEST_2

class tests
{
    private:

    static constexpr unsigned int tests_num = 23;

    const std::string prog_call     = "./run.sh '";

    const std::string graph_name    = "' test_graph";

    const std::string graph_format  = ".png";

    const std::string tex_name      = " test_tex";

    const std::string tex_format    = ".tex";

    const std::string tests[tests_num] =
    {
        "",
        
        "1",
        
        "sin(1)",
        
        "2+3",
        
        "sqrt(4)",
        
        "2+3*5",

        "x",

        "x-1",

        "0",
        
        "0+5",

        "0*11",
        
        "0/11",
        
        "0*0",
        
        "0/0",
        
        "5/0",
        
        "5^0",
        
        "0^5",
        
        "0^0",
        
        "x^x^0*7",
        
        "1 * 10",
        
        "1-1",
        
        "1/2",
        
        "2/1",
    
    };

    public:

    void run_tests();

    int run_single_test(const unsigned int test_num); 
};

#endif