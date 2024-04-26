#pragma once

#include "MazeSolver.hpp"

class DfsMazeSolver final : public MazeSolver
{
public:
    DfsMazeSolver();
    ~DfsMazeSolver();

    auto solveMaze(Maze const &maze) -> std::vector<Point>;
};