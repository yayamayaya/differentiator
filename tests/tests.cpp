#include <iostream>
#include "tests.hpp"

int main()
{
    tests testing = {};
    testing.run_tests();

    return 0;
}

void tests::run_tests()
{
    int ret_val = 0;

    for (unsigned int i = 0; i < tests_num; i++)
    {
        ret_val = run_single_test(i);
        std::cout << "> test number " << i << " had return status of: \"" << ret_val << "\"\n";
    }

    return;
}

int tests::run_single_test(const unsigned int test_number)
{
    const std::string num = std::to_string(test_number);
    const std::string call_expr = prog_call + tests[test_number] + graph_name + num + graph_format + tex_name + num + tex_format;

    return system(call_expr.c_str());
}