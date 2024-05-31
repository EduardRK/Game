#include "BackpackCell.hpp"
#include "EmptyItem.hpp"

BackpackCell::BackpackCell() : _item{std::make_shared<EmptyItem>()}
{
}

bool BackpackCell::empty() const
{
    return _empty;
}

bool BackpackCell::empty()
{
    return _empty;
}

std::shared_ptr<Item> BackpackCell::getItem()
{
    std::shared_ptr<Item> item = _item;
    _item = std::make_shared<EmptyItem>();
    _empty = true;
    return item;
}

void BackpackCell::addItem(std::shared_ptr<Item> item)
{
    _item = item;
    _empty = false;
}
