#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (1);
    }

    std::string literal = argv[1];
    ScalarConverter::convert(literal);

    return (0);
}
