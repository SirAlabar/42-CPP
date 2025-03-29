/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:22:38 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:22:39 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &src);
    ~Dog();

    void makeSound() const;
    Brain *getBrain() const;
};

#endif