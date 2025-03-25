/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:03 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/24 20:44:12 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define RED "\033[31m"
#define BOLD_RED "\033[1;31m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1;32m"
#define CYAN "\033[36m"
#define BOLD_CYAN "\033[1;36m"
#define RESET "\033[0m"

class PhoneBook
{
private:
    Contact contacts[8];
    int oldestIndex;

public:
    int count;

    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact& contact);
    void displayAllContacts() const;
    void displayContact(int index) const;
};

#endif