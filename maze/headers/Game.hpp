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
#include "Exit.hpp"
#include "GamePhase.hpp"
#include "Explosion.hpp"

class Game final : public Turnable, public Drawable
{
private:
    static constexpr float LINE_WIDTH = 9.f;

    Player &_player;
    Maze &_maze;
    Exit _exit;
    std::vector<std::shared_ptr<Enemy>> _enemies;
    std::vector<std::shared_ptr<Item>> _items;
    std::vector<std::shared_ptr<ActivatingItem<Explosion>>> _atcivatingItems;
    std::vector<Explosion> _explosions;
    std::unique_ptr<MazeRenderer> _mazeRenderer;

    GamePhase _phase = GamePhase::LOAD_PHASE;

public:
    Game(Player &player, Maze &maze, std::vector<std::shared_ptr<Enemy>> &enemy, std::vector<std::shared_ptr<Item>> &items, Exit &exit);
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
    bool isActivatingItemInRadiusOfView(std::shared_ptr<ActivatingItem<Explosion>> &activatingItem);

    bool isExitInRadiusOfView();

    void damageExchange();
    void itemTake();
    void winCheck();

    void attack();

    bool isEnemyInRadiusOfAttack(std::shared_ptr<Enemy> &enemy);
    bool isActivatingItemInRadiusOfAttack(std::shared_ptr<ActivatingItem<Explosion>> &activatingItem);

    void explosionCalculate(Explosion &explosion);
    void explosionDraw(Explosion &explosion);

    bool isPlayerInExlosionRadius(Explosion &explosion);
    bool isEnemyInExplosionRadius(Explosion &explosion, std::shared_ptr<Enemy> &enemy);

    void gamePhaseKeybordFunc(unsigned char key);

    void drawLoadPhase();
    void drawGamePhase();
    void drawDefeatPhase();
    void drawWinPhase();
};