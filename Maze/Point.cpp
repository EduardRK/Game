#include <utility>

#include "Point.hpp"

Point::Point(int x, int y) : _x{x}, _y{y}
{
}

Point::Point() : Point(0, 0)
{
}

Point::Point(const Point &other) : _x{other.x()}, _y{other.y()}
{
}

Point::Point(Point &&other) noexcept : _x{std::move(other._x)}, _y{std::move(other._y)}
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        _x = other.x();
        _y = other.y();
    }

    return *this;
}

int Point::x() const
{
    return _x;
}

int Point::y() const
{
    return _y;
}

bool Point::operator==(const Point &other) const
{
    return _x == other.x() && _y == other.y();
}
