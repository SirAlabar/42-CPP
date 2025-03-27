#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " viciously attacks " << target
                  << ", inflicting " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " is broken and cannot attack!" << std::endl;  
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}