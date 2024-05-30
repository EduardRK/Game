#include <GL/glut.h>

#include "BombActivatingItem.hpp"

BombActivatinItem::BombActivatinItem(Point currentPosition, Player &player, const Maze &maze) : _currentPosition{currentPosition}, _player{player}, _maze{maze}
{
}

void BombActivatinItem::draw()
{
    switch (_phase)
    {
    case 1:
        drawDefaultPhase();
        break;
    case 2:
        drawActivePhase();
        break;
    case 3:
        drawPreExplosionPhase();
        break;
    default:
        break;
    }
}

void BombActivatinItem::nextTurn()
{
    if (_active)
    {
        ++_phase;
    }
}

void BombActivatinItem::activate()
{
    if (!_active && _player.statuses().fireStatus())
    {
        _active = true;
        ++_phase;
    }
}

bool BombActivatinItem::complete()
{
    return _phase == 4;
}

Point BombActivatinItem::currentPosition()
{
    return _currentPosition;
}

void BombActivatinItem::drawDefaultPhase()
{
    glColor3f(192.f / 255.f, 192.f / 255.f, 192.f / 255.f);
}

void BombActivatinItem::drawActivePhase()
{
    glColor3f(205.f / 255.f, 92.f / 255.f, 13.f / 255.f);
}

void BombActivatinItem::drawPreExplosionPhase()
{
    glColor3f(178.f / 255.f, 34.f / 255.f, 34.f / 255.f);
}

void BombActivatinItem::drawBomb()
{
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
