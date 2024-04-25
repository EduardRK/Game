#include <bits/stdc++.h>

#include "Maze.hpp"
#include "Point/Point.hpp"

class MazeSolver
{
    public:
    virtual ~MazeSolver();

    virtual auto solveMaze(Maze const& maze) -> std::vector<Point> = 0;
}