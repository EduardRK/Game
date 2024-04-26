#pragma once

#include "MazeSolver.hpp"

class DfsMazeSolver final : public MazeSolver
{
public:
    DfsMazeSolver();
    ~DfsMazeSolver();

    std::vector<Point> solveMaze(Maze const &maze) override;
};