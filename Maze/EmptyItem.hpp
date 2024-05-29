#pragma once

#include "Item.hpp"
#include "Point.hpp"

class EmptyItem final : public Item
{
private:
    Point _currentPosition;

public:
    EmptyItem();
    ~EmptyItem() = default;

    void draw() override;
    void useItem() override;
    const Point &currentPosition() override;
};