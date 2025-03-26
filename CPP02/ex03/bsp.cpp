
#include "Point.hpp"

static Fixed area(Point const &a, Point const &b, Point const &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) + 
                  c.getX() * (a.getY() - b.getY()));

    if (area < 0)
        area = area * Fixed(-1);

    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed triangleArea = area(a, b, c);

    if (triangleArea == 0)
        return false;
    
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);
    
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    Fixed totalArea = area1 + area2 + area3;
    
    Fixed epsilon = Fixed(0.01f);
    Fixed diff = totalArea - triangleArea;
    if (diff < 0)
        diff = diff * Fixed(-1);
    
    return (diff < epsilon); 
}