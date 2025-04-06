#include <iostream>
#include <list> 
#include "MutantStack.hpp"

int main()
{
    //subject
    std::cout << "=== Testing MutantStack Subject ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Iterating through MutantStack: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    //add test
    std::cout << "\n=== Testing std::list for comparison ===" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Iterating through std::list: ";
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++lst_it;
    --lst_it;
    while (lst_it != lst_ite) {
        std::cout << *lst_it << " ";
        ++lst_it;
    }
    std::cout << std::endl;
    
    // test copying
    std::cout << "\n=== Testing MutantStack copying ===" << std::endl;
    std::stack<int> s(mstack);
    MutantStack<int> mstack_copy(mstack);
    
    std::cout << "Original stack size: " << mstack.size() << std::endl;
    std::cout << "Copied stack size: " << mstack_copy.size() << std::endl;
    
    std::cout << "Iterating through copied MutantStack: ";
    for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // test reverse iterators
    std::cout << "\n=== Testing reverse iterators ===" << std::endl;
    std::cout << "Iterating through MutantStack in reverse: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) 
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    return (0);
}