#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() 
{
    Data original;
    original.id = 42;
    original.name = "Douglas Adams";

    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << std::endl;


    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
    std::cout << std::endl;


    Data* deserialized = Serializer::deserialize(serialized);
    

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << std::endl;


    if (deserialized == &original) {
        std::cout << "Success! The original and deserialized pointers are identical." << std::endl;
    } else {
        std::cout << "Error! The pointers do not match." << std::endl;
    }

    return (0);
}