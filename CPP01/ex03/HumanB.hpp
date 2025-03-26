

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon; //Pointer because HumanB might not alway have a weapon

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif