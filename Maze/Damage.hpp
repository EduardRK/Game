#pragma once

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
    ~Damage() = default;

    int damage();
};