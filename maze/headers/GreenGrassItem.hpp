#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Maze.hpp"
#include "Heal.hpp"
#include "Explosion.hpp"

class GreenGrassItem final : public Item
{
private:
    static constexpr float SIDE_ON_MAP = 0.5f;
    static constexpr float SIDE_ON_BACKPACK = 1.f;

    static constexpr int DEFAULT_HEAL = 1;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

    Heal _heal;

public:
    GreenGrassItem(Player &player, const Maze &maze, Point currentPosition);
    ~GreenGrassItem() = default;

    void draw() override;
    void backpackDraw(float left, float top, float side) override;
    std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() override;
    void useItem() override;
    Point currentPosition() override;
};