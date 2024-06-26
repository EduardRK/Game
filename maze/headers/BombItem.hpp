#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "Explosion.hpp"

class BombItem final : public Item
{
private:
    static constexpr float SIDE_ON_MAP = 0.5f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    BombItem(Player &player, const Maze &maze, Point currentPosition);
    ~BombItem() = default;

    void draw() override;
    void backpackDraw(float left, float top, float side) override;
    std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() override;
    void useItem() override;
    Point currentPosition() override;
};