#pragma once

#include "Item.hpp"
#include "Player.hpp"

class BombItem final : public Item
{
public:
    BombItem() = default;
    ~BombItem() = default;

    void draw() override;
    void useItem() override;
};