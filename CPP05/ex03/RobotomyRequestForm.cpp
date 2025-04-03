#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Parameterized RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    :AForm(other), _target(other._target)
{
    std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecuteRequirements(executor);
    std::cout << "* DRILLING NOISES * Brrrrrrrrrr... Drrrrrrr..." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}


