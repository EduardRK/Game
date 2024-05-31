#include <GL/glut.h>

#include "Exit.hpp"

Exit::Exit(Point position, const Maze &maze) : _position{position}, _maze{maze}
{
}

Exit::Exit(const Maze &maze) : Exit(Point(maze.height() - 2, maze.width() - 2), maze)
{
}

Exit::~Exit()
{
}

Point Exit::posisiton()
{
    return _position;
}

const Point &Exit::position() const
{
    return _position;
}

void Exit::draw()
{
    glColor3f(83.f / 55.f, 112.f / 255.f, 122.f / 255.f);

    float width = _maze.width();
    float height = _maze.height();

    float left = static_cast<float>(_position.x()) / (width / 2) - 1.f;
    float top = -static_cast<float>(_position.y()) / (height / 2) + 1.f;

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top - SIDE / (height / 2));
    glVertex2f(left + SIDE / (width / 2), top);
    glEnd();
}
