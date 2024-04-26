#pragma once

#include <cstdlib>

#include "Maze.hpp"

class MazeGenerator
{
public:
    virtual ~MazeGenerator();

    virtual auto generateMaze(std::size_t height, std::size_t width) -> Maze const = 0;
};