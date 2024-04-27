#include <vector>
#include <memory>
#include <utility>
#include <math.h>
#include <iostream>

#include "maze/Maze.hpp"
#include "maze/Cell.hpp"
#include "maze/MazeTypeCell.hpp"
#include "maze/PrimMazeGenerator.hpp"
#include "maze/MazeGenerator.hpp"
#include "maze/DfsMazeSolver.hpp"
#include "maze/MazeSolver.hpp"
#include "maze/Point.hpp"

void renderMaze(const Maze &maze)
{
    for (size_t i = 0; i < maze.height(); ++i)
    {
        for (size_t j = 0; j < maze.width(); ++j)
        {
            if (maze.cell(i, j).isWall())
            {
                std::cout << "###";
            }
            else if (maze.cell(i, j).isPassage())
            {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>();
    std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(11, 11);

    renderMaze(*maze);

    system("pause");
    return 0;
}