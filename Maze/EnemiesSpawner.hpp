#pragma once

#include <memory>
#include <vector>

#include "Spawner.hpp"
#include "Enemy.hpp"
#include "MazeSolver.hpp"

class EnemiesSpawner final : public Spawner<std::shared_ptr<Enemy>>
{
public:
    EnemiesSpawner() = default;
    ~EnemiesSpawner() = default;

    std::vector<std::shared_ptr<Enemy>> spawn(const Maze &maze);

private:
    std::shared_ptr<Enemy> standartEnemy(const Maze &maze, MazeSolver &mazeSolver);
    std::shared_ptr<Enemy> randomEnemy(const Maze &maze, MazeSolver &mazeSolver);

    Point randomPassagePoint(const Maze &maze);
    Point randomPoint(const Maze &maze);
    int nextRandomInt(int min, int max);
};