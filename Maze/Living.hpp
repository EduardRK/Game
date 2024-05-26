#pragma once

class Living
{
public:
    virtual ~Living() = default;

    virtual bool isAlive() = 0;
};