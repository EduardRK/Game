#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"

class BombItem final : public Item
{
private:
    static constexpr float SIDE = 0.5f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    BombItem(Player &player, const Maze &maze, Point currentPosition);
    ~BombItem() = default;

    void draw() override;
    void useItem() override;
    const Point &currentPosition() override;
};