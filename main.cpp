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
#include "maze/MazeRenderer.hpp"
#include "maze/GlutMazeRenderer.hpp"
#include "maze/CellRenderer.hpp"
#include "maze/GlutCellRenderer.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
    std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(31, 31);
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(*maze);

    system("pause");
    return 0;
}