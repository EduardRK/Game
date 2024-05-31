#pragma once

#include "Point.hpp"
#include "Maze.hpp"
#include "Drawable.hpp"

class Exit final : public Drawable
{
private:
    static constexpr float SIDE = 1.f;

    Point _position;
    const Maze &_maze;

public:
    Exit(Point position, const Maze &maze);
    Exit(const Maze &maze);
    ~Exit();

    Point posisiton();
    const Point &position() const;

    void draw() override;
};