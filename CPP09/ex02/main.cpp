#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

int main(int argc, char** argv) 
{
    if (argc == 1) 
    {
        std::cerr << "Error: No arguments provided. Usage: " << argv[0] << " [positive integers...]" << std::endl;
        return (1);
    }

    return (0);
}