#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"

class KeyItem final : public Item
{
private:
    static constexpr float SIDE = 0.5f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    KeyItem(Player &player, const Maze &maze, Point currentPosition);
    ~KeyItem() = default;

    void draw() override;
    void useItem() override;
    const Point &currentPosition() override;
};