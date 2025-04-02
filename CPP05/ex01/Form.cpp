#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Parameterized Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed),
     _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy Form constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    std::cout << "Form Assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_signed);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();    
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high, cannot be less than 1";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low for this form";
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName() 
        << ", sign grade: " << form.getGradeToSign() 
        << ", execute grade: " << form.getGradeToExecute() 
        << ", signed: " << (form.isSigned() ? "yes" : "no");
    return (out);
}