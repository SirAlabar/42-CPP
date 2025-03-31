/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:54:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:29 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& src) : name(src.name)
{
    for (int i = 0; i < 4; i++)
    {
        if(src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& src)
{
    if (this != &src)
        this->name = src.name;

    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if(src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
    }

    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
         delete this->inventory[i];
    }
}  

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;

    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            return ;
        }
    }    
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        this->inventory[idx]->use(target);
    }
}
