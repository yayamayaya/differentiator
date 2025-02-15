#include "differentiator.hpp"
#include <cmath>

int main(int argc, char const *argv[])
{
    if (argc != 2) return 1;

    differentiator differ = {};

    // differ.turn_on_picture_printing("pic.png");

    differ.differentiate(argv[1]);

    //std::cout << "result = " << differ.evaluate_x_value(3) << "\n";

    differ.print_results(stdout);

    return 0;
}
