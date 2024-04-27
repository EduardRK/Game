#pragma once

#include "Point.hpp"
#include "MazeTypeCell.hpp"

class Cell final
{
private:
    Point _point;
    MazeTypeCell _type;

public:
    Cell() = default;

    Cell(Point point, MazeTypeCell type);
    Cell(const Point &point, MazeTypeCell type);
    Cell(const Point &point);
    Cell(Point &&point, MazeTypeCell type);

    ~Cell();

    bool isWall() const;
    bool isPassage() const;

    void createPassage();

    const Point &point() const;
};