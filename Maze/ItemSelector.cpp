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
    case Items::GREEN_GRASS_ITEM:
        item = std::make_shared<GreenGrassItem>(_player, _maze, point);
        break;
    case Items::YELLOW_GRASS_ITEM:
        item = std::make_shared<YellowGrassItem>(_player, _maze, point);
        break;
    case Items::BOMB_ITEM:
        item = std::make_shared<BombItem>(_player, _maze, point);
        break;
    case Items::TORCH_ITEM:
        item = std::make_shared<TorchItem>(_player, _maze, point);
        break;
    case Items::KEY_ITEM:
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
