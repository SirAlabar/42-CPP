/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:20:13 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:26 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    AMateria(const Amateria& src);
    AMateria& operator=(const AMateria& src);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif