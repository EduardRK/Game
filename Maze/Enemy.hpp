#pragma once

#include "Drawable.hpp"
#include "Turnable.hpp"

class Enemy : public Drawable, public Turnable
{
public:
    virtual ~Enemy() = default;
};