#pragma once

#include "Maze.hpp"

class MazeRenderer
{
public:
    virtual ~MazeRenderer();

    virtual void render(const Maze &maze) = 0;
};