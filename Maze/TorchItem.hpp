#pragma once

#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "Explosion.hpp"

class TorchItem final : public Item
{
private:
    static constexpr float SIDE = 0.5f;

    Player &_player;
    const Maze &_maze;
    Point _currentPosition;

public:
    TorchItem(Player &player, const Maze &maze, Point currentPosition);
    ~TorchItem() = default;

    void draw() override;
    std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() override;
    void useItem() override;
    Point currentPosition() override;
};