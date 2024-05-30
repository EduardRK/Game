#include <GL/glut.h>

#include "Game.hpp"
#include "GlutMazeRenderer.hpp"

Game::Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Item>> &items) : _player{player}, _maze{maze}, _enemies{enemies}, _items{items}, _mazeRenderer{std::make_unique<GlutMazeRenderer>(player, maze)}
{
}

const Player &Game::player() const
{
    return _player;
}

Player &Game::player()
{
    return _player;
}

const Maze &Game::maze() const
{
    return _maze;
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
                _items.push_back(_enemies.at(i)->deathRattle());
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

    glLineWidth(LINE_WIDTH);

    glColor3f(0.0f, 0.1f, 0.5f);

    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.7f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.5f, -0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.f);
    glVertex2f(-0.5f, 0.f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.25f);
    glVertex2f(-0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.4f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.4f, 0.25f);
    glVertex2f(-0.2f, -0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(-0.2f, -0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.25f);
    glVertex2f(0.1f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.f, -0.25f);
    glVertex2f(0.f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, -0.25f);
    glVertex2f(0.2f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.25f);
    glVertex2f(0.4f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, -0.25f);
    glVertex2f(0.4f, -0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.f);
    glVertex2f(0.4f, 0.f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.5f, -0.25f);
    glVertex2f(0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.7f, 0.25f);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.5f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.7f, -0.25f);
    glEnd();
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
    glLineWidth(LINE_WIDTH);

    glColor3f(1.f, 0.f, 0.2f);

    glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.5f, -0.25f);
    glVertex2f(-0.5f, -0.25f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.2f, 0.23f);
    glVertex2f(-0.2f, -0.23f);
    glVertex2f(-0.2f, 0.23f);
    glVertex2f(-0.18f, 0.25f);
    glVertex2f(-0.2f, -0.23f);
    glVertex2f(-0.18f, -0.25f);
    glVertex2f(-0.02f, 0.25f);
    glVertex2f(0.f, 0.23f);
    glVertex2f(0.f, -0.23f);
    glVertex2f(-0.02f, -0.25f);
    glVertex2f(0.f, 0.23f);
    glVertex2f(0.f, -0.23f);
    glVertex2f(-0.18f, -0.25f);
    glVertex2f(-0.02f, -0.25f);
    glVertex2f(-0.02f, 0.25f);
    glVertex2f(-0.18f, 0.25f);
    glVertex2f(0.1f, 0.02f);
    glVertex2f(0.1f, 0.23f);
    glVertex2f(0.1f, 0.02f);
    glVertex2f(0.12f, 0.f);
    glVertex2f(0.1f, 0.23f);
    glVertex2f(0.12f, 0.25f);
    glVertex2f(0.12f, 0.f);
    glVertex2f(0.28f, 0.f);
    glVertex2f(0.28f, 0.f);
    glVertex2f(0.3f, -0.02f);
    glVertex2f(0.3f, -0.23f);
    glVertex2f(0.3f, -0.02f);
    glVertex2f(0.3f, -0.23f);
    glVertex2f(0.28f, -0.25f);
    glVertex2f(0.1f, -0.25f);
    glVertex2f(0.28f, -0.25f);
    glVertex2f(0.12f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.4f, -0.25f);
    glVertex2f(0.4f, 0.25f);
    glVertex2f(0.4f, -0.25f);
    glVertex2f(0.6f, -0.25f);
    glVertex2f(0.4f, 0.25f);
    glVertex2f(0.6f, 0.25f);
    glVertex2f(0.4f, 0.f);
    glVertex2f(0.6f, 0.f);
    glEnd();
}

void Game::drawWinPhase()
{
    glLineWidth(LINE_WIDTH);

    glColor3f(1.f, 1.f, 0.32f);

    glBegin(GL_LINES);
    glVertex2f(-0.45f, 0.25f);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.35f, 0.25f);
    glVertex2f(-0.35f, 0.25f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.25f, 0.25f);

    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-0.15f, -0.25f);
    glVertex2f(0.05f, -0.25f);
    glVertex2f(-0.15f, 0.25f);
    glVertex2f(0.05f, 0.25f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.05f, -0.25f);
    glVertex2f(0.15f, 0.25f);
    glVertex2f(0.15f, -0.25f);
    glVertex2f(0.15f, 0.25f);
    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.35f, 0.25f);
    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.45f, -0.24f);
    glVertex2f(0.45f, -0.25f);
    glVertex2f(0.45f, -0.2f);
    glVertex2f(0.45f, 0.25f);
    glEnd();
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
        _player.useItem(0);
        nextTurn();
        break;

    case '2':
        _player.useItem(1);
        nextTurn();
        break;

    case '3':
        _player.useItem(2);
        nextTurn();
        break;

    case '4':
        _player.useItem(3);
        nextTurn();
        break;

    case '5':
        _player.useItem(4);
        nextTurn();
        break;

    case '6':
        _player.useItem(5);
        nextTurn();
        break;

    case '7':
        _player.useItem(6);
        nextTurn();
        break;

    case '8':
        _player.useItem(7);
        nextTurn();
        break;

    case '9':
        _player.useItem(8);
        nextTurn();
        break;

    case '0':
        _player.useItem(9);
        nextTurn();
        break;

    default:
        break;
    }
}
