#pragma once

class Heal final
{
private:
    int _healValue;
    float _critChance;
    int _critMultiplier;

    int _cachedHealValue;
    bool _healCalculated = false;

public:
    Heal(int healValue, float critChance, int critMultiplier);
    Heal(int healValue);
    ~Heal() = default;

    int heal();
};