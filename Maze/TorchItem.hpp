#pragma once

#include "Item.hpp"

class TorchItem final : public Item
{
public:
    TorchItem() = default;
    ~TorchItem() = default;

    void draw() override;
    void useItem(const Player &player) override;
};