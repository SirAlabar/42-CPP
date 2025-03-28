#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal 
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &src);
    AAnimal &operator=(const AAnimal &src);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif