#pragma once

#include <cstdlib>

#include "MazeGenerator.hpp"
#include "Maze.hpp"

class PrimMazeGenerator final : public MazeGenerator
{
public:
    PrimMazeGenerator();
    ~PrimMazeGenerator();

    auto generateMaze(std::size_t height, std::size_t width) -> Maze const override;
};