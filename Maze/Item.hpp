#pragma once

#include "Drawable.hpp"
#include "Player.hpp"

class Item : public Drawable
{
public:
    virtual ~Item() = default;

    virtual void useItem(const Player &player) = 0;
};