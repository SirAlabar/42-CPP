#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Program requires exactly one argument" << std::endl;
        return (1);
    }

    RPN calculator;
    std::string expression = argv[1];

    try
    {
        int result = calculator.calculate(expression);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}