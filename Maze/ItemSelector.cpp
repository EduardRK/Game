#include "ItemSelector.hpp"
#include "GreenGrassItem.hpp"
#include "BombItem.hpp"
#include "YellowGrassItem.hpp"
#include "TorchItem.hpp"
#include "RandomFunctions.hpp"
#include "KeyItem.hpp"

std::shared_ptr<Item> ItemSelector::seedSelect(int seed)
{
    std::shared_ptr<Item> item;

    switch (seed)
    {
    case GREEN_GRASS_SEED:
        item = std::make_shared<GreenGrassItem>();
        break;
    case YELLOW_GRASS_SEED:
        item = std::make_shared<YellowGrassItem>();
        break;
    case BOMB_SEED:
        item = std::make_shared<BombItem>();
        break;
    case TORCH_SEED:
        item = std::make_shared<TorchItem>();
        break;
    case KEY_SEED:
        item = std::shared_ptr<KeyItem>();
        break;
    default:
        break;
    }

    return item;
}

std::shared_ptr<Item> ItemSelector::randomSelect()
{
    return seedSelect(nextRandomInt(3));
}
