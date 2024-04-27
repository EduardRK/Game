#include <utility>

#include "Cell.hpp"
#include "MazeTypeCell.hpp"
#include "Point.hpp"

Cell::Cell(Point point, MazeTypeCell type) : _point{std::move(point)}, _type{type}
{
}

Cell::Cell(const Point &point, MazeTypeCell type) : _point{point}, _type{type}
{
}

Cell::Cell(const Point &point) : _point{point}, _type{MazeTypeCell::WALL}
{
}

Cell::Cell(Point &&point, MazeTypeCell type) : _point{std::move(point)}, _type{type}
{
}

Cell::~Cell()
{
}

bool Cell::isWall() const
{
    return _type == MazeTypeCell::WALL;
}

bool Cell::isPassage() const
{
    return _type == MazeTypeCell::PASSAGE;
}

void Cell::createPassage()
{
    _type = MazeTypeCell::PASSAGE;
}

const Point &Cell::point() const
{
    return _point;
}
