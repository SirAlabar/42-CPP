#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

void printSeparator() 
{
    std::cout << "\n----------------------------------------\n" << std::endl;
}

void testIntArray() 
{
    std::cout << "TEST 1: Integer Array" << std::endl;
    
    Array<int> numbers(5);
    
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    std::cout << "Integer array (size " << numbers.size() << "): ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nTesting deep copy:" << std::endl;
    Array<int> numbersCopy = numbers;
    
    numbersCopy[0] = 100;
    
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << numbersCopy[0] << std::endl;
}

void testEmptyArray() 
{
    std::cout << "TEST 2: Empty Array" << std::endl;
    
    Array<float> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    try {
        std::cout << "Trying to access empty[0]..." << std::endl;
        float value = empty[0];
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testStringArray() 
{
    std::cout << "TEST 3: String Array" << std::endl;
    
    Array<std::string> strings(4);
    strings[0] = "C++";
    strings[1] = "is";
    strings[2] = "very";
    strings[3] = "cool!";
    
    std::cout << "String array (size " << strings.size() << "): ";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    Array<std::string> stringsCopy(strings);
    
    stringsCopy[3] = "amazing!";
    
    std::cout << "Original[3]: " << strings[3] << std::endl;
    std::cout << "Copy[3]: " << stringsCopy[3] << std::endl;
}

void testOutOfBounds() 
{
    std::cout << "TEST 4: Out of Bounds Access" << std::endl;
    
    Array<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    std::cout << "Array created with size " << arr.size() << std::endl;
    
    try {
        std::cout << "Trying to access arr[3]..." << std::endl;
        int value = arr[3];
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTrying to access arr[-1]..." << std::endl;
        int value = arr[-1];
        std::cout << "Value: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    srand(time(NULL));
    
    testIntArray();
    printSeparator();
    
    testEmptyArray();
    printSeparator();
    
    testStringArray();
    printSeparator();
    
    testOutOfBounds();
    
    return (0);
}