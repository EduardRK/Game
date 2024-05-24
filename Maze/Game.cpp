#include "Game.hpp"
#include "GlutMazeRenderer.hpp"

Game::Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemies) : _player{player}, _maze{maze}, _enemies{enemies}, _mazeRenderer{std::make_unique<GlutMazeRenderer>(player, maze)}
{
}

void Game::draw()
{
    _mazeRenderer->render();

    _player.draw();

    for (auto &&enemy : _enemies)
    {
        enemy->draw();
    }
}

void Game::nextTurn()
{
    _player.nextTurn();

    for (auto &&enemy : _enemies)
    {
        enemy->nextTurn();
    }
}
