#include "Game.hpp"
#include "GlutMazeRenderer.hpp"

Game::Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemies) : _player{player}, _maze{maze}, _enemies{enemies}, _mazeRenderer{std::make_unique<GlutMazeRenderer>(player, maze)}
{
}

Player &Game::player()
{
    return _player;
}

Maze &Game::maze()
{
    return _maze;
}

void Game::draw()
{
    _mazeRenderer->render();

    _player.draw();

    for (auto &&enemy : _enemies)
    {
        if (isEnemyInRadiusOfView(enemy))
        {
            enemy->draw();
        }
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

bool Game::isEnemyInRadiusOfView(std::shared_ptr<Enemy> enemy)
{
    bool flagX = (enemy->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (enemy->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (enemy->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (enemy->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}
