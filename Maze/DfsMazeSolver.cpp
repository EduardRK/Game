#include <vector>
#include <unordered_set>

#include "PointHash.hpp"
#include "Maze.hpp"
#include "Point.hpp"
#include "DfsMazeSolver.hpp"

DfsMazeSolver::DfsMazeSolver(const Maze &maze) : _maze{maze}
{
}

std::vector<Point> DfsMazeSolver::solveMaze(const Point &start, const Point &end)
{
    if (_maze.cell(start).isWall())
    {
        return std::vector<Point>();
    }

    if (_maze.cell(end).isWall())
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
    if (!isValidPoint(point) || _maze.cell(point.x(), point.y()).isWall() || visited.contains(point))
    {
        return false;
    }

    path.push_back(point);
    visited.insert(point);

    if (point == end)
    {
        return true;
    }

    for (auto &&direction : directions)
    {
        Point nextPoint;
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
