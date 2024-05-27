#pragma once

#include <vector>
#include <memory>

#include "Item.hpp"

class Backpack final
{
private:
    static constexpr int DEFAULT_CAPACITY = 10;

    std::vector<std::shared_ptr<Item>> _backpack;
    int _capacity;

public:
    Backpack(int capacity);
    Backpack();
    ~Backpack() = default;

    bool saveItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> getItem(int index);
};