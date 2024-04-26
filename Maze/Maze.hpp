#pragma once

#include <vector>
#include <cstdlib>

#include "MazeTypeCell.hpp"
#include "Cell.hpp"

class Maze final
{
private:
    std::vector<std::vector<Cell>> &maze;

public:
    Maze(std::vector<std::vector<Cell>> const &maze);
    ~Maze();

    Cell &cell(std::size_t x, std::size_t y);
};