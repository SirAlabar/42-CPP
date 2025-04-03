#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called" << std:: endl;
    (void)other;
    return (*this);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const int num_forms = 3;
    int index = -1;
    
    std::string formTypes[num_forms] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    

    for (int i = 0; i < num_forms; i++) 
    {
        if (formTypes[i] == formName) 
        {
            index = i;
            break;
        }
    }

    if (index != -1)
        std::cout << "Intern creates " << formName << std::endl;
    
    switch (index) 
    {
        case 0: return new ShrubberyCreationForm(target);
        case 1: return new RobotomyRequestForm(target);
        case 2: return new PresidentialPardonForm(target);
        default: throw FormNotFoundException();
    }
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
