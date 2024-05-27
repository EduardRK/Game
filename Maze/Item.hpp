#pragma once

#include "Player.hpp"
#include "Drawable.hpp"

class Item : public Drawable
{
public:
    virtual ~Item() = default;

    virtual void useItem() = 0;
};