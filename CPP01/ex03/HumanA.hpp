
#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon; //Reference because HumanA will always be armed 

public:
    HumanA(std::string name, Weapon& weapon);
    void attack();
};

#endif