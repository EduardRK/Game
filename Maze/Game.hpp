#pragma once

#include <memory>
#include <vector>

#include "Turnable.hpp"
#include "Player.hpp"
#include "Drawable.hpp"
#include "Maze.hpp"
#include "Enemy.hpp"
#include "MazeRenderer.hpp"
#include "Item.hpp"
#include "ActivatingItem.hpp"

class Game final : public Turnable, public Drawable
{
private:
    static constexpr float LINE_WIDTH = 9.f;

    static constexpr int LOAD_PHASE = 1;
    static constexpr int GAME_PHASE = 2;
    static constexpr int WIN_PHASE = 3;
    static constexpr int DEFEAT_PHASE = 4;

    Player &_player;
    Maze &_maze;
    std::vector<std::shared_ptr<Enemy>> _enemies;
    std::vector<std::shared_ptr<Item>> _items;
    std::vector<std::shared_ptr<ActivatingItem>> _atcivatingItems;
    std::unique_ptr<MazeRenderer> _mazeRenderer;

    int _phase = LOAD_PHASE;

public:
    Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemy, std::vector<std::shared_ptr<Item>> &items);
    ~Game() = default;

    const Player &player() const;
    Player &player();
    const Maze &maze() const;
    Maze &maze();

    void useKeyboardKey(unsigned char key);

    void draw() override;
    void nextTurn() override;

private:
    bool isEnemyInRadiusOfView(std::shared_ptr<Enemy> &enemy);
    bool isItemInRadiusOfView(std::shared_ptr<Item> &item);
    bool isActivatingItemInRadiusOfView(std::shared_ptr<ActivatingItem> &activatingItem);

    void damageExchange();
    void itemTake();

    void attack();

    bool isEnemyInRadiusOfAttack(std::shared_ptr<Enemy> &enemy);
    bool isActivatingItemInRadiusOfAttack(std::shared_ptr<ActivatingItem> &activatingItem);

    void gamePhaseKeybordFunc(unsigned char key);

    void drawLoadPhase();
    void drawGamePhase();
    void drawDefeatPhase();
    void drawWinPhase();
};