#include <cmath>

#include "Damage.hpp"
#include "RandomFunctions.hpp"

Damage::Damage(int damageValue, float critChance, int critMultiplier) : _damageValue{damageValue}, _critChance{critChance > 1.f ? 1.f : critChance}, _critMultiplier{critMultiplier}
{
}

Damage::Damage(int damageValue) : Damage(damageValue, 0.1f, 2)
{
}

Damage::Damage() : Damage(0, 0.f, 0)
{
}

int Damage::damage()
{
    if (_damageCalculated)
    {
        return _cachedDamageValue;
    }
    else
    {
        float randomFloat = nextRandomFloat(1.f);
        float intPart = 0;
        float fracPart = std::modf(randomFloat, &intPart);

        _cachedDamageValue = (_critChance < fracPart) ? _damageValue : (_damageValue * _critMultiplier);
        _damageCalculated = true;

        return _cachedDamageValue;
    }
}
