#include "GL/glut.h"
#include <memory>

#include "GhostEnemy.hpp"
#include "Selector.hpp"
#include "ItemSelector.hpp"

GhostEnemy::GhostEnemy(const Maze &maze, Player &player, const std::vector<Point> &route, int startPosition) : _maze{maze}, _player{player}, _route{route}, _currentPosition{startPosition}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}
{
}

GhostEnemy::GhostEnemy(const Maze &maze, Player &player, const std::vector<Point> &route) : GhostEnemy(maze, player, route, 0)
{
}

void GhostEnemy::draw()
{
    glColor3f(105.f / 255.f, 105.f / 255.f, 105.f / 255.f);

    float width = _maze.width();
    float height = _maze.height();

    float left = static_cast<float>(_route.at(_currentPosition).x()) / (width / 2) - 1.f;
    float top = -static_cast<float>(_route.at(_currentPosition).y()) / (height / 2) + 1.f;

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top);
    glEnd();
}

void GhostEnemy::nextTurn()
{
    if (_skipTurn)
    {
        _route.at(_currentPosition) = _previusPosition;
        _skipTurn = false;
        return;
    }

    if (playerInRadiusOfView())
    {
        _previusPosition = _route.at(_currentPosition);
        _route.at(_currentPosition) = _player.currentPosition();
        _skipTurn = true;
        return;
    }

    if (_goAhead)
    {
        if (_currentPosition + 1 >= _route.size())
        {
            _goAhead = false;
            --_currentPosition;
        }
        else
        {
            ++_currentPosition;
        }
    }
    else
    {
        if (_currentPosition - 1 < 0)
        {
            _goAhead = true;
            ++_currentPosition;
        }
        else
        {
            --_currentPosition;
        }
    }
}

Point &GhostEnemy::currentPosition()
{
    return _route.at(_currentPosition);
}

void GhostEnemy::hit(Damage damage)
{
    _healthPoints.decreaseHealth(damage);
}

Damage GhostEnemy::deal()
{
    return _damage;
}

bool GhostEnemy::isAlive()
{
    return _healthPoints.isAlive();
}

std::shared_ptr<Item> GhostEnemy::deathRattle()
{
    std::unique_ptr<Selector<Item>> selector = std::make_unique<ItemSelector>(_player, _maze);
    return selector->randomSelect(_route.at(_currentPosition));
}

bool GhostEnemy::playerInRadiusOfView()
{
    bool flagX = _player.currentPosition().x() >= (_route.at(_currentPosition).x() - _radiusView) && _player.currentPosition().x() <= (_route.at(_currentPosition).x() + _radiusView);
    bool flagY = _player.currentPosition().y() >= (_route.at(_currentPosition).y() - _radiusView) && _player.currentPosition().y() <= (_route.at(_currentPosition).y() + _radiusView);
    return flagX && flagY;
}
