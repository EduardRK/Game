#include "Backpack.hpp"
#include "EmptyItem.hpp"

Backpack::Backpack(int capacity) : _capacity{capacity}
{
}

Backpack::Backpack() : Backpack(DEFAULT_CAPACITY)
{
}

bool Backpack::saveItem(std::shared_ptr<Item> item)
{
    if (_backpack.size() >= _capacity)
    {
        return false;
    }

    _backpack.push_back(item);
    return true;
}

std::shared_ptr<Item> Backpack::getItem(int index)
{
    if (_backpack.size() < index)
    {
        return _backpack.at(index);
    }

    return std::make_shared<EmptyItem>();
}