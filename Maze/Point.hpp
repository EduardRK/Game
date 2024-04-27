#pragma once

class Point final
{
private:
    int _x;
    int _y;

public:
    Point(int x, int y);
    Point();
    Point(const Point &other);
    Point(Point &&other) noexcept;
    ~Point();

    int x() const;
    int y() const;

    bool equals(const Point &point) const;
};