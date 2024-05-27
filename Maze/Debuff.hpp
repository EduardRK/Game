#pragma once

#include "Turnable.hpp"
#include "Player.hpp"

class Debuff : public Turnable
{
public:
    virtual ~Debuff() = default;

    virtual debuffAction(Player &player) = 0;
};