#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() 
{
    std::cout << "----- Testing Concrete Forms -----" << std::endl;
    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    
    try 
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat worker("Worker", 140);
        
        std::cout << "\n----- ShrubberyCreationForm Tests -----" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;
        
        worker.signForm(shrubForm);
        worker.executeForm(shrubForm);

        std::cout << "\n----- RobotomyRequestForm Tests -----" << std::endl;
        RobotomyRequestForm robotForm("target");
        std::cout << robotForm << std::endl;
        
        manager.signForm(robotForm);
        manager.executeForm(robotForm);
        
        std::cout << "\n----- PresidentialPardonForm Tests -----" << std::endl;
        PresidentialPardonForm pardonForm("criminal");
        std::cout << pardonForm << std::endl;
        
        boss.signForm(pardonForm);
        boss.executeForm(pardonForm);
        
        std::cout << "\n----- Testing Intern Class -----" << std::endl;
        Intern someRandomIntern;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        scf = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        
        ppf = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        
        std::cout << "\n----- Testing Invalid Form -----" << std::endl;
        try 
        {
            AForm* invalidForm = someRandomIntern.makeForm("time travel request", "Einstein");
            std::cout << *invalidForm << std::endl;
            delete invalidForm;
        } 
        catch (std::exception &e) 
        {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    if (rrf) delete rrf;
    if (scf) delete scf;
    if (ppf) delete ppf;
    
    return (0);
}