

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "";
    std::cout << "Zombie with empty name is created." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie " << this->name << " is created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
    std::cout << "Zombie is now known as " << this->name << std::endl;
}