#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "Heal.hpp"

class YellowGrassItem final : public Item
{
private:
    static constexpr float SIDE = 0.5f;

    static constexpr int DEFAULT_HEAL = 1;
    static constexpr int DEFAULT_MAX_HEALTH_INCREASE = 1;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

    Heal _heal;

public:
    YellowGrassItem(Player &player, const Maze &maze, Point currentPosition);
    ~YellowGrassItem() = default;

    void draw() override;
    void useItem() override;
    const Point &currentPosition() override;
};