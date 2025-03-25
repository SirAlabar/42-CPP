/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:53 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/24 20:57:01 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook()
{
    this->count = 0;
    this->oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
   
}

int PhoneBook::getCount() const
{
    return this->count;
}

std::string formatString(const std::string& str)
{
    std::string result;

    if(str.length() > 10)
        result = str.substr(0, 9) + ".";
    else
    {
        result = std::string(10, ' ');

        int startPos = 10 - str.length();
        for (size_t i = 0; i < str.length(); i++)
            result[startPos + i] = str[i];
    }
    return result;
}

void PhoneBook::addContact(const Contact& contact)
{
    this->contacts[this->oldestIndex] = contact;
    
    if(this->count < 8)
        this->count++;

    this->oldestIndex = (this->oldestIndex + 1) % 8;

    std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;  
}

void PhoneBook::displayAllContacts() const
{
    if (this->count == 0)
    {
        std::cout << RED << "No contacts to display." << RESET << std::endl;
        return ;
    }

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name|Last Name | Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < this->count; i++)
    {
        std::cout << "|" << std::setw(10) << (i + 1) << "|";
        std::cout << formatString(this->contacts[i].getFirstName()) << "|";
        std::cout << formatString(this->contacts[i].getLastName()) << "|";
        std::cout << formatString(this->contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << "|___________________________________________|" << std::endl;
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= this->count)
    {
        std::cout << RED << "Invalid index. No contact found." << RESET << std::endl;
        return ;
    }

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|  Details of contact found                 |" << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
    
    std::cout << "| First Name:     " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "| Last Name:      " << this->contacts[index].getLastName() << std::endl;
    std::cout << "| Nickname:       " << this->contacts[index].getNickname() << std::endl;
    std::cout << "| Phone Number:   " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "| Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
}
