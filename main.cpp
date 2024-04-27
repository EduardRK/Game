#include <vector>
#include <memory>
#include <utility>
#include <math.h>

#include "maze/Maze.hpp"
#include "maze/Cell.hpp"
#include "maze/MazeTypeCell.hpp"
#include "maze/PrimMazeGenerator.hpp"
#include "maze/MazeGenerator.hpp"
#include "maze/DfsMazeSolver.hpp"
#include "maze/MazeSolver.hpp"
#include "maze/Point.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>();
    Maze maze = mazeGenerator->generateMaze(11, 11);

    return 0;
}