#pragma once

#include "Cell.hpp"

class CellRenderer
{
public:
    virtual ~CellRenderer() = default;

    virtual void render(const Cell &cell) = 0;
};