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
#include "Game.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "EnemiesSpawner.hpp"

std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(45, 45);
std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(*maze);
std::unique_ptr<Player> player = std::make_unique<Player>(1, 1, *maze);
std::unique_ptr<Spawner<std::shared_ptr<Enemy>>> spawner = std::make_unique<EnemiesSpawner>();
std::vector<std::shared_ptr<Enemy>> enemies = spawner->spawn(*maze);
Game game(*player, *maze, enemies);

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    game.draw();

    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        game.player().moveUp();
        game.nextTurn();
        break;

    case 's':
        game.player().moveDown();
        game.nextTurn();
        break;

    case 'a':
        game.player().moveLeft();
        game.nextTurn();
        break;

    case 'd':
        game.player().moveRight();
        game.nextTurn();
        break;

    case ' ':
        game.nextTurn();
        break;

    default:
        break;
    }

    glutPostRedisplay();
}