#pragma once

#include "Selector.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Maze.hpp"
#include "Items.hpp"

class ItemSelector final : public Selector<Item>
{
private:
    Player &_player;
    const Maze &_maze;

public:
    ItemSelector(Player &player, const Maze &maze);
    ~ItemSelector() = default;

    std::shared_ptr<Item> seedSelect(int seed, Point point) override;
    std::shared_ptr<Item> randomSelect(const Point &point) override;
};