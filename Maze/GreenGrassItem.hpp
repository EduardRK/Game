#pragma once

#include "Item.hpp"

class GreenGrassItem final : public Item
{
public:
    GreenGrassItem() = default;
    ~GreenGrassItem() = default;

    void draw() override;
    void useItem() override;
};