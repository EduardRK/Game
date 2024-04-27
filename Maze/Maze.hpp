#pragma once

#include <vector>
#include <cstdlib>

#include "MazeTypeCell.hpp"
#include "Cell.hpp"

class Maze final
{
private:
    std::size_t _height;
    std::size_t _width;
    std::vector<std::vector<Cell>> _maze;

public:
    Maze(std::vector<std::vector<Cell>> &maze, std::size_t height, std::size_t width);
    ~Maze();

    const Cell &cell(std::size_t x, std::size_t y) const;
    const Cell &cell(const Point &point);
    std::size_t height() const;
    std::size_t width() const;
};