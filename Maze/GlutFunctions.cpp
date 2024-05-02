#include <GL/glut.h>
#include <memory>
#include <iostream>

#include "GlutFunctions.hpp"
#include "CellRenderer.hpp"
#include "GlutCellRenderer.hpp"
#include "MazeGenerator.hpp"
#include "PrimMazeGenerator.hpp"
#include "Maze.hpp"
#include "MazeSolver.hpp"
#include "DfsMazeSolver.hpp"

std::unique_ptr<CellRenderer> cellRenderer = std::make_unique<GlutCellRenderer>();
std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(32, 32);
std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(*maze);

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (size_t i = 0; i < maze->height(); ++i)
    {
        for (size_t j = 0; j < maze->width(); ++j)
        {
            cellRenderer->render(maze->cell(i, j));
        }
    }

    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int x, int y)
{
}
