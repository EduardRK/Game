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