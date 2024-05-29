#include "ItemSelector.hpp"
#include "GreenGrassItem.hpp"
#include "BombItem.hpp"
#include "YellowGrassItem.hpp"
#include "TorchItem.hpp"
#include "RandomFunctions.hpp"
#include "KeyItem.hpp"
#include "EmptyItem.hpp"

ItemSelector::ItemSelector(Player &player, const Maze &maze) : _player{player}, _maze{maze}
{
}

std::shared_ptr<Item> ItemSelector::seedSelect(int seed, Point point)
{
    std::shared_ptr<Item> item;

    switch (seed)
    {
    case GREEN_GRASS_SEED:
        item = std::make_shared<GreenGrassItem>(_player, _maze, point);
        break;
    case YELLOW_GRASS_SEED:
        item = std::make_shared<YellowGrassItem>(_player, _maze, point);
        break;
    case BOMB_SEED:
        item = std::make_shared<BombItem>(_player, _maze, point);
        break;
    case TORCH_SEED:
        item = std::make_shared<TorchItem>(_player, _maze, point);
        break;
    case KEY_SEED:
        item = std::make_shared<KeyItem>(_player, _maze, point);
        break;
    default:
        item = std::make_shared<EmptyItem>();
        break;
    }

    return item;
}

std::shared_ptr<Item> ItemSelector::randomSelect(const Point &point)
{
    return seedSelect(nextRandomInt(3), point);
}
