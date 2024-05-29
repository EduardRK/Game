#pragma once

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

class Player final : public Drawable, public Turnable, public Hitable, public Healable, public Dealer<Damage>, public Living, public Moveable
{
private:
    static constexpr int DEFAULT_DAMAGE = 0;
    static constexpr float DEFAULT_CRIT_CHANCE = 0.25f;
    static constexpr int DEFAULT_CRIT_MULTIPLIER = 2;

    static constexpr int DEFAULT_MAX_HP = 3;
    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    const Maze &_maze;
    Backpack _backpack;
    HealthPoints _healthPoints;
    Damage _damage;

    int _radiusView = 100;

public:
    Player(const Point &startPosition, const Maze &maze);
    Player(Point startPosition, const Maze &maze);
    Player(int x, int y, const Maze &maze);
    ~Player() = default;

    void moveUp() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;

    void newRadiusView(unsigned int newRadiusView);

    bool peekItem(std::shared_ptr<Item> item);
    void useItem(int index);

    void increaseMaxHealth(int bonusHealthPoints);
    void decreaseMaxHealth(int bonusHealthPoints);

    int radiusView();
    int radiusView() const;

    Point &currentPosition();
    const Point &currentPosition() const;

    void draw() override;
    void nextTurn() override;
    void hit(Damage damage) override;
    void heal(Heal heal) override;
    Damage &deal() override;
    bool isAlive() override;
};