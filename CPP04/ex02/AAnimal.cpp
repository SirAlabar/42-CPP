/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:22:56 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:22:57 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") 
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) 
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src) 
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    if (this != &src) 
    {
        this->type = src.type;
    }
    return (*this);
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const 
{
    return (this->type);
}