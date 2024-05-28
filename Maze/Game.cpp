#include <GL/glut.h>

#include "Game.hpp"
#include "GlutMazeRenderer.hpp"

Game::Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Item>> &items) : _player{player}, _maze{maze}, _enemies{enemies}, _items{items}, _mazeRenderer{std::make_unique<GlutMazeRenderer>(player, maze)}
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

void Game::useKeyboardKey(unsigned char key)
{
    switch (_phase)
    {
    case GAME_PHASE:
        gamePhaseKeybordFunc(key);
        break;
    case LOAD_PHASE:
        _phase = GAME_PHASE;
        break;
    default:
        break;
    }
}

void Game::draw()
{
    switch (_phase)
    {
    case GAME_PHASE:
        drawGamePhase();
        break;
    case LOAD_PHASE:
        drawLoadPhase();
        break;
    case DEFEAT_PHASE:
        drawDefeatPhase();
        break;
    case WIN_PHASE:
        drawWinPhase();
        break;
    default:
        break;
    }
}

void Game::nextTurn()
{
    _player.nextTurn();

    for (auto &&enemy : _enemies)
    {
        enemy->nextTurn();
    }

    damageExchange();
    itemTake();
}

bool Game::isEnemyInRadiusOfView(std::shared_ptr<Enemy> enemy)
{
    bool flagX = (enemy->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (enemy->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (enemy->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (enemy->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

bool Game::isItemInRadiusOfView(std::shared_ptr<Item> item)
{
    bool flagX = (item->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (item->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (item->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (item->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

void Game::damageExchange()
{
    for (size_t i = 0; i < _enemies.size(); ++i)
    {
        if (_player.currentPosition() == _enemies.at(i)->currentPosition())
        {
            Damage &playerDamage = _player.deal();
            Damage &enemyDamage = _enemies.at(i)->deal();

            _player.hit(enemyDamage);
            _enemies.at(i)->hit(playerDamage);

            if (!_enemies.at(i)->isAlive())
            {
                _enemies.erase(_enemies.begin() + i);
            }

            if (!_player.isAlive())
            {
                _phase = DEFEAT_PHASE;
                return;
            }
        }
    }
}

void Game::itemTake()
{
    for (size_t i = 0; i < _items.size(); ++i)
    {
        if (_player.currentPosition() == _items.at(i)->currentPosition() && _player.peekItem(_items.at(i)))
        {
            _items.erase(_items.begin() + i);
        }
    }
}

void Game::drawLoadPhase()
{
}

void Game::drawGamePhase()
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

    for (auto &&item : _items)
    {
        if (isItemInRadiusOfView(item))
        {
            item->draw();
        }
    }
}

void Game::drawDefeatPhase()
{
}

void Game::drawWinPhase()
{
}

void Game::gamePhaseKeybordFunc(unsigned char key)
{
    switch (key)
    {
    case 'w':
        _player.moveUp();
        nextTurn();
        break;

    case 's':
        _player.moveDown();
        nextTurn();
        break;

    case 'a':
        _player.moveLeft();
        nextTurn();
        break;

    case 'd':
        _player.moveRight();
        nextTurn();
        break;

    case ' ':
        nextTurn();
        break;

    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':

    default:
        break;
    }
}
