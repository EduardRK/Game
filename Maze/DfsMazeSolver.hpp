#pragma once

#include <vector>

#include "MazeSolver.hpp"
#include "Maze.hpp"
#include "Point.hpp"

class DfsMazeSolver final : public MazeSolver
{
public:
    DfsMazeSolver();
    ~DfsMazeSolver();

    std::vector<Point> solveMaze(const Maze &maze) override;
};