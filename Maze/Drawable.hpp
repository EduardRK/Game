#pragma once

class Drawable
{
public:
    virtual ~Drawable();

    virtual void draw() = 0;
};