#pragma once

#include "Point.hpp"
#include "MazeTypeCell.hpp"

class Cell final
{
private:
    MazeTypeCell type;

public:
    Cell(MazeTypeCell type);
    Cell();

    ~Cell();

    auto isWall() -> bool;
    auto isPassage() -> bool;

    auto createPassage() -> void;
};