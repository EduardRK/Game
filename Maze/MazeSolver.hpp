#pragma once

#include <vector>

#include "Maze.hpp"
#include "Point.hpp"

class MazeSolver
{
public:
    virtual ~MazeSolver();

    virtual std::vector<Point> solveMaze(const Maze &maze) = 0;
};