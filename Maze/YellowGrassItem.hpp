#pragma once

#include "Item.hpp"

class YellowGrassItem final : public Item
{
public:
    YellowGrassItem() = default;
    ~YellowGrassItem() = default;

    void draw() override;
    void useItem() override;
};