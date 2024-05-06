#pragma once

#include <memory>

#include "MazeRenderer.hpp"
#include "Maze.hpp"
#include "Player.hpp"
#include "GlutCellRenderer.hpp"

class GlutMazeRenderer final : public MazeRenderer
{
private:
    const Player &_player;
    const Maze &_maze;
    std::unique_ptr<GlutCellRenderer> _glutCellRenderer;

public:
    GlutMazeRenderer(const Player &player, const Maze &maze);
    ~GlutMazeRenderer();

    void render() override;
};