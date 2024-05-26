#include <GL/glut.h>
#include <vector>

#include "TrollEnemy.hpp"
#include "DfsMazeSolver.hpp"

TrollEnemy::TrollEnemy(const Maze &maze, Point &currentPosition, const Player &player) : _maze{maze}, _currentPosition{currentPosition}, _player{player}, _mazeSolver{std::make_unique<DfsMazeSolver>(maze)}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}
{
}

void TrollEnemy::draw()
{
    glColor3f(0.f, 0.8f, 0.f);

    float width = _maze.width();
    float height = _maze.height();

    float left = static_cast<float>(_currentPosition.x()) / (width / 2) - 1.f;
    float top = -static_cast<float>(_currentPosition.y()) / (height / 2) + 1.f;

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top);
    glEnd();
}

void TrollEnemy::nextTurn()
{
    if (_chase)
    {
        if (playerInRadiusOfView() && _turnCounter < _route.size())
        {
            _currentPosition = _route.at(_turnCounter);
            ++_turnCounter;
        }
        else
        {
            _chase = false;
            _turnCounter = 0;
        }
    }

    else if (playerInRadiusOfView())
    {
        if (_currentPosition != _player.currentPosition())
        {
            _route = _mazeSolver->solveMaze(_currentPosition, _player.currentPosition());
            _turnCounter = 0;

            if (_player.currentPosition() != _currentPosition)
            {
                _turnCounter = 1;
            }

            _currentPosition = _route.at(_turnCounter);
            ++_turnCounter;
            _chase = true;
        }
    }
}

Point &TrollEnemy::currentPosition()
{
    return _currentPosition;
}

void TrollEnemy::hit(Damage &damage)
{
    _healthPoints.decreaseHealth(damage);
}

Damage &TrollEnemy::deal()
{
    return _damage;
}

bool TrollEnemy::isAlive()
{
    return _healthPoints.isAlive();
}

bool TrollEnemy::playerInRadiusOfView()
{
    bool flagX = _player.currentPosition().x() >= (_currentPosition.x() - _radiusView) && _player.currentPosition().x() <= (_currentPosition.x() + _radiusView);
    bool flagY = _player.currentPosition().y() >= (_currentPosition.y() - _radiusView) && _player.currentPosition().y() <= (_currentPosition.y() + _radiusView);
    return flagX && flagY;
}
