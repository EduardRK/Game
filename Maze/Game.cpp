#include <GL/glut.h>

#include "Game.hpp"
#include "GlutMazeRenderer.hpp"
#include "Explosion.hpp"

Game::Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Item>> &items) : _player{player}, _maze{maze}, _enemies{enemies}, _items{items}, _mazeRenderer{std::make_unique<GlutMazeRenderer>(player, maze)}, _exit{Exit(maze)}
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
    case GamePhase::GAME_PHASE:
        gamePhaseKeybordFunc(key);
        break;

    case GamePhase::LOAD_PHASE:
        _phase = GamePhase::GAME_PHASE;
        break;

    default:
        break;
    }
}

void Game::draw()
{
    switch (_phase)
    {
    case GamePhase::GAME_PHASE:
        drawGamePhase();
        break;

    case GamePhase::LOAD_PHASE:
        drawLoadPhase();
        break;

    case GamePhase::DEFEAT_PHASE:
        drawDefeatPhase();
        break;

    case GamePhase::WIN_PHASE:
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

    std::vector<Explosion> explosions;

    for (size_t i = 0; i < _atcivatingItems.size(); ++i)
    {
        if (_atcivatingItems.at(i)->complete())
        {
            explosions.push_back(_atcivatingItems.at(i)->result());
            _atcivatingItems.erase(_atcivatingItems.begin() + i);
        }
        else
        {
            _atcivatingItems.at(i)->nextTurn();
        }
    }

    for (auto &&explosion : explosions)
    {
        explosionCalculate(explosion);
        explosionDraw(explosion);
    }

    damageExchange();
    itemTake();
    winCheck();
}

bool Game::isEnemyInRadiusOfView(std::shared_ptr<Enemy> &enemy)
{
    bool flagX = (enemy->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (enemy->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (enemy->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (enemy->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

bool Game::isItemInRadiusOfView(std::shared_ptr<Item> &item)
{
    bool flagX = (item->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (item->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (item->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (item->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

bool Game::isActivatingItemInRadiusOfView(std::shared_ptr<ActivatingItem<Explosion>> &activatingItem)
{
    bool flagX = (activatingItem->currentPosition().x() <= (_player.currentPosition().x() + _player.radiusView())) && (activatingItem->currentPosition().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (activatingItem->currentPosition().y() <= (_player.currentPosition().y() + _player.radiusView())) && (activatingItem->currentPosition().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

bool Game::isExitInRadiusOfView()
{
    bool flagX = (_exit.position().x() <= (_player.currentPosition().x() + _player.radiusView())) && (_exit.position().x() >= (_player.currentPosition().x() - _player.radiusView()));
    bool flagY = (_exit.position().y() <= (_player.currentPosition().y() + _player.radiusView())) && (_exit.position().y() >= (_player.currentPosition().y() - _player.radiusView()));
    return flagX && flagY;
}

void Game::damageExchange()
{
    for (size_t i = 0; i < _enemies.size(); ++i)
    {
        if (_player.currentPosition() == _enemies.at(i)->currentPosition())
        {
            Damage enemyDamage = _enemies.at(i)->deal();

            _player.hit(enemyDamage);

            if (!_player.isAlive())
            {
                _phase = GamePhase::DEFEAT_PHASE;
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

void Game::winCheck()
{
    if (_player.currentPosition() == _exit.position() && _player.statuses().keyStatus())
    {
        _phase = GamePhase::WIN_PHASE;
    }
}

void Game::attack()
{
    Damage damage = _player.deal();

    for (size_t i = 0; i < _enemies.size(); ++i)
    {
        if (isEnemyInRadiusOfAttack(_enemies.at(i)))
        {
            _enemies.at(i)->hit(damage);

            if (!_enemies.at(i)->isAlive())
            {
                _items.push_back(_enemies.at(i)->deathRattle());
                _enemies.erase(_enemies.begin() + i);
            }
        }
    }

    for (size_t i = 0; i < _atcivatingItems.size(); ++i)
    {
        if (isActivatingItemInRadiusOfAttack(_atcivatingItems.at(i)))
        {
            _atcivatingItems.at(i)->activate();
        }
    }

    _player.attack();
}

bool Game::isEnemyInRadiusOfAttack(std::shared_ptr<Enemy> &enemy)
{
    bool flagX = (enemy->currentPosition().x() <= (_player.currentPosition().x() + _player.stats().radiusAttack())) && (enemy->currentPosition().x() >= (_player.currentPosition().x() - _player.stats().radiusAttack()));
    bool flagY = (enemy->currentPosition().y() <= (_player.currentPosition().y() + _player.stats().radiusAttack())) && (enemy->currentPosition().y() >= (_player.currentPosition().y() - _player.stats().radiusAttack()));
    return flagX && flagY;
}

bool Game::isActivatingItemInRadiusOfAttack(std::shared_ptr<ActivatingItem<Explosion>> &activatingItem)
{
    bool flagX = (activatingItem->currentPosition().x() <= (_player.currentPosition().x() + _player.stats().radiusAttack())) && (activatingItem->currentPosition().x() >= (_player.currentPosition().x() - _player.stats().radiusAttack()));
    bool flagY = (activatingItem->currentPosition().y() <= (_player.currentPosition().y() + _player.stats().radiusAttack())) && (activatingItem->currentPosition().y() >= (_player.currentPosition().y() - _player.stats().radiusAttack()));
    return flagX && flagY;
}

void Game::explosionCalculate(Explosion &explosion)
{
    if (isPlayerInExlosionRadius(explosion))
    {
        _player.hit(explosion.damage());

        if (!_player.isAlive())
        {
            _phase = GamePhase::DEFEAT_PHASE;
            return;
        }
    }

    for (size_t i = 0; i < _enemies.size(); ++i)
    {
        if (isEnemyInExplosionRadius(explosion, _enemies.at(i)))
        {
            _enemies.at(i)->hit(explosion.damage());

            if (!_enemies.at(i)->isAlive())
            {
                _items.push_back(_enemies.at(i)->deathRattle());
                _enemies.erase(_enemies.begin() + i);
            }
        }
    }

    for (size_t i = (explosion.center().x() - explosion.radius()); i <= (explosion.center().x() + explosion.radius()); ++i)
    {
        for (size_t j = (explosion.center().y() - explosion.radius()); j <= (explosion.center().x() + explosion.radius()); ++j)
        {
            if (_maze.cell(i, j).isCracked())
            {
                _maze.cell(i, j).createPassage();
            }
        }
    }
}

void Game::explosionDraw(Explosion &explosion)
{
    glColor3f(1.f, 0.f, 0.f);

    float width = _maze.width();
    float height = _maze.height();

    float side = 1.f;

    float left = 0.f;
    float top = 0.f;

    for (size_t i = (explosion.center().x() - explosion.radius()); i < (explosion.center().x() + explosion.radius()); ++i)
    {
        for (size_t j = (explosion.center().y() - explosion.radius()); j < (explosion.center().y() + explosion.radius()); ++j)
        {
            left = static_cast<float>(i) / (width / 2) - 1.f;
            top = -static_cast<float>(j) / (height / 2) + 1.f;

            glBegin(GL_QUADS);
            glVertex2f(left, top);
            glVertex2f(left, top - side / (height / 2));
            glVertex2f(left + side / (width / 2), top - side / (height / 2));
            glVertex2f(left + side / (width / 2), top);
            glEnd();

            left = 0.f;
            top = 0.f;
        }
    }
}

bool Game::isPlayerInExlosionRadius(Explosion &explosion)
{
    bool flagX = (_player.currentPosition().x() <= (explosion.center().x() + explosion.radius())) && (_player.currentPosition().x() >= (explosion.center().x() - explosion.radius()));
    bool flagY = (_player.currentPosition().y() <= (explosion.center().y() + explosion.radius())) && (_player.currentPosition().y() >= (explosion.center().y() - explosion.radius()));
    return flagX && flagY;
}

bool Game::isEnemyInExplosionRadius(Explosion &explosion, std::shared_ptr<Enemy> &enemy)
{
    bool flagX = (enemy->currentPosition().x() <= (explosion.center().x() + explosion.radius())) && (enemy->currentPosition().x() >= (explosion.center().x() - explosion.radius()));
    bool flagY = (enemy->currentPosition().y() <= (explosion.center().y() + explosion.radius())) && (enemy->currentPosition().y() >= (explosion.center().y() - explosion.radius()));
    return flagX && flagY;
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

    case 'e':
        attack();
        nextTurn();
        break;

    case '1':
        _atcivatingItems.push_back(_player.useItem(0));
        nextTurn();
        break;

    case '2':
        _atcivatingItems.push_back(_player.useItem(1));
        nextTurn();
        break;

    case '3':
        _atcivatingItems.push_back(_player.useItem(2));
        nextTurn();
        break;

    case '4':
        _atcivatingItems.push_back(_player.useItem(3));
        nextTurn();
        break;

    case '5':
        _atcivatingItems.push_back(_player.useItem(4));
        nextTurn();
        break;

    case '6':
        _atcivatingItems.push_back(_player.useItem(5));
        nextTurn();
        break;

    case '7':
        _atcivatingItems.push_back(_player.useItem(6));
        nextTurn();
        break;

    case '8':
        _atcivatingItems.push_back(_player.useItem(7));
        nextTurn();
        break;

    case '9':
        _atcivatingItems.push_back(_player.useItem(8));
        nextTurn();
        break;

    case '0':
        _atcivatingItems.push_back(_player.useItem(9));
        nextTurn();
        break;

    default:
        break;
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

    for (auto &&activatingItem : _atcivatingItems)
    {
        if (isActivatingItemInRadiusOfView(activatingItem))
        {
            activatingItem->draw();
        }
    }

    if (isExitInRadiusOfView())
    {
        _exit.draw();
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
