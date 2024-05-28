#include "Stats.hpp"

Stats::Stats(int defaultDamage, int defaultCritMultiplier, float defaultCritChance, int defaultRadiusView) : _defaultDamage{defaultDamage}, _defaultCritMultiplier{defaultCritMultiplier}, _defaultCritChance{defaultCritChance}, _defaultRadiusView{defaultRadiusView}
{
}

int Stats::defaultDamage() const
{
    return _defaultDamage;
}

int Stats::defaultDamage()
{
    return _defaultDamage;
}

int Stats::defaultCritMultiplier() const
{
    return _defaultCritMultiplier;
}

int Stats::defaultCritMultiplier()
{
    return _defaultCritMultiplier;
}

float Stats::defaultCritChance() const
{
    return _defaultCritChance;
}

float Stats::defaultCritChance()
{
    return _defaultCritChance;
}

int Stats::defaultRadiusView() const
{
    return _defaultRadiusView;
}

int Stats::defaultRadiusView()
{
    return _defaultRadiusView;
}

int Stats::bonusDamage() const
{
    return _bonusDamage;
}

int Stats::bonusDamage()
{
    return _bonusDamage;
}

int Stats::bonusCritMultiplier() const
{
    return _bonusCritMultiplier;
}

int Stats::bonusCreitultiplier()
{
    return _bonusCritMultiplier;
}

float Stats::bonusCritChance() const
{
    return _bonusCritChance;
}

float Stats::bonusCritChance()
{
    return _bonusCritChance;
}

int Stats::bonusRadiusView() const
{
    return _bonusRadiusView;
}

int Stats::bonusRadiusView()
{
    return _bonusRadiusView;
}

int Stats::damage() const
{
    return (_defaultDamage + _bonusDamage < 0) ? 0 : (_defaultDamage + _bonusDamage);
}

int Stats::damage()
{
    return (_defaultDamage + _bonusDamage < 0) ? 0 : (_defaultDamage + _bonusDamage);
}

int Stats::critMultiplier() const
{
    return (_defaultCritMultiplier + _bonusCritMultiplier < 1) ? 1 : (_defaultCritMultiplier + _bonusCritMultiplier);
}

int Stats::critMultiplier()
{
    return (_defaultCritMultiplier + _bonusCritMultiplier < 1) ? 1 : (_defaultCritMultiplier + _bonusCritMultiplier);
}

float Stats::critChance() const
{
    return (_defaultCritChance + _bonusCritChance > 1) ? 1 : (_defaultCritChance + _bonusCritChance);
}

float Stats::critChance()
{
    return (_defaultCritChance + _bonusCritChance > 1) ? 1 : (_defaultCritChance + _bonusCritChance);
}

int Stats::radiusView() const
{
    return (_defaultRadiusView + _bonusRadiusView < 0) ? 0 : (_defaultRadiusView + _bonusRadiusView);
}

int Stats::radiusView()
{
    return (_defaultRadiusView + _bonusRadiusView < 0) ? 0 : (_defaultRadiusView + _bonusRadiusView);
}

void Stats::addBonusDamage(int bonusDamage)
{
    _bonusDamage += bonusDamage;
}

void Stats::addBonusCritMultiplier(int bonusCritMultiplier)
{
    _bonusCritMultiplier += bonusCritMultiplier;
}

void Stats::addBonusCritChance(float bonusCritChance)
{
    _bonusCritChance += bonusCritChance;
}

void Stats::addBonusRadiusView(int bonusRadiusView)
{
    _bonusRadiusView += bonusRadiusView;
}
