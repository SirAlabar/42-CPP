/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:21:44 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:21:45 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") 
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src) 
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) 
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &src) 
    {
        this->type = src.type;
    }
    return (*this);
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "* Silence... Animal makes no specific sound *" << std::endl;
}

std::string Animal::getType() const 
{
    return (this->type);
}