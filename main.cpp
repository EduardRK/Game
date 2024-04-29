#include <vector>
#include <memory>
#include <utility>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>

#include "maze/Maze.hpp"
#include "maze/Cell.hpp"
#include "maze/MazeTypeCell.hpp"
#include "maze/PrimMazeGenerator.hpp"
#include "maze/MazeGenerator.hpp"
#include "maze/DfsMazeSolver.hpp"
#include "maze/MazeSolver.hpp"
#include "maze/Point.hpp"
#include "maze/CellRenderer.hpp"
#include "maze/GlutCellRenderer.hpp"

std::string wallBorder(int n)
{
    std::string string;

    for (size_t i = 0; i < n + 2; ++i)
    {
        string += "##";
    }

    return string;
}

void renderMaze(const Maze &maze)
{
    std::cout << wallBorder(maze.width()) << std::endl;
    for (size_t i = 0; i < maze.height(); ++i)
    {
        std::cout << "##";
        for (size_t j = 0; j < maze.width(); ++j)
        {
            if (maze.cell(i, j).isWall())
            {
                std::cout << "##";
            }
            else if (maze.cell(i, j).isPassage())
            {
                std::cout << "  ";
            }
            else if (maze.cell(i, j).isCracked())
            {
                std::cout << "&&";
            }
        }
        std::cout << "##" << std::endl;
    }
    std::cout << wallBorder(maze.width()) << std::endl;
}

int main(int argc, char **argv)
{
    std::unique_ptr<Runner> runner = std::make_unique<GameRunner>();
    runner->run();

    std::unique_ptr<CellRenderer> cellRenderer = std::make_unique<GlutCellRenderer>();
    std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
    std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(31, 31);
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(*maze);

    renderMaze(*maze);

    system("pause");
    return 0;
}