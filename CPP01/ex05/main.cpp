
#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "INVALID level:" << std::endl;
    harl.complain("INVALID");

    return (0);
}