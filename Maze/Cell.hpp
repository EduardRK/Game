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

    Cell(int x, int y, MazeTypeCell type);
    Cell(int x, int y);
    Cell(Point point, MazeTypeCell type);
    Cell(const Point &point, MazeTypeCell type);
    Cell(const Point& point, const MazeTypeCell& type);
    Cell(const Point &point);
    Cell(Point &&point, MazeTypeCell type);
    Cell(const Cell& cell);

    ~Cell();

    bool isWall() const;
    bool isPassage() const;
    bool isCracked() const;

    void createWall();
    void createPassage();
    void createCracked();

    Point &point();
    const Point &point() const;

    MazeTypeCell type();
    const MazeTypeCell type() const;
};