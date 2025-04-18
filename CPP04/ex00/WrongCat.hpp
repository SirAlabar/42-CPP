/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:22:14 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 18:22:15 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
public:
    WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &src);
    ~WrongCat();

    void makeSound() const;
};

#endif