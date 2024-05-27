#pragma once

#include "Drawable.hpp"
#include "Turnable.hpp"
#include "Point.hpp"
#include "Hitable.hpp"
#include "Dealer.hpp"
#include "Living.hpp"
#include "DeathRattlable.hpp"

class Enemy : public Drawable, public Turnable, public Hitable, public Dealer<Damage>, public Living, public DeathRattlable
{
public:
    virtual ~Enemy() = default;

    virtual Point &currentPosition() = 0;
};