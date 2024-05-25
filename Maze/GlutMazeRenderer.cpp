#include <memory>

#include "GlutMazeRenderer.hpp"
#include "Player.hpp"
#include "Maze.hpp"

GlutMazeRenderer::GlutMazeRenderer(const Player &player, const Maze &maze) : _player{player}, _maze{maze}, _glutCellRenderer{std::make_unique<GlutCellRenderer>(_maze.height(), _maze.width())}
{
}

void GlutMazeRenderer::render()
{
    int startX = (_player.currentPosition().x() - _player.radiusView()) <= 0 ? 0 : (_player.currentPosition().x() - _player.radiusView());
    int endX = (_player.currentPosition().x() + _player.radiusView()) >= _maze.height() ? (_maze.height() - 1) : (_player.currentPosition().x() + _player.radiusView());

    int startY = (_player.currentPosition().y() - _player.radiusView()) <= 0 ? 0 : (_player.currentPosition().y() - _player.radiusView());
    int endY = (_player.currentPosition().y() + _player.radiusView()) >= _maze.width() ? (_maze.width() - 1) : (_player.currentPosition().y() + _player.radiusView());

    for (int i = startX; i <= endX; ++i)
    {
        for (int j = startY; j <= endY; ++j)
        {
            _glutCellRenderer->render(_maze.cell(i, j));
        }
    }
}
