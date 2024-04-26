#pragma once

#include <cstdlib>

#include "Maze.hpp"

class MazeGenerator
{
public:
    virtual ~MazeGenerator();

    virtual Maze generateMaze(std::size_t height, std::size_t width) = 0;
};