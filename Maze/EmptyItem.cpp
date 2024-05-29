#include "EmptyItem.hpp"

EmptyItem::EmptyItem() : _currentPosition{Point()}
{
}

void EmptyItem::draw()
{
}

void EmptyItem::useItem()
{
}

const Point &EmptyItem::currentPosition()
{
   return _currentPosition;
}
