#pragma once

#include <memory>

#include "Item.hpp"
#include "BackpackDrawable.hpp"

class BackpackCell final : public BackpackDrawable
{
private:
    std::shared_ptr<Item> _item;
    bool _empty = true;

public:
    BackpackCell();

    bool empty() const;
    bool empty();

    std::shared_ptr<Item> getItem();

    void addItem(std::shared_ptr<Item> item);

    void backpackDraw(float left, float top, float side) override;
};