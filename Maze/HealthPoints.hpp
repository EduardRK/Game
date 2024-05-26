#pragma once

#include "Damage.hpp"
#include "Heal.hpp"

class HealthPoints final
{
private:
    int _maxHealthPoints;
    int _healthPoints;

public:
    HealthPoints(int maxHealthPoints, int currentHealthPoints);
    HealthPoints(int healPoints);
    ~HealthPoints() = default;

    bool isAlive();
    void decreaseHealth(Damage &damage);
    void increaseHealth(Heal &heal);
    void decreaseMaxHealth(int decreaseMaxHealth);
    void increaseMaxHealth(int increaseMaxHealth);
    int currentHealth();
};