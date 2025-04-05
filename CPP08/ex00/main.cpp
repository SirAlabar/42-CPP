#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

int main()
{
    //test vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);        
    
    std::cout << "=== Testing with std::vector ===" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value " << *it << " at position "
                  << std::distance(vec.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found value " << *it << " at position "
                  << std::distance(vec.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    //test list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);    
    
    std::cout << "\n=== Testing with std::list ===" << std::endl;

    try
    {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found value " << *it << " at position "
                  << std::distance(lst.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found value " << *it << " at position "
                  << std::distance(lst.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    //test  deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);    
    
    std::cout << "\n=== Testing with std::deque ===" << std::endl;

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "Found value " << *it << " at position "
                    << std::distance(deq.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    //test set

    std::set<int> set;
    set.insert(5);
    set.insert(10);
    set.insert(15);
    set.insert(20);
    set.insert(25);    
    
    std::cout << "\n=== Testing with std::set ===" << std::endl;

    try
    {
        std::set<int>::iterator it = easyfind(set, 15);
        std::cout << "Found value " << *it << " at position "
                    << std::distance(set.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::set<int>::iterator it = easyfind(set, 30);
        std::cout << "Found value " << *it << " at position "
                    << std::distance(set.begin(), it) << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }    

}