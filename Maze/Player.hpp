#pragma once

#include "Point.hpp"
#include "Maze.hpp"
#include "Drawable.hpp"

class Player final : public Drawable
{
private:
    static constexpr float SIDE = 1.f;

    Point _currentPosition;
    Maze _maze;
    int _radiusView = 4;

public:
    Player(const Point &startPosition, const Maze &maze);
    Player(Point startPosition, const Maze &maze);
    Player(int x, int y, const Maze &maze);
    ~Player();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int radiusView() const;
    int radiusView();

    void newRadiusView(unsigned int newRadiusView);

    void draw() override;

    Point currentPosition();
    const Point currentPosition() const;
};