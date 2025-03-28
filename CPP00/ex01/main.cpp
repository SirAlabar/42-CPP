/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:50 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/27 19:10:30 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

bool isValidPhoneNumber(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

std::string getInput(const std::string& prompt, bool isPhone = false)
{
    std::string input;
    
    while(true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if(std::cin.eof())
            exit(0);
        
        if(input.empty())
        {
            std::cout << RED << "Field cannot be empty. Please try again." << RESET << std::endl;
            continue;
        }
        
        if (isPhone && !isValidPhoneNumber(input))
        {
            std::cout << RED << "Phone number must contain only digits. Please try again." << RESET << std::endl;
            continue;
        }
        
        return input;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << BOLD_GREEN << "Welcome to the Awesome PhoneBook!" << RESET <<std::endl;


    do
    {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";        
        std::getline(std::cin, command);

        if(std::cin.eof())
            break;
        
        if (command == "ADD")
        {
            Contact newContact;
            
            newContact.setFirstName(getInput("Enter first name: "));
            newContact.setLastName(getInput("Enter last name: "));
            newContact.setNickname(getInput("Enter nickname: "));
            newContact.setPhoneNumber(getInput("Enter phone number: ", true));
            newContact.setDarkestSecret(getInput("Enter darkest secret: "));

            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayAllContacts();

            if (phoneBook.getCount() == 0)
                continue;

            std::string indexStr;
            std::cout << "Search [1 .. 8]: ";
            std::getline(std::cin, indexStr);
            
            if (std::cin.eof())
                break;

            bool validNumber = true;
            for (size_t i = 0; i < indexStr.length(); i++)
            {
                if (!isdigit(indexStr[i]))
                {
                    validNumber = false;
                    break;
                }
            }
            
            if (!validNumber || indexStr.empty())
            {
                std::cout << RED << "Invalid index, choose between 1 and 8" << RESET << std::endl;
                continue;
            }
            
            int index = std::atoi(indexStr.c_str());
            
            if (index < 1 || index > 8)
            {
                std::cout << RED << "Invalid index, choose between 1 and 8" << RESET << std::endl;
                continue;
            }
            int arrayIndex = index - 1;
            std::cout << "Searching..." << std::endl;
            phoneBook.displayContact(arrayIndex);
        }
        else if (command != "EXIT")
        {
            std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
        }
    } while (command != "EXIT");

    std::cout << GREEN << "Goodbye!" << RESET << std::endl;
    return(0);
}