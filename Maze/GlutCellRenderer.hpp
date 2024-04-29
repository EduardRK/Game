#pragma once

#include "Cell.hpp"
#include "CellRenderer.hpp"

class GlutCellRenderer final : public CellRenderer
{
private:
    static constexpr float BASE_WIDTH = 0.5f;

    float _height;
    float _width;

public:
    GlutCellRenderer(float height, float width);
    GlutCellRenderer(float width);
    GlutCellRenderer();
    ~GlutCellRenderer();

    void render(const Cell &cell) override;
};