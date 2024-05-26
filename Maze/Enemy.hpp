#pragma once

#include "Drawable.hpp"
#include "Turnable.hpp"
#include "Point.hpp"
#include "Hitable.hpp"
#include "Dealer.hpp"
#include "Living.hpp"

class Enemy : public Drawable, public Turnable, public Hitable, public Dealer<Damage>, public Living
{
public:
    virtual ~Enemy() = default;

    virtual Point &currentPosition() = 0;
};