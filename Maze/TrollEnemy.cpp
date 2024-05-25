#include <GL/glut.h>
#include <vector>

#include "TrollEnemy.hpp"
#include "DfsMazeSolver.hpp"

TrollEnemy::TrollEnemy(const Maze &maze, Point &currentPosition, const Player &player) : _maze{maze}, _currentPosition{currentPosition}, _player{player}, _mazeSolver{std::make_unique<DfsMazeSolver>(maze)}
{
}

void TrollEnemy::draw()
{
    glColor3f(0.8f, 0.f, 0.8f);

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

void TrollEnemy::nextTurn()
{
    if (_chase)
    {
        if (_turnCounter < 5)
        {
            _currentPosition = _route.at(_turnCounter);
            ++_turnCounter;
        }
        else
        {
            _chase = false;
            _turnCounter = 0;
        }
    }

    else if (playerInRadiusOfView())
    {
        if (_currentPosition != _player.currentPosition())
        {
            _route = _mazeSolver->solveMaze(_currentPosition, _player.currentPosition());
            _currentPosition = _route.at(0);
            _chase = true;
            _turnCounter = 1;
        }
    }
}

Point &TrollEnemy::currentPosition()
{
    return _currentPosition;
}

bool TrollEnemy::playerInRadiusOfView()
{
    bool flagX = _player.currentPosition().x() >= (_currentPosition.x() - _radiusView) && _player.currentPosition().x() <= (_currentPosition.x() + _radiusView);
    bool flagY = _player.currentPosition().y() >= (_currentPosition.y() - _radiusView) && _player.currentPosition().y() <= (_currentPosition.y() + _radiusView);
    return flagX && flagY;
}
