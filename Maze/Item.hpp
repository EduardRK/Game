#pragma once

#include "Drawable.hpp"
#include "Point.hpp"

class Item : public Drawable
{
public:
    virtual ~Item() = default;

    virtual void useItem() = 0;
    virtual const Point& currentPosition() = 0;
};