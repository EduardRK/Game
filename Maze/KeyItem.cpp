#include <GL/glut.h>

#include "KeyItem.hpp"
#include "EmptyActivatingItem.hpp"

KeyItem::KeyItem(Player &player, const Maze &maze, Point currentPosition) : _player{player}, _maze{maze}, _currentPosition{currentPosition}
{
}

void KeyItem::draw()
{
    glColor3f(0.8f, 0.8f, 0.8f);

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

std::shared_ptr<ActivatingItem<Explosion>> KeyItem::getActivatingItem()
{
    return std::make_shared<EmptyActivatingItem>();
}

void KeyItem::useItem()
{
    _player.statuses().addKeyStatus();
}

Point KeyItem::currentPosition()
{
    return _currentPosition;
}
