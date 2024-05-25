#pragma once

#include <memory>
#include <vector>

#include "Enemy.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "MazeSolver.hpp"

class TrollEnemy final : public Enemy
{
private:
    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    const Maze &_maze;
    const Player& _player;
    std::unique_ptr<MazeSolver> _mazeSolver;

    int _radiusView = 3;
    bool _chase = false;
    int _turnCounter = 0;
    std::vector<Point> _route;

public:
    TrollEnemy(const Maze &maze, Point &currentPosition, const Player& player);
    ~TrollEnemy() = default;

    void draw() override;
    void nextTurn() override;
    Point& currentPosition() override;

private:
    bool playerInRadiusOfView();
};