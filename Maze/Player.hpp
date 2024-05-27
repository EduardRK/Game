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

class Player final : public Drawable, public Turnable, public Hitable, public Healable, public Dealer<Damage>, public Living
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

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void newRadiusView(unsigned int newRadiusView);
    bool peekItem(std::shared_ptr<Item> item);
    void useItem(int index);

    int radiusView();
    int radiusView() const;

    Point &currentPosition();
    const Point &currentPosition() const;

    HealthPoints &healthPoints();
    const HealthPoints &healthPoints() const;

    Damage &damage();
    const Damage &damage() const;

    void draw() override;
    void nextTurn() override;
    void hit(Damage &damage) override;
    void heal(Heal &heal) override;
    Damage &deal() override;
    bool isAlive() override;
};