#pragma once

#include <cstdlib>

#include "MazeGenerator.hpp"
#include "Maze.hpp"

class PrimMazeGenerator final : public MazeGenerator
{
public:
    PrimMazeGenerator();
    ~PrimMazeGenerator();

    Maze generateMaze(std::size_t height, std::size_t width) override;
};