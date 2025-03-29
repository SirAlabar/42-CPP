/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:21:15 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:21:15 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}


ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is broken and cannot attack!" << std::endl;  
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        if (amount >= _hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;

        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! " 
                  << "Remaining hit points: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already broken and cannot take more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
                  << " hit points! Current hit points: " << _hitPoints << std::endl;
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself!" << std::endl;  
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is broken and cannot repair itself!" << std::endl;
    }
}

std::string ClapTrap::getName() const
{
    return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (_attackDamage);
}
