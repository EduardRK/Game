#include "EmptyActivatingItem.hpp"

void EmptyActivatingItem::draw()
{
}

void EmptyActivatingItem::nextTurn()
{
}

void EmptyActivatingItem::activate()
{
}

bool EmptyActivatingItem::complete()
{
    return true;
}

Explosion EmptyActivatingItem::result()
{
    return Explosion();
}

Point EmptyActivatingItem::currentPosition()
{
    return Point();
}
