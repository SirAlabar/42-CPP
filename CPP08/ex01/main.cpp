#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

void testBasicFunctionality() 
{
    std::cout << "========== Basic Functionality Test ==========" << std::endl;
    
    //subject
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testErrorHandling() 
{
    std::cout << "\n========== Error Handling Test ==========" << std::endl;
    
    // Test limit
    Span sp = Span(3);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    
    try 
    {
        std::cout << "Trying to add a number beyond capacity..." << std::endl;
        sp.addNumber(4); //exception
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test empty span
    Span emptySpan = Span(5);
    try 
    {
        std::cout << "Trying to find spans in an empty span..." << std::endl;
        emptySpan.shortestSpan(); //exception
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test one number
    Span singleSpan = Span(5);
    singleSpan.addNumber(42);
    try 
    {
        std::cout << "Trying to find spans with only one number..." << std::endl;
        singleSpan.longestSpan(); //exception
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testLargeSpan() 
{
    std::cout << "\n========== Large Span Test ==========" << std::endl;
    
    const unsigned int N = 10000;
    Span largeSpan(N);
    
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (unsigned int i = 0; i < N; ++i) 
    {
        largeSpan.addNumber(std::rand() % 1000000);
    }
    
    std::cout << "Created a span with " << largeSpan.getSize() << " random numbers" << std::endl;
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

void testAddRange() 
{
    std::cout << "\n========== Add Range Test ==========" << std::endl;
    
    Span sp = Span(10);
    
    std::vector<int> numbers;
    for (int i = 1; i <= 5; ++i) 
    {
        numbers.push_back(i * 10);
    }
    
    sp.addRange(numbers.begin(), numbers.end());
    std::cout << "Added " << numbers.size() << " numbers using addRange()" << std::endl;
    
    sp.addNumber(1);
    sp.addNumber(100);
    
    std::cout << "Span now contains " << sp.getSize() << " numbers" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    try 
    {
        std::vector<int> moreNumbers(10, 42);
        std::cout << "Trying to add more numbers than capacity using addRange()..." << std::endl;
        sp.addRange(moreNumbers.begin(), moreNumbers.end());
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() 
{
    testBasicFunctionality();
    testErrorHandling();
    testLargeSpan();
    testAddRange();
    
    return (0);
}