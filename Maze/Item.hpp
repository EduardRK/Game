#pragma once

#include "Drawable.hpp"

class Item : public Drawable
{
public:
    virtual ~Item() = default;

    virtual void useItem() = 0;
};