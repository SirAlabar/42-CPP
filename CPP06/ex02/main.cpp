
#include "Base.hpp"
#include <iostream>

int main() 
{
    std::cout << "Testing type identification:" << std::endl;
    std::cout << "===========================" << std::endl;

    for (int i = 0; i < 5; i++) 
    {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        
        Base* randomClass = generate();
        
        std::cout << "Identifying with pointer: ";
        identify(randomClass);
        
        std::cout << "Identifying with reference: ";
        identify(*randomClass);
        
        delete randomClass;
    }

    std::cout << "\nTesting explicit instantiation:" << std::endl;
    std::cout << "=============================" << std::endl;

    // Test with class A
    std::cout << "\nExplicit A test:" << std::endl;
    Base* testA = new A();
    std::cout << "Identifying with pointer: ";
    identify(testA);
    std::cout << "Identifying with reference: ";
    identify(*testA);
    delete testA;

    // Test with class B
    std::cout << "\nExplicit B test:" << std::endl;
    Base* testB = new B();
    std::cout << "Identifying with pointer: ";
    identify(testB);
    std::cout << "Identifying with reference: ";
    identify(*testB);
    delete testB;

    // Test with class C
    std::cout << "\nExplicit C test:" << std::endl;
    Base* testC = new C();
    std::cout << "Identifying with pointer: ";
    identify(testC);
    std::cout << "Identifying with reference: ";
    identify(*testC);
    delete testC;

    return (0);
}