#pragma once

#include <vector>

#include "Maze.hpp"
#include "Point.hpp"

class MazeSolver
{
    public:
    virtual ~MazeSolver();

    virtual auto solveMaze(Maze const& maze) -> std::vector<Point> = 0;
};