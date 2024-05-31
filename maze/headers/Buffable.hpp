#pragma once

#include <memory>

#include "Buff.hpp"

class Buffable
{
public:
    virtual ~Buffable() = default;

    virtual void buff(std::shared_ptr<Buff> buff) = 0;
};