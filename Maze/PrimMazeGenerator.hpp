#pragma once

#include <memory>
#include <cstdlib>
#include <vector>

#include "MazeGenerator.hpp"
#include "Cell.hpp"
#include "Maze.hpp"

class PrimMazeGenerator final : public MazeGenerator
{
public:
    PrimMazeGenerator() = default;
    ~PrimMazeGenerator() = default;

    std::unique_ptr<Maze> generateMaze(std::size_t height, std::size_t width) override;

private:
    std::vector<std::vector<Cell>> createStartGrid(std::size_t height, std::size_t width);
    void createRandomPassageFromCell(std::vector<std::vector<Cell>> &grid, std::vector<char> &directions, std::vector<Cell> &visitedCells, Cell &currentCell);

    void postProcessing(Maze &maze);
    void createBorders(std::vector<std::vector<Cell>> &grid, std::size_t height, std::size_t width);
};