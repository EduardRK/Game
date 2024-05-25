#pragma once

#include "Drawable.hpp"
#include "Turnable.hpp"
#include "Point.hpp"

class Enemy : public Drawable, public Turnable
{
public:
    virtual ~Enemy() = default;

    virtual Point& currentPosition() = 0;
};