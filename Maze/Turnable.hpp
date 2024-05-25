#pragma once

class Turnable
{
public:
    virtual ~Turnable() = default;

    virtual void nextTurn() = 0;
};