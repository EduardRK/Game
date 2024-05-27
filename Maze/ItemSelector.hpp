#pragma once

#include "Selector.hpp"
#include "Item.hpp"

class ItemSelector final : public Selector<Item>
{
public:
    static constexpr int GREEN_GRASS_SEED = 0;
    static constexpr int YELLOW_GRASS_SEED = 1;
    static constexpr int BOMB_SEED = 2;
    static constexpr int TORCH_SEED = 3;
    static constexpr int KEY_SEED = 4;

    ItemSelector() = default;
    ~ItemSelector() = default;

    std::shared_ptr<Item> seedSelect(int seed) override;
    std::shared_ptr<Item> randomSelect() override;
};