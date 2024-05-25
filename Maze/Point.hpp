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
    ~Point() = default;

    Point &operator=(const Point &other);
    bool operator==(const Point &other) const;
    bool operator!=(const Point& other) const;

    int x() const;
    int y() const;
};