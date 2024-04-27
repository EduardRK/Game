#include <vector>
#include <cstdlib>

#include "Maze.hpp"
#include "Cell.hpp"

Maze::Maze(std::vector<std::vector<Cell>> &maze, std::size_t height, std::size_t width) : _maze{maze}, _height{height}, _width{width}
{
}

Maze::~Maze()
{
}

const Cell &Maze::cell(std::size_t x, std::size_t y) const
{
    return _maze.at(x).at(y);
}

const Cell &Maze::cell(const Point &point)
{
    return _maze.at(point.x()).at(point.y());
}

std::size_t Maze::height() const
{
    return _height;
}

std::size_t Maze::width() const
{
    return _width;
}
