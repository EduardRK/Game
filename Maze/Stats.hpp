#pragma once

class Stats final
{
private:
    int _defaultDamage;
    int _defaultCritMultiplier;
    float _defaultCritChance;
    int _defaultRadiusView;

    int _bonusDamage = 0;
    int _bonusCritMultiplier = 0;
    float _bonusCritChance = 0.f;
    int _bonusRadiusView = 0;

public:
    Stats(int defaultDamage, int defaultCritMultiplier, float defaultCritChance, int defaultRadiusView);
    ~Stats() = default;

    int defaultDamage() const;
    int defaultDamage();
    int defaultCritMultiplier() const;
    int defaultCritMultiplier();
    float defaultCritChance() const;
    float defaultCritChance();
    int defaultRadiusView() const;
    int defaultRadiusView();

    int bonusDamage() const;
    int bonusDamage();
    int bonusCritMultiplier() const;
    int bonusCreitultiplier();
    float bonusCritChance() const;
    float bonusCritChance();
    int bonusRadiusView() const;
    int bonusRadiusView();

    int damage() const;
    int damage();
    int critMultiplier() const;
    int critMultiplier();
    float critChance() const;
    float critChance();
    int radiusView() const;
    int radiusView();

    void addBonusDamage(int bonusDamage);
    void addBonusCritMultiplier(int bonusCritMultiplier);
    void addBonusCritChance(float bonusCritChance);
    void addBonusRadiusView(int bonusRadiusView);
};