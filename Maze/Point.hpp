#pragma once

class Point final
{
private:
    int _x;
    int _y;

public:
    Point(int x, int y);
    ~Point();

    int x();
    int y();

    bool equals(Point const &point);
};