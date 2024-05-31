#pragma once

#include "Stats.hpp"

class Damage final
{
private:
    int _damageValue;
    float _critChance;
    int _critMultiplier;

    int _cachedDamageValue;
    bool _damageCalculated = false;

public:
    Damage(int damageValue, float critChance, int critMultiplier);
    Damage(int damageValue);
    Damage(const Stats &stats);
    Damage();
    ~Damage() = default;

    int damage();
};