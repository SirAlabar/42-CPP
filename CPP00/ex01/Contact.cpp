/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:46 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/24 20:22:10 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::getFirstName() const
{
    return (this->_firstName);
}

std::string Contact::getLastName() const
{
    return (this->_lastName);
}

std::string Contact::getNickname() const
{
    return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (this->_darkestSecret);
}

void Contact::setFirstName(const std::string& firstName)
{
    this->_firstName = firstName;
}
void Contact::setLastName(const std::string& lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}