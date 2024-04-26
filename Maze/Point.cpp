#include "Point.hpp"

Point::Point(int x, int y) : _x{x}, _y{y}
{
}

Point::~Point()
{
}

int Point::x()
{
    return x;
}

int Point::y()
{
    return y;
}

bool Point::equals(Point const &point)
{
    return _x == poitn.x() && _y == point.y();
}
