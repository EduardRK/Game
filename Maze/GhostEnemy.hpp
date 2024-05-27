#pragma once

#include <memory>
#include <vector>

#include "Enemy.hpp"
#include "Point.hpp"
#include "Maze.hpp"
#include "HealthPoints.hpp"
#include "Damage.hpp"
#include "Player.hpp"

class GhostEnemy final : public Enemy
{
private:
    static constexpr int DEFAULT_DAMAGE = 1;
    static constexpr float DEFAULT_CRIT_CHANCE = 0.3f;
    static constexpr int DEFAULT_CRIT_MULTIPLIER = 3;

    static constexpr int DEFAULT_MAX_HP = 1;
    static constexpr float SIDE = 1.f;

    bool _goAhead = true;

    const Maze &_maze;
    const Player &_player;
    HealthPoints _healthPoints;
    int _currentPosition;
    std::vector<Point> _route;
    Damage _damage;

public:
    GhostEnemy(const Maze &maze, const Player &player, const std::vector<Point> &route, int startPosition);
    GhostEnemy(const Maze &maze, const Player &player, const std::vector<Point> &route);
    ~GhostEnemy() = default;

    void draw() override;
    void nextTurn() override;
    Point &currentPosition() override;
    void hit(Damage &damage) override;
    Damage &deal() override;
    bool isAlive() override;
    std::shared_ptr<Item> deathRattle() override;
};