#include "Cell.hpp"
#include "MazeTypeCell.hpp"

Cell::Cell(Point &point, MazeTypeCell type) : point{point}, type{type}
{
}

Cell::Cell(Point &point) : Cell(point, MazeTypeCell::WALL)
{
}

Cell::~Cell()
{
}

auto Cell::isWall() -> bool
{
    
}