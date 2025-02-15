#include <iostream>
#include "tests.hpp"
#include "differentiator.hpp"

int main()
{
    tests testing = {};
    testing.run_tests();

    return 0;
}

void tests::run_tests()
{
    int ret_val = 0;

    differentiator differ = {};

    for (unsigned int i = 0; i < tests_num; i++)
    {
        ret_val = differ.differentiate(tests[i]);
        
        if (!ret_val)
            differ.print_results(stdout);

        std::cout << "> test number " << i << " had return status of: \"" << ret_val << "\"\n";
    }

    return;
}