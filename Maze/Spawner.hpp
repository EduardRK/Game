#pragma once

#include <vector>
#include <memory>

#include "Maze.hpp"

template <typename T>
class Spawner
{
public:
    virtual ~Spawner() = default;

    virtual std::vector<std::shared_ptr<T>> spawn(const Maze &maze) = 0;
};