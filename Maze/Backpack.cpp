#include "Backpack.hpp"
#include "EmptyItem.hpp"

Backpack::Backpack(int capacity) : _capacity{capacity}
{
    _backpack = new BackpackCell[capacity];
}

Backpack::Backpack() : Backpack(DEFAULT_CAPACITY)
{
}

Backpack::~Backpack()
{
    delete[] _backpack;
}

bool Backpack::saveItem(std::shared_ptr<Item> item)
{
    int index = findEmpty();

    if (index == -1)
    {
        return false;
    }

    _backpack[index].addItem(item);
    return true;
}

std::shared_ptr<Item> Backpack::getItem(int index)
{
    if (index < _capacity)
    {
        std::shared_ptr<Item> item = _backpack[index].getItem();
        return item;
    }

    return std::make_shared<EmptyItem>();
}

int Backpack::findEmpty()
{
    for (size_t i = 0; i < _capacity; ++i)
    {
        if (_backpack[i].empty())
        {
            return i;
        }
    }

    return -1;
}
