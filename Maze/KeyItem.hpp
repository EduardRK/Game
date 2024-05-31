#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "Explosion.hpp"

class KeyItem final : public Item
{
private:
    static constexpr float SIDE_ON_MAP = 0.5f;
    static constexpr float SIDE_ON_BACKPACK = 1.f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    KeyItem(Player &player, const Maze &maze, Point currentPosition);
    ~KeyItem() = default;

    void draw() override;
    void backpackDraw(float left, float top, float side) override;
    std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() override;
    void useItem() override;
    Point currentPosition() override;
};