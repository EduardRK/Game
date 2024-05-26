#include <cmath>

#include "Heal.hpp"
#include "RandomFunctions.hpp"

Heal::Heal(int healValue, float critChance, int critMultiplier) : _healValue{healValue}, _critChance{critChance > 1.f ? 1.f : critChance}, _critMultiplier{critMultiplier}
{
}

Heal::Heal(int healValue) : Heal(healValue, 0.1f, 2)
{
}

int Heal::heal()
{
    if (_healCalculated)
    {
        return _cachedHealValue;
    }
    else
    {
        float randomFloat = nextRandomFloat(1.f);
        float intPart = 0;
        float fracPart = std::modf(randomFloat, &intPart);

        _cachedHealValue = (_critChance < fracPart) ? _healValue : (_healValue * _critMultiplier);
        _healCalculated = true;

        return _cachedHealValue;
    }
}
