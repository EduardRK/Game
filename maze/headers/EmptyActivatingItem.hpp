#pragma once

#include "ActivatingItem.hpp"
#include "Explosion.hpp"

class EmptyActivatingItem final : public ActivatingItem<Explosion>
{
public:
    EmptyActivatingItem() = default;
    ~EmptyActivatingItem() = default;

    void draw() override;
    void nextTurn() override;
    void activate() override;
    bool complete() override;
    Explosion result() override;
    Point currentPosition() override;
};