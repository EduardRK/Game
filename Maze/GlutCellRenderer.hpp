#pragma once

#include "Cell.hpp"
#include "CellRenderer.hpp"

class GlutCellRenderer final : public CellRenderer
{
public:
    GlutCellRenderer();
    ~GlutCellRenderer();

    void render(const Cell &cell) override;

private:
    void wallRender();
    void passageRender();
    void crackedRender();
};