#pragma once

class Moveable
{
public:
    virtual ~Moveable() = default;

    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
};