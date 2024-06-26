#pragma once

#include <memory>

#include "MazeRenderer.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "CellRenderer.hpp"

class GlutMazeRenderer final : public MazeRenderer
{
private:
    const Player &_player;
    Maze &_maze;
    std::unique_ptr<CellRenderer> _cellRenderer;

public:
    GlutMazeRenderer(const Player &player, Maze &maze);
    ~GlutMazeRenderer() = default;

    void render() override;
};