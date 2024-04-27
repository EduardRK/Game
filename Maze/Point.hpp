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

    Point &operator=(const Point &other);

    int x() const;
    int y() const;

    bool operator==(const Point &other) const;
};