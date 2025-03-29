/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:23:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:23:19 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &src);
    ~Cat();

    void makeSound() const;
    Brain *getBrain() const;
};

#endif