#include "EmptyItem.hpp"
#include "EmptyActivatingItem.hpp"

void EmptyItem::draw()
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
