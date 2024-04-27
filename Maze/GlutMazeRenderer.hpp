#pragma once

#include <GL/glut.h>
#include <memory>

#include "MazeRenderer.hpp"
#include "Maze.hpp"
#include "CellRenderer.hpp"
#include "GlutCellRenderer.hpp"

// std::vector<std::vector<int>> maze = { {0,0,1,0,1,0},
//                              {1,0,1,0,1,0},
//                              {1,0,0,0,0,0},
//                              {1,1,1,1,0,1},
//                              {0,1,1,1,0,1},
//                              {0,0,0,0,0,0} };

class GlutMazeRenderer final : public MazeRenderer
{
private:
    std::unique_ptr<CellRenderer> cellRenderer = std::make_unique<GlutCellRenderer>();

public:
    GlutMazeRenderer();
    ~GlutMazeRenderer();

    void render(const Maze &maze) override;
};