#pragma once

#include <vector>

#include "Enemy.hpp"
#include "Point.hpp"
#include "Maze.hpp"

class GhostEnemy : public Enemy
{
private:
    static constexpr float SIDE = 1.f;
    bool _goAhead = true;

    Maze _maze;
    int _currentPosition;
    std::vector<Point> _route;

public:
    GhostEnemy(const Maze &maze, const std::vector<Point> &route, int startPosition);
    GhostEnemy(const Maze &maze, const std::vector<Point> &route);
    ~GhostEnemy() = default;

    void draw() override;
    void nextTurn() override;
    Point& currentPosition() override;
};