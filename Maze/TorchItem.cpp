#include <GL/glut.h>

#include "TorchItem.hpp"
#include "TorchBuff.hpp"

TorchItem::TorchItem(Player &player, const Maze &maze, Point currentPosition) : _player{player}, _maze{maze}, _currentPosition{currentPosition}
{
}

void TorchItem::draw()
{
    glColor3f(1.f, 144.f / 255.f, 0.f);

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

void TorchItem::useItem()
{
    _player.buff(std::make_shared<TorchBuff>(_player));
}

const Point &TorchItem::currentPosition()
{
    return _currentPosition;
}
