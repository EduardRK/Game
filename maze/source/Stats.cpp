#include "Stats.hpp"

Stats::Stats(int defaultDamage, int defaultCritMultiplier, float defaultCritChance, int defaultRadiusView, int defaultRadiusAttack) : _defaultDamage{defaultDamage}, _defaultCritMultiplier{defaultCritMultiplier}, _defaultCritChance{defaultCritChance}, _defaultRadiusView{defaultRadiusView}, _defaultRadiusAttack{defaultRadiusAttack}
{
}

Stats::Stats(int defaultDamage, int defaultCritMultiplier, float defaultCritChance, int defaultRadiusView) : Stats(defaultDamage, defaultCritMultiplier, defaultCritChance, defaultRadiusView, 0)
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

int Stats::defaultRadiusAttack() const
{
    return _defaultRadiusAttack;
}

int Stats::defaultRadiusAttack()
{
    return _defaultRadiusAttack;
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

int Stats::bonusRadiusAttack() const
{
    return _bonusRadiusAttack;
}

int Stats::bonusRadiusAttack()
{
    return _bonusRadiusAttack;
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

int Stats::radiusAttack() const
{
    return (_defaultRadiusAttack + _bonusRadiusAttack < 0) ? 0 : (_defaultRadiusAttack + _bonusRadiusAttack);
}

int Stats::radiusAttack()
{
    return (_defaultRadiusAttack + _bonusRadiusAttack < 0) ? 0 : (_defaultRadiusAttack + _bonusRadiusAttack);
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

void Stats::addBonusRadiusAttack(int bonusRadiusAttack)
{
    _bonusRadiusAttack += bonusRadiusAttack;
}

void Stats::removeBonusDamage(int bonusDamage)
{
    _bonusDamage -= bonusDamage;
}

void Stats::removeBonusCritMultiplier(int bonusCritMultiplier)
{
    _bonusCritMultiplier -= bonusCritMultiplier;
}

void Stats::removeBonusCritChance(float bonusCritChance)
{
    _bonusCritChance -= bonusCritChance;
}

void Stats::removeBonusRadiusView(int bonusRadiusView)
{
    _bonusRadiusView -= bonusRadiusView;
}

void Stats::removeBonusRadiusAttack(int bonusRadiusAttack)
{
    _bonusRadiusAttack -= bonusRadiusAttack;
}

Stats &Stats::operator=(const Stats &other)
{
    if (this != &other)
    {
        _defaultDamage = other.defaultDamage();
        _defaultCritMultiplier = other.defaultCritMultiplier();
        _defaultCritChance = other.defaultCritChance();
        _defaultRadiusView = other.defaultRadiusView();
        _defaultRadiusAttack = other.defaultRadiusAttack();

        _bonusDamage = other.bonusDamage();
        _bonusCritMultiplier = other.bonusCritMultiplier();
        _bonusCritChance = other.bonusCritChance();
        _bonusRadiusView = other.bonusRadiusView();
        _bonusRadiusAttack = other.bonusRadiusAttack();
    }

    return *this;
}

bool Stats::operator==(const Stats &other) const
{
    if (this == &other)
    {
        return true;
    }

    return _defaultDamage == other.defaultDamage() &&
           _defaultCritMultiplier == other.defaultCritMultiplier() &&
           _defaultCritChance == other.defaultCritChance() &&
           _defaultRadiusView == other.defaultRadiusView() &&
           _defaultRadiusAttack == other.defaultRadiusAttack() &&
           _bonusDamage == other.bonusDamage() &&
           _bonusCritMultiplier == other.bonusCritMultiplier() &&
           _bonusCritChance == other.bonusCritChance() &&
           _bonusRadiusView == other.bonusRadiusView() &&
           _bonusRadiusAttack == other.bonusRadiusAttack();
}

bool Stats::operator!=(const Stats &other) const
{
    if (this == &other)
    {
        return false;
    }

    return !(_defaultDamage == other.defaultDamage() &&
             _defaultCritMultiplier == other.defaultCritMultiplier() &&
             _defaultCritChance == other.defaultCritChance() &&
             _defaultRadiusView == other.defaultRadiusView() &&
             _defaultRadiusAttack == other.defaultRadiusAttack() &&
             _bonusDamage == other.bonusDamage() &&
             _bonusCritMultiplier == other.bonusCritMultiplier() &&
             _bonusCritChance == other.bonusCritChance() &&
             _bonusRadiusView == other.bonusRadiusView() &&
             _bonusRadiusAttack == other.bonusRadiusAttack());
}