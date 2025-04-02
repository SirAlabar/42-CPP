#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private: 
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat &other);

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


