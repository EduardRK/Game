#include <GL/glut.h>
#include <memory>
#include <iostream>

#include "GlutFunctions.hpp"
#include "CellRenderer.hpp"
#include "GlutCellRenderer.hpp"
#include "MazeGenerator.hpp"
#include "PrimMazeGenerator.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "MazeRenderer.hpp"
#include "GlutMazeRenderer.hpp"
#include "Game.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "EnemiesSpawner.hpp"
#include "ItemsSpawner.hpp"
#include "Exit.hpp"

std::unique_ptr<MazeGenerator> mazeGenerator = std::make_unique<PrimMazeGenerator>();
std::unique_ptr<Maze> maze = mazeGenerator->generateMaze(45, 45);
std::unique_ptr<Exit> exitPosition = std::make_unique<Exit>(*maze);
std::unique_ptr<Player> player = std::make_unique<Player>(1, 1, *maze, *exitPosition);
std::unique_ptr<Spawner<Enemy>> enemiesSpawner = std::make_unique<EnemiesSpawner>(*player);
std::vector<std::shared_ptr<Enemy>> enemies = enemiesSpawner->spawn(*maze);
std::unique_ptr<Spawner<Item>> itemsSpawner = std::make_unique<ItemsSpawner>(*player);
std::vector<std::shared_ptr<Item>> items = itemsSpawner->spawn(*maze);
std::unique_ptr<Game> game = std::make_unique<Game>(*player, *maze, enemies, items, *exitPosition);

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    game->draw();

    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    if (!game->canRestart())
    {
        game->useKeyboardKey(key);
    }
    else
    {
        if (key == 'r')
        {
            mazeGenerator = std::make_unique<PrimMazeGenerator>();
            maze = mazeGenerator->generateMaze(45, 45);
            exitPosition = std::make_unique<Exit>(*maze);
            player = std::make_unique<Player>(1, 1, *maze, *exitPosition);
            enemiesSpawner = std::make_unique<EnemiesSpawner>(*player);
            enemies = enemiesSpawner->spawn(*maze);
            itemsSpawner = std::make_unique<ItemsSpawner>(*player);
            items = itemsSpawner->spawn(*maze);
            game = std::make_unique<Game>(*player, *maze, enemies, items, *exitPosition);
        }
    }

    glutPostRedisplay();
}