#include "Point.hpp"

Point::Point(int x, int y) : x{x}, y{y}
{
}

Point::~Point()
{
}

auto Point::x() -> int const
{
    return x;
}

auto Point::y() -> int const
{
    return y;
}