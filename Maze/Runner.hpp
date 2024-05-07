#pragma once

class Runner
{
public:
    virtual ~Runner() = default;

    virtual void run() = 0;
};