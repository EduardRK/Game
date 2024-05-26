#include <vector>
#include <unordered_set>
#include <random>

#include "PointHash.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "DfsMazeSolver.hpp"
#include "RandomFunctions.hpp"

DfsMazeSolver::DfsMazeSolver(const Maze &maze) : _maze{maze}
{
}

std::vector<Point> DfsMazeSolver::solveMaze(const Point &start, const Point &end)
{
    if (_maze.cell(start).isWall() || _maze.cell(start).isCracked())
    {
        return std::vector<Point>();
    }

    if (_maze.cell(end).isWall() || _maze.cell(start).isCracked())
    {
        return std::vector<Point>();
    }

    std::vector<Point> path;
    std::unordered_set<Point> visited;

    if (explore(start, end, path, visited))
    {
        return path;
    }

    return std::vector<Point>();
}

bool DfsMazeSolver::explore(const Point &point, const Point &end, std::vector<Point> &path, std::unordered_set<Point> &visited)
{
    if (!isValidPoint(point) || _maze.cell(point).isWall() || _maze.cell(point).isCracked() || visited.contains(point))
    {
        return false;
    }

    path.push_back(point);
    visited.insert(point);

    if (point == end)
    {
        return true;
    }

    // for (auto &&direction : _directions)
    std::vector<char> directions { 'U', 'D', 'R', 'L' };
    for (int i = 0; i < 4; ++i)
    {
        Point nextPoint;
        int index = nextRandomInt(directions.size());
        char direction = directions.at(index);
        directions.erase(directions.begin() + index);

        if (direction == 'U')
        {
            nextPoint = Point(point.x() + 1, point.y());
        }
        else if (direction == 'D')
        {
            nextPoint = Point(point.x() - 1, point.y());
        }
        else if (direction == 'R')
        {
            nextPoint = Point(point.x(), point.y() + 1);
        }
        else if (direction == 'L')
        {
            nextPoint = Point(point.x(), point.y() - 1);
        }

        if (explore(nextPoint, end, path, visited))
        {
            return true;
        }
    }

    path.pop_back();
    return false;
}

bool DfsMazeSolver::isValidPoint(const Point &point)
{
    return point.x() >= 0 && point.y() < _maze.height() && point.y() >= 0 && point.x() < _maze.width();
}