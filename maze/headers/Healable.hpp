#pragma once

#include "Heal.hpp"

class Healable
{
public:
    virtual ~Healable() = default;

    virtual void heal(Heal heal) = 0;
};