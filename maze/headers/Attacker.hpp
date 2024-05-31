#pragma once

class Attacker
{
public:
    virtual ~Attacker() = default;

    virtual void attack() = 0;
};