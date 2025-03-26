#pragma once
#ifndef WEAPON_HPP
#define WEAPOM_HPP

#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string newType);
};

#endif
