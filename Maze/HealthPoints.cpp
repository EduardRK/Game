#include "HealthPoints.hpp"

HealthPoints::HealthPoints(int maxHealthPoints, int currentHealthPoints) : _maxHealthPoints{maxHealthPoints}, _healthPoints{currentHealthPoints}
{
}

HealthPoints::HealthPoints(int healPoints) : HealthPoints(healPoints, healPoints)
{
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

int HealthPoints::currentHealth()
{
    return _healthPoints;
}
