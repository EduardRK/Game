#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Maze.hpp"

class GreenGrassItem final : public Item
{
private:
    static constexpr float SIDE = 0.5f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    GreenGrassItem(Player &player, const Maze &maze, Point currentPosition);
    ~GreenGrassItem() = default;

    void draw() override;
    void useItem() override;
    const Point &currentPosition() override;
};