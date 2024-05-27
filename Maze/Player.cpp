#include <GL/glut.h>
#include <iostream>

#include "Player.hpp"
#include "Point.hpp"
#include "Maze.hpp"

Player::Player(const Point &startPosition, const Maze &maze) : _currentPosition{startPosition}, _maze{maze}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}, _backpack{Backpack()}
{
}

Player::Player(Point startPosition, const Maze &maze) : _currentPosition{startPosition}, _maze{maze}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}, _backpack{Backpack()}
{
}

Player::Player(int x, int y, const Maze &maze) : _currentPosition{Point(x, y)}, _maze{maze}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _damage{Damage(DEFAULT_DAMAGE, DEFAULT_CRIT_CHANCE, DEFAULT_CRIT_MULTIPLIER)}, _backpack{Backpack()}
{
}

void Player::moveUp()
{
    if (!(_currentPosition.y() - 1 < 0 || _maze.cell(_currentPosition.x(), _currentPosition.y() - 1).isWall() || _maze.cell(_currentPosition.x(), _currentPosition.y() - 1).isCracked()))
    {
        _currentPosition = Point(_currentPosition.x(), _currentPosition.y() - 1);
    }
}

void Player::moveDown()
{
    if (!(_currentPosition.y() + 1 > _maze.height() - 1 || _maze.cell(_currentPosition.x(), _currentPosition.y() + 1).isWall() || _maze.cell(_currentPosition.x(), _currentPosition.y() + 1).isCracked()))
    {
        _currentPosition = Point(_currentPosition.x(), _currentPosition.y() + 1);
    }
}

void Player::moveLeft()
{
    if (!(_currentPosition.x() - 1 < 0 || _maze.cell(_currentPosition.x() - 1, _currentPosition.y()).isWall() || _maze.cell(_currentPosition.x() - 1, _currentPosition.y()).isCracked()))
    {
        _currentPosition = Point(_currentPosition.x() - 1, _currentPosition.y());
    }
}

void Player::moveRight()
{
    if (!(_currentPosition.x() + 1 > _maze.width() - 1 || _maze.cell(_currentPosition.x() + 1, _currentPosition.y()).isWall() || _maze.cell(_currentPosition.x() + 1, _currentPosition.y()).isCracked()))
    {
        _currentPosition = Point(_currentPosition.x() + 1, _currentPosition.y());
    }
}

int Player::radiusView() const
{
    return _radiusView;
}

int Player::radiusView()
{
    return _radiusView;
}

void Player::newRadiusView(unsigned int newRadiusView)
{
    _radiusView = newRadiusView;
}

Point Player::currentPosition()
{
    return _currentPosition;
}

const Point Player::currentPosition() const
{
    return _currentPosition;
}

void Player::draw()
{
    glColor3f(0.8f, 0.f, 0.f);

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

void Player::nextTurn()
{
    std::cout << _healthPoints.currentHealth() << std::endl;
}

void Player::hit(Damage &damage)
{
    _healthPoints.decreaseHealth(damage);
}

void Player::heal(Heal &heal)
{
    _healthPoints.increaseHealth(heal);
}

Damage &Player::deal()
{
    return _damage;
}

bool Player::isAlive()
{
    return _healthPoints.isAlive();
}
