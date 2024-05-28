#pragma once

#include <memory>
#include <vector>

#include "Spawner.hpp"
#include "Item.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Selector.hpp"

class ItemsSpawner final : public Spawner<Item>
{
private:
    Player &_player;

public:
    ItemsSpawner(Player &player);
    ~ItemsSpawner() = default;

    std::vector<std::shared_ptr<Item>> spawn(const Maze &maze) override;

private:
    std::shared_ptr<Item> torchSpawn(const Maze& maze, std::unique_ptr<Selector<Item>> &selector);

    Point randomPassagePoint(const Maze &maze);
    Point randomPoint(const Maze &maze);
};