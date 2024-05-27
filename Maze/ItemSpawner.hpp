#pragma once

#include <memory>

#include "Spawner.hpp"
#include "Item.hpp"

class ItemSpawner final : public Spawner<Item>
{
};