#include <utility>

#include "Point.hpp"

Point::Point(int x, int y) : _x{x}, _y{y}
{
}

Point::Point() : Point(0, 0)
{
}

Point::Point(const Point &other) : _x{other._x}, _y{other._y}
{
}

Point::Point(Point &&other) noexcept : _x{std::move(other._x)}, _y{std::move(other._y)}
{
}

Point::~Point()
{
}

int Point::x() const
{
    return _x;
}

int Point::y() const
{
    return _y;
}

bool Point::equals(const Point &point) const
{
    return this->_x == point.x() && this->_y == point.y();
}
