#include <bits/stdc++.h>

#include "MazeGenerator.hpp"
#include "Maze.hpp"

class final PrimMazeGenerator : public MazeGenerator
{
public:
    PrimMazeGenerator();
    ~PrimMazeGenerator();

    auto generateMaze(std::size_t height, std::size_t width) -> Maze const override;
}