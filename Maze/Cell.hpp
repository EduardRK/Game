#pragma once

#include "Point.hpp"
#include "MazeTypeCell.hpp"

class Cell final
{
private:
    Point _point;
    MazeTypeCell type;

public:
    Cell(Point &point, MazeTypeCell type);
    Cell(Point &point);

    ~Cell();

    bool isWall();
    bool isPassage();

    void createPassage();

    Point &point();
};