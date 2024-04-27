#include <cstdlib>
#include <vector>
#include <random>

#include "PrimMazeGenerator.hpp"
#include "Cell.hpp"
#include "Point.hpp"

PrimMazeGenerator::PrimMazeGenerator()
{
}

PrimMazeGenerator::~PrimMazeGenerator()
{
}

Maze PrimMazeGenerator::generateMaze(std::size_t height, std::size_t width)
{
    const std::size_t maxVisitedCells = ((height + 1) / 2) * ((width + 1) / 2);

    std::vector<std::vector<Cell>> grid = createStartGrid(height, width);

    grid.at(0).at(0).createPassage();
    Cell currentCell = grid.at(0).at(0);

    std::vector<Cell> visitedCells = {currentCell};
    std::vector<Cell> finalVisitedCells;

    while ((visitedCells.size() + finalVisitedCells.size()) != maxVisitedCells)
    {
        int cellIndex = nextRandomInt(visitedCells.size());
        currentCell = visitedCells.at(cellIndex);

        int x = currentCell.point().x();
        int y = currentCell.point().y();

        std::vector<char> directions{'U', 'D', 'R', 'L'};
        while (!directions.empty())
        {
            createRandomPassageFromCell(grid, directions, visitedCells, currentCell);
        }

        if ((x + 2 >= height || grid.at(x + 2).at(y).isPassage()) && (x - 2 < 0 || grid.at(x - 2).at(y).isPassage()) && (y + 2 >= width || grid.at(x).at(y + 2).isPassage()) && (y - 2 < 0 || grid.at(x).at(y - 2).isPassage()))
        {
            finalVisitedCells.push_back(currentCell);
            visitedCells.erase(visitedCells.begin() + cellIndex);
        }
    }

    return Maze(grid);
}

std::vector<std::vector<Cell>> PrimMazeGenerator::createStartGrid(std::size_t height, std::size_t width)
{
    std::vector<std::vector<Cell>> grid(height, std::vector<Cell>(width));

    for (std::size_t i = 0; i < width; ++i)
    {
        for (std::size_t j = 0; j < height; ++j)
        {
            Point point(i, j);
            grid.at(i).at(j) = Cell(point);
        }
    }

    return grid;
}

void PrimMazeGenerator::createRandomPassageFromCell(std::vector<std::vector<Cell>> &grid, std::vector<char> &directions, std::vector<Cell> &visitedCells, Cell &currentCell)
{
    int xCell = currentCell.point().x();
    int yCell = currentCell.point().y();
    int directionIndex = nextRandomInt(directions.size());
    char currentDirection = directions.at(directionIndex);

    if (currentDirection == 'R')
    {
        if (yCell + 2 < grid.at(0).size() && grid.at(xCell).at(yCell + 2).isWall())
        {
            grid.at(xCell).at(yCell + 1).createPassage();
            grid.at(xCell).at(yCell + 2).createPassage();
            visitedCells.push_back(grid.at(xCell).at(yCell + 2));
            directions.clear();
        }
    }
    else if (currentDirection == 'L')
    {
        if (yCell - 2 >= 0 && grid.at(xCell).at(yCell - 2).isWall())
        {
            grid.at(xCell).at(yCell - 1).createPassage();
            grid.at(xCell).at(yCell - 1).createPassage();
            visitedCells.push_back(grid.at(xCell).at(yCell - 2));
            directions.clear();
        }
    }
    else if (currentDirection == 'U')
    {
        if (xCell + 2 < grid.size() && grid.at(xCell + 2).at(yCell).isWall())
        {
            grid.at(xCell + 1).at(yCell).createPassage();
            grid.at(xCell + 2).at(yCell).createPassage();
            visitedCells.push_back(grid.at(xCell + 2).at(yCell));
            directions.clear();
        }
    }
    else
    {
        if (xCell - 2 >= 0 && grid.at(xCell - 2).at(yCell).isWall())
        {
            grid.at(xCell - 1).at(yCell).createPassage();
            grid.at(xCell - 2).at(yCell).createPassage();
            visitedCells.push_back(grid.at(xCell - 2).at(yCell));
            directions.clear();
        }
    }

    if (!directions.empty())
    {
        directions.erase(directions.begin() + directionIndex);
    }
}

int PrimMazeGenerator::nextRandomInt(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    return dist6(rng);
}

int PrimMazeGenerator::nextRandomInt(int max)
{
    return nextRandomInt(0, max);
}
