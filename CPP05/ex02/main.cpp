#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() 
{
    std::cout << "----- Testing Concrete Forms -----" << std::endl;
    try 
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat worker("Worker", 140);
        Bureaucrat clerk("Clerk", 137);
        
        std::cout << "\n----- ShrubberyCreationForm Tests -----" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;
        
        worker.signForm(shrubForm);
        worker.executeForm(shrubForm);

        std::cout << "\n----- ShrubberyCreationForm Tests (with Boss) -----" << std::endl;
        ShrubberyCreationForm shrubBossForm("office");
        std::cout << shrubBossForm << std::endl;

        boss.signForm(shrubBossForm);
        boss.executeForm(shrubBossForm);
        
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
        
        std::cout << "\n----- Testing Form Execution Failures -----" << std::endl;
        PresidentialPardonForm unsignedForm("fugitive");
        boss.executeForm(unsignedForm);
        
        ShrubberyCreationForm anotherShrubForm("park");
        boss.signForm(anotherShrubForm);
        worker.executeForm(anotherShrubForm);
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}