#pragma once

#include "Item.hpp"
#include "Point.hpp"
#include "Explosion.hpp"

class EmptyItem final : public Item
{
public:
    EmptyItem() = default;
    ~EmptyItem() = default;

    void draw() override;
    std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() override;
    void useItem() override;
    Point currentPosition() override;
};