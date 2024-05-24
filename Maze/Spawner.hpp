#pragma once

#include <vector>

#include "Maze.hpp"

template <typename T>
class Spawner
{
public:
    virtual ~Spawner() = default;

    virtual std::vector<T> spawn(const Maze &maze) = 0;
};