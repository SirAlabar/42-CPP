/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:20:10 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:22 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type)
{
    
}

AMateria::AMateria(const AMateria& src) : type(src.type)
{
    
}

AMateria& AMateria::operator=(const AMateria& src)
{
    if (this != &src)
    {
        this->type= src.type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
