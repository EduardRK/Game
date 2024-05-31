#include <GL/glut.h>

#include "Player.hpp"
#include "Point.hpp"
#include "Maze.hpp"
#include <iostream>

Player::Player(Point startPosition, const Maze &maze, const Exit &exit) : _currentPosition{startPosition}, _maze{maze}, _exit{exit}, _healthPoints{HealthPoints(DEFAULT_MAX_HP)}, _stats{Stats(DEFAULT_DAMAGE, DEFAULT_CRIT_MULTIPLIER, DEFAULT_CRIT_CHANCE, DEFAULT_RADIUS_OF_VIEW, DEFAULT_RADIUS_OF_ATTACK)}, _backpack{Backpack()}, _statuses{Statuses()}
{
}

Player::Player(int x, int y, const Maze &maze, const Exit &exit) : Player(Point(x, y), maze, exit)
{
}

void Player::moveUp()
{
    if (!(_currentPosition.y() - 1 < 0 || _maze.cell(_currentPosition.x(), _currentPosition.y() - 1).isWall() || _maze.cell(_currentPosition.x(), _currentPosition.y() - 1).isCracked()))
    {
        Point nextPoint(_currentPosition.x(), _currentPosition.y() - 1);

        if (nextPoint == _exit.position())
        {
            _currentPosition = _statuses.keyStatus() ? nextPoint : _currentPosition;
        }
        else
        {
            _currentPosition = nextPoint;
        }
    }
}

void Player::moveDown()
{
    if (!(_currentPosition.y() + 1 > _maze.height() - 1 || _maze.cell(_currentPosition.x(), _currentPosition.y() + 1).isWall() || _maze.cell(_currentPosition.x(), _currentPosition.y() + 1).isCracked()))
    {
        Point nextPoint(_currentPosition.x(), _currentPosition.y() + 1);

        if (nextPoint == _exit.position())
        {
            _currentPosition = _statuses.keyStatus() ? nextPoint : _currentPosition;
        }
        else
        {
            _currentPosition = nextPoint;
        }
    }
}

void Player::moveLeft()
{
    if (!(_currentPosition.x() - 1 < 0 || _maze.cell(_currentPosition.x() - 1, _currentPosition.y()).isWall() || _maze.cell(_currentPosition.x() - 1, _currentPosition.y()).isCracked()))
    {
        Point nextPoint(_currentPosition.x() - 1, _currentPosition.y());

        if (nextPoint == _exit.position())
        {
            _currentPosition = _statuses.keyStatus() ? nextPoint : _currentPosition;
        }
        else
        {
            _currentPosition = nextPoint;
        }
    }
}

void Player::moveRight()
{
    if (!(_currentPosition.x() + 1 > _maze.width() - 1 || _maze.cell(_currentPosition.x() + 1, _currentPosition.y()).isWall() || _maze.cell(_currentPosition.x() + 1, _currentPosition.y()).isCracked()))
    {
        Point nextPoint(_currentPosition.x() + 1, _currentPosition.y());

        if (nextPoint == _exit.position())
        {
            _currentPosition = _statuses.keyStatus() ? nextPoint : _currentPosition;
        }
        else
        {
            _currentPosition = nextPoint;
        }
    }
}

int Player::radiusView() const
{
    return _stats.radiusView();
}

int Player::radiusView()
{
    return _stats.radiusView();
}

bool Player::peekItem(std::shared_ptr<Item> item)
{
    return _backpack.saveItem(item);
}

std::shared_ptr<ActivatingItem<Explosion>> Player::useItem(int index)
{
    std::shared_ptr<Item> item = _backpack.getItem(index);
    item->useItem();
    return item->getActivatingItem();
}

void Player::increaseMaxHealth(int bonusHealthPoints)
{
    _healthPoints.increaseMaxHealth(bonusHealthPoints);
}

void Player::decreaseMaxHealth(int bonusHealthPoints)
{
    _healthPoints.decreaseMaxHealth(bonusHealthPoints);
}

Point Player::currentPosition()
{
    return _currentPosition;
}

const Point &Player::currentPosition() const
{
    return _currentPosition;
}

Stats &Player::stats()
{
    return _stats;
}

const Stats &Player::stats() const
{
    return _stats;
}

Statuses &Player::statuses()
{
    return _statuses;
}

const Statuses &Player::statuses() const
{
    return _statuses;
}

void Player::draw()
{
    _healthPoints.draw();
    _backpack.draw();

    for (size_t i = 0; i < _buffs.size(); ++i)
    {
        _buffs.at(i)->draw(i, BUFF_SIDE);
    }

    glColor3f(0.7f, 0.f, 0.f);

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
    for (int i = 0; i < _buffs.size(); ++i)
    {
        _buffs.at(i)->nextTurn();

        if (_buffs.at(i)->complete())
        {
            _buffs.erase(_buffs.begin() + i);
        }
    }
}

void Player::hit(Damage damage)
{
    _healthPoints.decreaseHealth(damage);
}

void Player::heal(Heal heal)
{
    _healthPoints.increaseHealth(heal);
}

void Player::attack()
{
    for (int i = 0; i < _buffs.size(); ++i)
    {
        _buffs.at(i)->attack();

        if (_buffs.at(i)->complete())
        {
            _buffs.erase(_buffs.begin() + i);
        }
    }
}

void Player::buff(std::shared_ptr<Buff> buff)
{
    _buffs.push_back(buff);
}

Damage Player::deal()
{
    return Damage(_stats);
}

bool Player::isAlive()
{
    return _healthPoints.isAlive();
}
