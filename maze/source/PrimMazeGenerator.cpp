#include <cstdlib>
#include <vector>
#include <memory>
#include <iostream>

#include "MazeTypeCell.hpp"
#include "PrimMazeGenerator.hpp"
#include "Cell.hpp"
#include "Point.hpp"
#include "RandomFunctions.hpp"

std::unique_ptr<Maze> PrimMazeGenerator::generateMaze(std::size_t height, std::size_t width)
{
    std::size_t maxVisitedCells = ((height + 1) / 2) * ((width + 1) / 2);

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

    createBorders(grid, height, width);
    Maze maze(grid, height + 2, width + 2);
    postProcessing(maze);

    return std::make_unique<Maze>(maze);
}

std::vector<std::vector<Cell>> PrimMazeGenerator::createStartGrid(std::size_t height, std::size_t width)
{
    std::vector<std::vector<Cell>> grid(height);

    for (std::size_t i = 0; i < height; ++i)
    {
        for (std::size_t j = 0; j < width; ++j)
        {
            Point point(i, j);
            Cell cell(point);
            grid.at(i).push_back(cell);
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
            grid.at(xCell).at(yCell - 2).createPassage();
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
    else if (currentDirection == 'D')
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

void PrimMazeGenerator::postProcessing(Maze &maze)
{
    for (size_t i = 1; i < maze.height() - 1; ++i)
    {
        for (size_t j = 1; j < maze.width() - 1; ++j)
        {
            if (maze.cell(i, j).isWall())
            {
                int randomNumber = nextRandomInt(100);

                if (randomNumber < 10)
                {
                    maze.cell(i, j).createCracked();
                }
                else if (randomNumber >= 15 && randomNumber < 23)
                {
                    maze.cell(i, j).createPassage();
                }
            }
        }
    }
}

void PrimMazeGenerator::createBorders(std::vector<std::vector<Cell>> &grid, std::size_t height, std::size_t width)
{
    std::vector<Cell> upBorder;
    std::vector<Cell> downBorder;

    for (size_t i = 0; i < width + 2; ++i)
    {
        Cell upCell(0, i);
        upBorder.push_back(upCell);

        Cell downCell(height + 1, i);
        downBorder.push_back(downCell);
    }

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            grid.at(i).at(j) = Cell(grid.at(i).at(j).point().x() + 1, grid.at(i).at(j).point().y() + 1, grid.at(i).at(j).type());
        }
    }

    for (size_t i = 0; i < height; ++i)
    {
        Cell leftCell(i + 1, 0);
        grid.at(i).insert(grid.at(i).begin(), 1, leftCell);

        Cell rightCell(i + 1, height + 1);
        grid.at(i).push_back(rightCell);
    }

    grid.insert(grid.begin(), 1, upBorder);
    grid.push_back(downBorder);
}
