#pragma once

class Runner
{
public:
    virtual ~Runner();

    virtual void run() = 0;
};