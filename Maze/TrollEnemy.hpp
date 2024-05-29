#pragma once

#include <memory>
#include <vector>

#include "Enemy.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "MazeSolver.hpp"
#include "HealthPoints.hpp"
#include "Dealer.hpp"
#include "Damage.hpp"

class TrollEnemy final : public Enemy
{
private:
    static constexpr int DEFAULT_DAMAGE = 2;
    static constexpr float DEFAULT_CRIT_CHANCE = 0.15f;
    static constexpr int DEFAULT_CRIT_MULTIPLIER = 2;

    static constexpr int DEFAULT_MAX_HP = 2;
    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    const Maze &_maze;
    Player &_player;
    HealthPoints _healthPoints;
    std::unique_ptr<MazeSolver> _mazeSolver;
    Damage _damage;

    int _radiusView = 3;
    bool _chase = false;
    int _turnCounter = 0;
    std::vector<Point> _route;

public:
    TrollEnemy(const Maze &maze, Point &currentPosition, Player &player);
    ~TrollEnemy() = default;

    void draw() override;
    void nextTurn() override;
    Point &currentPosition() override;
    void hit(Damage damage) override;
    Damage &deal() override;
    bool isAlive() override;
    std::shared_ptr<Item> deathRattle() override;

private:
    bool playerInRadiusOfView();
};