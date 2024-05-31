#include <GL/glut.h>

#include "BombItem.hpp"
#include "BombActivatingItem.hpp"
#include "Explosion.hpp"

BombItem::BombItem(Player &player, const Maze &maze, Point currentPosition) : _player{player}, _maze{maze}, _currentPosition{currentPosition}
{
}

void BombItem::draw()
{
    glColor3f(170.f / 255.f, 170.f / 255.f, 170.f / 255.f);

    float width = _maze.width();
    float height = _maze.height();

    float left = static_cast<float>(_currentPosition.x()) / (width / 2) - 1.f;
    float top = -static_cast<float>(_currentPosition.y()) / (height / 2) + 1.f;

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - SIDE_ON_MAP / (height / 2));
    glVertex2f(left + SIDE_ON_MAP / (width / 2), top - SIDE_ON_MAP / (height / 2));
    glVertex2f(left + SIDE_ON_MAP / (width / 2), top);
    glEnd();
}

void BombItem::backpackDraw(float left, float top, float side)
{
    glColor3f(170.f / 255.f, 170.f / 255.f, 170.f / 255.f);

    float width = _maze.width();
    float height = _maze.height();

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - side);
    glVertex2f(left + side, top - side);
    glVertex2f(left + side, top);
    glEnd();
}

std::shared_ptr<ActivatingItem<Explosion>> BombItem::getActivatingItem()
{
    return std::make_shared<BombActivatingItem>(_player, _maze);
}

void BombItem::useItem()
{
}

Point BombItem::currentPosition()
{
    return _currentPosition;
}
