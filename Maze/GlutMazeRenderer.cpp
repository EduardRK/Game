#include <GL/glut.h>

#include "GlutMazeRenderer.hpp"
#include "Maze.hpp"

GlutMazeRenderer::GlutMazeRenderer()
{
}

GlutMazeRenderer::~GlutMazeRenderer()
{
}

void GlutMazeRenderer::render(const Maze &maze)
{
    for (size_t i = 0; i < maze.height(); ++i)
    {
        for (size_t j = 0; j < maze.width(); ++j)
        {
            Cell cell = maze.cell(i, j);
            cellRenderer->render(cell);
        }
    }
}
