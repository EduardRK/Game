#pragma once

#include <memory>
#include <vector>

#include "Spawner.hpp"
#include "Enemy.hpp"
#include "MazeSolver.hpp"
#include "Player.hpp"

class EnemiesSpawner final : public Spawner<Enemy>
{
private:
    Player &_player;

public:
    EnemiesSpawner(Player &player);
    ~EnemiesSpawner() = default;

    std::vector<std::shared_ptr<Enemy>> spawn(const Maze &maze) override;

private:
    std::shared_ptr<Enemy> standartGhostEnemy(const Maze &maze, MazeSolver &mazeSolver);
    std::shared_ptr<Enemy> randomGhostEnemy(const Maze &maze, MazeSolver &mazeSolver);

    std::vector<std::shared_ptr<Enemy>> standartTrollEnemy(const Maze &maze, MazeSolver &mazeSolver);

    Point randomPassagePoint(const Maze &maze);
    Point randomPoint(const Maze &maze);
};