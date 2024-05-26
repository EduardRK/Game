#pragma once

#include "Point.hpp"
#include "Maze.hpp"
#include "Drawable.hpp"
#include "Turnable.hpp"
#include "HealthPoints.hpp"

class Player final : public Drawable, public Turnable
{
private:
    static constexpr int DEFAULT_MAX_HP = 3;
    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    const Maze &_maze;
    HealthPoints _healthPoints;
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

    int radiusView() const;
    int radiusView();

    void newRadiusView(unsigned int newRadiusView);

    Point currentPosition();
    const Point currentPosition() const;

    void draw() override;
    void nextTurn() override;
};