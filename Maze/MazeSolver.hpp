#pragma once

#include <vector>

#include "Maze.hpp"
#include "Point.hpp"

class MazeSolver
{
public:
    virtual ~MazeSolver();

    virtual std::vector<Point> solveMaze(Maze const &maze) = 0;
};