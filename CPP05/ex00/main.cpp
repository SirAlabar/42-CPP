#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
    std::cout << "----- Testing valid bureaucrat creation -----" << std::endl;
    try 
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        
        Bureaucrat copiedBob(bob);
        std::cout << "Copied Bob: " << copiedBob << std::endl;
        
        Bureaucrat alice("Alice", 75);
        std::cout << "Before assignment: " << alice << std::endl;
        alice = bob;
        std::cout << "After assignment: " << alice << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing grade too high exception -----" << std::endl;
    try 
    {
        Bureaucrat john("John", 0);
        std::cout << john << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing grade too low exception -----" << std::endl;
    try 
    {
        Bureaucrat jane("Jane", 151);
        std::cout << jane << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing increment and decrement -----" << std::endl;
    try 
    {
        Bureaucrat jim("Jim", 5);
        std::cout << "Initial: " << jim << std::endl;
        
        jim.incrementGrade();
        std::cout << "After increment: " << jim << std::endl;
        
        jim.decrementGrade();
        std::cout << "After decrement: " << jim << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing increment exception -----" << std::endl;
    try 
    {
        Bureaucrat top("Top Bureaucrat", 1);
        std::cout << "Initial: " << top << std::endl;
        
        top.incrementGrade();
        std::cout << "After increment: " << top << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n----- Testing decrement exception -----" << std::endl;
    try 
    {
        Bureaucrat bottom("Bottom Bureaucrat", 150);
        std::cout << "Initial: " << bottom << std::endl;
        
        bottom.decrementGrade(); 
        std::cout << "After decrement: " << bottom << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
}