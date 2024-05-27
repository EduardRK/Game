#pragma once

#include "Turnable.hpp"
#include "Player.hpp"

class Buff : public Turnable
{
public:
    virtual ~Buff() = default;

    virtual void buffAction(Player &player) = 0;
};