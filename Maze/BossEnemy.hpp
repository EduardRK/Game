#pragma once

#include <memory>

#include "Player.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Maze.hpp"
#include "MazeSolver.hpp"

class BossEnemy final : public Enemy
{
private:
    static constexpr float SIDE = 1.f;

    const Player &_player;
    const Maze &_maze;
    Point _currentPosition;
    std::unique_ptr<MazeSolver> _mazeSolver;

public:
    BossEnemy(const Player &player, const Maze &maze, Point startPosition);
    ~BossEnemy() = default;

    void draw() override;
    void nextTurn() override;
};