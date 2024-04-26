#pragma once

#include <vector>

#include "MazeTypeCell.hpp"

class Maze final
{
private:
    std::vector<std::vector<MazeTypeCell>> maze;

public:
    Maze(std::vector<std::vector<MazeTypeCell>> const &maze);
    ~Maze();
};