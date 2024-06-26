#pragma once

#include "Cell.hpp"
#include "CellRenderer.hpp"

class GlutCellRenderer final : public CellRenderer
{
private:
    static constexpr float SIDE = 1.f;

    float _height;
    float _width;

public:
    GlutCellRenderer(float height, float width);
    GlutCellRenderer(float width);
    ~GlutCellRenderer() = default;

    void render(const Cell &cell) override;
};