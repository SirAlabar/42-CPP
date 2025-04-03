#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();

    Intern& operator=(const Intern &other);

    AForm* makeForm(const std::string &formName, const std::string &target) const;

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};
