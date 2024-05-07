#pragma once

#include <vector>

#include "Maze.hpp"
#include "Point.hpp"

class MazeSolver
{
public:
    virtual ~MazeSolver() = default;

    virtual std::vector<Point> solveMaze(const Point &start, const Point &end) = 0;
};