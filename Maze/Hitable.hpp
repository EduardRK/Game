#pragma once

#include "Damage.hpp"

class Hitable
{
public:
    virtual ~Hitable() = default;

    virtual void hit(Damage &damage) = 0;
};