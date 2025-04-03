#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Parameterized AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed),
     _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy AForm constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    std::cout << "AForm Assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::isSigned() const
{
    return (_signed);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();    
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high, cannot be less than 1";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low for this form";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::checkExecuteRequirements(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: " << form.getName() 
        << ", sign grade: " << form.getGradeToSign() 
        << ", execute grade: " << form.getGradeToExecute() 
        << ", signed: " << (form.isSigned() ? "yes" : "no");
    return (out);
}