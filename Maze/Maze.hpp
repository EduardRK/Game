#include <bits/stdc++.h>

#include "MazeTypeCell.hpp"

class Maze
{
private:
    std::vector<std::vector<MazeTypeCell>> maze;

public:
    Maze(std::vector<std::vector<MazeTypeCell>> const &maze);
    ~Maze();
};