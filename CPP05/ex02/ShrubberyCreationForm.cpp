#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Parameterized ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecuteRequirements(executor);
    
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile)
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    outfile << "       *       " << std::endl;
    outfile << "      ***      " << std::endl;
    outfile << "     *****     " << std::endl;
    outfile << "    *******    " << std::endl;
    outfile << "   *********   " << std::endl;
    outfile << "  ***********  " << std::endl;
    outfile << " ************* " << std::endl;
    outfile << "***************" << std::endl;
    outfile << "      |||      " << std::endl;
    outfile << "      |||      " << std::endl;
    outfile << "      |||      " << std::endl;
    outfile << std::endl;
    outfile << "       *       " << std::endl;
    outfile << "      ***      " << std::endl;
    outfile << "     *****     " << std::endl;
    outfile << "    *******    " << std::endl;
    outfile << "   *********   " << std::endl;
    outfile << "      |||      " << std::endl;
    outfile << "      |||      " << std::endl;
    
    outfile.close();
    std::cout << "Created shrubbery in file " << filename << std::endl;
}
