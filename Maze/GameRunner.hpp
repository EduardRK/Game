#pragma once

class GameRunner
{
public:
    virtual ~GameRunner() = default;

    virtual void run() = 0;
};