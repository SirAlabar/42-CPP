#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPPTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &other);

    void attack(const std::string &target);
    void highFivesGuys();
};

#endif