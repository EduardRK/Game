#pragma once

#include <memory>
#include <cstdlib>

#include "Maze.hpp"

class MazeGenerator
{
public:
    virtual ~MazeGenerator() = default;

    virtual std::unique_ptr<Maze> generateMaze(std::size_t height, std::size_t width) = 0;
};