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

    auto isWall() -> bool;
    auto isPassage() -> bool;

    auto createPassage() -> void;

    Point &point();
};