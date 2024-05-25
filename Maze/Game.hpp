#pragma once

#include <memory>
#include <vector>

#include "Turnable.hpp"
#include "Player.hpp"
#include "Drawable.hpp"
#include "Maze.hpp"
#include "Enemy.hpp"
#include "MazeRenderer.hpp"

class Game : public Turnable, public Drawable
{
private:
    Player &_player;
    Maze &_maze;
    std::vector<std::shared_ptr<Enemy>> _enemies;
    std::unique_ptr<MazeRenderer> _mazeRenderer;

public:
    Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemy);
    ~Game() = default;

    Player &player();
    Maze &maze();

    void draw() override;
    void nextTurn() override;

private:
    bool isEnemyInRadiusOfView(std::shared_ptr<Enemy> enemy);
};