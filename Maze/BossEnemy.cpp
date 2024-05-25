#include <GL/glut.h>

#include "BossEnemy.hpp"
#include "DfsMazeSolver.hpp"

BossEnemy::BossEnemy(const Player &player, const Maze &maze, Point startPosition) : _player{player}, _maze{maze}, _currentPosition{startPosition}, _mazeSolver{std::make_unique<DfsMazeSolver>(maze)}
{
}

void BossEnemy::draw()
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

void BossEnemy::nextTurn()
{
}
