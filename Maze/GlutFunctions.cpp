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
#include "Player.hpp"
#include "MazeRenderer.hpp"
#include "GlutMazeRenderer.hpp"

std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(31, 31);
std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(*maze);
std::unique_ptr<Player> player = std::make_unique<Player>(1, 1, *maze);
std::unique_ptr<MazeRenderer> mazeRenderer = std::make_unique<GlutMazeRenderer>(*player, *maze);

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mazeRenderer->render();

    player->draw();

    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        player->moveUp();
        break;

    case 's':
        player->moveDown();
        break;

    case 'a':
        player->moveLeft();
        break;

    case 'd':
        player->moveRight();
        break;

    default:
        break;
    }

    glutPostRedisplay();
}
