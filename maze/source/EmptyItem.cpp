#include "EmptyItem.hpp"
#include "EmptyActivatingItem.hpp"

void EmptyItem::draw()
{
}

void EmptyItem::backpackDraw(float left, float top, float side)
{
}

std::shared_ptr<ActivatingItem<Explosion>> EmptyItem::getActivatingItem()
{
   return std::make_shared<EmptyActivatingItem>();
}

void EmptyItem::useItem()
{
}

Point EmptyItem::currentPosition()
{
   return Point();
}
