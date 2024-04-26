#include <vector>

#include "Maze.hpp"

Maze::Maze(std::vector<std::vector<MazeTypeCell>> const &maze) : maze{maze}
{
}

Maze::~Maze()
{
}