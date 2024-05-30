#pragma once

#include "ActivatingItem.hpp"
#include "Point.hpp"
#include "Maze.hpp"
#include "Player.hpp"

class BombActivatinItem final : public ActivatingItem
{
private:
    static constexpr float SIDE = 1.f;

    const Maze &_maze;
    Player &_player;
    Point _currentPosition;

    bool _active = false;
    int _phase = 1;

public:
    BombActivatinItem(Point currentPosition, Player &player, const Maze &maze);
    ~BombActivatinItem() = default;

    void draw() override;
    void nextTurn() override;
    void activate() override;
    bool complete() override;
    Point currentPosition() override;

private:
    void drawDefaultPhase();
    void drawActivePhase();
    void drawPreExplosionPhase();
    void drawBomb();
};