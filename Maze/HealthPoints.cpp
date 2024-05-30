#include <GL/glut.h>

#include "HealthPoints.hpp"

HealthPoints::HealthPoints(int maxHealthPoints, int currentHealthPoints) : _maxHealthPoints{maxHealthPoints}, _healthPoints{currentHealthPoints}
{
}

HealthPoints::HealthPoints(int healPoints) : HealthPoints(healPoints, healPoints)
{
}

bool HealthPoints::isAlive() const
{
    return _healthPoints > 0;
}

bool HealthPoints::isAlive()
{
    return _healthPoints > 0;
}

void HealthPoints::decreaseHealth(Damage &damage)
{
    _healthPoints -= damage.damage();
}

void HealthPoints::increaseHealth(Heal &heal)
{
    _healthPoints = (_healthPoints + heal.heal() > _maxHealthPoints) ? _maxHealthPoints : (_healthPoints + heal.heal());
}

void HealthPoints::decreaseMaxHealth(int decreaseMaxHealth)
{
    _maxHealthPoints = (_maxHealthPoints - decreaseMaxHealth <= 0) ? 1 : (_maxHealthPoints - decreaseMaxHealth);
}

void HealthPoints::increaseMaxHealth(int increaseMaxHealth)
{
    _maxHealthPoints += increaseMaxHealth;
}

int HealthPoints::currentHealth() const
{
    return _healthPoints;
}

int HealthPoints::currentHealth()
{
    return _healthPoints;
}

int HealthPoints::maxHealthPoints() const
{
    return _maxHealthPoints;
}

int HealthPoints::maxHealthPoints()
{
    return _maxHealthPoints;
}

void HealthPoints::draw()
{
    float left = -1.f;
    float top = 1.f - GAP;

    glColor3f(0.9f, 0.f, 0.f);

    glLineWidth(LINE_WIDTH);

    for (size_t i = 0; i < _maxHealthPoints; ++i)
    {
        glBegin(GL_LINE_LOOP);
        glVertex2f(left, top);
        glVertex2f(left, top - SIDE);
        glVertex2f(left + SIDE, top - SIDE);
        glVertex2f(left + SIDE, top);
        glVertex2f(left, top);
        glEnd();

        left += (SIDE + GAP);
    }

    left = -1.f;

    for (size_t i = 0; i < _healthPoints; ++i)
    {
        glBegin(GL_QUADS);
        glVertex2f(left, top);
        glVertex2f(left, top - SIDE);
        glVertex2f(left + SIDE, top - SIDE);
        glVertex2f(left + SIDE, top);
        glEnd();

        left += (SIDE + GAP);
    }
}
