#pragma once

#include <vector>
#include <unordered_set>

#include "MazeSolver.hpp"
#include "Maze.hpp"
#include "Point.hpp"

class DfsMazeSolver final : public MazeSolver
{
private:
    Maze _maze;
    std::vector<char> _directions{'U', 'D', 'R', 'L'};

public:
    DfsMazeSolver(const Maze &maze);
    ~DfsMazeSolver() = default;

    std::vector<Point> solveMaze(const Point &start, const Point &end) override;

private:
    bool explore(const Point &point, const Point &end, std::vector<Point> &path, std::unordered_set<Point> &visited);
    bool isValidPoint(const Point &point);

    int nextRandomInt(int min, int max);
    int nextRandomInt(int max);
};