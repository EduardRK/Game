#pragma once

#include <vector>
#include <memory>

#include "Item.hpp"
#include "ActivatingItem.hpp"
#include "BackpackCell.hpp"

class Backpack final
{
private:
    static constexpr int DEFAULT_CAPACITY = 10;

    BackpackCell *_backpack;
    int _capacity;

public:
    Backpack(int capacity);
    Backpack();
    ~Backpack();

    bool saveItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> getItem(int index);

private:
    int findEmpty();
};