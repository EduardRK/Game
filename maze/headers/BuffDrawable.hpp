#pragma once

class BuffDrawable
{
public:
    virtual ~BuffDrawable() = default;

    virtual void draw(int BuffIndex, float side) = 0;
};