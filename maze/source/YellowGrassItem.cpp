#include <GL/glut.h>

#include "YellowGrassItem.hpp"
#include "EmptyActivatingItem.hpp"

YellowGrassItem::YellowGrassItem(Player &player, const Maze &maze, Point currentPosition) : _player{player}, _maze{maze}, _currentPosition{currentPosition}, _heal{Heal(DEFAULT_HEAL)}
{
}

void YellowGrassItem::draw()
{
    glColor3f(1.f, 215.f / 255.f, 0.f);

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

void YellowGrassItem::backpackDraw(float left, float top, float side)
{
    glColor3f(1.f, 215.f / 255.f, 0.f);

    float width = _maze.width();
    float height = _maze.height();

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - side);
    glVertex2f(left + side, top - side);
    glVertex2f(left + side, top);
    glEnd();
}

std::shared_ptr<ActivatingItem<Explosion>> YellowGrassItem::getActivatingItem()
{
    return std::make_shared<EmptyActivatingItem>();
}

void YellowGrassItem::useItem()
{
    _player.increaseMaxHealth(DEFAULT_MAX_HEALTH_INCREASE);
    _player.heal(_heal);
}

Point YellowGrassItem::currentPosition()
{
    return _currentPosition;
}
