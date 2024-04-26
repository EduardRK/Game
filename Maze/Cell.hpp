#include "point/Point.hpp"
#include "MazeTypeCell.hpp"

class final Cell
{
private:
    Point point;
    MazeTypeCell type;

public:
    Cell(Point &point, MazeTypeCell type);
    Cell(Point &point);

    ~Cell();

    auto isWall() -> bool;
    auto isPassage() -> bool;

    auto createPassage() -> void;

    auto point() -> Point;
}