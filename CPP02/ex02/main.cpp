#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    
    // Additional tests for other operators
    std::cout << "\n----- Additional Tests -----\n";
    
    // Testing arithmetic operators
    Fixed c(10.5f);
    Fixed d(2.5f);
    
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c / d = " << c / d << std::endl;
    
    // Testing comparison operators
    std::cout << "\nComparisons:" << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    
    // Testing decrement operators
    Fixed e(1.5f);
    std::cout << "\nDecrement test with e = " << e << std::endl;
    std::cout << "--e = " << --e << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "e = " << e << std::endl;
    
    // Testing min/max functions
    Fixed f(100.1f);
    Fixed g(100.2f);
    std::cout << "\nf = " << f << ", g = " << g << std::endl;
    std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;
    
    return (0);
}