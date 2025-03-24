/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:51:50 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/24 20:44:06 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

std::string getInput(const std::string& prompt)
{
    std::string input;
    
    while(true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if(std::cin.eof())
            exit(0);
        if(!input.empty())
            return input;
        
        std::cout << RED << "Field cannot be empty. Please try again." << RESET << std::endl;
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

        }
        else if (command == "SEARCH")
        {
            
        }
        else if (command != "EXIT")
        {
            std::cout << RED << "Invalid command. Please try again."
        }
    } while (command != "EXIT");

    std::cout << GREEN << "Goodbye!" << RESET << std::endl;
    return(0);
}