#include "Animal.hpp"

Animal::Animal() : type("") 
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src) 
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) 
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &src) 
    {
        this->type = src.type;
    }
    return (*this);
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "* Silence... Animal makes no specific sound *" << std::endl;
}

std::string Animal::getType() const 
{
    return (this->type);
}