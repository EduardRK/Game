#pragma once

class Stats final
{
private:
    int _defaultDamage;
    int _defaultCritMultiplier;
    float _defaultCritChance;
    int _defaultRadiusView;
    int _defaultRadiusAttack;

    int _bonusDamage = 0;
    int _bonusCritMultiplier = 0;
    float _bonusCritChance = 0.f;
    int _bonusRadiusView = 0;
    int _bonusRadiusAttack = 0;

public:
    Stats(int defaultDamage, int defaultCritMultiplier, float defaultCritChance, int defaultRadiusView, int defaultRadiusAttack);
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
    int defaultRadiusAttack() const;
    int defaultRadiusAttack();

    int bonusDamage() const;
    int bonusDamage();
    int bonusCritMultiplier() const;
    int bonusCreitultiplier();
    float bonusCritChance() const;
    float bonusCritChance();
    int bonusRadiusView() const;
    int bonusRadiusView();
    int bonusRadiusAttack() const;
    int bonusRadiusAttack();

    int damage() const;
    int damage();
    int critMultiplier() const;
    int critMultiplier();
    float critChance() const;
    float critChance();
    int radiusView() const;
    int radiusView();
    int radiusAttack() const;
    int radiusAttack();

    void addBonusDamage(int bonusDamage);
    void addBonusCritMultiplier(int bonusCritMultiplier);
    void addBonusCritChance(float bonusCritChance);
    void addBonusRadiusView(int bonusRadiusView);
    void addBonusRadiusAttack(int bonusRadiusAttack);

    void removeBonusDamage(int bonusDamage);
    void removeBonusCritMultiplier(int bonusCritMultiplier);
    void removeBonusCritChance(float bonusCritChance);
    void removeBonusRadiusView(int bonusRadiusView);
    void removeBonusRadiusAttack(int bonusRadiusAttack);
};