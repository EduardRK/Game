#pragma once

#include "Turnable.hpp"
#include "BuffDrawable.hpp"
#include "Attacker.hpp"

class Buff : public BuffDrawable, public Turnable, public Attacker
{
public:
    virtual ~Buff() = default;

    virtual bool complete() = 0;
};