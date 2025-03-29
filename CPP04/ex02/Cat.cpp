/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:23:15 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:23:16 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) 
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = src;
}

Cat &Cat::operator=(const Cat &src) 
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src) 
    {
        AAnimal::operator=(src);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}