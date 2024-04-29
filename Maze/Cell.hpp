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
    bool isCracked() const;

    void createWall();
    void createPassage();
    void createCracked();

    const Point &point() const;
};