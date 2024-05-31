#pragma once

#include "Turnable.hpp"
#include "Drawable.hpp"
#include "Attacker.hpp"

class Buff : public Drawable, public Turnable, public Attacker
{
public:
    virtual ~Buff() = default;

    virtual bool complete() = 0;
};