#include <bits/stdc++.h>

#include "PrimMazeGenerator.hpp"

PrimMazeGenerator::PrimMazeGenerator()
{
}

PrimMazeGenerator::~PrimMazeGenerator()
{
}

Maze PrimMazeGenerator::generateMaze(std::size_t height, std::size_t width)
{
    const std::size_t maxVisitedCells = ((height + 1) / 2) * ((width + 1) / 2);

    std::vector<std::vector<Cell>> grid;
    return Maze(NULL);
}
