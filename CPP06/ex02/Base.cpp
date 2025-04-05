#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() 
{

}

Base* generate(void)
{
    static bool firstCall = true;
    if (firstCall)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        firstCall = false;
    }

    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "Generated class A" << std::endl;
            return (new A());
        case 1:
            std::cout << "Generated class B" << std::endl;
            return (new B());    
        case 2:
            std::cout << "Generated class C" << std::endl;
            return (new C());
        default:
            return NULL;        
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unkown type" << std::endl;           
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception&) {} 
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception&) {}  
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception&) {}
    
    std::cout << "Unkown type" << std::endl;
}