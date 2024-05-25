#include <random>

#include "EnemiesSpawner.hpp"
#include "MazeSolver.hpp"
#include "DfsMazeSolver.hpp"
#include "GhostEnemy.hpp"
#include "TrollEnemy.hpp"

EnemiesSpawner::EnemiesSpawner(Player &player) : _player{player}
{
}

std::vector<std::shared_ptr<Enemy>> EnemiesSpawner::spawn(const Maze &maze)
{
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(maze);
    std::vector<std::shared_ptr<Enemy>> enemies;

    enemies.push_back(standartGhostEnemy(maze, *mazeSolver));

    for (size_t i = 0; i < (maze.height() / 7) + 2; ++i)
    {
        enemies.push_back(randomGhostEnemy(maze, *mazeSolver));
    }

    std::vector<std::shared_ptr<Enemy>> trolls = standartTrollEnemy(maze, *mazeSolver);
    enemies.insert(enemies.end(), trolls.begin(), trolls.end());

    return enemies;
}

std::shared_ptr<Enemy> EnemiesSpawner::standartGhostEnemy(const Maze &maze, MazeSolver &mazeSolver)
{
    Point startPosition(maze.height() - 2, 1);
    Point endPosition(1, maze.width() - 2);
    std::vector<Point> route = mazeSolver.solveMaze(startPosition, endPosition);

    return std::make_shared<GhostEnemy>(maze, route);
}

std::shared_ptr<Enemy> EnemiesSpawner::randomGhostEnemy(const Maze &maze, MazeSolver &mazeSolver)
{
    Point startPosition = randomPassagePoint(maze);
    Point endPosition = randomPassagePoint(maze);
    std::vector<Point> route = mazeSolver.solveMaze(startPosition, endPosition);

    return std::make_shared<GhostEnemy>(maze, route);
}

std::vector<std::shared_ptr<Enemy>> EnemiesSpawner::standartTrollEnemy(const Maze &maze, MazeSolver &mazeSolver)
{
    std::vector<std::shared_ptr<Enemy>> trolls;

    Point startPosition;

    if (maze.cell(1, maze.width() - 3).isPassage())
    {
        startPosition = Point(1, maze.width() - 3);
    }
    else
    {
        startPosition = Point(2, maze.width() - 2);
    }

    trolls.push_back(std::make_shared<TrollEnemy>(maze, startPosition, _player));

    if (maze.cell(maze.height() - 3, 1).isPassage())
    {
        startPosition = Point(maze.height() - 3, 1);
    }
    else
    {
        startPosition = Point(maze.height() - 2, 2);
    }

    trolls.push_back(std::make_shared<TrollEnemy>(maze, startPosition, _player));

    return trolls;
}

Point EnemiesSpawner::randomPassagePoint(const Maze &maze)
{
    Point point = randomPoint(maze);

    while (!maze.cell(point).isPassage())
    {
        point = randomPoint(maze);
    }

    return point;
}

Point EnemiesSpawner::randomPoint(const Maze &maze)
{
    return Point(nextRandomInt(1, maze.height() - 2), nextRandomInt(1, maze.width() - 2));
}

int EnemiesSpawner::nextRandomInt(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max - 1);
    return dist6(rng);
}
