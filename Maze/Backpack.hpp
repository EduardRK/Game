#pragma once

#include <vector>
#include <memory>

#include "Item.hpp"
#include "ActivatingItem.hpp"
#include "BackpackCell.hpp"
#include "Drawable.hpp"

class Backpack final : public Drawable
{
private:
    static constexpr int DEFAULT_CAPACITY = 10;

    static constexpr float SIDE = 0.08f;
    static constexpr float GAP = 0.02f;
    static constexpr float LINE_WIDTH = 2.2f;

    BackpackCell *_backpack;
    int _capacity;

public:
    Backpack(int capacity);
    Backpack();
    ~Backpack();

    bool saveItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> getItem(int index);

    void draw() override;

private:
    int findEmpty();
};