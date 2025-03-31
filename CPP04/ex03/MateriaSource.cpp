/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:54:50 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/29 19:54:51 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        this->templates[i]= NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.templates[i])
            this->templates[i]= src.templates[i]->clone();
        else
            this->templates[i] = NULL;    
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->templates[i])
            {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }

        for (int i = 0; i < 4; i++) 
        {
            if (src.templates[i])
                this->templates[i] = src.templates[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i])
        {
            delete this->templates[i];
            this->templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
        
    for (int i = 0; i < 4; i++) 
    {
        if (!this->templates[i]) 
        {
            this->templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
    for (int i = 0; i < 4; i++) 
    {
        if (this->templates[i] && this->templates[i]->getType() == type) 
        {
            return this->templates[i]->clone();
        }
    }
    return (NULL);
}