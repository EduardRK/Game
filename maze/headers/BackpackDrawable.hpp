#pragma once

class BackpackDrawable
{
public:
    virtual ~BackpackDrawable() = default;

    virtual void backpackDraw(float left, float top, float side) = 0;
};