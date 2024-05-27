#pragma once

#include <memory>

#include "Item.hpp"

class DeathRattlable
{
public:
    virtual ~DeathRattlable() = default;

    virtual std::shared_ptr<Item> deathRattle() = 0;
};