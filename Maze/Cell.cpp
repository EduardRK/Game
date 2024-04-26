#include "Cell.hpp"
#include "MazeTypeCell.hpp"

Cell::Cell(MazeTypeCell type) : type{type}
{
}

Cell::Cell() : Cell(MazeTypeCell::WALL)
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