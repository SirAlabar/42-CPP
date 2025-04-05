#include "iter.hpp"
#include <string>

//test
template <typename T>
void printElement(T const & element) 
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T & element) 
{
    element++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;
    
    std::cout << "Integer array before: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intArrayLength, incrementElement<int>);
    
    std::cout << "Integer array after increment: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    std::string stringArray[] = {"Hello", "from", "the", "iter", "function"};
    size_t stringArrayLength = 5;
    
    std::cout << "String array: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;
    
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = 5;
    
    std::cout << "Character array before: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    iter(charArray, charArrayLength, incrementElement<char>);
    
    std::cout << "Character array after increment: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatArrayLength = 5;
    
    std::cout << "Float array: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;
    
    return (0);
}