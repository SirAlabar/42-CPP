/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:23:33 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:23:34 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = NULL;
    *this = src;
}

Dog &Dog::operator=(const Dog &src) 
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src) 
    {
        AAnimal::operator=(src);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}
