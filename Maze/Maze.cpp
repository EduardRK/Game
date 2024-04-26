#include <vector>
#include <cstdlib>

#include "Maze.hpp"
#include "Cell.hpp"

Maze::Maze(std::vector<std::vector<Cell>> &maze) : _maze{maze}
{
}

Maze::~Maze()
{
}

Cell &Maze::cell(std::size_t x, std::size_t y)
{
    return _maze.at(x).at(y);
}