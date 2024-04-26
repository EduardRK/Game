#include "Cell.hpp"
#include "MazeTypeCell.hpp"
#include "Point.hpp"

Cell::Cell(Point &point, MazeTypeCell type) : _point{point}, type{type}
{
}

Cell::Cell(Point &point) : Cell(point, MazeTypeCell::WALL)
{
}

Cell::~Cell()
{
}

bool Cell::isWall()
{
    return type == MazeTypeCell::WALL;
}

bool Cell::isPassage()
{
    return type == MazeTypeCell::PASSAGE;
}

void Cell::createPassage()
{
    type = MazeTypeCell::PASSAGE;
}

Point &Cell::point()
{
    return _point;
}
