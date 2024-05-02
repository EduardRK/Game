#include <utility>

#include "Cell.hpp"
#include "MazeTypeCell.hpp"
#include "Point.hpp"

Cell::Cell(int x, int y, MazeTypeCell type)
{
    Point point(x, y);
    _point = point;
    _type = type;
}

Cell::Cell(int x, int y) : Cell(x, y, MazeTypeCell::WALL)
{
}

Cell::Cell(Point point, MazeTypeCell type) : _point{std::move(point)}, _type{type}
{
}

Cell::Cell(const Point &point, MazeTypeCell type) : _point{point}, _type{type}
{
}

Cell::Cell(const Point &point, const MazeTypeCell &type) : _point{point}, _type{type}
{
}

Cell::Cell(const Point &point) : _point{point}, _type{MazeTypeCell::WALL}
{
}

Cell::Cell(Point &&point, MazeTypeCell type) : _point{std::move(point)}, _type{type}
{
}

Cell::Cell(const Cell &cell) : _point{cell.point()}, _type{cell.type()}
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

bool Cell::isCracked() const
{
    return _type == MazeTypeCell::CRACKED;
}

void Cell::createWall()
{
    _type = MazeTypeCell::WALL;
}

void Cell::createPassage()
{
    _type = MazeTypeCell::PASSAGE;
}

void Cell::createCracked()
{
    _type = MazeTypeCell::CRACKED;
}

Point &Cell::point()
{
    return _point;
}

const Point &Cell::point() const
{
    return _point;
}

MazeTypeCell Cell::type()
{
    return _type;
}

const MazeTypeCell Cell::type() const
{
    return _type;
}
