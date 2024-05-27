#include "GL/glut.h"
#include <memory>

#include "GhostEnemy.hpp"
#include "Selector.hpp"
#include "ItemSelector.hpp"

GhostEnemy::GhostEnemy(const Maze &maze, const Player &player, const std::vector<Point> &route, int startPosition) : _maze{maze}, _player{player}, _route{route}, _currentPosition{startPosition}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}
{
}

GhostEnemy::GhostEnemy(const Maze &maze, const Player &player, const std::vector<Point> &route) : GhostEnemy(maze, player, route, 0)
{
}

void GhostEnemy::draw()
{
    glColor3f(0.8f, 0.8f, 0.f);

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

void GhostEnemy::hit(Damage &damage)
{
    _healthPoints.decreaseHealth(damage);
}

Damage &GhostEnemy::deal()
{
    return _damage;
}

bool GhostEnemy::isAlive()
{
    return _healthPoints.isAlive();
}

std::shared_ptr<Item> GhostEnemy::deathRattle()
{
    std::unique_ptr<Selector<Item>> selector = std::make_unique<ItemSelector>();
    return selector->randomSelect();
}
