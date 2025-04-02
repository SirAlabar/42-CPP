#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    std::cout << "----- Testing Form Creation -----" << std::endl;
    try 
    {
        Form defaultForm;
        std::cout << defaultForm << std::endl;
        
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
        
        Form copiedForm(taxForm);
        std::cout << "Copied Form: " << copiedForm << std::endl;
        
        Form assignedForm;
        assignedForm = taxForm;
        std::cout << "Assigned Form: " << assignedForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- Testing Form Grade Exceptions -----" << std::endl;
    try 
    {
        Form invalidForm("Invalid Form", 0, 25); 
        std::cout << invalidForm << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try 
    {
        Form invalidForm("Invalid Form", 50, 151);
        std::cout << invalidForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing Bureaucrat Signing Forms -----" << std::endl;
    try 
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);
        
        Form topSecretForm("Top Secret", 5, 2);
        Form standardForm("Standard", 50, 25);
        Form basicForm("Basic", 100, 100);
        
        std::cout << "\nInitial form states:" << std::endl;
        std::cout << topSecretForm << std::endl;
        std::cout << standardForm << std::endl;
        std::cout << basicForm << std::endl;
        
        std::cout << "\nTesting signing with different bureaucrat levels:" << std::endl;
        boss.signForm(topSecretForm);
        manager.signForm(standardForm);
        intern.signForm(basicForm);
        
        std::cout << "\nAttempting to sign forms with insufficient grade:" << std::endl;
        intern.signForm(topSecretForm);
        intern.signForm(standardForm);
        
        std::cout << "\nFinal form states:" << std::endl;
        std::cout << topSecretForm << std::endl;
        std::cout << standardForm << std::endl;
        std::cout << basicForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
}