#include "Point.hpp"
#include <iostream>

int main(void)
{
    // Test cases for the BSP function
    
    // Define a triangle with vertices at (0,0), (4,0) and (2,3)
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    Point inside(2, 1);  
    Point outside(5, 5);
    Point onVertex(0, 0); 
    Point onEdge(2, 0);
    
    std::cout << "Testing BSP (Binary Space Partitioning) algorithm for point in triangle:\n";
    std::cout << "Triangle vertices: A(0,0), B(4,0), C(2,3)\n\n";
    
    std::cout << "Point (2,1): " << (bsp(a, b, c, inside) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (5,5): " << (bsp(a, b, c, outside) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (0,0): " << (bsp(a, b, c, onVertex) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (2,0): " << (bsp(a, b, c, onEdge) ? "INSIDE" : "OUTSIDE") << std::endl;
    

    std::cout << "\nAdditional tests:\n";
    
    // Triangle with vertices at (1,1), (4,1) and (2.5,4)
    Point d(1, 1);
    Point e(4, 1);
    Point f(2.5, 4);
    

    Point p1(2.5, 2); 
    Point p2(1, 2);
    Point p3(2.5, 1); 
    
    std::cout << "Triangle vertices: D(1,1), E(4,1), F(2.5,4)\n";
    std::cout << "Point (2.5,2): " << (bsp(d, e, f, p1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (1,2): " << (bsp(d, e, f, p2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (2.5,1): " << (bsp(d, e, f, p3) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    return (0);
}