#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return (1);
    }

    BitcoinExchange exchange;
    exchange.loadDatabase("data.csv");
    exchange.processInputFile(argv[1]);

    return (0);
}
