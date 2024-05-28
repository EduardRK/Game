#include <GL/glut.h>

#include "GreenGrassItem.hpp"

GreenGrassItem::GreenGrassItem(Player &player, const Maze &maze, Point currentPosition) : _player{player}, _maze{maze}, _currentPosition{currentPosition}
{
}

void GreenGrassItem::draw()
{
    glColor3f(154.f / 255.f, 205.f / 255.f, 50.f / 255.f);

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

void GreenGrassItem::useItem()
{
}

const Point &GreenGrassItem::currentPosition()
{
    return _currentPosition;
}
