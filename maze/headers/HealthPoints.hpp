#pragma once

#include "Damage.hpp"
#include "Heal.hpp"
#include "Drawable.hpp"

class HealthPoints final : public Drawable
{
private:
    static constexpr float SIDE = 0.03f;
    static constexpr float GAP = 0.015f;
    static constexpr float LINE_WIDTH = 2.2f;

    static constexpr int HELATH_POINTS_IN_ONE_LINE = 10;

    int _maxHealthPoints;
    int _healthPoints;

    int _healthPointsInLine = 0;

public:
    HealthPoints(int maxHealthPoints, int currentHealthPoints);
    HealthPoints(int healPoints);
    ~HealthPoints() = default;

    bool isAlive() const;
    bool isAlive();

    void decreaseHealth(Damage &damage);
    void increaseHealth(Heal &heal);

    void decreaseMaxHealth(int decreaseMaxHealth);
    void increaseMaxHealth(int increaseMaxHealth);

    int currentHealth() const;
    int currentHealth();

    int maxHealthPoints() const;
    int maxHealthPoints();

    void draw() override;
};