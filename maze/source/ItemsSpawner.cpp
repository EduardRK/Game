#include <unordered_set>

#include "ItemsSpawner.hpp"
#include "RandomFunctions.hpp"
#include "Selector.hpp"
#include "ItemSelector.hpp"
#include "RandomFunctions.hpp"
#include "PointHash.hpp"
#include "Items.hpp"

ItemsSpawner::ItemsSpawner(Player &player) : _player{player}
{
}

std::vector<std::shared_ptr<Item>> ItemsSpawner::spawn(const Maze &maze)
{
    std::unique_ptr<Selector<Item>> selector = std::make_unique<ItemSelector>(_player, maze);
    std::vector<std::shared_ptr<Item>> items;
    std::unordered_set<Point> alreadyUsePoints;
    int random = 0;

    for (int i = 0; i < (maze.height() / 3); ++i)
    {
        random = nextRandomInt(100);
        Point currentPosition = randomPassagePoint(maze);

        while (alreadyUsePoints.contains(currentPosition))
        {
            currentPosition = randomPassagePoint(maze);
        }

        alreadyUsePoints.insert(currentPosition);

        if (random <= 10)
        {
            items.push_back(selector->seedSelect(Items::TORCH_ITEM, currentPosition));
        }
        else if (random > 10 && random <= 40)
        {
            items.push_back(selector->seedSelect(Items::BOMB_ITEM, currentPosition));
        }
        else if (random > 40 && random <= 80)
        {
            items.push_back(selector->seedSelect(Items::GREEN_GRASS_ITEM, currentPosition));
        }
        else
        {
            items.push_back(selector->seedSelect(Items::YELLOW_GRASS_ITEM, currentPosition));
        }
    }

    items.push_back(torchSpawn(maze, selector));

    return items;
}

std::shared_ptr<Item> ItemsSpawner::torchSpawn(const Maze &maze, std::unique_ptr<Selector<Item>> &selector)
{
    Point point;
    if (maze.cell(1, 2).isPassage())
    {
        point = Point(1, 2);
        return selector->seedSelect(Items::TORCH_ITEM, point);
    }
    else
    {
        point = Point(2, 1);
        return selector->seedSelect(Items::TORCH_ITEM, point);
    }
}

Point ItemsSpawner::randomPassagePoint(const Maze &maze)
{
    Point point = randomPoint(maze);

    while (!maze.cell(point).isPassage())
    {
        point = randomPoint(maze);
    }

    return point;
}

Point ItemsSpawner::randomPoint(const Maze &maze)
{
    return Point(nextRandomInt(1, maze.height() - 2), nextRandomInt(1, maze.width() - 2));
}
