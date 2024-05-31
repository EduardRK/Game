#pragma once

#include "ActivatingItem.hpp"
#include "Point.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "Explosion.hpp"
#include "BombActivatingItemPhase.hpp"

class BombActivatingItem final : public ActivatingItem<Explosion>
{
private:
    static constexpr float SIDE = 1.f;

    static constexpr int DEFAULT_DAMAGE = 2;
    static constexpr int DEFAULT_RADIUS = 1;

    const Maze &_maze;
    Player &_player;
    Point _currentPosition;

    bool _active = false;
    BombActivatingItemPhase _phase = BombActivatingItemPhase::DEFAULT_PHASE;

public:
    BombActivatingItem(Point currentPosition, Player &player, const Maze &maze);
    BombActivatingItem(Player &player, const Maze &maze);
    ~BombActivatingItem() = default;

    void draw() override;
    void nextTurn() override;
    void activate() override;
    bool complete() override;
    Explosion result() override;
    Point currentPosition() override;

private:
    void drawDefaultPhase();
    void drawActivePhase();
    void drawPreExplosionPhase();
    void drawBomb();

    void nextPhase();
};