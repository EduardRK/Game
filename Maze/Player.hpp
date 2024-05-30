#pragma once

#include <vector>
#include <memory>

#include "Point.hpp"
#include "Maze.hpp"
#include "Drawable.hpp"
#include "Turnable.hpp"
#include "HealthPoints.hpp"
#include "Damage.hpp"
#include "Heal.hpp"
#include "Hitable.hpp"
#include "Healable.hpp"
#include "Living.hpp"
#include "Dealer.hpp"
#include "Backpack.hpp"
#include "Moveable.hpp"
#include "Stats.hpp"
#include "Statuses.hpp"
#include "Attacker.hpp"
#include "Buff.hpp"
#include "Buffable.hpp"
#include "ActivatingItem.hpp"
#include "Explosion.hpp"

class Player final : public Drawable, public Turnable, public Hitable, public Healable, public Dealer<Damage>, public Living, public Moveable, public Attacker, public Buffable
{
private:
    static constexpr int DEFAULT_DAMAGE = 0;
    static constexpr float DEFAULT_CRIT_CHANCE = 0.2f;
    static constexpr int DEFAULT_CRIT_MULTIPLIER = 2;
    static constexpr int DEFAULT_RADIUS_OF_VIEW = 4;
    static constexpr int DEFAULT_RADIUS_OF_ATTACK = 1;

    static constexpr int DEFAULT_MAX_HP = 5;

    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    const Maze &_maze;
    Backpack _backpack;
    HealthPoints _healthPoints;
    Stats _stats;
    Statuses _statuses;
    std::vector<std::shared_ptr<Buff>> _buffs;

public:
    Player(Point startPosition, const Maze &maze);
    Player(int x, int y, const Maze &maze);
    ~Player() = default;

    void moveUp() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;

    bool peekItem(std::shared_ptr<Item> item);
    std::shared_ptr<ActivatingItem<Explosion>> useItem(int index);

    void increaseMaxHealth(int bonusHealthPoints);
    void decreaseMaxHealth(int bonusHealthPoints);

    int radiusView();
    int radiusView() const;

    Point currentPosition();
    const Point &currentPosition() const;

    Stats &stats();
    const Stats &stats() const;

    Statuses &statuses();
    const Statuses &statuses() const;

    void draw() override;
    void nextTurn() override;
    void hit(Damage damage) override;
    void heal(Heal heal) override;
    void attack() override;
    void buff(std::shared_ptr<Buff> buff) override;
    Damage deal() override;
    bool isAlive() override;
};