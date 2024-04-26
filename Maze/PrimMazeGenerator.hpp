#pragma once

#include <cstdlib>
#include <vector>

#include "MazeGenerator.hpp"
#include "Cell.hpp"
#include "Maze.hpp"

class PrimMazeGenerator final : public MazeGenerator
{
public:
    PrimMazeGenerator();
    ~PrimMazeGenerator();

    Maze generateMaze(std::size_t height, std::size_t width) override;

private:
    std::vector<std::vector<Cell>> &createStartGrid(std::size_t height, std::size_t width);
    void createRandomPassageFromCell(std::vector<std::vector<Cell>> &grid, std::vector<char> &directions, std::vector<Cell> &visitedCells, Cell &currentCell);

    int nextRandomInt(int min, int max);
    int nextRandomInt(int max);
};