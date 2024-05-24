#include <random>

#include "EnemiesSpawner.hpp"
#include "MazeSolver.hpp"
#include "DfsMazeSolver.hpp"
#include "GhostEnemy.hpp"

std::vector<std::shared_ptr<Enemy>> EnemiesSpawner::spawn(const Maze &maze)
{
    std::unique_ptr<MazeSolver> mazeSolver = std::make_unique<DfsMazeSolver>(maze);
    std::vector<std::shared_ptr<Enemy>> enemies;

    enemies.push_back(standartEnemy(maze, *mazeSolver));

    for (size_t i = 0; i < (maze.height() / 10) + 2; ++i)
    {
        enemies.push_back(randomEnemy(maze, *mazeSolver));
    }

    return enemies;
}

std::shared_ptr<Enemy> EnemiesSpawner::standartEnemy(const Maze &maze, MazeSolver &mazeSolver)
{
    Point startPosition(maze.height() - 2, 1);
    Point endPosition(1, maze.width() - 2);
    std::vector<Point> route = mazeSolver.solveMaze(startPosition, endPosition);

    return std::make_shared<GhostEnemy>(maze, route);
}

std::shared_ptr<Enemy> EnemiesSpawner::randomEnemy(const Maze &maze, MazeSolver &mazeSolver)
{
    Point startPosition = randomPassagePoint(maze);
    Point endPosition = randomPassagePoint(maze);
    std::vector<Point> route = mazeSolver.solveMaze(startPosition, endPosition);

    return std::make_shared<GhostEnemy>(maze, route);
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
